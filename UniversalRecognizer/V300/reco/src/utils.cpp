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

#include "hwr_sys.h"
#include "hwr_swap.h"
#include "zctype.h"

#include "ams_mg.h"
#include "xrword.h"

#include "reco.h"
#include "langid.h"

/* ************************************************************************* */
/*        Single letter recognition algorithm                                */
/* ************************************************************************* */
_INT GetCharset( p_UCHAR charset, _INT cs_size, rc_type _PTR rc )
{
    _INT    i, j;
    _INT    all_sorted;
    _INT    en_alc;

    charset[0] = 0;
    en_alc     = rc->enabled_cs;

    // if (rc->filter == FLT_NUMBER) en_alc = CS_NUMBER | CS_OTHER;

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_ALPHA)  && (_INT)(i + HWRStrLen((_STR)rc->alpha_charset)) < cs_size-2)
        HWRStrCpy((_STR)&charset[i], (_STR)rc->alpha_charset);

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_NUMBER) && (_INT)(i + HWRStrLen((_STR)rc->num_charset)) < cs_size-2)
        HWRStrCpy((_STR)&charset[i], (_STR)rc->num_charset);

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_MATH) && (_INT)(i + HWRStrLen((_STR)rc->math_charset)) < cs_size-2)
        HWRStrCpy((_STR)&charset[i], (_STR)rc->math_charset);

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_LPUNCT) && (_INT)(i + HWRStrLen((_STR)rc->lpunct_charset)) < cs_size-2)
        HWRStrCpy((_STR)&charset[i], (_STR)rc->lpunct_charset);

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_EPUNCT) && (_INT)(i + HWRStrLen((_STR)rc->epunct_charset)) < cs_size-2)
        HWRStrCpy((_STR)&charset[i], (_STR)rc->epunct_charset);

    i = HWRStrLen((_STR)&charset[0]);
    if ((en_alc & CS_OTHER) && i + HWRStrLen((_STR)rc->other_charset) < 254)
        HWRStrCpy((_STR)&charset[i],(_STR) rc->other_charset);

    j = HWRStrLen((_STR)&charset[0]);

    all_sorted = 0;
    while ( !all_sorted )
    {
        _UCHAR m;

        all_sorted = 1;
        for ( i = 1; i < j; i++)
        {
            if (charset[i] < charset[i-1])
            {
                m            = charset[i-1];
                charset[i-1] = charset[i];
                charset[i]   = m;
                all_sorted   = 0;
            }
        }
    }

    for (i = 1; i < j; i ++)
    {
        if (charset[i-1] == charset[i])
        {
            HWRMemCpy((_STR)&charset[i-1], (_STR)&charset[i], j - i + 1);
            j --;
            i --;
        }
    }

    return 0;
}

/* ************************************************************************* */
/*  This function calculates the coeffs "a" and "b" of the  */
/* straight line with formula "y=a*x+b".  This line must be */
/* the best in terms of the least sum of (error squared).   */
/* ************************************************************************* */

_INT GetBaseBord(p_rc_type rc)
{
    _INT  i;
    _INT  a;
    _UCHAR _PTR curv_bord = rc->curv_bord;
    _LONG SXY=0, SY=0;
    _INT  Dx = (rc->stroka.box.right - rc->stroka.box.left);
    _INT  Dy = (rc->stroka.box.bottom - rc->stroka.box.top);

    for ( i = 0; i <= (CB_NUM_VERTEX-1); i++ )
    {
        SXY += i*(_LONG)((curv_bord[2*i]+curv_bord[2*i+1])/2);
        SY  +=   (_LONG)((curv_bord[2*i]+curv_bord[2*i+1])/2);
    }

    if ( Dx != 0 )
        a = (_INT)(3*Dy*(2*SXY - (CB_NUM_VERTEX-1)*SY) / (Dx*(CB_NUM_VERTEX)*(CB_NUM_VERTEX+1)));
    else 
        a = 0;

    return a;
}
 
RECO_DATA_EXTERNAL _UCHAR DiacriticsLetter[LANGUAGE_SIZE][60];

/* ************************************************************************* */
/* *  Count box for a given xrdata elements line                           * */
/* ************************************************************************* */

_INT GetSymBox(_UCHAR sym, _INT st, _INT end, p_xrdata_type xrdata, p_RECT box, _INT lang )
{
    _INT j;
    _INT fl_punct = IsPunct(sym);
    _INT yt, yb, ytp, ybp, set, setp;
    _INT xl, xr, xlp, xrp;
    _INT fl_crest = 0;
    //  xrlw_gr_data_type_array  (_PTR xrlg)[XRINP_SIZE] = xd->xrlg;
    //  p_xrlw_gr_data_type_array pxrlg;
    //  p_xrd_type                xrd = xd->xrdata->xrd;
    p_xrd_el_type   xel;

    if ( st >= end ) 
        return 1;

    xel = &((*xrdata->xrd)[st]);
    yt  = ytp = 32000; 
    yb = ybp = 0; 
    set = setp = 0;
    xl  = xlp = 32000; 
    xr = xrp = 0;

    for ( j = st; j < end; j ++, xel ++ )
    {
        if ( IsXrLink(xel) ) 
            continue;

        if ( GetXrMovable(xel) )
        {
            if ( ytp > xel->box_up ) 
                ytp = xel->box_up;

            if (ybp < xel->box_down ) 
                ybp = xel->box_down;

            if (xlp > xel->box_left ) 
                xlp = xel->box_left;

            if (xrp < xel->box_right) 
                xrp = xel->box_right;

            if (xel->xr.type != X_ST) 
                fl_crest ++;

            setp ++;
        }
        else
        {
            if (yt > xel->box_up   )
                yt = xel->box_up;
            if (yb < xel->box_down )
                yb = xel->box_down;
            if (xl > xel->box_left )
                xl = xel->box_left;
            if (xr < xel->box_right)
                xr = xel->box_right;
            set ++;
        }
    }

    if ( set < 2 ) // Less than 2 normal els in letter
    {
        if ( !setp )
        {
            yt = yb = (*xrdata->xrd)[0].box_up;   // Nothing at alll???
            xl = xr = (*xrdata->xrd)[0].box_left; // Nothing at alll???
        }
        else
        {
            if ( set ) 
            {
                yt = HWRMin(yt,ytp); 
                yb = HWRMax(yb,ybp);
                xl = HWRMin(xl,xlp); 
                xr = HWRMax(xr,xrp);
            }
            else 
            {
                yt = ytp; 
                yb = ybp; 
                xl = xlp; 
                xr = xrp;
            }
        }
    }

    if ( fl_punct && setp ) 
    {
        yt = HWRMin(yt,ytp); 
        yb = HWRMax(yb,ybp);
        xl = HWRMin(xl,xlp); 
        xr = HWRMax(xr,xrp);
    }

    box->top    = (_SHORT)yt;
    box->bottom = (_SHORT)yb;
    box->left   = (_SHORT)xl;
    box->right  = (_SHORT)xr;

    if (fl_crest && setp) // Widen box for letters like capital 'T' and 'E' and 'I'
    {
        if ((lang == LANGUAGE_NORWEGIAN || lang == LANGUAGE_DANISH
            || lang == LANGUAGE_GERMAN || lang == LANGUAGE_FRENCH
            || lang == LANGUAGE_ITALIAN || lang == LANGUAGE_SPANISH
            || lang == LANGUAGE_SWEDISH || lang == LANGUAGE_FINNISH) == false
            || HWRStrChr((p_CHAR)DiacriticsLetter[lang],sym) == _NULL)
        {
            yt = HWRMin(yt,ytp); yb = HWRMax(yb,ybp);
            // xl = HWRMin(xl,xlp); xr = HWRMax(xr,xrp);
            
            if ( yt < box->top )
            {
                if (box->top-yt > (box->bottom - box->top)/3) 
                    box->top -= (box->bottom - box->top)/3;
                else 
                    box->top = yt;
            }

            if ( yb > box->bottom )
            {
                if (yb - box->bottom > (box->bottom - box->top)/3) 
                    box->bottom += (box->bottom - box->top)/3;
                else 
                    box->bottom = yb;
            }
        }
    }

    return 0;
}
