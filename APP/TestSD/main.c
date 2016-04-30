#include "_type.h"
#include "APIStub.h"

//use the XMODEM ram address as the data buffer
#define TEST_BUFFER_BASE1               BUFFER_XMODEM_FILE_BASE
#define TEST_BUFFER_BASE2               (BUFFER_XMODEM_FILE_BASE+(MMCSD_BLOCK_SIZE * MMCSD_BLOCK_NUMBER))

static void tRead(void)
{
    U8* pbuf;

    pbuf = (U8*)TEST_BUFFER_BASE1;

    SD_BlockRead(DBG_GetDecDef("ID", 3, 0), pbuf, MMCSD_BLOCK_SIZE);

    DBG_TraceMem("", pbuf, 8);
}

static void tWrite(void)
{
    SD_BlockWrite(DBG_GetDecDef("ID", 3, 0), (U8*)TEST_BUFFER_BASE1, MMCSD_BLOCK_SIZE);
    DBG_TraceStrLine("Write done NOW!");

}

static void tErase(void)
{
    SD_BlockErase(DBG_GetDecDef("START", 3, 0), DBG_GetDecDef("STOP", 3, 3));
}

static void tCardInitial(void)
{
    SD_Initial();
    SD_OnCardInsert();
}

static BOOL MemoryCompare(U32 startAddr1,U32 startAddr2,U32 len)
{
    U32 i;
    U8 *pv1, *pv2;

    pv1 = (U8*) startAddr1;
    pv2 = (U8*) startAddr2;

    for(i=0;i<len;i++)
    {
        if(pv1[i] != pv2[i])
        {
            DBG_TraceHex("addr1", (U32)(pv1 + i));
            DBG_TraceHex("addr2", (U32)(pv2 + i));
            return FALSE;
            break;
        }
        if(DBG_GotEvent) break;
    }

    return TRUE;

}

static void tSDAutoTest(void)
{

    MemSet((void*)TEST_BUFFER_BASE1,0, MMCSD_BLOCK_SIZE);
    MemSet((void*)TEST_BUFFER_BASE2,1, MMCSD_BLOCK_SIZE);

    DBG_TraceStrLine("SD Auto Test Begin");

    DBG_TraceStrLine("Step 1: Write test data to block 1 in card.");
    SD_BlockWrite(1, (U8*)TEST_BUFFER_BASE1,MMCSD_BLOCK_SIZE);

    DBG_TraceStrLine("Step 2: Read test data from block 1 in card.");
    SD_BlockRead(1,(U8*)TEST_BUFFER_BASE2 ,MMCSD_BLOCK_SIZE);

    DBG_TraceStrLine("Step 3: Compare the read data with the written data...");
    if(MemoryCompare(TEST_BUFFER_BASE1,TEST_BUFFER_BASE2,MMCSD_BLOCK_SIZE))
        DBG_TraceStrLine("Compare Finished.Read/Write Test Pass!");
    else
        DBG_TraceStrLine("Compare Finished.Read/Write Test Failed!");

    DBG_TraceStrLine("SD Auto Test End");
}

static MENU_REC l_Module[] = {
    {'s', "CardInit",  tCardInitial},
    {'r', "Read ",  tRead},
    {'w', "Write  ",  tWrite},
    {'e', "Erase",  tErase},
    {'a', "Auto Test",  tSDAutoTest},
    {'\0'}
};

void Main(void)
{
//    DBG_BreakPoint("Hello");
//    DBG_CountDown(3);

    MenuFunction("MMC/SD Test", l_Module);
    DBG_BreakPoint("Bye");
//    DBG_CountDown(3);
}
