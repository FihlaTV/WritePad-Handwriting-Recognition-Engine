/***************************************************************************************
 *
 *  WRITEPAD(r): Handwriting Recognition Engine (HWRE) and components.
 *  Copyright (c) 2001-2016 PhatWare (r) Corp. All rights reserved.
 *
 *  Licensing and other inquires: <developer@phatware.com>
 *  Developer: Stan Miasnikov, et al. (c) PhatWare Corp. <http://www.phatware.com>
 *
 *  WRITEPAD HWRE is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 *  AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 *  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 *  FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL PHATWARE CORP.
 *  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT, SPECIAL, INCIDENTAL,
 *  INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER,
 *  INCLUDING WITHOUT LIMITATION, LOSS OF PROFIT, LOSS OF USE, SAVINGS
 *  OR REVENUE, OR THE CLAIMS OF THIRD PARTIES, WHETHER OR NOT PHATWARE CORP.
 *  HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 *  POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with WritePad.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************************/

#ifndef LSTRIP

#include  "hwr_sys.h"
#include  "ams_mg.h"
#include  "lowlevel.h"
#include  "calcmacr.h"
#include  "def.h"
#include  "arcs.h"

#define    L_DER_MIN         10
#define    L_CR_ZER          14
#define    L_DER_ZER         21
#define    L_DER_MID         18

/**************************************************************************/

static _INT CrookCalc(low_type _PTR pLowData, p_SHORT pDer, _INT iBeg,
		_INT iEnd);
static _BOOL ArcTurnsOK(low_type _PTR pLowData, _ARC_TYPE typeBordArc,
		_INT iBegArc, _INT iEndArc);
static _BOOL DownStepOK(low_type _PTR pLowData, p_SPECL pSlashArcDown,
		p_SPECL pEndGroup);

#ifdef     D_ARCS

static _BOOL NoteArcData( p_ARC_CONTROL pArcControl, low_type _PTR low_data, p_ARC_DESCR ptmpArcData );
static _VOID DelArcElem( p_ARC_CONTROL pArcControl , _SHORT iDelElement );
static _INT Tan( _SHORT x1 , _SHORT y1 , _SHORT x2 , _SHORT y2 );
static _SHORT ArcsKern( p_LowData low_data, p_ARC_CONTROL pArcControl, _SHORT iInit , _SHORT iStop );

#define    NOSHIFT               0
#define    SHIFT                 1

#define    P_CR_MIN              20
#define    P_CR_MAX              150
#define    P1_A                  250
#define    P2_A                  35

/**************************************************************************/

#endif

#if 0

static _BOOL MeadUpperThen( low_type _PTR pLowData, p_SPECL pSpecl0, p_SPECL pSpecl1 )
{
	_SHORT yM0 , yM1;

	yM0 = (_SHORT) MEAN_OF( (_LONG) ( *(yArr + pSpecl0->ibeg) ), (_LONG) ( *(yArr + pSpecl0->iend) ) );
	yM1 = (_SHORT) MEAN_OF( (_LONG) ( *(yArr + pSpecl1->ibeg) ), (_LONG) ( *(yArr + pSpecl1->iend) ) );

	if ( yM0 < yM1 )
	return( _TRUE );
	else
	return( _FALSE );
}

/**************************************************************************/

static _BOOL MinLeftThen( low_type _PTR pLowData , p_SPECL pSpecl0 , p_SPECL pSpecl1 )
{
	p_SHORT xArr = pLowData->x;
	_INT iMin0 , iMin1;

	iMin0 = ixMin ( pSpecl0->ibeg, pSpecl0->iend, xArr, yArr );
	iMin1 = ixMin ( pSpecl1->ibeg, pSpecl1->iend, xArr, yArr );

	if ( xArr[iMin0] < xArr[iMin1] )
	return( _TRUE );
	else
	return( _FALSE );
}

#endif // 0
/**************************************************************************/

_SHORT SlashArcs(low_type _PTR pLowData, _INT iBeg, _INT iEnd)
{
	p_SPECL pSpecl = pLowData->specl;
	_SHORT _PTR xArr = pLowData->x;
	_SHORT _PTR yArr = pLowData->y;
	p_SPECL pSlashArcDown;
	p_SPECL pSlashArcUp;
	p_SPECL pBegGroup;
	p_SPECL pEndGroup;
	SPECL RecordSpeclElement;
	SPECL _PTR pRecordSpeclElement = &RecordSpeclElement;
	p_SPECL tmpSpecl;
	_INT lenSpecl = pLowData->len_specl;
	_INT dS_h;
	_INT im;

	_SHORT flagSA = SUCCESS;

	for (im = 0; im < lenSpecl; im++)
	{
		pSlashArcDown = pSpecl + im;

		if (pSlashArcDown->ibeg > iEnd)
			break;

		if (pSlashArcDown->iend < iBeg)
			continue;

		if ((pSlashArcDown->mark != MINYX)
				|| ((pSlashArcDown + 1)->mark != MAXYX))
			continue; /* The staff of elements is not fit ... */
		tmpSpecl = pSlashArcDown;
		while ((tmpSpecl->mark != MAXW) && (tmpSpecl->mark != MINW)
				&& (tmpSpecl->mark != BEG))
		{
			tmpSpecl = tmpSpecl->prev;
		}

		if (tmpSpecl->mark != MINW)
			continue;

		pSlashArcUp = pSlashArcDown + 1;
		pBegGroup = tmpSpecl;

		tmpSpecl = pSlashArcDown;
		while ((tmpSpecl->mark != MAXYX) && (tmpSpecl->mark != BEG))
		{
			tmpSpecl = tmpSpecl->prev;
		}

		if (tmpSpecl->mark != MAXYX)
			continue; /* The staff of elements is not fit ... */

		tmpSpecl = pSlashArcUp;
		while ((tmpSpecl->mark != MAXW) && (tmpSpecl->mark != MINW)
				&& (tmpSpecl->mark != END))
		{
			tmpSpecl = tmpSpecl->next;
		}

		if (tmpSpecl->mark != MAXW)
			continue; /* The staff of elements is not fit ... */

		pEndGroup = tmpSpecl;

		tmpSpecl = pBegGroup;
		while ((tmpSpecl->mark != MAXW) && (tmpSpecl != pEndGroup))
		{
			tmpSpecl = tmpSpecl->next;
		}

		if (tmpSpecl != pEndGroup)
			continue; /* The staff of elements is not fit ... */

		if (pSlashArcDown->ipoint0 >= pSlashArcUp->ipoint0)
			continue;

		if (!DownStepOK(pLowData, pSlashArcDown, pEndGroup))
			continue;

		dS_h = HWRMathILSqrt(
				DistanceSquare(pSlashArcDown->ipoint0, pSlashArcUp->ipoint0,
						xArr, yArr));

		if (dS_h <= DEF_MINLENTH_S)
			continue;

		if (ArcTurnsOK(pLowData, ARC_DOWN_LEFT, pSlashArcDown->ibeg,
				pSlashArcDown->iend)
				&& ArcTurnsOK(pLowData, ARC_UP_RIGHT, pSlashArcUp->ibeg,
						pSlashArcUp->iend))
		{
			_INT Cr, minH;
			_SHORT Der;

			pRecordSpeclElement->other = 0;

			Cr = HWRAbs(
					CrookCalc(pLowData, &Der, pBegGroup->ipoint0,
							pEndGroup->ipoint0));
			minH = HeightInLine(yArr[pEndGroup->ipoint0], pLowData);

			if ((Cr < L_DER_MIN) && (Der < L_DER_MIN))
			{
				continue;
			}
			else if ((Cr < L_CR_ZER) && (Der < L_DER_ZER))
			{
				if (minH < _DE2_)
				{
					pRecordSpeclElement->other = pRecordSpeclElement->other
							| ZERO_PENALTY;
				}
				else
				{
					pRecordSpeclElement->other = pRecordSpeclElement->other
							| REGULAR_PENALTY;
				}
			}
			else if ((Cr <= L_DER_MID) || (Der <= L_DER_MID))
			{
				pRecordSpeclElement->other = pRecordSpeclElement->other
						| REGULAR_PENALTY;
			}
			else
			{
				pRecordSpeclElement->other = pRecordSpeclElement->other
						| LARGE_PENALTY;
			}

			pRecordSpeclElement->mark = SHELF;
			pRecordSpeclElement->ibeg = pSlashArcDown->ipoint0;
			pRecordSpeclElement->iend = pSlashArcUp->ipoint0;
			pRecordSpeclElement->ipoint0 = pBegGroup->ipoint0;
			pRecordSpeclElement->ipoint1 = pEndGroup->ipoint0;

			pRecordSpeclElement->other = pRecordSpeclElement->other
					| LETTER_H_STEP;

			if (MarkSpecl(pLowData, pRecordSpeclElement) == UNSUCCESS)
			{
				flagSA = UNSUCCESS;
				goto QUIT;
			}
		}

	}

	QUIT: return (flagSA);
}

/**************************************************************************/

#define   CR_LIM_SHELF_BORD_SLASH_ARCS     8

static _BOOL ArcTurnsOK(low_type _PTR pLowData, _ARC_TYPE typeBordArc,
		_INT iBegArc, _INT iEndArc)
{
	_INT maxCr, tmpCr;
	_SHORT Der;
	_SHORT _PTR yArr = pLowData->y;
	_INT nK;

	if (typeBordArc == ARC_DOWN_LEFT)
		nK = -1;
	else if (typeBordArc == ARC_UP_RIGHT)
		nK = 1;
	else
	{
		nK = 0;
	}

	tmpCr = CrookCalc(pLowData, &Der, iBegArc, iEndArc);
	maxCr = HWRMax( nK * tmpCr , -ALEF );

	if (yArr[iBegArc - 1] != BREAK)
	{
		tmpCr = CrookCalc(pLowData, &Der, iBegArc - 1, iEndArc);
		maxCr = HWRMax( nK * tmpCr , maxCr );
	}

	if (yArr[iEndArc + 1] != BREAK)
	{
		tmpCr = CrookCalc(pLowData, &Der, iBegArc, iEndArc + 1);
		maxCr = HWRMax( nK * tmpCr , maxCr );
	}

	if ((yArr[iBegArc - 1] != BREAK) && (yArr[iEndArc + 1] != BREAK))
	{
		tmpCr = CrookCalc(pLowData, &Der, iBegArc - 1, iEndArc + 1);
		maxCr = HWRMax( nK * tmpCr , maxCr );
	}

	if (maxCr < CR_LIM_SHELF_BORD_SLASH_ARCS)
		return _FALSE;
	else
		return _TRUE;
}

/**************************************************************************/

static _INT CrookCalc(low_type _PTR pLowData, p_SHORT pDer, _INT iBeg,
		_INT iEnd)
{
	_SDS tmpSDS;
	p_SDS pTmpSDS = &tmpSDS;
	_SHORT xd, yd;

	InitElementSDS(pTmpSDS);
	pTmpSDS->ibeg = iBeg;
	pTmpSDS->iend = iEnd;
	iMostFarDoubleSide(pLowData->x, pLowData->y, pTmpSDS, &xd, &yd, _TRUE);

	*pDer = pTmpSDS->des.d;

	if (pTmpSDS->des.dL > pTmpSDS->des.dR)
		return (pTmpSDS->des.cr);
	else
		return (-pTmpSDS->des.cr);
}

/**************************************************************************/

/*     Another sense of the function :  */
/* 'generalized up-slash arc is OK ...' */

#define   H_LIM_HEIGHT_STEP                15

static _BOOL DownStepOK(low_type _PTR pLowData, p_SPECL pSlashArcDown,
		p_SPECL pEndGroup)
{
	_SHORT _PTR yArr = pLowData->y;

	if ((yArr[pEndGroup->ipoint0] - yArr[pSlashArcDown->iend])
			< CR_LIM_SHELF_BORD_SLASH_ARCS)
		return _FALSE;
	else
		return _TRUE;
}

/**************************************************************************/

#ifdef     D_ARCS

static _SHORT Prepare_Arcs_Data( p_ARC_CONTROL pArcControl )
{
	_SHORT sSize;
	_SHORT flag_pa = SUCCESS;

	pArcControl->arc_buf_Len = LEN_ARC_BUFFER;
	pArcControl->LenArcData = 0;
	sSize = ( (pArcControl->arc_buf_Len) * sizeof(ARC_DESCR) );

	if ( ((pArcControl->pArcData) = (p_ARC_DESCR)HWRMemoryAlloc(sSize)) == _NULL )
	{
		flag_pa = UNSUCCESS;
	}
	else
	{
		HWRMemSet((p_CHAR)(pArcControl->pArcData), 0, sSize );
	}

	return ( flag_pa );
}

/**************************************************************************/

static _VOID Dealloc_Arcs_Data ( p_ARC_CONTROL pArcControl )
{
	pArcControl->LenArcData = 0;
	pArcControl->arc_buf_Len = 0;

	if ( (pArcControl->pArcData) != _NULL )
	{
		HWRMemoryFree( (pArcControl->pArcData) );
		pArcControl->pArcData = _NULL;
	}
}

/**************************************************************************/

static _BOOL NoteArcData( p_ARC_CONTROL pArcControl, low_type _PTR low_data, p_ARC_DESCR ptmpArcData )
{
	p_SHORT ind_back = low_data->buffers[2].ptr;
	_BOOL flag_note;

	flag_note = _TRUE;

	if ( pArcControl->LenArcData < (pArcControl->arc_buf_Len - 1) )
	{
		p_ARC_DESCR pNew = pArcControl->pArcData + pArcControl->LenArcData;
		*pNew = *ptmpArcData;
		pNew->iBeg = ind_back[ptmpArcData->iBeg];
		pNew->iEnd = ind_back[ptmpArcData->iEnd];
		( pArcControl->LenArcData )++;
	}
	else
	{
		flag_note = _FALSE;
		goto QUIT;
	}

	QUIT:
	return ( flag_note );
}

/**************************************************************************/

static _VOID DelArcElem( p_ARC_CONTROL pArcControl , _SHORT iDelElement )
{
	p_ARC_DESCR pArcData = pArcControl->pArcData;

	HWRMemCpy( (p_CHAR)( pArcData + iDelElement),
			(p_CHAR)( pArcData + iDelElement + 1 ),
			( (pArcControl->LenArcData) - iDelElement ) *
			sizeof(ARC_DESCR) );

	(pArcControl->LenArcData)--;

QUIT:
	return;
}

/**************************************************************************/

static _SHORT Tan( _SHORT x1 , _SHORT y1 , _SHORT x2 , _SHORT y2 )
{
	_LONG a;
	_SHORT dx;
	_SHORT dy;

	dx = x1 - x2;
	dy = y1 - y2;

	if ( dx==0 && dy==0 )
	{
		a = (_LONG)(-ALEF);
		goto QUIT;
	}
	else
	{
		if (dx != 0)
		a = (_LONG)( LONG_BASE * dy ) / dx;

		if ((dx == 0) || ( HWRLAbs(a) > MAX_NO_VERT ))
		a = ALEF;
		else if ( HWRLAbs(a) < (_LONG)MIN_NO_HOR )
		a = 0L;
	}

	QUIT:
	return( (_SHORT)a );
}

/**************************************************************************/

_SHORT ArcRetrace( low_type _PTR p_low_data , p_ARC_CONTROL pArcControl )
{
	_SHORT ii = p_low_data->ii;
	p_SHORT x = p_low_data->x;
	p_SHORT y = p_low_data->y;
	p_SHORT indBack = p_low_data->buffers[2].ptr;
	p_ARC_DESCR pArcData = pArcControl->pArcData;
	p_ARC_DESCR p_tmpArcData;
	_SHORT iBeg , iEnd , iExt;
	_SHORT il, jl;
	_SHORT init , fin;
	_SHORT shift_Beg;
	_SHORT shift_End;
	_SHORT old_iBeg;
	_SHORT old_iEnd;
	_SHORT ymid;

	il = 0;
	while ( ( (p_tmpArcData = (pArcData+il) )->type != ARC_UNKNOWN )
			&& ( p_tmpArcData->iEnd < ii ) )
	{
		old_iBeg = p_tmpArcData->iBeg;
		old_iEnd = p_tmpArcData->iEnd;
		iBeg = NewIndex( indBack, y, old_iBeg, ii, _MEAD );
		iEnd = NewIndex( indBack, y, old_iEnd, ii, _MEAD );
		shift_Beg = NOSHIFT;
		shift_End = NOSHIFT;

		for ( jl = iBeg+1; jl < iEnd; jl++ )
		{
			if ( y[jl] == BREAK )
			{
				DelArcElem( pArcControl, il );
				goto BOTTOM;
			}

		}

		if ( y[iBeg] == BREAK )
		{
			iBeg++;
			shift_Beg = SHIFT;
		}

		if ( y[iEnd] == BREAK )
		{
			iEnd--;
			shift_End = SHIFT;
		}

		if ( ( p_tmpArcData->type == ARC_DOWN ) || ( p_tmpArcData->type == ARC_UP ) )
		{
			ymid = ( y[iBeg] + y[iEnd] ) / 2;

			if ( shift_Beg == NOSHIFT )
			{
				init = NewIndex( indBack, y, old_iBeg-1, ii, _MEAD );
				if ( y[init] == BREAK )
				init = iBeg;
			}
			else
			{
				init = iBeg;
			}

			if ( shift_End == NOSHIFT )
			{
				fin = NewIndex( indBack, y, old_iEnd+1, ii, _MEAD );
				if ( y[fin] == BREAK )
				fin = iEnd;
			}
			else
			{
				fin = iEnd;
			}

			iExt = iMostFarFromChord( x, y, iBeg, iEnd );
			iBeg = iClosestToY( y, init, iExt, ymid );
			iEnd = iClosestToY( y, iExt, fin, ymid );
		}

		p_tmpArcData->iBeg = iBeg;
		p_tmpArcData->iEnd = iEnd;

		il++;
		BOTTOM:
	}

	QUIT:
	return SUCCESS;
}

/**************************************************************************/

_SHORT Arcs( low_type _PTR low_data, p_ARC_CONTROL pArcControl )
{
	_SHORT stop = low_data->ii - 1;
	p_SHORT y = low_data->y;
	_SHORT fl_begin;
	_SHORT fl_arcs;
	_SHORT i;
	_SHORT begin, end;

	fl_begin = 0;
	fl_arcs = SUCCESS;
	pArcControl->LenArcData = 0;

	for ( i = 0; i <= stop; i++ )
	{
		if ( y[i] == BREAK )
		{
			if ( fl_begin==0 )
			{
				fl_begin = 1;
				begin = i + 1;
			}
			else
			{
				fl_begin = 0;
				end = --i;
				if ( ArcsKern( low_data, pArcControl, begin,end )
						!= SUCCESS )
				{
					fl_arcs = UNSUCCESS;
					goto QUIT;
				}

				if ( i+1 == stop )
				break;
			}
		}
	}
QUIT:

	return( fl_arcs);
}

/**************************************************************************/

static _SHORT ArcsKern( p_LowData low_data, p_ARC_CONTROL pArcControl, _SHORT iInit , _SHORT iStop )
{
	p_SHORT x = low_data->x;
	p_SHORT y = low_data->y;
	p_SPECL pSpecl = low_data->specl;
	p_SPECL pTmp , pPoint, pPrev , pNext;
	ARC_DESCR tmpArcData;
	_SDS tmpSDS;
	_SHORT flag_arc;
	_SHORT ibeg, iend;
	_SHORT tanPrev , tanNext;
	_SHORT xd, yd;
	_SHORT signCurv;
	_ARC_TYPE typeArc;

	flag_arc = UNSUCCESS;
	if ( iInit == iStop )
	goto QUIT;

	pTmp = pSpecl;
	while ( ( pTmp->next != _NULL ) && (( (pTmp->next)->mark != BEG) || ( (pTmp->next)->ibeg != iInit ) ) )
	{
		pTmp = pTmp->next;
	}

	if ( pTmp == _NULL || pTmp->next == _NULL )
		goto QUIT;

	while ( (pTmp=pTmp->next) != _NULL && pTmp->mark != END )
	{
		if ( pTmp->mark ==_MAXX || pTmp->mark ==_MINX ||
				pTmp->mark == MAXW || pTmp->mark == MINW )
		{
			pPoint = pTmp;

			/* Searching appropriate previous element ... */
			pPrev = pPoint;
			while ( ( (pPrev=pPrev->prev) != pSpecl ) && /*CHE*/
					( pPrev->mark != BEG ) &&
					( pPrev->mark != MINW ) &&
					( pPrev->mark != MAXW ) &&
					( pPrev->mark != _MAXX ) &&
					( pPrev->mark != _MINX )
			);
			if ( pPrev->mark == BEG )
				continue;
			if ( pPrev->ibeg == pPoint->ibeg )
				continue;

			/* Searching appropriate next element ......  */
			pNext = pPoint;
			while ( ( (pNext=pNext->next) != _NULL ) && /*CHE*/
					( pNext->mark != END ) &&
					( pNext->mark != MINW ) &&
					( pNext->mark != MAXW ) &&
					( pNext->mark != _MAXX ) &&
					( pNext->mark != _MINX )
			);
			if ( pNext->mark == END )
				continue;
			if ( pNext->iend == pPoint->iend )
				continue;

			if ( pPoint->mark ==_MAXX || pPoint->mark ==_MINX )
			{
				if ( pPrev->ibeg == iInit )
				{
					ibeg = pPrev->ipoint0;
				}
				else if ( pPoint->ibeg <= pPrev->iend )
				{
					ibeg = pPoint->ibeg;
				}
				else
				{
					ibeg = MEAN_OF(pPoint->ibeg, pPrev->iend);
				}

				if ( pNext->iend == iStop )
				{
					iend = pNext->ipoint0;
				}
				else if ( pPoint->iend >= pNext->ibeg )
				{
					iend = pPoint->iend;
				}
				else
				{
					iend = MEAN_OF(pPoint->iend, pNext->ibeg);
				}

				tmpSDS.ibeg = ibeg;
				tmpSDS.iend = iend;
				iMostFarDoubleSide( x, y, &tmpSDS, &xd, &yd, _TRUE );

				if ( tmpSDS.des.cr < P_CR_MIN )
					continue;
				if ( tmpSDS.des.cr > P_CR_MAX )
					continue;

				tanPrev = Tan( x[pPoint->ipoint0], y[pPoint->ipoint0], x[ibeg] , y[ibeg] );
				tanNext = Tan( x[pPoint->ipoint0], y[pPoint->ipoint0], x[iend] , y[iend] );

				if ( ( (_LONG)tanPrev * tanNext ) > 0L )
				continue;

				if (((pNext->mark !=_MAXX && pNext->mark !=_MINX) ||
								(pNext->iend == iStop)) && (HWRAbs(tanNext) > P1_A))
					continue;

				if (((pPrev->mark !=_MAXX && pPrev->mark !=_MINX) ||
								(pPrev->ibeg == iInit)) && (HWRAbs(tanPrev) > P1_A))
					continue;

				if ( pPoint->mark == _MAXX )
				typeArc = ARC_RIGHT;
				if ( pPoint->mark == _MINX )
				typeArc = ARC_LEFT;

				signCurv = CurvMeasure( x,y,ibeg,iend,tmpSDS.des.imax );
				tmpArcData.box.bottom = tmpSDS.ymax;
				tmpArcData.box.right = tmpSDS.xmax;
				tmpArcData.box.left = tmpSDS.xmin;
				tmpArcData.box.top = tmpSDS.ymin;
				tmpArcData.iBeg = ibeg;
				tmpArcData.iEnd = iend;
				tmpArcData.nLength = tmpSDS.des.s;
				tmpArcData.nCurv = signCurv;
				tmpArcData.type = typeArc;

				if ( NoteArcData( pArcControl, low_data, &tmpArcData ) == _FALSE )
				{
					flag_arc = UNSUCCESS;
					goto QUIT;
				}
			}

			else if ( pPoint->mark == MAXW || pPoint->mark == MINW )
			{
				if ( pPrev->ibeg == iInit )
				{
					ibeg = pPrev->ipoint0;
				}
				else if ( pPoint->ibeg <= pPrev->iend )
				{
					ibeg = pPoint->ibeg;
				}
				else
				{
					ibeg = MEAN_OF(pPoint->ibeg, pPrev->iend);
				}

				if ( pNext->iend == iStop )
				{
					iend = pNext->ipoint0;
				}
				else if ( pPoint->iend >= pNext->ibeg )
				{
					iend = pPoint->iend;
				}
				else
				{
					iend = MEAN_OF(pPoint->iend, pNext->ibeg);
				}

				if ( pPoint->mark == MAXW )
				{
					if ( y[pPoint->ipoint0] <= y[ibeg] || y[pPoint->ipoint0] <= y[iend] )
						continue;

					if ( y[ibeg] < y[iend] )
					ibeg = iClosestToY( y,ibeg, pPoint->ipoint0, y[iend] );
					else
					iend=iClosestToY( y, pPoint->ipoint0, iend, y[ibeg] );
				}
				else
				{
					if ( y[pPoint->ipoint0] >= y[ibeg] || y[pPoint->ipoint0] >= y[iend] )
						continue;

					if ( y[ibeg] >= y[iend] )
						ibeg = iClosestToY( y , ibeg , pPoint->ipoint0, y[iend] );
					else
						iend = iClosestToY( y, pPoint->ipoint0, iend, y[ibeg] );
				}

				if ( ibeg > pPoint->ibeg )
					ibeg = pPoint->ibeg;
				if ( iend < pPoint->iend )
					iend = pPoint->iend;

				tmpSDS.ibeg = ibeg; tmpSDS.iend = iend;
				iMostFarDoubleSide( x, y, &tmpSDS, &xd, &yd, _TRUE );

				if ( tmpSDS.des.cr < P_CR_MIN )
					continue;
				if ( tmpSDS.des.cr > P_CR_MAX )
					continue;

				tanPrev = Tan( x[pPoint->ipoint0], y[pPoint->ipoint0],
						x[ibeg] , y[ibeg] );
				tanNext = Tan( x[pPoint->ipoint0], y[pPoint->ipoint0],
						x[iend] , y[iend] );

				if ( ( (_LONG)tanPrev * tanNext ) > 0L )
					continue;

				if (((pNext->mark != MAXW && pNext->mark != MINW ) ||
								(pNext->iend == iStop)) && (HWRAbs(tanNext) < P2_A))
					continue;

				if (((pPrev->mark != MAXW && pPrev->mark != MINW ) ||
								(pPrev->ibeg == iInit)) && (HWRAbs(tanPrev) < P2_A))
					continue;

				if ( pPoint->mark == MAXW )
					typeArc = ARC_DOWN;
				if ( pPoint->mark == MINW )
					typeArc = ARC_UP;

				signCurv = CurvMeasure( x,y,ibeg,iend,tmpSDS.des.imax );
				tmpArcData.box.bottom = tmpSDS.ymax;
				tmpArcData.box.right = tmpSDS.xmax;
				tmpArcData.box.left = tmpSDS.xmin;
				tmpArcData.box.top = tmpSDS.ymin;
				tmpArcData.iBeg = ibeg;
				tmpArcData.iEnd = iend;
				tmpArcData.nLength = tmpSDS.des.s;
				tmpArcData.nCurv = signCurv;
				tmpArcData.type = typeArc;

				if ( NoteArcData( pArcControl, low_data, &tmpArcData ) == _FALSE )
				{
					flag_arc = UNSUCCESS;
					goto QUIT;
				}
			}
		}

		else if ( pTmp->mark == MAXXY && pTmp->mark == MINXY )
		{

		}

		else if ( pTmp->mark == MAXYX && pTmp->mark == MINYX )
		{

		}

	}
	flag_arc = SUCCESS;

QUIT:
	return ( flag_arc);
}

/**************************************************************************/

#endif /*D_ARCS*/

#endif //#ifndef LSTRIP
