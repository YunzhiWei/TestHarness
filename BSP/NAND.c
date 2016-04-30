#include "_Platform.h"

#ifdef INCLUDE_MODULE_NAND

/*
    Caution

    #1. The NAND controller FIFO entry unit is 8BYTE.
        This means you MUST read/write FIFO N times of 8BYTE.
        If you read X bytes and X is not N times of 8BYTE, you will get unwanted result next time when reading the FIFO.
        So dummy read is needed in this case.
        This ONLY happen when ECC disable.

    #2. ECC needs all data & spare.
        If you enable HW ECC, you must read/write the whole size of sector data and remain size of spare data.

    Bug

    #1. Nand_ReadBlock has bug. It will read out not only the data but also the spare array.
*/

/*
    This module supports ECC enable ONLY!!!
*/

#define NAND_FIFO_ENTRY_SIZE            8

#define CMD_WITH_AUTO_STATUS

#define REG_NDCR                        (*MH_NDCR)
#define REG_NDTR0CS0                    (*MH_NDTR0CS0)
#define REG_NDTR1CS0                    (*MH_NDTR1CS0)
#define REG_NDSR                        (*MH_NDSR)
#define REG_NDPCR                       (*MH_NDPCR)
#define REG_NDBDR0                      (*MH_NDBDR0)
#define REG_NDBDR1                      (*MH_NDBDR1)
#define REG_NDDB                        (*MH_NDDB)
#define REG_NDCB0                       (*MH_NDCB0)
#define REG_NDCB1                       (*MH_NDCB1)
#define REG_NDCB2                       (*MH_NDCB2)

#define DEFAULT_NDCR_VALUE              (NDCR_DWIDTH_C      |\
                                         NDCR_DWIDTH_M      |\
                                         NDCR_PAGE_SZ       |\
                                         NDCR_RD_ID_CNT(4)  |\
                                         NDCR_PG_PER_BLK    |\
                                         NDCR_ND_ARB_EN     |\
                                         NDCR_RDYM          |\
                                         NDCR_CS0_PAGEDM    |\
                                         NDCR_CS1_PAGEDM    |\
                                         NDCR_CS0_CMDDM     |\
                                         NDCR_CS1_CMDDM     |\
                                         NDCR_CS0_BBDM      |\
                                         NDCR_CS1_BBDM      |\
                                         NDCR_DBERRM        |\
                                         NDCR_SBERRM        |\
                                         NDCR_WRDREQM       |\
                                         NDCR_RDDREQM       |\
                                         NDCR_WRCMDREQM     |\
                                         NDCR_SPARE_EN      |\
                                         NDCR_ECC_EN)

// Most safety timing
#ifndef DEFAULT_NDTR0CS0_VALUE
#define DEFAULT_NDTR0CS0_VALUE          NDTR0CS_tCH(7) | NDTR0CS_tCS(7) | NDTR0CS_tWH(7) | NDTR0CS_tWP(7) | NDTR0CS_tRH(7) | NDTR0CS_tRP(7)
#endif
#ifndef DEFAULT_NDTR1CS0_VALUE
#define DEFAULT_NDTR1CS0_VALUE          NDTR1CS_tR(0x1FF0) | NDTR1CS_tWHR(0xF) |NDTR1CS_tAR(0xF)
#endif

/* Nand Command */
#define NAND_CMD_READ_STATUS            0x0070
#define NAND_CMD_READ_ID                0x0090
#define NAND_CMD_READ                   0x3000
#define NAND_CMD_ERASE                  0xD060
#define NAND_CMD_PROGRAM                0x1080
#define NAND_CMD_PROGRAM_CONFIRM        0x0010
#define NAND_CMD_RESET                  0x00FF
#define NAND_LOCK
#define NAND_UNLOCK

inline static int waitFlag(U32 dwNDSRFlag, U32 dwTimeLimit)
{
    while (dwTimeLimit--)
    {
        if((dwNDSRFlag & REG_NDSR) == dwNDSRFlag)
        {
            return(ERR_CODE_NONE);
        }
    }

    DBG_TraceStrLine("waitFlag: Timeout");
    DBG_TraceHex("Flag", dwNDSRFlag);
    DBG_TraceHex("NDSR", REG_NDSR);

    return(ERR_CODE_NAND_TIMEOUT);
}

inline static int Nand_ControllerStart(void)
{
    U32 dummy;

    REG_NDCR |= NDCR_ND_RUN;

    while(REG_NDSR & NDSR_RDDREQ)
    {
        REG_NDSR = NDSR_RDDREQ;
        dummy = REG_NDDB;
        DBG_TraceHex("dummy", dummy);
    }

    while(!(REG_NDSR & NDSR_WRCMDREQ))
    {
        DBG_TraceString("\r S->");
        DBG_TraceHex(NULL, REG_NDSR);
        if(DBG_GotEvent)
        {
            DBG_GET_BYTE;
            return(ERR_CODE_NAND_TIMEOUT);
        }
    }
    REG_NDSR = NDSR_WRCMDREQ;

    return(ERR_CODE_NONE);
}

inline static void Nand_ControllerStop(void)
{
    REG_NDCR &=~ NDCR_ND_RUN;
    REG_NDSR = REG_NDSR;
}

#if 0
Dynamic configure ECC enable and Spare enable will make the preformance worse

static void Nand_ControllerECCEnable(BOOL bEn)
{
    if(bEn)
    {
        REG_NDCR |= (NDCR_SPARE_EN | NDCR_ECC_EN);
    }
    else
    {
        REG_NDCR &=~ NDCR_ECC_EN;
    }
}

static void Nand_ControllerSpareEnable(BOOL bEn)
{
    if(bEn)
    {
        REG_NDCR |= NDCR_SPARE_EN;
    }
    else
    {
        REG_NDCR &=~ (NDCR_ECC_EN | NDCR_SPARE_EN);
    }
}
#endif

void Nand_ControllerInit(void)
{
    REG_NDCR        = 0;

    REG_NDTR0CS0    = DEFAULT_NDTR0CS0_VALUE;
    REG_NDTR1CS0    = DEFAULT_NDTR1CS0_VALUE;

    REG_NDSR        = NDSR_FLAG_ALL;

    REG_NDCR        = DEFAULT_NDCR_VALUE;

    {
        U32 i;
        U32 dummy;

        for(i=0;i<40;i++)
        {
            dummy = REG_NDDB;
        }
    }

//    DBG_TraceStrLine("NAND @ " __DATE__ " " __TIME__);
//    DBG_TraceHex("TR0", REG_NDTR0CS0);
//    DBG_TraceHex("TR1", REG_NDTR1CS0);
}

#if 0
Did not tested!
int Nand_Reset(void)
{
    int err = ERR_CODE_NONE;

    err = Nand_ControllerStart();
    if(err != ERR_CODE_NONE)
    {
        goto Nand_Reset_Return;
    }

    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_RESET) | NDCB0_ADDR_CYC(0) | NAND_CMD_RESET;
    REG_NDCB0 = 0x00;
    REG_NDCB0 = 0x00;

    err = waitFlag(NDSR_CS0_CMDD, 1000000);
    if(err != ERR_CODE_NONE)
    {
        DBG_TraceStrLine("Nand_Reset: NDSR_CS0_CMDD timeout");
        goto Nand_Reset_Return;
    }

Nand_Reset_Return:

    Nand_ControllerStop();
    return (err);
}
#endif

int Nand_GetID(U32 *pdwID)
{
    int err;

    if((err = Nand_ControllerStart()) != ERR_CODE_NONE)
    {
        goto Nand_ReadID_Return;
    }

    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_READ_ID) | NDCB0_ADDR_CYC(1) | NAND_CMD_READ_ID;
    REG_NDCB0 = 0;
    REG_NDCB0 = 0;

    if((err = waitFlag(NDSR_RDDREQ, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_ReadID_Return;
    }
//    REG_NDSR = NDSR_RDDREQ;

    *pdwID = REG_NDDB;

#if 1
    {  // Caution #1
        U32 dummy;

        dummy = REG_NDDB;
//        DBG_TraceHex("dummy", dummy);
    }
#endif

Nand_ReadID_Return:

    Nand_ControllerStop();
    return(err);
}

int Nand_GetStatus(U32 *pdwStatus)
{
    int err;

    if((err = Nand_ControllerStart()) != ERR_CODE_NONE)
    {
        goto Nand_ReadStatus_Return;
    }

    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_READ_STATUS) | NDCB0_ADDR_CYC(0)  | NAND_CMD_READ_STATUS;
    REG_NDCB0 = 0;
    REG_NDCB0 = 0;

    if((err = waitFlag(NDSR_RDDREQ, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_ReadStatus_Return;
    }
//    REG_NDSR = NDSR_RDDREQ;

    *pdwStatus = REG_NDDB;

#if 1
    {  // Caution #1
        U32 dummy;

        dummy = REG_NDDB;
//        DBG_TraceHex("dummy", dummy);
    }
#endif

Nand_ReadStatus_Return:

    Nand_ControllerStop();
    return(err);
}

int Nand_ReadSector(U32 dwPhysicalBlockID, U32 dwSectorID, U32 *pdwData, U32 *pdwSpare)
{
#define ADDRESS_POS_OFFSET              0
#define ADDRESS_POS_SETCTOR             16
#define ADDRESS_POS_BLOCK               22
#define ADDRESS_BLOCK_LEFT_BIT          (32 - ADDRESS_POS_BLOCK)

    int err;
    U32 dSize, sSize, dummy;
    U32 addr[2]; // 5Byte Address Cycles, 2 32bit Address Registers

    if(
        (dwPhysicalBlockID   >= NAND_BLOCK_NUMBER_IN_TOTAL) ||
        (dwSectorID >= NAND_SECTOR_NUMBER_PER_BLOCK) ||
         (pdwData == NULL)
        )
    {   // Because the FIFO entry size is 8, the dwSize must be N times of 8!!!
        return(ERR_CODE_NAND_PARAMETER);
    }

    // Prepare
    sSize = (NAND_SPAREAREA_SIZE - NAND_HW_ECC_RESULT_SIZE) / sizeof(U32);
    dSize = NAND_SECTOR_SIZE / sizeof(U32);

    addr[1] = (dwPhysicalBlockID >> ADDRESS_BLOCK_LEFT_BIT) & NDCB2_ADDR_MASK;
    addr[0] = (dwPhysicalBlockID << ADDRESS_POS_BLOCK) | (dwSectorID << ADDRESS_POS_SETCTOR); // | dwOffset;

    if((err = Nand_ControllerStart()) != ERR_CODE_NONE)
    {
        goto Nand_Read_Return;
    }

    // NAND command
    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_READ) | NDCB0_DBC | NDCB0_ADDR_CYC(NAND_CMD_READ_CYCLE) | NAND_CMD_READ;
    REG_NDCB0 = addr[0];
    REG_NDCB0 = addr[1] | NDCB2_PAGE_COUNT(1);

    if((err = waitFlag(NDSR_RDDREQ, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Read_Return;
    }
    REG_NDSR = NDSR_RDDREQ;

    {
        while(dSize--)
        {
            *pdwData++ = REG_NDDB;
        }
    }
    {
        if(pdwSpare != NULL)
        {
            while(sSize--)
            {
                *pdwSpare++ = REG_NDDB;
            }
        }
        else
        {
            while(sSize--)
            {
                dummy = REG_NDDB;
            }
        }
    }
    {
        if(REG_NDSR & NDSR_DBERR)
        {
            err = ERR_CODE_NAND_DBERR;
            REG_NDSR = NDSR_DBERR;
            goto Nand_Read_Return;
        }
        if(REG_NDSR & NDSR_SBERR)
        {
            err = ERR_CODE_NAND_SBERR;
            REG_NDSR = NDSR_SBERR;
            goto Nand_Read_Return;
        }
    }
Nand_Read_Return:

    Nand_ControllerStop();
    return(err);

#undef ADDRESS_POS_OFFSET
#undef ADDRESS_POS_SETCTOR
#undef ADDRESS_POS_BLOCK
#undef ADDRESS_BLOCK_LEFT_BIT
}

int Nand_WriteSector(U32 dwPhysicalBlockID, U32 dwSectorID, U32 *pdwData, POEM_SectorInfo_t pOEMSecInfo)
{
#define ADDRESS_POS_OFFSET              0
#define ADDRESS_POS_SETCTOR             16
#define ADDRESS_POS_BLOCK               22
#define ADDRESS_BLOCK_LEFT_BIT          (32 - ADDRESS_POS_BLOCK)

    int err;
    U32 dSize, sSize;
    U32 addr[2]; // 5Byte Address Cycles, 2 32bit Address Registers

    if(
        (dwPhysicalBlockID   >= NAND_BLOCK_NUMBER_IN_TOTAL) ||
        (dwSectorID >= NAND_SECTOR_NUMBER_PER_BLOCK) ||
        (pdwData == NULL))
    {
        return(ERR_CODE_NAND_PARAMETER);
    }

    addr[1] = (dwPhysicalBlockID >> ADDRESS_BLOCK_LEFT_BIT) & NDCB2_ADDR_MASK;
    addr[0] = (dwPhysicalBlockID << ADDRESS_POS_BLOCK) | (dwSectorID << ADDRESS_POS_SETCTOR);  // | dwOffset;

    dSize = NAND_SECTOR_SIZE / sizeof(U32);
    sSize = (NAND_SPAREAREA_SIZE - NAND_HW_ECC_RESULT_SIZE)/ sizeof(U32);

    if((err = Nand_ControllerStart()) != ERR_CODE_NONE)
    {
        goto Nand_Write_Return;
    }

#ifdef CMD_WITH_AUTO_STATUS
    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_PROGRAM) | NDCB0_DBC | NDCB0_ADDR_CYC(NAND_CMD_WRITE_CYCLE) | NAND_CMD_PROGRAM | NDCB0_AUTO_RS;
#else
    REG_NDCB0 = NDCB0_CMD_TYPE(CMD_TYPE_PROGRAM) | NDCB0_DBC | NDCB0_ADDR_CYC(NAND_CMD_WRITE_CYCLE) | NAND_CMD_PROGRAM;
#endif

    REG_NDCB0 = addr[0];
    REG_NDCB0 = addr[1] | NDCB2_PAGE_COUNT(1);

    if((err = waitFlag(NDSR_WRDREQ, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Write_Return;
    }

    while(dSize--)
    {
        REG_NDDB = *pdwData++;
    }

    {
        if(pOEMSecInfo != NULL)
        {
            PU32 p32;
            u32  i;

            p32 = (PU32)pOEMSecInfo;
            for(i=0;i<(sizeof(OEM_SectorInfo_t)/sizeof(U32));i++) REG_NDDB = *p32++;
            for(;i<sSize;i++) REG_NDDB = (U32)(-1);
        }
        else
        {
            while(sSize--)
                REG_NDDB = (U32)(-1);
        }
    }
    REG_NDSR = NDSR_WRDREQ;

#ifdef CMD_WITH_AUTO_STATUS
    if((err = waitFlag(NDSR_RDY, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Write_Return;
    }
    REG_NDSR = NDSR_RDY;

    if(REG_NDCB0 & NDCB0_AUTO_RS)
    {
        if(REG_NDSR & NDSR_CS0_BBD)
        {
            err = ERR_CODE_NAND_BADBLOCK;
            REG_NDSR = NDSR_CS0_BBD;
            goto Nand_Write_Return;
        }
    }
#else
    if((err = waitFlag(NDSR_CS0_CMDD, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Write_Return;
    }
    REG_NDSR = NDSR_CS0_CMDD;
#endif

Nand_Write_Return:

    Nand_ControllerStop();
    return(err);

#undef ADDRESS_POS_OFFSET
#undef ADDRESS_POS_SETCTOR
#undef ADDRESS_POS_BLOCK
#undef ADDRESS_BLOCK_LEFT_BIT
}

/*
    Note:
        The caller should read out the NAND Flash STATUS by NAND_Status to see if the Erase is successful or not.
*/
int Nand_EraseBlock(U32 dwPhysicalBlockID)
{
#define ADDRESS_POS_BLOCK    6

    int err;

    if(dwPhysicalBlockID >= NAND_BLOCK_NUMBER_IN_TOTAL)
    {
        return(ERR_CODE_NAND_PARAMETER);
    }

    dwPhysicalBlockID = dwPhysicalBlockID << ADDRESS_POS_BLOCK;

    if((err = Nand_ControllerStart()) != ERR_CODE_NONE)
    {
        goto Nand_Erase_Return;
    }

#ifdef CMD_WITH_AUTO_STATUS
    REG_NDCB0 = (NDCB0_CMD_TYPE(CMD_TYPE_ERASE)) | NDCB0_DBC | NDCB0_ADDR_CYC(NAND_CMD_ERASE_CYCLE) | NAND_CMD_ERASE | NDCB0_AUTO_RS;
#else
    REG_NDCB0 = (NDCB0_CMD_TYPE(CMD_TYPE_ERASE)) | NDCB0_DBC | NDCB0_ADDR_CYC(NAND_CMD_ERASE_CYCLE) | NAND_CMD_ERASE;
#endif

    REG_NDCB0 = dwPhysicalBlockID;
    REG_NDCB0 = 0;

    if((err = waitFlag(NDSR_RDY, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Erase_Return;
    }
    REG_NDSR = NDSR_RDY;

#ifdef CMD_WITH_AUTO_STATUS
    if(REG_NDCB0 & NDCB0_AUTO_RS)
    {
        if(REG_NDSR & NDSR_CS0_BBD)
        {
            err = ERR_CODE_NAND_BADBLOCK;
            REG_NDSR = NDSR_CS0_BBD;
            goto Nand_Erase_Return;
        }
    }
#else
    if((err = waitFlag(NDSR_CS0_CMDD, 1000000)) != ERR_CODE_NONE)
    {
        goto Nand_Erase_Return;
    }
    REG_NDSR = NDSR_CS0_CMDD;
#endif

Nand_Erase_Return:

    Nand_ControllerStop();
    return(err);

#undef ADDRESS_POS_BLOCK
}

#endif //INCLUDE_MODULE_NAND

