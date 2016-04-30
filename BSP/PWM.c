
#include "_platform.h"

#ifdef INCLUDE_MODULE_PWM

/*
    Register Value
*/

#define REG_CR                          (*MH_PWMCR3)
#define REG_DCR                         (*MH_PWMDCR3)
#define REG_PCR                         (*MH_PWMPCR3)

void PWM3_OutControl(U32 dwPercentage)
{
    REG_CR  = 0;
    REG_PCR = 800;

    if(dwPercentage == 100)
    {
        REG_DCR = DCR_FD;
    }
    else
    {
        REG_DCR = dwPercentage * 8;
    }
}

/*
    Public Data Structure
    Public Functions
    Export to other Modules

*/

#endif

