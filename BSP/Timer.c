
#include "_platform.h"

#ifdef INCLUDE_MODULE_TIMER

/*
    Bug:
        1. Timer 5 ~ 7 does not work
*/

/*
    Register Value
*/

#define OSTIMER_CHENNEL1_INTERVAL       3250000
#define TIMER_OSTM_CIRCLE_ID            1

#define TIMER_OIER                      (*MH_OIER)
#define TIMER_OSSR                      (*MH_OSSR)

#define TIMER_DELAY_ID                  4
static volatile U32 *s_pdwTimerOSMR     = MH_OSMR4;
static volatile U32 *s_pdwTimerOSCR     = MH_OSCR4;
static volatile U32 *s_pdwTimerOMCR     = MH_OMCR4;

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

void Timer_Delay(U32 dwID, t_TIMER_UNIT tUnit, U32 dwCount)
{
    if(dwCount == 0)        return;

    s_pdwTimerOMCR[dwID]    = OMCR_CRES(tUnit);
    s_pdwTimerOSMR[dwID]    = dwCount;
    s_pdwTimerOSCR[dwID]    = 0;

    TIMER_OIER |= 1<<(TIMER_DELAY_ID + dwID);
    while(!(TIMER_OSSR & (1<<(TIMER_DELAY_ID + dwID))))   { ; }
    TIMER_OSSR = (1<<(TIMER_DELAY_ID + dwID));

    s_pdwTimerOMCR[dwID] = OMCR_CRES(e_TIMER_UNIT_Stop);
}

void Timer_Start(U32 dwID, t_TIMER_UNIT tUnit)
{
    s_pdwTimerOMCR[dwID]    = OMCR_CRES(tUnit);
    s_pdwTimerOSMR[dwID]    = (U32)(-1);
    s_pdwTimerOSCR[dwID]    = 0;
}

U32 Timer_Stop(U32 dwID)
{
    volatile U32 t;

    t = s_pdwTimerOSCR[dwID];

    s_pdwTimerOMCR[dwID] = OMCR_CRES(e_TIMER_UNIT_Stop);

    return(t);
}

void OSTimer01_INTHandler(void)
{
    DBG_TraceHex("OSMR1", *MH_OSMR1);

    TIMER_OSSR |= (1<<TIMER_OSTM_CIRCLE_ID);

    *MH_OSMR1 = *MH_OSCR0 + OSTIMER_CHENNEL1_INTERVAL;
}

#endif //INCLUDE_MODULE_TIMER

