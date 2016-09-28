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

#include "ams_mg.h"
#include "langid.h"

#include "trd_imge.cpp"
#if defined(LANG_FRENCH) || defined(LANG_ITALIAN) || defined(LANG_PORTUGUESE)
#include "trd_imgf.cpp"
#endif // defined(LANG_FRENCH) || defined(LANG_ITALIAN) || defined(LANG_PORTUGUESE)
#ifdef LANG_GERMAN
#include "trd_imgg.cpp"
#endif // LANG_GERMAN

RECO_DATA p_tr_descr_type triads_get_header(_INT lang)
{
    switch(lang)
    {
#if defined(LANG_FRENCH) || defined(LANG_ITALIAN) || defined(LANG_PORTUGUESE)
        case LANGUAGE_FRENCH:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_PORTUGUESE:
            return (RECO_DATA p_tr_descr_type)&img_trd_header_frn;
#endif
#ifdef LANG_GERMAN
        case LANGUAGE_GERMAN:
            return (RECO_DATA p_tr_descr_type)&img_trd_header_ger;
#endif
        default:
            return (RECO_DATA p_tr_descr_type)&img_trd_header_eng;
    }
}

RECO_DATA p_ULONG triads_get_body(_INT lang)
{
    switch(lang)
    {
#if defined(LANG_FRENCH) || defined(LANG_ITALIAN) || defined(LANG_PORTUGUESE)
        case LANGUAGE_FRENCH:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_PORTUGUESE:
            return (RECO_DATA p_ULONG)&img_trd_body_frn[0];
#endif // defined(LANG_FRENCH) || defined(LANG_ITALIAN) || defined(LANG_PORTUGUESE)
#ifdef LANG_GERMAN
        case LANGUAGE_GERMAN:
            return (RECO_DATA p_ULONG)&img_trd_body_ger[0];
#endif // LANG_GERMAN
        default:
            return (RECO_DATA p_ULONG)&img_trd_body_eng[0];
    }
}

