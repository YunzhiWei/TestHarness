
/*
    Bugs

    1. For GPLUS panel, some time we read the ID as 0x0054, some times 0xFF54
*/

#define PANEL_ID_INVALID                0
#define PANEL_ID_TRUELY_0154            0x0154
#define PANEL_ID_TRUELY_4531            0x4531
#define PANEL_ID_GPLUS_0                0x0054
#define PANEL_ID_GPLUS_F                0xFF54

#define PANEL_SELECT                    0x07

#define ACCESS_REG                      0
#define ACCESS_DATA                     1

#define RW_WRITE                        0
#define RW_READ                         1

#define PANEL_SPI_SEND(accessType,rwType,AD)    ((PANEL_SELECT << 4) | (accessType << 1) | rwType),((AD & 0xFF00) >> 8),(AD & 0xFF)

#define PANEL_REG_SELECT(regAddr)       PANEL_SPI_SEND(ACCESS_REG,  RW_WRITE, regAddr)
#define PANEL_REG_WRITE(regData)        PANEL_SPI_SEND(ACCESS_DATA, RW_WRITE, regData)
#define PANEL_REG_READ(regData)         PANEL_SPI_SEND(ACCESS_DATA, RW_READ,  regData)

#define PANEL_COMMAND(regAddr,regData,delay)    {PANEL_REG_SELECT(regAddr), PANEL_REG_WRITE(regData), delay},

typedef struct
{
    U8  m_cCommand[3];
    U8  m_cData[3];
    U16 m_nDelay;
}PANEL_COMMAND_t;
#define PANEL_COMMAND_END_FLAG          0xFFFF

#ifdef DISPLAY_RESOLUSION_QVGA_PORTRAIT
#include "Panel_Truely0154.c"
//#include "Panel_Truely4531.c"
//#include "Panel_GenPlus.c"
#endif

static void Panel_SPISendTiming(U8* pData)
{
    SSP_Wait4Idle(SSP_ID_2);
    SSP_SendB2B(SSP_ID_2, pData, 3);
    SSP_Wait4Idle(SSP_ID_2);

    msSleep(1);                         //must delay 1 ms
}

static U32 Panel_GetID(void)
{
#define CMD_SIZE                        3

    U8 cmd[][CMD_SIZE] = {
        {PANEL_REG_SELECT(0x00)},
        {PANEL_REG_WRITE(0x01)},
        {PANEL_REG_READ(0x00)}
    };
    U8 id[sizeof(cmd)];
    U32 l;

    do
    {
        l = SSP_ReceiveB2B(SSP_ID_2, id, sizeof(id));
    }while(l != 0);

//    DBG_TraceMem("", cmd, 8);

    Panel_SPISendTiming(cmd[0]);
    Panel_SPISendTiming(cmd[1]);
    msSleep(5);
    Panel_SPISendTiming(cmd[2]);
    msSleep(5);
    SSP_Wait4Idle(SSP_ID_2);
    l = SSP_ReceiveB2B(SSP_ID_2, id, sizeof(id));
    SSP_Wait4Idle(SSP_ID_2);

//    DBG_TraceDec("L", l);
//    DBG_TraceMem("", id, 8);

    if((l > sizeof(id)) || (l < 2))
    {
        DBG_TraceDec("Panel_GetID Error!", l);
        return(PANEL_ID_INVALID);
    }

    return((U32)(MAKEWORD(id[l-1], id[l-2])));
}

static U32 Panel_GetCmdAddr(U32 dwID)
{
#define BUG_1_WORKARROUND_MASK 0xFF

    switch(dwID)// & BUG_1_WORKARROUND_MASK)
    {
#ifdef PANEL_CMD_TRUELY_0154_INIT
    case PANEL_ID_TRUELY_0154:
        return((U32)TRUELY0154_Initial);
#endif
#ifdef PANEL_CMD_TRUELY_4531_INIT
    case PANEL_ID_TRUELY_4531:
        return((U32)TRUELY4531_Initial);
#endif
#ifdef PANEL_CMD_GENPLUS_XX54_INIT
    case PANEL_ID_GPLUS_0: // Workarround for Bug 1
    case PANEL_ID_GPLUS_F:
        return((U32)GPLUS_Initial);
#endif
    default:
        DBG_TraceHex("Panel_GetCmdAddr Error!", dwID);
        return(NULL);
    }
}

static void Panel_CmdSerial(U32 dwCmdAddr)
{
    PANEL_COMMAND_t *pCmd;

    if(dwCmdAddr == NULL)
    {
        DBG_TraceStrLine("Panel_CmdSerial Fail");
        return;
    }

    for(pCmd = (PANEL_COMMAND_t *)dwCmdAddr;pCmd->m_nDelay!=PANEL_COMMAND_END_FLAG;pCmd++)
    {
        Panel_SPISendTiming(pCmd->m_cCommand);

        if(pCmd->m_cCommand[2] != 0x22)
        {
            Panel_SPISendTiming(pCmd->m_cData);
        }
        msSleep(pCmd->m_nDelay);
    }
}

void Panel_Initial(void)
{
    Panel_CmdSerial(Panel_GetCmdAddr(Panel_GetID()));
}

