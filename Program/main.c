
#include "_Platform.h"

#define REG_PSPR                        (*MH_PSPR)

static void tMemoryDump(void)
{
    U32 addr;

    addr = DBG_GetHexDef("ADDR", 8, SYS_SDRAM_BASE);

    DBG_TraceMem("", addr, 8);
}

static void tJumpToRun(void)
{
    U32 addr;

    addr = DBG_GetHexDef("Where to go?", 8, BUFFER_SHARED_UNION_BASE);
    msSleep(1000);
    JumpToRun(addr);
}

static void tFileDownload(void)
{
#define FILE_DL_BASE                    BUFFER_SHARED_UNION_BASE
#define FILE_DL_SIZE                    BUFFER_SHARED_UNION_SIZE

    int err;
    U32 s;

    if((err = XMdm_Receive((U8*)FILE_DL_BASE, FILE_DL_SIZE, &s)) == ERR_CODE_DONE)
    {
        DBG_TraceHex("\r\nDone!", s);
    }
    else
    {
        ErrCodeDisplay(err);
    }

    DBG_TraceMem("Content", FILE_DL_BASE, 16);

#undef FILE_DL_BASE
#undef FILE_DL_SIZE
}

#ifdef INCLUDE_MODULE_UPDATE

typedef struct
{
    U32 m_dwBlockID;
    U32 m_dwBlockNumber;
    U32 m_dwRAMAddress;
}ImageConfig_T;

static const ImageConfig_T UPD_tConfig[] = {
    // UPD_IMAGE_ID_MOBM
    {UPD_STORE_POS_BLOCK_ID_MOBM,     UPD_STORE_BLOCK_NUMBER_MOBM,     UPD_STORE_RAM_ADDRESS_MOBM},
    // UPD_IMAGE_ID_EBOOT
    {UPD_STORE_POS_BLOCK_ID_EBOOT,    UPD_STORE_BLOCK_NUMBER_EBOOT,    UPD_STORE_RAM_ADDRESS_EBOOT},
    // UPD_IMAGE_ID_IPL
    {UPD_STORE_POS_BLOCK_ID_IPL,      UPD_STORE_BLOCK_NUMBER_IPL,      UPD_STORE_RAM_ADDRESS_IPL},
    // UPD_IMAGE_ID_HWTESTER
    {UPD_STORE_POS_BLOCK_ID_HWTESTER, UPD_STORE_BLOCK_NUMBER_HWTESTER, UPD_STORE_RAM_ADDRESS_HWTESTER},
};
#define UPD_IMAGE_ID_NUMBER             (sizeof(UPD_tConfig)/sizeof(ImageConfig_T))

static int GetImageID(void)
{
    const MENU_REC image[] = {
        {'m', "MOBM",   NULL},
        {'e', "EBoot",  NULL},
        {'i', "IPL",    NULL},
        {'t', "Test",   NULL},
        {'\0'}
    };

    return(MenuFunction("?", image));
}

static void tUpdate(void)
{
#define IMAGE_ADDR                      BUFFER_SHARED_UNION_BASE
#define IMAGE_SIZE                      BUFFER_SHARED_UNION_SIZE

    U32 s;
    int i, err;

    i = GetImageID();
    if(i < 0)
    {
        return;
    }

    if((err = XMdm_Receive((U8*)IMAGE_ADDR, IMAGE_SIZE, &s)) != ERR_CODE_DONE)
    {
        ErrCodeDisplay(err);
        return;
    }

    err = UPD_UpdateImage(UPD_tConfig[i].m_dwBlockID, IMAGE_ADDR, s);

    ErrCodeDisplay(err);

#undef IMAGE_ADDR
#undef IMAGE_SIZE
}

static void tLoad(void)
{
    int i, err;

    i = GetImageID();
    if(i < 0)
    {
        return;
    }

    if(ERR_CODE_SUCCESS != (err = UPD_LoadImage(UPD_tConfig[i].m_dwBlockID, UPD_tConfig[i].m_dwRAMAddress, (UPD_tConfig[i].m_dwBlockNumber) * (NAND_BLOCK_SIZE))))
    {
        ErrCodeDisplay(err);
    }
    else
    {
//        DBG_TraceHex("@", UPD_tConfig[i].m_dwRAMAddress);
        JumpToRun(UPD_tConfig[i].m_dwRAMAddress);
    }
}

static void tUSBInitial(void)
{
#ifdef INCLUDE_MODULE_UDC
    UDC_Initial();
#endif
#ifdef INCLUDE_MODULE_U2D
    int i;
    const MENU_REC option[] = {
        {'d', "Disk",    NULL},
        {'c', "Sync",    NULL},
        {'s', "Serial",  NULL},
        {'p', "Complex", NULL},
        {'\0'}
    };
    F_USBDeviceInitial_t fInit[] = {
        USB_DiskInitial,
        USB_MSSyncInitial,
        USB_SerialInitial,
        USB_CompositeInitial,
    };

    U2D_Disconnect();

    i = MenuFunction("Select a function", option);
    if(i != MENU_SEL_EXIT) fInit[i]();

#endif

    INT_Initial();
}

#endif //INCLUDE_MODULE_UPDATE

void tSDDectect(void)
{
    SetEvent(MAIN_EVENT_MMCSD_INSERT);

#if 0
    SD_Initial();
    if(ERR_CODE_NONE != SD_OnCardInsert()) return;

    {
        U32 i, n;

        i = DBG_GetDec("BID", 3);
        n = DBG_GetDec("NUM", 3);

        for(;i< n;i++)
        {
            MemSet((PU8)BUFFER_SHARED_UNION_BASE, (U8)(-1), MMCSD_BLOCK_SIZE + 16);
            SD_BlockRead1(i, (PU8)BUFFER_SHARED_UNION_BASE, MMCSD_BLOCK_SIZE);
            DBG_TraceMem("DAT", BUFFER_SHARED_UNION_BASE, 8);
        }
    }
#endif
}

static void tTest(void)
{
    RTC_Time_t time;
    RTC_Date_t date;

    RTC_Initial(2009, 12, 13, 16, 10, 59);

    while(!DBG_GotEvent)
    {
        time.m_dwTime = RTC_TimeGet();
        date.m_dwDate = RTC_DateGet();

        DBG_TraceString("\r");
        RTC_ShowDate(date);
        DBG_TraceString(" ");
        RTC_ShowTime(time);
    }

#if 0
    RTC_WatchClear();
    RTC_WatchStart();

    while(!DBG_GotEvent)
    {
        RTC_Watch_t dt;

        DBG_TraceString("\r");
        dt.m_dwTime = RTC_WatchTime();
        RTC_WatchShow(dt);
    }
    RTC_WatchStop();
#endif
#if 0
    DBG_TraceHex("BV", PMIC_GetBatteryVoltage());
#endif
#if 0
    RTC_DT_t tmp;
    int      i;

    SD_Initial();
    if(ERR_CODE_NONE != SD_OnCardInsert()) return;

    RTC_GetDateTime(&tmp);
    RTC_ShowDT(&tmp);

    for(i=0;i<5000; i++)
    {
        SD_BlockRead1(6, (PU8)BUFFER_SHARED_UNION_BASE, MMCSD_BLOCK_SIZE);
    }

    RTC_GetDateTime(&tmp);
    RTC_ShowDT(&tmp);
#endif

#if 0
#define GPIO_REG_GPLR0                  (*MH_GPLR0)
#define GPIO_REG_GPLR1                  (*MH_GPLR1)
#define GPIO_REG_GPLR2                  (*MH_GPLR2)
#define GPIO_REG_GPLR3                  (*MH_GPLR3)

    DBG_TraceStrLine("");

    while(!DBG_GotEvent)
    {
        DBG_TraceString("\r");
        DBG_TraceHex(NULL, GPIO_REG_GPLR0);
        DBG_TraceHex(NULL, GPIO_REG_GPLR1);
        DBG_TraceHex(NULL, GPIO_REG_GPLR2);
        DBG_TraceHex(NULL, GPIO_REG_GPLR3);
    }
#endif
#if 0
    U16  blkID, secID, pID;
    int  err;
    PU32 pBuf, pSpr;

    pBuf = (PU32)(BUFFER_SHARED_UNION_BASE);
    pSpr = (PU32)(BUFFER_SHARED_UNION_BASE + NAND_SECTOR_SIZE);

    for(blkID = 1;blkID<NAND_BLOCK_NUMBER_IN_TOTAL;blkID++)
    {
        pID = BBM_QueryPhysicalBlockID((U32)blkID);

        for(secID = 0;secID < NAND_SECTOR_NUMBER_PER_BLOCK;secID++)
        {
            DBG_TraceString("\r\n");
            DBG_PutChar('['); DBG_TraceHex(NULL, blkID);DBG_PutChar(']');
            DBG_PutChar('['); DBG_TraceHex(NULL, secID);DBG_PutChar(']');

            err = Nand_ReadSector((U32)pID, (U32)secID, pBuf, pSpr);

            DBG_TraceHex(NULL, MemSum((PU8)pBuf, NAND_SECTOR_SIZE, 0));
            DBG_TraceHex(NULL, MemSum((PU8)pSpr, (NAND_SPAREAREA_SIZE - NAND_HW_ECC_RESULT_SIZE), 0));

            if(err != ERR_CODE_NONE)
            {
                DBG_TraceHex(NULL, err);DBG_PutChar('*');
            }
        }
    }
#endif
}

#ifdef INCLUDE_MODULE_TOUCH
static void tTouchPolling(void)
{
    U16 xMin, xMax, yMin, yMax;
    U16 x,y;
    U32 counter, secx;
    RTC_Watch_t time;

    PMIC_SetModeAutoSample();
    PMIC_INTDisable((PMIC_INT_PEN_DOWN | PMIC_INT_TSI_READY));

    counter = 0;
    xMin = yMin = 0xFFFF;
    xMax = yMax = 0;

    DBG_TraceStrLine("Begin\r\n\r\n");

    RTC_WatchClear();
    RTC_WatchStart();

    while(!DBG_GotEvent)
    {
        PMIC_ReadXY(&x, &y);
        DBG_TraceString("\r[");  DBG_TraceHex(NULL, x); DBG_TraceString("][");  DBG_TraceHex(NULL, y); DBG_TraceString("]");

#define X_VALUE_ON_PEN_UP 0x3E0

        if(x < X_VALUE_ON_PEN_UP)
        {
            if(x > xMax) xMax = x;
            if(x < xMin) xMin = x;
            if(y > yMax) yMax = y;
            if(y < yMin) yMin = y;
        }

        DBG_TraceString("\r[");
        DBG_TraceHex(NULL, x); DBG_TraceString("][");
        DBG_TraceHex(NULL, y); DBG_TraceString("][");
        DBG_TraceHex(NULL, xMin); DBG_TraceString("][");
        DBG_TraceHex(NULL, xMax); DBG_TraceString("][");
        DBG_TraceHex(NULL, yMin); DBG_TraceString("][");
        DBG_TraceHex(NULL, yMax); DBG_TraceString("][");
        DBG_TraceHex(NULL, counter++);
        DBG_TraceString("]");
    }
    RTC_WatchStop();
    DBG_GET_BYTE;

    time.m_dwTime = RTC_WatchTime();
    secx = time.m_bTime.m_bSeconds * 100 + time.m_bTime.m_bHundreths;
    if(secx != 0) DBG_TraceDec("SampleRate", counter * 100/secx);

    PMIC_SetModePenDownDetect();
    PMIC_INTEnable(PMIC_INT_PEN_DOWN);
}
#endif

static void tKITLEnable(void)
{
    int err;

    REG_PSPR |= PSPR_FLAG_USB_KITL;

    if(ERR_CODE_SUCCESS != (err = UPD_LoadImage(UPD_tConfig[2].m_dwBlockID, UPD_tConfig[2].m_dwRAMAddress, (UPD_tConfig[2].m_dwBlockNumber) * (NAND_BLOCK_SIZE))))
    {
        ErrCodeDisplay(err);
    }
    else
    {
        JumpToRun(UPD_tConfig[2].m_dwRAMAddress);
    }
}

#include "PowerManager.c"
#include "Modem.c"

void Main(void)
{
    const MENU_REC menu[] = {
        {'t', "test",           tTest},

//        {'m', "MemDump",        tMemoryDump},
        {'d', "xModem",         tFileDownload},
        {'J', "Jump",           tJumpToRun},
#ifdef INCLUDE_MODULE_UPDATE
        {'U', "Update",         tUpdate},
        {'L', "Load",           tLoad},
#endif //INCLUDE_MODULE_UPDATE

        {'s', "SD Dectect",     tSDDectect},
        {'u', "USB Initial",    tUSBInitial},

        {'f', "File Sys",       FILE_Test},

        {'k', "KITL EN",        tKITLEnable},

        {'p', "Power Mode",     TestPWRMode},
        {'m', "Modem",          TestModem},
#ifdef INCLUDE_MODULE_TOUCH
        {'T', "Touch",          tTouchPolling},
#endif
        {'\0'}
    };

    MenuFunction("Main Menu", menu);
}

