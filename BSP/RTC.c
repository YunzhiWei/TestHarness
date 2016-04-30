
#include "_platform.h"

/*
*/

#ifdef INCLUDE_MODULE_RTC

/*
    Register Value
*/

#define REG_RDCR                        (*MH_RDCR)
#define REG_RYCR                        (*MH_RYCR)
#define REG_RCNR                        (*MH_RCNR)
#define REG_RTSR                        (*MH_RTSR)
#define REG_SWCR                        (*MH_SWCR)

U32 RTC_WatchTime(void)
{
    return(REG_SWCR);
}

void RTC_WatchClear(void)
{
    REG_SWCR = 0;
}

void RTC_WatchStart(void)
{
    REG_RTSR |= RTSR_SWCE;
}

void RTC_WatchStop(void)
{
    REG_RTSR &=~ RTSR_SWCE;
}

U32 RTC_TimeGet(void)
{
    return(REG_RDCR);
}

void RTC_TimeSet(RTC_Time_t tTime)
{
    REG_RDCR = tTime.m_dwTime;
}

U32 RTC_DateGet(void)
{
    return(REG_RYCR);
}

void RTC_DateSet(RTC_Date_t tDate)
{
    REG_RYCR = tDate.m_dwDate;
}

void RTC_ShowWatch(RTC_Watch_t tWatchTime)
{
    DBG_TraceDec(NULL, tWatchTime.m_bTime.m_bHours);
    DBG_TraceString(":");
    DBG_TraceDec(NULL, tWatchTime.m_bTime.m_bMinutes);
    DBG_TraceString(":");
    DBG_TraceDec(NULL, tWatchTime.m_bTime.m_bSeconds);
    DBG_TraceString(":");
    DBG_TraceDec(NULL, tWatchTime.m_bTime.m_bHundreths);
}

void RTC_ShowTime(RTC_Time_t tTime)
{
    DBG_TraceDec(NULL, tTime.m_bTime.m_bHour);
    DBG_TraceString(":");
    DBG_TraceDec(NULL, tTime.m_bTime.m_bMinute);
    DBG_TraceString(":");
    DBG_TraceDec(NULL, tTime.m_bTime.m_bSecond);
}

void RTC_ShowDate(RTC_Date_t tDate)
{
    DBG_TraceDec(NULL, tDate.m_bDate.m_bYear);
    DBG_TraceString("-");
    DBG_TraceDec(NULL, tDate.m_bDate.m_bMonth);
    DBG_TraceString("-");
    DBG_TraceDec(NULL, tDate.m_bDate.m_bDay);
}

void RTC_Initial(U32 dwYear, U32 dwMonth, U32 dwDay, U32 dwHour, U32 dwMinute, U32 dwSecond)
{
    RTC_Time_t time;
    RTC_Date_t date;

    date.m_bDate.m_bYear   = dwYear;
    date.m_bDate.m_bMonth  = dwMonth;
    date.m_bDate.m_bDay    = dwDay;

    time.m_bTime.m_bHour   = dwHour;
    time.m_bTime.m_bMinute = dwMinute;
    time.m_bTime.m_bSecond = dwSecond;

    REG_RYCR = date.m_dwDate;
    REG_RDCR = time.m_dwTime;
}

#endif

