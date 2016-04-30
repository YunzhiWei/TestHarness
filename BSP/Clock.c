
#include "_platform.h"

#ifdef INCLUDE_MODULE_CLOCK

/*
    Register Value
*/

#define REG_OSCC                        (*MH_OSCC)

#define REG_CKENA                       (*MH_D0CKENA)
#define REG_CKENB                       (*MH_D0CKENB)
#define REG_PCFR                        (*MH_PCFR)

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

void Clock_Initial(void)
{
    REG_CKENA = REG_CKENA_SETTING;
    REG_CKENB = REG_CKENB_SETTING;

    REG_PCFR |= PCFR_SYSEN_EN | PCFR_PI2C_EN;

    REG_OSCC |= OSCC_PEN;
}

void Clock_Enable(U32 dwRegSet, U32 dwMask, BOOL bTrue)
{
    volatile U32 *p;

    p = MH_D0CKENA;

    if(dwRegSet > CLOCK_REG_SET_LAST)
    {   // We have only two sets: MH_D0CKENA & MH_D0CKENB
        return;
    }

    if(bTrue)
    {
        p[dwRegSet] |= dwMask;
    }
    else
    {
        p[dwRegSet] &=~ dwMask;
    }
}

#endif //INCLUDE_MODULE_CLOCK

