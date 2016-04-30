#include "_type.h"
#include "APIStub.h"

#define NAND_TEST_MEM_BASE              BUFFER_XMODEM_FILE_BASE
#define NAND_TEST_MEM_SIZE              BUFFER_XMODEM_FILE_SIZE

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

static void regDump(U32 dwLevel)
{
    DBG_TraceStrLine("DCF Dump");

    switch(dwLevel)
    {
    case 100:
        DBG_TraceHex("NDPCR",       REG_NDPCR);
        DBG_TraceHex("NDBDR0",      REG_NDBDR0);
        DBG_TraceHex("NDBDR0",      REG_NDBDR1);
        DBG_TraceHex("NDDB",        REG_NDDB);
        DBG_TraceHex("MH_NDCB0",    REG_NDCB0);
        DBG_TraceHex("MH_NDCB1",    REG_NDCB1);
        DBG_TraceHex("MH_NDCB2",    REG_NDCB2);
    case 80:
        DBG_TraceHex("NDTR0CS0",    REG_NDTR0CS0);
        DBG_TraceHex("NDTR1CS0",    REG_NDTR1CS0);
    case 2:
        DBG_TraceHex("NDCR",        REG_NDCR);
    case 1:
        DBG_TraceHex("NDSR",        REG_NDSR);
    }
}

static void tPrintError(U32 dwError)
{
    DBG_TraceStrLine("Result: ");

    switch(dwError)
    {
    case NAND_FUNC_ERROR_CODE_NULL:
        DBG_TraceString("OK");
        break;
    case NAND_FUNC_ERROR_CODE_PARAMS:
        DBG_TraceString("PARAM");
        break;
    case NAND_FUNC_ERROR_CODE_TIMEOUT:
        DBG_TraceString("Timeout");
        break;
    case NAND_FUNC_ERROR_CODE_BADBLOCK:
        DBG_TraceString("Bad block");
        break;
    case NAND_FUNC_ERROR_CODE_DBERR:
        DBG_TraceString("Double Bit Error");
        break;
    case NAND_FUNC_ERROR_CODE_SBERR:
        DBG_TraceString("Single Bit Error");
        break;

    default:
        DBG_TraceHex("?", dwError);
        break;
    }
}

static void tDumpReg(void)
{
    regDump(100);
}

static void tStatus(void)
{
    U32 status;

    tPrintError(Nand_CmdGetStatus(&status));
    DBG_TraceHex("Status:", status);
}

static void tReadID(void)
{
    U32 id;

    tPrintError(Nand_CmdGetID(&id));
    DBG_TraceHex("NAND ID:", id);
}

#define TEST_BLOCK_NUMBER               6

static void tFormatMem(void)
{
    MemSet((void*)NAND_TEST_MEM_BASE, (U8)DBG_GetHexDef("Format MEM Value", 2, 0xAB), NAND_BLOCK_SIZE);
}

static void tDumpMem(void)
{
    U32 *p;
    U32 i;

    for(p = (U32*)NAND_TEST_MEM_BASE, i = 0;i < NAND_SECTOR_NUMBER_PER_BLOCK;i++, p += (NAND_SECTOR_SIZE/sizeof(U32)))
    {
        if(i%8 == 0) DBG_TraceStrLine("");
        DBG_TraceHex(NULL, *p);
    }

    DBG_BreakPoint(NULL);
}

static void tErase(void)
{
    U32 block, r;

    block = DBG_GetDecDef("PhysicalBlock#:", 8, TEST_BLOCK_NUMBER);

    if(block == 0x00)
    {
        DBG_TraceStrLine("DONOT use block 0 for testing");
        return;
    }

    tPrintError(Nand_CmdEraseBlock(block));
}

static void tWrite(void)
{
    U32 sector, block, offset, length;

    tFormatMem();

    block = DBG_GetDecDef("Block#", 8, TEST_BLOCK_NUMBER);
    sector = DBG_GetDecDef("Sector#", 8, 0);
    offset = DBG_GetDecDef("Offset", 8, 0);

    tPrintError(Nand_CmdWriteSector(block, sector, offset, (U32*)NAND_TEST_MEM_BASE, (U32*)(NAND_TEST_MEM_BASE + NAND_SECTOR_SIZE)));
}

static void tRead(void)
{
    U32 sector, block, offset, length;

    tFormatMem();

    block = DBG_GetDecDef("Block#", 8, TEST_BLOCK_NUMBER);
    sector = DBG_GetDecDef("Sector#", 8, 0);
    offset = DBG_GetDecDef("Offset", 8, 0);
    length= DBG_GetHexDef("length", 8, NAND_SECTOR_SIZE);

    tPrintError(Nand_CmdReadSector(block, sector, offset,  (U32*)NAND_TEST_MEM_BASE, length,  (U32*)(NAND_TEST_MEM_BASE + NAND_SECTOR_SIZE)));
    DBG_TraceMem("DATA",  (U32*)NAND_TEST_MEM_BASE, 8);
    DBG_TraceMem("Spare",  (U32*)(NAND_TEST_MEM_BASE + NAND_SECTOR_SIZE), 8);
}

static void tReadBlock(void)
{
    U32 block;

    block = DBG_GetDecDef("Block#", 8, TEST_BLOCK_NUMBER);

    tFormatMem();

    Nand_ReadBlock(block, (U32*)NAND_TEST_MEM_BASE);

    tDumpMem();
}

static void tWriteBlock(void)
{
    U32 block, i;
    U32 *p;

    block = DBG_GetDecDef("Block#", 8, TEST_BLOCK_NUMBER);

    for(p = (U32*)NAND_TEST_MEM_BASE, i = 0;i < NAND_SECTOR_NUMBER_PER_BLOCK;i++, p += (NAND_SECTOR_SIZE/sizeof(U32)))
    {
        *p = i;
    }
    tDumpMem();

    Nand_WriteBlock(block, (U32*)NAND_TEST_MEM_BASE);
}

static void tECCDisable(void)
{
//    Nand_ControllerECCEnable(FALSE);

    regDump(2);
}

static void tSpareDisable(void)
{
//    Nand_ControllerSpareEnable(FALSE);

    regDump(2);
}

typedef struct{
    U32 m_dwBad;
    U32 m_dwSB;
    U32 m_dwDB;
    U32 m_dwCompare;
    U32 m_dwOther;
}NAND_Error_Counter_t;

static void tStatisticError(U8 *pszTitle, U32 dwBlockID, U32 dwError, NAND_Error_Counter_t *tCounter)
{
    DBG_TraceStrLine(pszTitle);

    switch(dwError)
    {
    case NAND_FUNC_ERROR_CODE_BADBLOCK:
        tCounter->m_dwBad++;
        DBG_TraceDec("BD", dwBlockID);
        break;
    case NAND_FUNC_ERROR_CODE_SBERR:
        tCounter->m_dwSB++;
        DBG_TraceDec("SB", dwBlockID);
        break;
    case NAND_FUNC_ERROR_CODE_DBERR:
        tCounter->m_dwDB++;
        DBG_TraceDec("DB", dwBlockID);
        break;
    case NAND_FUNC_ERROR_CODE_COMPARE:
        tCounter->m_dwCompare++;
        DBG_TraceDec("CP", dwBlockID);
        break;
    default:
        tCounter->m_dwOther++;
        DBG_TraceDec("??", dwBlockID);
        tPrintError(dwError);
        break;
    }

    DBG_TraceStrLine("");
}

static void tStressCycle(U32 dwBlockID, U32 dwBlockCT, U32 dwTestValue, NAND_Error_Counter_t *tCounter)
{
    U32 i, j, k;
    U32 r;
    U32 lastBlckID;

    U8 *pRead;
    U8 *pWrite;
    U32 *pr32;
    U32 *pw32;

    pRead  = (U8*)(NAND_TEST_MEM_BASE);
    pWrite = (U8*)(NAND_TEST_MEM_BASE + 1 * 1024 * 1024);
    pr32   = (U32*)pRead;
    pw32   = (U32*)pWrite;

    lastBlckID = NAND_BLOCK_NUMBER_IN_TOTAL - dwBlockCT;

    for(;dwBlockID < lastBlckID;dwBlockID += dwBlockCT)
    {
        DBG_TraceString("\r");  DBG_TraceDec(NULL, dwBlockID);

        // Format Buffer

        MemSet((void*)pRead, (U8)0, NAND_SECTOR_SIZE+NAND_SPAREAREA_SIZE);
        for(i = 0;i < ((NAND_SECTOR_SIZE + NAND_SPAREAREA_SIZE)/sizeof(U32));i++)
        {
            pw32[i] = dwTestValue++;
        }

        // Erase

        for(i = 0; i<dwBlockCT; i++)
        {
            r = Nand_CmdEraseBlock(dwBlockID + i);

            if(r != NAND_FUNC_ERROR_CODE_NULL)
            {
                tStatisticError("E", dwBlockID + i, r, tCounter);
            }
        }

        // Write

        for(i = 0; i <dwBlockCT; i++)
        {
            for(j = 0; j<NAND_SECTOR_NUMBER_PER_BLOCK; j++)
            {
                r = Nand_CmdWriteSector(dwBlockID + i, j, 0,
                                        (U32*)pWrite,
                                        (U32*)(pWrite+ NAND_SECTOR_SIZE));

                if(r != NAND_FUNC_ERROR_CODE_NULL)
                {
                    tStatisticError("W", dwBlockID + i, r, tCounter);
                }
            }
        }

        // Read & Compare

        for(i = 0; i <dwBlockCT; i++)
        {
            for(j = 0; j<NAND_SECTOR_NUMBER_PER_BLOCK; j++)
            {
                r = Nand_CmdReadSector(dwBlockID + i, j, 0,
                                        (U32*)pRead,
                                        NAND_SECTOR_SIZE,
                                        (U32*)(pRead + NAND_SECTOR_SIZE));

                if(r != NAND_FUNC_ERROR_CODE_NULL)
                {
                    tStatisticError("R", dwBlockID + i, r, tCounter);
                }

                for(k = 0; k < (NAND_SECTOR_SIZE/sizeof(u32)); k++)
                {
                    if(pw32[k] != pr32[k])
                    {
                        tStatisticError("C", dwBlockID + i, NAND_FUNC_ERROR_CODE_COMPARE, tCounter);
                        break;
                    }
                }
            }
        }
#if 0
        u32BlockIndex = u32BlockIndex+10;
        if((u32BlockIndex == 100) || (u32BlockIndex == 200) || (u32BlockIndex == 300)
        || (u32BlockIndex == 400) || (u32BlockIndex == 500) || (u32BlockIndex == 600)
        || (u32BlockIndex == 700) || (u32BlockIndex == 800) || (u32BlockIndex == 900) || (u32BlockIndex == 1000))
        {
            DBG_TraceStrLine("$$On Going!!");
        }
        if(u32BlockIndex == 1020)
        {
            break;
        }
#endif
    }
}

void TestAutoNand(void)
{

    U32 i;
    NAND_Error_Counter_t ct;

    i = 0;

    while(!DBG_GotEvent)
    {
        ct.m_dwBad     = 0;
        ct.m_dwSB      = 0;
        ct.m_dwDB      = 0;
        ct.m_dwCompare = 0;
        ct.m_dwOther   = 0;

        DBG_TraceString("\r\n #");
        DBG_TraceDec(NULL, i);

        tStressCycle(6, 10, i++, &ct);

        if(ct.m_dwBad     != 0) DBG_TraceDec("BD", ct.m_dwBad);
        if(ct.m_dwSB      != 0) DBG_TraceDec("SB", ct.m_dwSB);
        if(ct.m_dwDB      != 0) DBG_TraceDec("DB", ct.m_dwDB);
        if(ct.m_dwCompare != 0) DBG_TraceDec("CP", ct.m_dwCompare);
        if(ct.m_dwOther   != 0) DBG_TraceDec("OT", ct.m_dwOther);
    }
    DBG_GET_BYTE;
}

static MENU_REC l_Module[] = {
    {'a', "auto test",  TestAutoNand},
    {'g', "Reg",        tDumpReg},
    {'m', "mem",        tDumpMem},
    {'f', "Format",     tFormatMem},
    {'i', "ID",         tReadID},
    {'s', "Status",     tStatus},
    {'r', "Read S",     tRead},
    {'w', "Write S",    tWrite},
    {'E', "Erase",      tErase},
    {'R', "Read B",     tReadBlock},
    {'W', "Write B",    tWriteBlock},
//    {'e', "ECC",        tECCDisable},
//    {'p', "Spare",      tSpareDisable},
    {'\0'}
};

void Main(void)
{
//    DBG_BreakPoint("Hello");
//    DBG_CountDown(3);

    MenuFunction("Nand Test", l_Module);
    DBG_BreakPoint("Bye");
//    DBG_CountDown(3);
}
