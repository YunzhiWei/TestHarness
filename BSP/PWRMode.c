#include "_Platform.h"

#ifdef INCLUDE_MODULE_PWRMODE

/*
    S0/D0/C0 RUN & Turbo
    S0/D0CS  Ring Oscillator
    S0/D0/C1 Idle
    S0/D1/C2 LCD Refresh Standby
    S0/D2/C2 Standby
    S2/D3/C4 Sleep
    S3/D4/C4 Deep Sleep
*/

/*
    Highlight:
          #1  direct-key wake-up option ( matrix-key has the same problem )

              When using direct-key to wake-up from D2/D3 to D0, the cpu can be in standby/sleep state for the first time and
              to press direct-key to wake-up is ok. But when continue to test again, the cpu will wake-up automatically without
              pressing that direct-key. Maybe the pin state is retained or the hardware of direct-key will give us two signals
              when pressing one time. Still under investigation.

              EXT_WAKEUP<0> wake-up option is ok.

          #2  If any one, such as LCD, is using DDR, enter standby mode will cause some error. This will lead to the system cannot enter low power mode again.

*/

#define REG_ASCR                        (*MH_ASCR)
#define REG_ARSR                        (*MH_ARSR)

#define REG_AD3ER                       (*MH_AD3ER)
#define REG_AD3SR                       (*MH_AD3SR)

#define REG_AD2D0ER                     (*MH_AD2D0ER)
#define REG_AD2D0SR                     (*MH_AD2D0SR)

#define REG_AD1D0ER                     (*MH_AD1D0ER)
#define REG_AD1D0SR                     (*MH_AD1D0SR)

#define REG_AD3R                        (*MH_AD3R)
#define REG_AD2R                        (*MH_AD2R)
#define REG_AD1R                        (*MH_AD1R)

#define REG_PMCR                        (*MH_PMCR)

#define REG_PWER                        (*MH_PWER)
#define REG_PWSR                        (*MH_PWSR)

#define REG_ACCR                        (*MH_ACCR)
#define REG_ACSR                        (*MH_ACSR)

#define REG_PSR                         (*MH_PSR)

void PWRMode_Initial(void)
{
    REG_ASCR &=~ ASCR_RDH; // UDC D+/D- need this to work!

     /* HSIO2 clock enable, must be set as '1' before any lower power mode ro D0CS entry */
}

U32 PWRMode_GetBootupScenario(void)
{
    volatile U32 arsr, psr, flagcounter;
    volatile U32 condition;

    condition = 0;
    flagcounter = 0;

    arsr = REG_ARSR;
    psr  = REG_PSR;

    REG_ARSR = arsr;
    REG_PSR  = psr;

    MY_TraceStrLine("Reset from ");

    if(psr & PSR_BFS)
    {
        MY_TraceStrLine("BF-DS");
        condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;
    }
    if(psr & PSR_SS3S)
    {
        MY_TraceStrLine("SW-DS");
        condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;
    }
    if(psr & PSR_SS2S)
    {
        MY_TraceStrLine("SW-SL");
        condition |= BOOT_UP_CONDITION_VOTAGE;
    }

    if(arsr != 0)
    {
        if(arsr & ARSR_GPR)
        {
            condition |= BOOT_UP_CONDITION_VOTAGE;

            flagcounter++;
            MY_TraceStrLine("GPIO");
        }
        if(arsr & ARSR_WDT)
        {
            condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;

            flagcounter++;
            MY_TraceStrLine("Watchdog");
        }
        if(arsr & ARSR_LPMR)
        {
            condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;

            flagcounter++;
            MY_TraceStrLine("Deep");
        }
        if(arsr & ARSR_HWR)
        {
            condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;

            flagcounter++;
            MY_TraceStrLine("HW");
        }

        if(flagcounter > 1)
        {
            MY_TraceStrLine("Error: multi-reset source");
            MY_TraceStrLine("ERROR");
        }
    }
    else
    {
        condition |= BOOT_UP_CONDITION_VOTAGE | BOOT_UP_CONDITION_ONKEY;
    }

    return(condition);
}

void PWRMode_SWGPIOReset(void)
{
    REG_PMCR = PMCR_SWGR;
}

void PWRMode_PreStandby(void)
{
    REG_AD2D0SR = REG_AD2D0SR;

    REG_AD2R    = ADnR_ADn_R3 | ADnR_ADn_R0;
    REG_AD2D0ER = ADnESR_WK_EXT(0) | ADnESR_WK_GPIN(5);
}

void PWRMode_PostStandby(void)
{
    DBG_TraceHex("AD2D0SR", REG_AD2D0SR);
}

void PWRMode_PreSleep(void)
{
    REG_AD3SR   = REG_AD3SR;

    REG_AD3R    = 0; // ADnR_ADn_R3 | ADnR_ADn_R0;
    REG_AD3ER   = ADnESR_WK_GPIN(12); // ADnESR_WK_EXT(0);
}

void PWRMode_PostSleep(void)
{
    DBG_TraceHex("AD3SR", REG_AD3SR);
    DBG_TraceHex("REG_PWSR", REG_PWSR);
}

void PWRMode_PreDSleep(void)
{
    REG_PWSR = REG_PWSR;
    REG_PWER = PWSR_WEF | PWSR_WER;
}

void PWRMode_PostDSleep(void)
{
    DBG_TraceHex("REG_PWSR", REG_PWSR);
}

#endif //INCLUDE_MODULE_PWRMODE

