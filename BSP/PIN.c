
#include "_Platform.h"

#ifdef INCLUDE_MODULE_PIN

/*
    Bug:

        1.     When we set this flag at PIN initial, event we invoke PIN_ClearEdgeFlag, the Wake Up event will never happen!!!
*/

#define MFPR_REG_VALUE_SETTING(regAddr, regValue)           (regAddr)
static U16 MFPR_REG_OFFSET[] = {
#include "PIN_Setting.c"
};
#undef MFPR_REG_VALUE_SETTING

#define MFPR_REG_VALUE_SETTING(regAddr, regValue)           (regValue)
static U16 MFPR_REG_VALUE[] = {
#include "PIN_Setting.c"
};
#undef MFPR_REG_VALUE_SETTING

void PIN_Initial(void)
{
//#define DEBUG_PIN_INIT

    U16* poffset;
    U16* pvalue;

    U32  regaddr;
    U32  *p;
    U32  regval;

    poffset = MFPR_REG_OFFSET;
    pvalue  = MFPR_REG_VALUE;

    while(0 != *poffset)
    {
        regaddr = MH_MFPR_BASE + (U32)(*poffset);
        p       = (U32*)regaddr;

#ifdef DEBUG_PIN_INIT
        regval  = *p;
#else
        regval  = (U32)(*pvalue);
        *p      = regval;
#endif
#ifdef DEBUG_PIN_INIT
        DBG_TraceStrLine("");

        DBG_TraceString("[");
        DBG_TraceHex(NULL, (U32)regaddr);
        DBG_TraceString("]");
        DBG_TraceString("[");
        DBG_TraceHex(NULL, *poffset);
        DBG_TraceString("]");

        DBG_TraceString(" ");
        DBG_TraceHex(NULL, regval);
        DBG_TraceString(" ");
        DBG_TraceHex(NULL, *pvalue);

        if(regval != (U32)(*pvalue))
        {
            DBG_TraceString(" ***");
//            DBG_BreakPoint("Wait...");
        }
#endif
        poffset++;
        pvalue++;
    }

//    DBG_BreakPoint("Wait...");
}

void PIN_ClearEdgeFlag(U32 dwNumber)
{
    U16* poffset;
    U32  regaddr;
    U32  *p;
    U32  regval;

    poffset = MFPR_REG_OFFSET;
    regaddr = MH_MFPR_BASE + poffset[dwNumber];

    p       = (U32*)regaddr;
    regval  = *p;

//    DBG_TraceHex("Addr", regaddr);
//    DBG_TraceHex("Val",  regval);

    *p     |= MFPR_EDGE_CLEAR;
    *p      = regval;
}

#endif //INCLUDE_MODULE_PIN

