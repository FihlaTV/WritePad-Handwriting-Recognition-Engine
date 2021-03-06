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

#ifndef AMS_MG_INCLUDED
#define AMS_MG_INCLUDED

#include "bastypes.h"
#include "reco_ver.h"

#ifdef _OS_LINUX
#undef __cdecl
#define __cdecl
#endif // _OS_LINUX


#if (defined(__PSION32__) || defined(__WINS__) || defined(__MARM__))
#include <e32def.h>
#ifdef __cdecl
#undef __cdecl
#endif
#define __cdecl GLDEF_C
#endif /* __PSION32__ */

/******* Definitions *********************************************/

#define ON                     1
#define OFF                    0

#define USE_ORTOGRAPH         OFF
#define USE_POSTPROC          OFF

#define EXTERN_VOCABULARY    OFF

#if EXTERN_VOCABULARY
#define   PS_VOC           OFF
#else
#define   PS_VOC            ON
#endif

#define SUCCESS   0
#define UNSUCCESS 1

/******* Definitions *********************************************/

#define NUM_RW              10                    /* Size of recognized str*/
#define XRINP_SIZE         160                    /* Len of corr matrix    */
#define w_lim               32                    /* Len of char strings   */
#define MAX_DICT            15
#define MAX_CUSTOM_SYM      40

#define CS_ALPHA         0x0001                   /* Letter enabled        */
#define CS_NUMBER        0x0002                   /* Number enabled        */
#define CS_MATH          0x0004                   /* Mathematic sym's en   */
#define CS_LPUNCT        0x0008                   /* Leading punctuation   */
#define CS_EPUNCT        0x0010                   /* Ending  punctuation   */
#define CS_OTHER         0x0020                   /* Any other symbols     */
#define CS_ADDRESS       0x0040                   /* Internet address symbols */

#define WW_RESTRICTED    0x0001                   /* Writing way -- Restricted set */
#define WW_GENERAL       0x0002                   /* Writing way -- Mixed     */
#define WW_BLOCK         0x0004                   /* Writing way -- HandPrint */
#define WW_PALMER        0x0008                   /* Writing way -- Palmer    */

#define EL_ENGLISH       0x0001                   /* Enabled language -- English */
#define EL_GERMAN        0x0002                   /* Enabled language -- German  */
#define EL_FRENCH        0x0004                   /* Enabled language -- French  */
#define EL_SWEDISH       0x0008                   /* Enabled language -- Swedish */
#define EL_SPANISH       0x0010                   /* Enabled language -- Spanish */

/* ---- XRW_ALGS definitions -------------------------------------------- */

#define XRWALG_XRWS          1            /* Main upper level recognition algorithm */
#define XRWALG_XR_SPL        2            /* Separated letter recognition algorithm */
#define XRWALG_XRSL          3            /* Single letter recognition algorithm */
#define XRWALG_XRLWS         4            /* Combined recognition algorithm */
#define XRWALG_XRLW          5            /* Word  recognition algorithm */
#define XRWALG_EXP          16            /* Experimental routines */
#define XRWALG_CMP          17            /* Get aliases for given CMP word in RC */

#define XRWM_VOC          0x0001          /* Xrws takes symbols from VOC    */
#define XRWM_CS           0x0002          /* Xrws takes symbols from CharSet*/
#define XRWM_TRIAD        0x0004          /* Symbols from charset verified by triads */
#define XRWM_LD           0x0008          /* Symbols are generated by LexDB */
#define XRWM_BLOCK        0x0010          /* Fast 'BLOCK' matrix counting   */
#define XRWM_MWORD        0x0020          /* Multiword dict recognition      */
#define XRWM_NONUMFILTER  0x0040          /* Disable CheckPure num filter      */
#define XRWM_NOSSPENL     0x0080          /* Disable Sources penalties */

#define XRCM_CACHE        0x0001          /* Use cache in counting of matrix */
#define XRCM_SEPLET       0x0002          /* Recognition of separated-letter word */

#define XCM_FL_DEFSIZE    0x0001          /* First letter in accordance with voc/charset   */
#define XCM_FL_TRYCAPS    0x0002          /* Use capitals vars for first letter from voc/cs*/
#define XCM_AL_DEFSIZE    0x0005          /* All letters in accordance with voc/cs         */
#define XCM_AL_TRYCAPS    0x000A          /* Use capitals vars for all letters from voc/cs */
#define XCM_AL_TRYS4C     0x0015          /* Try also small vars for capitals form voc/cs  */
#define XCM_AL_RETC4AV    0x0020          /* Return capitalization for all answer variants */

/* ----------- Load utilities command definitions ----------------------- */

#define TR_REQUEST         1              /* Request to load beg triads */

#define DTI_DTE_REQUEST   0x0001          /* Operation on DTI requested */
#define DTI_XRT_REQUEST   0x0002          /* Operation on XRT requested */
#define DTI_PDF_REQUEST   0x0004          /* Operation on PDF requested */
#define DTI_PICT_REQUEST  0x0008          /* Operation on PICT requested*/

/* ----------- Low level modes & values --------------------------------- */

/*  Possible values of the "rec_mode" field of "rc_type" structure. */
/* May be combined (using OR):                                      */

#define  RECM_TEXT       1
#define  RECM_FORMULA    2
#define  RECM_ALL        (RECM_TEXT|RECM_FORMULA)

/*
 Constants - values of the "low_mode" field in "rc_type"
 structure:
 Only one flag from each group (excluding
 LMOD_CHECK_PUNCTN) may be set!
 Flags concerning BORDER have effect only when LMOD_FREE_TEXT
 is set.  When LMOD_BOX_EDIT is set, the border fields in "rc"
 must contain predefined value for the line borders.
 Flag LMOD_CHECK_PUNCTN has no effect in LMOD_BOX_EDIT mode.
 */

#define   LMOD_BOX_EDIT       (_USHORT)0x0001
#define   LMOD_FREE_TEXT      (_USHORT)0x0002

#define   LMOD_BORDER_TEXT    (_USHORT)0x0010
#define   LMOD_BORDER_NUMBER  (_USHORT)0x0020

#define   LMOD_BORDER_GENERAL (LMOD_BORDER_TEXT|LMOD_BORDER_NUMBER)
#define   LMOD_NO_BORDER_DECISION  (_USHORT)0
#define   LMOD_BORDER_ONLY    (_USHORT)0x0040

#define   LMOD_SEPARATE_LET   (_USHORT)0x0400

#define   LMOD_SMALL_CAPS     (_USHORT)0x0800

#define   LMOD_CHECK_PUNCTN   (_USHORT)0x8000

#define   CB_NUM_VERTEX         10

/* -------------- XRinp section ----------------------------------------- */

#define XRB_ST_ELEM        0x01                  /* Tail flag of starting element */
#define XRB_EN_ELEM        0x02                  /* Tail flag of ending element */

/* ------- Learning info flags definitions for LearningHandleConfig field - */
#define kLDRC       0x0001          /* write RC         to learning info    */
#define kLDTrace    0x0002          /* write Trace      to learning info    */
#define kLDXRdata   0x0004          /* write XRdata     to learning info    */
#define kLDRWS      0x0008          /* write RWS        to learning info    */
#define kLDRWGPPD   0x0010          /* write RWG PDD    to learning info    */
#define kLDRecWrd   0x0020          /* write rec words  to learning info    */
#define kLDORT      0x0040          /* write poliakov's data to learning info   */
/* ---------------------------------------------------------------------- */

/* ------- Learning info flags definitions for fOrto field ------------ */
#define kORTO_UPPER 0x0001      /*  use ortograph in upper level        */
#define kORTO_POSTP 0x0002      /*  use ortograph as a postrocessing    */
#define kORTO_EMPTY 0x0004      /*  use an empty data base              */
#define kORTO_LEARN 0x0008      /*  perform learning                    */
/* -------------------------------------------------------------------- */

/* ----------------- Upper level defines -------------------------------- */

#define XRWG_FCASECHANGE  0x80    /* Flag of case-of-letter change in alias */

#define XRLV_DATA_SAVE    0x01    /* Save not-finished state for the word */
#define XRLV_DATA_USE     0x02    /* Use not-finished state for the word */

/* ----------- System yield function ------------------------------------- */

#define __cdecl

typedef _INT (__cdecl *RecYield_type)(p_VOID);

/********** Structure definitions *******************************/

/* ----------------- Lower level structures ----------------------------- */

typedef struct
{
    _SHORT          x;
    _SHORT          y;
} PS_point_type, _PTR p_PS_point_type;

typedef  p_PS_point_type _TRACE ;

typedef  struct
{
    _SHORT          left;
    _SHORT          top;
    _SHORT          right;
    _SHORT          bottom;
} _RECT, _PTR p_RECT;

typedef struct
{
    _RECT           box;
    _SHORT          extr_depth;
    
    _SHORT          size_in;
    _SHORT          dn_pos_in;
    _SHORT          size_sure_in;
    _SHORT          pos_sure_in;
    
    _SHORT          size_out;
    _SHORT          dn_pos_out;
    _SHORT          size_sure_out;
    _SHORT          pos_sure_out;
} stroka_data, _PTR p_stroka_data;

/* --------------------------------------------------------------------- */
/*  Structure containing control variables for postprocessing  */
/* applicability:                                              */

typedef  struct
{
    _SHORT   nMinWeight; /*  Min. weight of 1st variant   */
    /* for postproc. to be applied.  */
    _SHORT   nMaxDist;   /*  Max. weight distance between */
    /* two first variants for post-  */
    /* proc. to be applied.          */
} POST_CONTROLS, _PTR p_POST_CONTROLS;

/* ----------------- Global Rec Context --------------------------------- */

typedef struct
{
    _SHORT          algorithm;          /* Upper level recognition algorithm */
    
    _SHORT          enabled_cs;         /* Inluded parts of symbol set (anmleo) */
    _SHORT          enabled_ww;         /* Enabled ways of writing (Handprint/Palmer/Mixed) (bpg) */
    _SHORT          enabled_languages;  /* Allowed languages to use from DTI prototypes (egf)*/
    
    _SHORT          xrw_mode;            /* Xrws mode v/c/t/b ....         */
    _SHORT          corr_mode;           /* Corr matr modes - s/c ...      */
    _SHORT          xrw_max_wlen;        /* Max Num let in word to read    */
    _SHORT          xrw_tag_size;        /* Number of TAG buffers          */
    _SHORT          bad_distance;        /* CutOff distance of XRW modules */
    
    _SHORT          answer_level;
    _SHORT          sure_level;
    _SHORT          answer_allow;
    
    _SHORT          bad_amnesty;
    
    _SHORT          caps_mode;

    _SHORT          use_vars_inf;
    
    _SHORT          lrn_class_level;
    _SHORT          lrn_min_class;
    
    p_VOID          dtiptr;               /* Handle to Xr database            */
    p_VOID          vocptr[MAX_DICT];     /* Handle to vocabularies           */
    p_VOID          tr_ptr;               /* Handle to character filters      */
    
    p_VOID          cflptr;               /* LexDB pointer                */
    p_UCHAR         alpha_charset;
    p_UCHAR         num_charset;
    _UCHAR          math_charset[MAX_CUSTOM_SYM];
    _UCHAR          lpunct_charset[MAX_CUSTOM_SYM];
    _UCHAR          epunct_charset[MAX_CUSTOM_SYM];
    _UCHAR          other_charset[MAX_CUSTOM_SYM];
    
    _USHORT         low_mode;          /*  See possible values above (LMOD_...).*/
    _USHORT         rec_mode;          /*  See possible values above (RECM_...).*/
    _USHORT         lmod_border_used;  /* See possible values above (LMOD_BORDER...).*/
    
    _SHORT          ii;                /* Number of points in trajectory */
    _TRACE          trace;             /* Trajectory */
    _RECT           trace_rect;        /* Box of the trajectory */
    _SHORT          slope;             /* Slope of the trajectory */
    
    _UCHAR          curv_bord[CB_NUM_VERTEX*2];  /* Curved border of the trace */
    
    _UCHAR          ws_handle;
    _USHORT         LearningHandleConfig;
        
    _SHORT         fOrto;                // ORTOGRAPH
    p_VOID          pDB;
    
    _CHAR          cmp_word[w_lim];
    
    stroka_data     stroka;             /* new data structure for baseline */
    _SHORT          BoxEditSamllHeight;
    _SHORT          BoxEditBase;
    
    _SHORT          fReject;              // REJECT
    
    POST_CONTROLS   postCtrl;
    
    RecYield_type   pFuncYield;       // Callback Yield fuction
    p_VOID          FY_param;         // Parameter for FuncYield
    
    p_VOID          p_ws_wi;          // Pointer to struct with ws info for cur word
    
    _INT            f_xd_data;        // Flags controlling saving of xd data
    p_VOID          p_xd_data;        // Pointer to XRLV data structure saved for continuing recognition
    _INT            lang;               // current language
    
} rc_type, _PTR p_rc_type;

/* -------------- XRinp section ----------------------------------------- */

typedef struct
{
    _UCHAR type;                 //64  direction:1b:type:2b:width:3b:
    _UCHAR attrib;               // bit field
    _UCHAR penalty;              //16 max value
    _UCHAR height;               //16
    
    _UCHAR shift;                //16
    _UCHAR orient;               //32
    _UCHAR depth;                //16
    
    _UCHAR emp;                  // 2x4 point/dash
} xrinp_type, _PTR p_xrinp_type;


typedef struct
{
    xrinp_type      xr;
    _SHORT          hotpoint;
    _SHORT          begpoint;
    _SHORT          endpoint;
    _SHORT          box_left;
    _SHORT          box_up;
    _SHORT          box_right;
    _SHORT          box_down;
    _UCHAR          location;
} xrd_el_type, _PTR p_xrd_el_type;

typedef xrd_el_type xrd_type[XRINP_SIZE];
typedef xrd_type _PTR p_xrd_type;

typedef struct
{
    _INT            len;     // Real filled length
    _INT            size;    // Allocated size (in els)
    p_xrd_type      xrd;     // Pointer to array of xrd_el's
} xrdata_type, _PTR p_xrdata_type;

/* ----------- Rec Words Structure --------------------------------------- */

typedef struct
{
    _UCHAR          word[w_lim];
    _UCHAR          nvar[w_lim];    /* Number of variants + CapsChange falg */
    _UCHAR          linp[w_lim];    /* Lengths of letter-correspondent xr strings */
    _SHORT          weight;
    _SHORT          src_id;
    _SHORT          attr;
} rec_w_type, _PTR p_rec_w_type;

/* ----------- Symbol Graph definitions ---------------------------------- */

typedef struct
{
    /* Type, defining base of graph             */
    _UCHAR           type;     /* Graph type (word/letter/number           */
    _INT             size;     /* Number of elements in RWS array          */
    p_VOID           rws_mem;  /* Pointer to RWS  memory                   */
    p_VOID           ppd_mem;  /* Pointer to PPD allocation                */
    _BOOL            bReversePass; /* For ppd in upper level -- flag of reverse rwg */
} RWG_type, _PTR p_RWG_type;

/* --------------------- Prototypes ---------------------------- */

_INT   AllocXrdata(p_xrdata_type xrdata, _INT size);
_INT   FreeXrdata(p_xrdata_type xrdata);
_INT   PreprocessTrajectory(p_rc_type rc);

#endif /*  AMS_MG_INCLUDED  */
