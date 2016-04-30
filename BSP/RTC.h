#define INCLUDE_MODULE_RTC

typedef union{
    struct{
        U32 m_bSecond:                  6;
        U32 m_bMinute:                  6;
        U32 m_bHour:                    5;
        U32 m_bDayOfWeek:               3;
        U32 m_bWeekOfMonth:             3;
        U32 m_bReserve:                 9;
    }m_bTime;
    U32 m_dwTime;
}RTC_Time_t;

typedef union{
    struct{
        U32 m_bDay:                     5;
        U32 m_bMonth:                   4;
        U32 m_bYear:                    12;
        U32 m_bReserve:                 11;
    }m_bDate;
    U32 m_dwDate;
}RTC_Date_t;

typedef union{
    struct{
        U32 m_bHundreths:               7;
        U32 m_bSeconds:                 6;
        U32 m_bMinutes:                 6;
        U32 m_bHours:                   5;
        U32 m_bReserve:                 8;
    }m_bTime;
    U32 m_dwTime;
}RTC_Watch_t;

U32  RTC_WatchTime(void);
void RTC_WatchClear(void);
void RTC_WatchStart(void);
void RTC_WatchStop(void);

U32  RTC_TimeGet(void);
void RTC_TimeSet(RTC_Time_t tTime);

U32  RTC_DateGet(void);
void RTC_DateSet(RTC_Date_t tDate);

void RTC_ShowWatch(RTC_Watch_t tWatchTime);
void RTC_ShowTime(RTC_Time_t tTime);
void RTC_ShowDate(RTC_Date_t tDate);

void RTC_Initial(U32 dwYear, U32 dwMonth, U32 dwDay, U32 dwHour, U32 dwMinute, U32 dwSecond);



