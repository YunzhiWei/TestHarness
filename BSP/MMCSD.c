/*

    To do:
    1. Check return value and deal with any Exception & Error
    2. SDHC(>=4G) support
    3. Test transfer speed

    Bug:
    1. SD initialize failed when using the SD_19_5MHz clock(SD_9_75MHz is OK) but MMC card is OK.
    2. 4bit mode is not faster than 1bit mode

    Caution:
    1. Writing REG_CMDAT will lead to MMC/SD read/write. FIFO full will leads to clock stop.

 v-leison 2007-12-12
*/
#include "_Platform.h"

#ifdef INCLUDE_MODULE_MMCSD

#define ENABLE_4BIT_MODE

#ifdef ENABLE_4BIT_MODE
#define DATA_BUS_MODE                   SD_CMDAT_4DAT
#else
#define DATA_BUS_MODE                   0
#endif

typedef struct {
    volatile U32 r_STRPCL;              // [00]
    volatile U32 r_STAT;                // [04]
    volatile U32 r_CLKRT;               // [08]
    volatile U32 r_SPI;                 // [0c]
    volatile U32 r_CMDAT;               // [10]
    volatile U32 r_RESTO;               // [14]
    volatile U32 r_RDTO;                // [18]
    volatile U32 r_BLKLEN;              // [1c]
    volatile U32 r_NUMBLK;              // [20]
    volatile U32 r_PRTBUF;              // [24]
    volatile U32 r_IMASK;               // [28]
    volatile U32 r_IREG;                // [2c]
    volatile U32 r_CMD;                 // [30]
    volatile U32 r_ARGH;                // [34]
    volatile U32 r_ARGL;                // [38]
    volatile U32 r_RES;                 // [3c]
    volatile U32 r_RXFIFO;              // [40]
    volatile U32 r_TXFIFO;              // [44]
    volatile U32 r_RDWAIT;              // [48]
    volatile U32 r_BLKSREM;             // [4C]
}MMCSD_REGs_t;

static MMCSD_REGs_t *g_MMCSD[] = {
    (MMCSD_REGs_t *)MH_MMC1_BASE,
    (MMCSD_REGs_t *)MH_MMC2_BASE,
    (MMCSD_REGs_t *)MH_MMC3_BASE
};

#define REG_STRCPL      (g_MMCSD[MMC_CONTROLLER_ID]->r_STRPCL)
#define REG_STAT        (g_MMCSD[MMC_CONTROLLER_ID]->r_STAT)
#define REG_CLKRT       (g_MMCSD[MMC_CONTROLLER_ID]->r_CLKRT)
#define REG_SPI         (g_MMCSD[MMC_CONTROLLER_ID]->r_SPI)
#define REG_CMDAT       (g_MMCSD[MMC_CONTROLLER_ID]->r_CMDAT)
#define REG_RESTO       (g_MMCSD[MMC_CONTROLLER_ID]->r_RESTO)
#define REG_RDTO        (g_MMCSD[MMC_CONTROLLER_ID]->r_RDTO)
#define REG_BLKLEN      (g_MMCSD[MMC_CONTROLLER_ID]->r_BLKLEN)
#define REG_NUMBLK      (g_MMCSD[MMC_CONTROLLER_ID]->r_NUMBLK)
#define REG_PRTBUF      (g_MMCSD[MMC_CONTROLLER_ID]->r_PRTBUF)
#define REG_IMASK       (g_MMCSD[MMC_CONTROLLER_ID]->r_IMASK)
#define REG_IREG        (g_MMCSD[MMC_CONTROLLER_ID]->r_IREG)
#define REG_CMD         (g_MMCSD[MMC_CONTROLLER_ID]->r_CMD)
#define REG_ARGH        (g_MMCSD[MMC_CONTROLLER_ID]->r_ARGH)
#define REG_ARGL        (g_MMCSD[MMC_CONTROLLER_ID]->r_ARGL)
#define REG_RES         (g_MMCSD[MMC_CONTROLLER_ID]->r_RES)
#define REG_RXFIFO      (g_MMCSD[MMC_CONTROLLER_ID]->r_RXFIFO)
#define REG_TXFIFO      (g_MMCSD[MMC_CONTROLLER_ID]->r_TXFIFO)
#define REG_RDWAIT      (g_MMCSD[MMC_CONTROLLER_ID]->r_RDWAIT)
#define REG_BLKSREM     (g_MMCSD[MMC_CONTROLLER_ID]->r_BLKSREM)

#define SD_RESPONSE_ENTRY_NUMBER    8
#define SD_RESPONSE_ENTRY_SIZE      2
#define SD_FIFO_ENTRY_NUMBER        32
#define SD_FIFO_ENTRY_SIZE          1

/*
    MMC/SD spec
*/
// OCR bit defination
#define CAPACITY_STATUS_ST_SD       0
#define CAPACITY_STATUS_SDHC_SD     1
#define OCR_CARD_CAPACITY_STATUS(n) ((n&1)<<30)
#define OCR_CARD_POWER_UP_READY     (1u<<31)    //Bit 31 - Card power up status bit, this status bit is set if the card power up procedure has been finished.

#define OCR_35_36_V   (1u<<23)
#define OCR_34_35_V   (1u<<22)
#define OCR_33_34_V   (1u<<21)
#define OCR_32_33_V   (1u<<20)
#define OCR_31_32_V   (1u<<19)
#define OCR_30_31_V   (1u<<18)
#define OCR_29_30_V   (1u<<17)
#define OCR_28_29_V   (1u<<16)
#define OCR_27_28_V   (1u<<15)

//the argument will be used by CMD1 or ACMD41 to fetch the OCR register
#define OCR_ARGUMENT    (OCR_CARD_CAPACITY_STATUS(CAPACITY_STATUS_ST_SD) |\
            OCR_27_28_V |\
            OCR_28_29_V |\
            OCR_29_30_V |\
            OCR_30_31_V |\
            OCR_31_32_V |\
            OCR_32_33_V |\
            OCR_33_34_V |\
            OCR_34_35_V |\
            OCR_35_36_V)    //it should be 0x00FF8000

#define RES_TIMEOUT(n)  (((n) & 0x7F) )
#define READ_TIMEOUT(n) (((n) & 0xFFFF) )

//Card type:SD or MMC. Don't support the SDHC and SDIO card now.
static SD_CMD g_EraseCmdSerial[2];

void DumpSDReg()
{
    DBG_TraceStrLine("*************Dump SD Reg BEGIN****************");
    DBG_TraceHex("SD_strpcl",   REG_STRCPL);
    DBG_TraceHex("SD_stat",     REG_STAT);
    DBG_TraceHex("SD_clkrt",    REG_CLKRT);
    DBG_TraceHex("SD_spi",      REG_SPI);
    DBG_TraceHex("SD_cmdat",    REG_CMDAT);
    DBG_TraceHex("SD_resto",    REG_RESTO);
    DBG_TraceHex("SD_rdto",     REG_RDTO);
    DBG_TraceHex("SD_blklen",   REG_BLKLEN);
    DBG_TraceHex("SD_numblk",   REG_NUMBLK);
    DBG_TraceHex("SD_prtbuf",   REG_PRTBUF );
    DBG_TraceHex("SD_i_mask",   REG_IMASK);
    DBG_TraceHex("SD_i_reg",    REG_IREG);
    DBG_TraceHex("SD_cmd",      REG_CMD);
    DBG_TraceHex("SD_argh",     REG_ARGH);
    DBG_TraceHex("SD_argl",     REG_ARGL);
    DBG_TraceHex("SD_res",      REG_RES);
    DBG_TraceHex("SD_rxfifo",   REG_RXFIFO);
    DBG_TraceHex("SD_txfifo",   REG_TXFIFO);
    DBG_TraceHex("SD_rdwait",   REG_RDWAIT );
    DBG_TraceHex("SD_blks_rem", REG_BLKSREM);
    DBG_TraceStrLine("*************Dump SD Reg END****************");
}

static void SD_SetBusRate(SD_CLOCK_SPEED rate)
{
    if(REG_STAT &SD_STAT_CLOCK_ON)
    {
        // Request bus clock stop
        REG_STRCPL = SD_STRPCL_STOP_CLOCK;
    }

    // Wait until clock actually stops
    while((REG_STAT & SD_STAT_CLOCK_ON))
        ;

    REG_CLKRT= CLKRT_CLKRATE(rate);

    REG_STRCPL = SD_STRPCL_START_CLOCK;

    while(!(REG_STAT &SD_STAT_CLOCK_ON)){;}

    return;
}

static void SD_GetResponse(U16* pResponse)
{
    U32 i;

    for (i=0; i<SD_RESPONSE_ENTRY_NUMBER; i++)
    {
        pResponse[i] = REG_RES;
    }
}

static int ResponseCheckR1(PResponse_R1_bit_t pR1Bit, PResponse_R1_t pR1)
{
    U32 CardStatus;

    if( (pR1Bit->m_bStart!= 0) ||
        (pR1Bit->m_bTransmission!= 0) )
    {
        return(ERR_CODE_MMCSD_RESP_INVALID);
    }

    CardStatus = pR1Bit->m_bCardStatusH;
    CardStatus <<= 16;
    CardStatus|= pR1Bit->m_bCardStatusM;
    CardStatus <<= 8;
    CardStatus |= pR1Bit->m_bCardStatusL;

    pR1->m_dwCardStatus = CardStatus;
    pR1->m_dwCommandIndex = pR1Bit->m_bCommandIndex;

    return(ERR_CODE_NONE);
}

static int ResponseCheckR2(PResponse_R2_bit_t pR2Bit, PResponse_R2_t pR2)
{
    U32 MID,OID,PRV,PSN,MDT;
    U32 PNM[2];

    if( (pR2Bit->m_bStart!= 0) ||
        (pR2Bit->m_bTransmission!= 0) )
    {
        return(ERR_CODE_MMCSD_RESP_INVALID);
    }

    MID = pR2Bit->m_bCID.m_bMID;
    OID = (pR2Bit->m_bCID.m_bOIDH <<8) |pR2Bit->m_bCID.m_bOIDL;
    PNM[0] = (pR2Bit->m_bCID.m_bPNMH<<24) |
            (pR2Bit->m_bCID.m_bPNMM<<8) |
            LOWORD(pR2Bit->m_bCID.m_bPNML) ;

    PNM[1] = HIWORD(pR2Bit->m_bCID.m_bPNML) ;

    PRV = pR2Bit->m_bCID.m_bPRV;
    PSN = (pR2Bit->m_bCID.m_bPSNH<<24) |
            (pR2Bit->m_bCID.m_bPSNM<<8)|
            pR2Bit->m_bCID.m_bPSNL ;

    MDT = (pR2Bit->m_bCID.m_bMDTH<<8) | pR2Bit->m_bCID.m_bMDTL;
    MDT &=0xfff;

    return(ERR_CODE_NONE);
}

static int ResponseCheckR2CSD(PCSD_bit_t pR2Bit,PCSD_t pCSD)
{
    U32 dwTotal;

    // ???? Format check!!!!
    pCSD->m_dwCSize = (pR2Bit->m_bCSizeH<<10) |pR2Bit->m_bCSizeL;
    pCSD->m_dwCSizeMult = pR2Bit->m_bCSzieMult;
    pCSD->m_dwTranSpeed = pR2Bit->m_bTRANSPEED;
    pCSD->m_dwReadBlockLength = pR2Bit->m_bReadBLLength;
    pCSD->m_dwCCC = (pR2Bit->m_bCCCH<<4)|pR2Bit->m_bCCCL;

    dwTotal=(2<<(pCSD->m_dwCSizeMult+1))*(pCSD->m_dwCSize+1)*(2<<(pCSD->m_dwReadBlockLength-1));

    DBG_TraceStrLine("Size: ");
    DBG_TraceDec(NULL, dwTotal);
    DBG_TraceString("Bytes [");

    DBG_TraceDec(NULL, dwTotal/(1024 * 1024));
    DBG_TraceString("MB]");

    return(ERR_CODE_NONE);
}

static int ResponseCheckR3(PResponse_R3_bit_t pR3Bit, PResponse_R3_t pR3)
{
    U32 ocr;

    ocr = pR3Bit->m_bOCRH;
    ocr <<= 16;
    ocr |= pR3Bit->m_bOCRM;
    ocr <<= 8;
    ocr |= pR3Bit->m_bOCRL;

    pR3->m_dwOCR = ocr;

    if( (pR3Bit->m_bReserved_3F != 0x3F) ||
        (pR3Bit->m_bStart!= 0) ||
        (pR3Bit->m_bTransmission!= 0) )
    {
        return(ERR_CODE_MMCSD_RESP_INVALID);
    }

    if(pR3->m_dwOCR & OCR_CARD_POWER_UP_READY)
        return(ERR_CODE_MMCSD_POWERUP_DONE);

    return(ERR_CODE_MMCSD_POWERUP_FAIL);
}

static int ResponseCheckR6(PResponse_R6_bit_t pR6Bit, PResponse_R6_t pR6)
{
    U32 Argument;

    if( (pR6Bit->m_bStart!= 0) ||
        (pR6Bit->m_bTransmission!= 0) )
    {
        return(ERR_CODE_MMCSD_RESP_INVALID);
    }

    Argument = pR6Bit->m_bArgumentH;
    Argument <<= 16;
    Argument|= pR6Bit->m_bArgumentM;
    Argument <<= 8;
    Argument |= pR6Bit->m_bArgumentL;

    pR6->m_dwRCA= HIWORD(Argument);
    pR6->m_dwCommandIndex = pR6Bit->m_bCommandIndex;

    return(ERR_CODE_NONE);
}

static int SD_WaitCMDEndResponse(U32 dwCmd)
{
    while(!(REG_STAT&SD_STAT_END_CMD))
    {
//        DBG_PutChar('\r'); DBG_TraceHex(NULL, REG_STAT);
    }

    if (REG_STAT & SD_STAT_RESP_CRC)
    {
        return ERR_CODE_MMCSD_RESP_CRC;
    }

    if (REG_STAT & SD_STAT_RESP_TIMEOUT)
    {
        return ERR_CODE_MMCSD_CMD_TIMEOUT;
    }

    return ERR_CODE_NONE;
}

static int SD_SendCommand(U32 dwCmd, U16 wArgumentH, U16 wArgumentL, U32 dwCmdOption, SD_Response_Type_t tResType)
{
    int returnCode;

    static U32 MMC_CMDAT_RES_TYPE[] =
        // Please refere Developer Manual Vol II Table 5-11
        // Refer to SD_Response_Type_t
        {
        0,  // When no Response is needed
        1,  // When Response Tpye is 1
        2,  // When Response Type is 2
        3,  // When Response Type is 3
        0,  // Response Type 4 is reserved
        0,  // Response Type 5 is reserved
        1   // When Response Type is 6
        };

    if (dwCmdOption & SD_CMDAT_DATA)
    {
            dwCmdOption &= ~SD_CMDAT_BUSY;
        REG_NUMBLK = MMCSD_BLOCK_NUMBER;
        REG_BLKLEN = MMCSD_BLOCK_SIZE;
     }

    //As to CMD7 and CMD38, their response is with a busy signal(R1b).
    if(dwCmd==SD_CMD7 ||dwCmd==SD_CMD38)
        dwCmdOption |= SD_CMDAT_BUSY;

    dwCmdOption &=~SD_CMDAT_DMA;
    dwCmdOption = dwCmdOption | MMC_CMDAT_RES_TYPE[tResType];

    REG_CMD   = dwCmd;
    REG_ARGH  = wArgumentH;
    REG_ARGL  = wArgumentL;
    REG_CMDAT = dwCmdOption;

    //Check whether the response to this command has some problem
    returnCode=SD_WaitCMDEndResponse(dwCmd);

    return returnCode;
}

static void SD_GetCardStatus(U32 rca,Response_R1_t  respR1)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER];

    SD_SendCommand(SD_CMD13, rca,0xffff, 0,SD_RESPONSE_TYPE_R1);
    SD_GetResponse(response);

    if((ResponseCheckR1((PResponse_R1_bit_t)response, &respR1)) != ERR_CODE_NONE)
    {
        DBG_TraceStrLine("Check R1 response Error!!!");
    }
}

void SD_BlockRead1(U32 dwBlockID, U8 *pBuffer, U32 dwSize)
{
    U32 i;
    volatile PU8 pRX;
    PU8 pDt;

    pDt = (PU8)(pBuffer);
    pRX = (volatile PU8)(&REG_RXFIFO);

    dwBlockID *= MMCSD_BLOCK_SIZE;
    SD_SendCommand(SD_CMD17, HIWORD(dwBlockID),LOWORD(dwBlockID), SD_CMDAT_DATA | DATA_BUS_MODE, SD_RESPONSE_TYPE_R1);

    while(dwSize >= SD_FIFO_ENTRY_NUMBER)
    {
        while(!(REG_IREG & SD_REG_RXFIFO_RD_REQ))
        {
            if(DBG_GotEvent)
            {
                DBG_GET_BYTE;
                DBG_TraceHex("REG_IREG=",REG_IREG);
            }
        }

        for(i=0;i<(SD_FIFO_ENTRY_NUMBER);i++)
            *pDt++ = *pRX;

        dwSize -= SD_FIFO_ENTRY_NUMBER;
    }
}

void SD_BlockReadN(U32 dwBlockID, U8 *pBuffer, U32 dwSize)
{
    for(;dwSize > MMCSD_BLOCK_SIZE;dwSize -= MMCSD_BLOCK_SIZE, pBuffer += MMCSD_BLOCK_SIZE)
    {
        SD_BlockRead1(dwBlockID++, pBuffer, MMCSD_BLOCK_SIZE);
    }
    if(dwSize > 0)  SD_BlockRead1(dwBlockID, pBuffer, MMCSD_BLOCK_SIZE);
}

void SD_BlockWrite(U32 dwBlockID, U8 *pBuffer, U32 dwSize)
{

    U32 i;
    //we access the TX FIFO by BYTE.
    volatile BYTE *pTX =  (volatile BYTE *)(&REG_TXFIFO);

    if(dwSize > MMCSD_BLOCK_SIZE)
        dwSize = MMCSD_BLOCK_SIZE;

    dwBlockID *= MMCSD_BLOCK_SIZE;
    SD_SendCommand(SD_CMD24,HIWORD(dwBlockID),LOWORD(dwBlockID), SD_CMDAT_WRITE | SD_CMDAT_DATA | DATA_BUS_MODE, SD_RESPONSE_TYPE_R1);

    dwSize = MMCSD_BLOCK_SIZE;
    while(dwSize>0)
    {
        while(!(REG_IREG&SD_REG_TXFIFO_WR_REQ))
        {
            //DBG_TraceHex("REG_IREG1=",REG_IREG);
        }

        for(i=0;i<SD_FIFO_ENTRY_NUMBER;i++)
            *pTX = (U8)*pBuffer++;

        dwSize -= SD_FIFO_ENTRY_NUMBER;
    }

}

void SD_BlockErase(U32 dwStartID, U32 dwEndID)
{
    dwStartID *= MMCSD_BLOCK_SIZE;
    dwEndID *= MMCSD_BLOCK_SIZE;

    SD_SendCommand(g_EraseCmdSerial[0], HIWORD(dwStartID), LOWORD(dwStartID), 0,SD_RESPONSE_TYPE_R1);
    SD_SendCommand(g_EraseCmdSerial[1], HIWORD(dwEndID), LOWORD(dwEndID), 0,SD_RESPONSE_TYPE_R1);

    SD_SendCommand(SD_CMD38, 0xffff,0xffff, 0, SD_RESPONSE_TYPE_R1);
}

static void SD_SetCardToBeIdle(void)
{
    int i;

#define RETRY_TIMES 3

    for (i = 0; i < RETRY_TIMES; i++)
    {
        SD_SendCommand(SD_CMD0, 0xffff,0xffff, SD_CMDAT_INIT ,SD_RESPONSE_TYPE_NONE);
    }
#undef RETRY_TIMES
}

static int SD_GetCSD(U32 dwRCA, CSD_t *pCSD)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];

    SD_SendCommand(SD_CMD9, dwRCA,0xffff,0, SD_RESPONSE_TYPE_R2);
    SD_GetResponse(response);

    return(ResponseCheckR2CSD((PCSD_bit_t)response, pCSD));
}

static U32 SD_GetRCA(void)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];
    Response_R6_t  respR6;

    SD_SendCommand(SD_CMD3, 0xffff,0xffff,0, SD_RESPONSE_TYPE_R6);

    SD_GetResponse(response);
    if((ResponseCheckR6((PResponse_R6_bit_t)response, &respR6)) !=ERR_CODE_NONE)
    {
        DBG_TraceStrLine("Check R6 response Error!!!");
    }

    return(respR6.m_dwRCA);
}

static void MMC_SetRCA(U32 dwRCA)
{
    SD_SendCommand( SD_CMD3, dwRCA, 0xffff,0, SD_RESPONSE_TYPE_R1);
}

static U32 SD_GetCID(void)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];
    Response_R2_t  respR2;

    SD_SendCommand(SD_CMD2, 0xffff,0xffff,0, SD_RESPONSE_TYPE_R2);

    SD_GetResponse(response);
    if(ResponseCheckR2((PResponse_R2_bit_t)response, &respR2) !=ERR_CODE_NONE)
    {
        DBG_TraceStrLine("Check R2 response Error!!!");
    }
    return(respR2.m_CID.m_dwPSN);
}

static int SD_SDCheckPowerReady(Response_R3_t *pR3)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];

    do
    {
        SD_SendCommand(SD_CMD55, 0,0xffff, SD_CMDAT_INIT ,SD_RESPONSE_TYPE_R1);
        SD_SendCommand(APP_ACMD41, HIWORD(OCR_ARGUMENT),LOWORD(OCR_ARGUMENT), SD_CMDAT_INIT ,SD_RESPONSE_TYPE_R3);

        SD_GetResponse(response);
        DBG_PutChar('?');

        if(DBG_GotEvent)
        {
            DBG_GET_BYTE;
            return(ERR_CODE_MMCSD_CMD_TIMEOUT);
        }
    }while (ResponseCheckR3((PResponse_R3_bit_t)response, pR3) != ERR_CODE_MMCSD_POWERUP_DONE);

    return(ERR_CODE_NONE);
}

static void MMC_CheckPowerReady(Response_R3_t *pR3)
{
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];

    do
    {
        SD_SendCommand(SD_CMD1, HIWORD(OCR_ARGUMENT),LOWORD(OCR_ARGUMENT), SD_CMDAT_INIT , SD_RESPONSE_TYPE_R3);
        SD_GetResponse(response);
    }while(ResponseCheckR3((PResponse_R3_bit_t)response, pR3)!=ERR_CODE_MMCSD_POWERUP_DONE);
}

int SD_OnCardInsert(void)
{
    U32 serialNum,i ;
    U16 response[SD_RESPONSE_ENTRY_NUMBER ];
    CSD_t csdInfo;
    U32 cardRCA;
    CARD_TYPE g_CardType=UNKNOW_CARD;
    SD_CLOCK_SPEED speed;

    Response_R3_t  respR3;

    SD_SetBusRate(SD_304KHz);

    SD_SetCardToBeIdle();

    //MMC use CMD1 to get OCR(has done)
    //Send CMD1,with the intended voltage range in the argument
    //MMC will always get the valid voltage value from OCR register
    DBG_TraceStrLine("Type: ");
    if(SD_SendCommand(SD_CMD1, HIWORD(OCR_ARGUMENT),LOWORD(OCR_ARGUMENT), SD_CMDAT_INIT , SD_RESPONSE_TYPE_R3)
        ==ERR_CODE_MMCSD_CMD_TIMEOUT)
    {
        g_CardType = CARD_TYPE_SD;
        g_EraseCmdSerial[0] = SD_CMD32;
        g_EraseCmdSerial[1] = SD_CMD33;
        speed = SD_9_75MHz;
        if(ERR_CODE_NONE == SD_SDCheckPowerReady(&respR3))
        {
            DBG_TraceString(" SD");
        }
        else return(ERR_CODE_MMCSD_CMD_TIMEOUT);
    }
    else
    {
        DBG_TraceString(" MMC");

        g_CardType = CARD_TYPE_MMC;
        g_EraseCmdSerial[0] = SD_CMD35;
        g_EraseCmdSerial[1] = SD_CMD36;
        speed = SD_19_5MHz;
        MMC_CheckPowerReady(&respR3);
    }
    DBG_TraceHex("Card OCR=", respR3.m_dwOCR);

    serialNum = SD_GetCID();

    if ( g_CardType == CARD_TYPE_SD)
    {
        cardRCA = SD_GetRCA();
        DBG_TraceStrLine("Detect SD card now!\r\n");
    }
    else
    {
        MMC_SetRCA(cardRCA = (serialNum >> 8) + 1);
        DBG_TraceStrLine("Detect MMC card now!\r\n");
    }
    DBG_TraceHex("Relative Card Address =", cardRCA);

    if(ERR_CODE_NONE == SD_GetCSD(cardRCA, &csdInfo))
    {
        DBG_TraceHex("Card Speed =", csdInfo.m_dwTranSpeed);
    }
    else
    {
        DBG_TraceStrLine("GetCSD Error!");
    }

    SD_SendCommand(SD_CMD7,  cardRCA, 0xffff, 0, SD_RESPONSE_TYPE_R1);
    SD_SendCommand(SD_CMD16, HIWORD(MMCSD_BLOCK_SIZE), LOWORD(MMCSD_BLOCK_SIZE),0,SD_RESPONSE_TYPE_R1);

#ifdef ENABLE_4BIT_MODE
    SD_SendCommand(SD_CMD55, cardRCA, 0xffff, 0, SD_RESPONSE_TYPE_R1);
    SD_SendCommand(SD_ACMD6, 0, 0x2,    0, SD_RESPONSE_TYPE_R1);

    msSleep(1);                         // wait at least 8 clock before any other operations
#endif

    SD_SetBusRate(speed);
    DBG_TraceStrLine("Done!");

    return(ERR_CODE_NONE);
}

void SD_Initial(void)
{
    REG_RDTO = READ_TIMEOUT(0xFFFF);
    REG_RESTO= RES_TIMEOUT(0x7F);

    return;
}

#endif //INCLUDE_MODULE_MMCSD

