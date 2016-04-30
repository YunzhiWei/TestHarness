#include "_type.h"
#include "APIStub.h"

#define FILESYS_TEMP_BUFFER_BASE        BUFFER_XMODEM_FILE_BASE
#define FILESYS_TEMP_BUFFER_SIZE        BUFFER_XMODEM_FILE_SIZE

static U32 DirTraverse(const PFAT_FileHandle_t pDir, PFAT_DIR_DOS_Entry_t pEntry, const PBYTE pFileName)
{
    U32 r;

    while(FAT_ERR_CODE_NONE == (r = FAT_DirGetNextEntry(pDir, pEntry, NULL)))
    {
        if(0 == StrCompare((char *)pFileName, pEntry->m_cName)) return(FAT_ERR_CODE_FOUND);
    }

    return(r);
}

static void BurnFile(PBYTE pFileName, U32 dwBlockID)
{
    U32 i, r, offset, size;
    U32 bufAddr;

    FAT_FileHandle_t    file;
    FAT_FileHandle_t    root;
    FAT_DIR_DOS_Entry_t entry;

    if((dwBlockID == 0) || (dwBlockID == 1))
    {
        DBG_TraceStrLine("0 & 1");
        return;
    }

    FAT_CreateHandle(NULL, &root);

    if(DirTraverse(&root, &entry, pFileName) != FAT_ERR_CODE_FOUND)
    {
        DBG_TraceStrLine("No found");
        return;
    }

    FAT_CreateHandle(&entry, &file);

    if(FAT_ERR_CODE_NONE != FAT_HandleTraverseCluID(&file, FALSE))
    {
        DBG_TraceHex("Err", r);
        DBG_TraceHex("CID", file.m_dwClusterID);
        return;
    }

    size   = file.m_tEntry.m_dwSize;
    bufAddr = RMD_SectorAddress(FAT_ClusterID2SectorID(file.m_tEntry.m_wStartClusterID));

    DBG_TraceStrLine("Start Burn ");
    DBG_TraceString(pFileName); DBG_TraceString(" @ "); DBG_TraceDec(NULL, dwBlockID); DBG_TraceString(" ...");
    DBG_TraceStrLine("");

    for(i = 0, offset = 0;offset < size; dwBlockID++, offset+=NAND_BLOCK_SIZE)
    {
        DBG_TraceString("\r");
        DBG_TraceDec(NULL, i++);

        if((r = Flash_EraseBlock(dwBlockID)) != FLASH_FUNC_ERROR_CODE_SUCCESS)
        {
            DBG_TraceHex("Flash_Erase", r);
            return;
        }
        if((r = Flash_WriteBlock(dwBlockID, (U32*)(bufAddr + offset))) != FLASH_FUNC_ERROR_CODE_SUCCESS)
        {
            DBG_TraceHex("Flash_Write", r);
            return;
        }
    }

    DBG_TraceStrLine("Done");
}

void tBurn(void)
{
	DBG_BreakPoint("Make sure you are going to burn!");

	BurnFile("EBOOT", 2);
	BurnFile("IPL",   4);
	BurnFile("FLASH", 6);
}

static MENU_REC l_Module[] = {
    {'b', "Burn",           tBurn},
    {'\0'}
};

void Main(void)
{
//    DBG_BreakPoint("Hello");
//    DBG_CountDown(3);

    if(FAT_ERR_CODE_NONE == FAT_Initial())
    {
        MenuFunction("Test File Sys", l_Module);
    }
	else
	{
		DBG_TraceStrLine("Initial Fail");
    }

    DBG_BreakPoint("Bye");
//    DBG_CountDown(3);
}































