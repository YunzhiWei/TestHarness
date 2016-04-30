
#include "_Platform.h"

#ifdef INCLUDE_MODULE_FSYS

#define FILESYS_TEMP_BUFFER_BASE        BUFFER_SHARED_UNION_BASE
#define FILESYS_TEMP_BUFFER_SIZE        BUFFER_SHARED_UNION_SIZE

FAT_FileHandle_t g_CurrentDir;

static void OutputChars(PBYTE pBuffer, U32 dwSize)
{
    U32 i;

    for(i=0;i<dwSize;i++) DBG_PutChar(pBuffer[i]);
    DBG_GET_BYTE;
}

static void PageBreak(U32 dwCounter)
{
#define _PAGE_BREAK_NUMBER_                   ((1 << 4) - 1)

    DBG_TraceString(" ... "); DBG_TraceDec(NULL, dwCounter);
    if(0 == (dwCounter & _PAGE_BREAK_NUMBER_)) DBG_GET_BYTE;
}

static int DirTraverse(const PFAT_FileHandle_t pDir, PFAT_DIR_DOS_Entry_t pEntry, const PBYTE pFileName, PCallBackTraverseDir_t pCallBack)
{
#define SUPPORT_LONGNAME
    int err, i;
    FAT_FileHandle_t dir;

    MemCopy((PBYTE)(&dir), (PBYTE)(pDir), sizeof(FAT_FileHandle_t));

    i = 0;

#ifdef SUPPORT_LONGNAME
    BYTE longname[FAT_WIN_NAME_MAXLEN + 10];
    while(ERR_CODE_NONE == (err = FAT_DirGetNextEntry(&dir, pEntry, longname)))
    {
        if(pFileName == NULL) FAT_ShowEntryInformation(pEntry, longname);
        else if(0 == StrCompare((char *) pFileName, longname)) return(ERR_CODE_FSYS_FOUND);
        if(pCallBack != NULL) pCallBack(++i);
    }
#else
    while(ERR_CODE_NONE == (err = FAT_DirGetNextEntry(&dir, pEntry, NULL)))
    {
        if(pFileName == NULL) FAT_ShowEntryInformation(pEntry, NULL);
        else if(0 == StrCompare((char *) pFileName, (char *)(pEntry->m_cName)) return(ERR_CODE_FSYS_FOUND);
        if(pCallBack != NULL) pCallBack(++i);
    }
#endif

    return(err);
}

static int FindEntry(PFAT_DIR_DOS_Entry_t pEntry)
{
    BYTE                filename[8];

    DBG_GetString("File Name", sizeof(filename), filename);

    return(DirTraverse(&g_CurrentDir, pEntry, filename, NULL));
}

static int FileTraverse(PBYTE pBuffer, U32 dwSize, PCallBackTraverseFile_t pCallBack)
{
    FAT_FileHandle_t    file;
    FAT_DIR_DOS_Entry_t entry;
    U32                 size;
    int                 err;

    if(ERR_CODE_FSYS_FOUND != (err = FindEntry(&entry)))
    {
        DBG_TraceStrLine("NO Found");
        return(err);
    }

    if((entry.m_cAttributes & FAT_ATTR_DIRECTORY) == FAT_ATTR_DIRECTORY)
    {
        DBG_TraceStrLine("It is Dir!");
        return(ERR_CODE_FSYS_INVALID);
    }

    FAT_CreateHandle(&entry, &file, NULL);

    while(1)
    {
        size = entry.m_dwSize - file.m_dwPosition;
        if(size == 0)
        {
            err = ERR_CODE_FAT_EOF;
            break;
        }
        if(size > dwSize) size = dwSize;

        if(ERR_CODE_NONE != (err = FAT_FileRead(&file, pBuffer, size))) break;

        if(pCallBack != NULL)
        {
            pCallBack(pBuffer, size);
        }
    }

    return(err);
}

static void tDir(void)
{
    FAT_DIR_DOS_Entry_t entry;

    DBG_TraceHex("dir", DirTraverse(&g_CurrentDir , &entry, NULL, PageBreak));
}

static void tFind(void)
{
    FAT_DIR_DOS_Entry_t entry;
    int err;

    if(ERR_CODE_FSYS_FOUND == (err = FindEntry(&entry))) FAT_ShowEntryInformation(&entry, NULL);
    else ErrCodeDisplay(err);
}

static void tDump(void)
{
    FAT_CatchFATTableFlush();
    ErrCodeDisplay(FileTraverse((PBYTE)FILESYS_TEMP_BUFFER_BASE, 256, OutputChars));
}

static void tLoad(void)
{
    FAT_CatchFATTableFlush();
    ErrCodeDisplay(FileTraverse((PBYTE)FILESYS_TEMP_BUFFER_BASE, FILESYS_TEMP_BUFFER_SIZE, NULL));
}

static void tRun(void)
{
    int err;

    FAT_CatchFATTableFlush();
    err = FileTraverse((PBYTE)FILESYS_TEMP_BUFFER_BASE, FILESYS_TEMP_BUFFER_SIZE, NULL);
    if(ERR_CODE_FAT_EOF == err)
    {
        JumpToRun(FILESYS_TEMP_BUFFER_BASE);
    }
    else
    {
        ErrCodeDisplay(err);
    }
}

static void tExecuteNKNB0(U32 dwBufAddr, U32 dwBufLen)
{
    ROMHDR_t *pTOC;
    PU8      pflag;
    PU32     ptmp;
    U32      addr, offset;
    U32      LaunchAdr;

    pflag = (PU8)(dwBufAddr + 0x40);
    if(0 != StrCompare("ECEC", pflag)) return;

    ptmp  = (PU32)(dwBufAddr + 0x44); addr   = *ptmp;
    ptmp  = (PU32)(dwBufAddr + 0x48); offset = *ptmp;

    pTOC =  (ROMHDR_t *)(dwBufAddr + offset);

    LaunchAdr = dwBufAddr+0x1000;

    DBG_TraceHex("cur", dwBufAddr);
    DBG_TraceHex("len", dwBufLen);
    DBG_TraceHex("ADD", addr);
    DBG_TraceHex("Off", offset);
    DBG_TraceHex("A-O", addr - offset);
    DBG_TraceHex("phy", pTOC->physfirst);
    DBG_TraceHex("LaunchAdr", LaunchAdr);
    DBG_TraceMem("DATA",  (U32*)0x80442000, 8);
    DBG_TraceMem("DATA1",  (U32*)0x80443000, 8);

    if( (dwBufAddr < pTOC->physfirst) &&
        ((dwBufAddr + dwBufLen ) > pTOC->physfirst) )
    {
        DBG_BreakPoint("Overflow!");
        return;
    }

    if(dwBufAddr != pTOC->physfirst)
    {
        DBG_BreakPoint("Press any key to copy!");
        MemCopy((PBYTE)pTOC->physfirst, (PBYTE)dwBufAddr, (int)dwBufLen);
    }

    DBG_BreakPoint("$Press any key to jump!");
    JumpToRun(LaunchAdr);
}

static void tGoThrough(void)
{
    int                 err;
    FAT_FileHandle_t    file;
    FAT_DIR_DOS_Entry_t entry;

    if(FindEntry(&entry) != ERR_CODE_FSYS_FOUND)
    {
        DBG_TraceStrLine("No found");
        return;
    }

    FAT_CreateHandle(&entry, &file, NULL);

    while(ERR_CODE_NONE != (err = FAT_HandleTraverseCluID(&file, TRUE)))
    {
        ErrCodeDisplay(err);
        DBG_TraceHex("CID", file.m_dwClusterID);
        DBG_BreakPoint(NULL);
        if(ERR_CODE_FAT_CLUID_BREAK != err) break;
    }
}

static void tChangeDir(void)
{
    FAT_DIR_DOS_Entry_t entry;

    if(ERR_CODE_FSYS_FOUND != FindEntry(&entry))
    {
        DBG_TraceStrLine("NO Found");
        return;
    }

    if((entry.m_cAttributes & FAT_ATTR_DIRECTORY) != FAT_ATTR_DIRECTORY)
    {
        DBG_TraceStrLine("It is not a Dir!");
        return;
    }

    FAT_CreateHandle(&entry, &g_CurrentDir, NULL);
}

typedef struct
{
    U32 m_dwBlockID;
    PU8 m_psFileName;
}ImageConfig_t;

static const ImageConfig_t g_Config[] = {
    {UPD_STORE_POS_BLOCK_ID_IMAGE,      "NK"},              // !!! NK must be the first known file name. Special deal with NK.NB0 !!!
    {UPD_STORE_POS_BLOCK_ID_IMAGE,      "FLASH"},

    {UPD_STORE_POS_BLOCK_ID_SCREEN,     "SCREEN"},

    {UPD_STORE_POS_BLOCK_ID_HWTESTER,   "TESTER"},
    {UPD_STORE_POS_BLOCK_ID_IPL,        "IPL"},

    {UPD_STORE_POS_BLOCK_ID_EBOOT,      "EBOOT"},
    {UPD_STORE_POS_BLOCK_ID_8,          "8"},
    {UPD_STORE_POS_BLOCK_ID_9,          "9"},
    {UPD_STORE_POS_BLOCK_ID_9,          "MUSIC"}
};
const char *g_ExtName[]  =              {"NB0", "BIN", "EXT", "SCR", "WAV"};

#define KNOWN_FILENAME_NUMBER           (sizeof(g_Config)/sizeof(ImageConfig_t))
#define KNOWN_FILETYPE_NUMBER           (sizeof(g_ExtName)/sizeof(char*))

#define KNOWN_TYPE_NB0                  0
#define KNOWN_TYPE_BIN                  1
#define KNOWN_TYPE_EXT                  2
#define KNOWN_TYPE_SCR                  3
#define KNOWN_TYPE_WAV                  4

static void tAutoBatch(void)
{
    U32 nameID, typeID, bufAddr, startBlkID;
    FAT_FileHandle_t    file;
    FAT_DIR_DOS_Entry_t entry;
    FAT_FileHandle_t    dir;
    int                 err;

    MemCopy((PBYTE)(&dir), (PBYTE)(&g_CurrentDir), sizeof(FAT_FileHandle_t));

    while(ERR_CODE_NONE == (err = FAT_DirGetNextEntry(&dir, &entry, NULL)))
    {
        for(nameID=0;nameID<KNOWN_FILENAME_NUMBER;nameID++)
        {
            if(0 == StrCompare(g_Config[nameID].m_psFileName, (char *)(entry.m_cName))) break;
        }
        if(nameID >= KNOWN_FILENAME_NUMBER) continue;

        MY_TraceStrLine("Find ");
        MY_TraceString((PU8)(g_Config[nameID].m_psFileName));

        startBlkID = g_Config[nameID].m_dwBlockID;

        for(typeID=0;typeID<KNOWN_FILETYPE_NUMBER;typeID++)
        {
            if(0 == StrCompare((char *)g_ExtName[typeID], (char *)(entry.m_cExtension))) break;
        }
        if(typeID>= KNOWN_FILETYPE_NUMBER) continue;

        MY_TraceString(".");
        MY_TraceString((PU8)g_ExtName[typeID]);

        FAT_CreateHandle(&entry, &file, NULL);
        switch(typeID)
        {
        case KNOWN_TYPE_NB0:
            DBG_TraceStrLine("NB0");
            if(nameID != 0)
            {   // !!! This is the special deal with NB0 !!!
                err = UPD_BurnFileRAWDATA(startBlkID, &file, entry.m_dwSize);
            }
            else
            {
                if(ERR_CODE_NONE != (err = FAT_HandleTraverseCluID(&file, FALSE)))
                {
                    ErrCodeDisplay(err);
                    DBG_TraceHex("CID", file.m_dwClusterID);
                    DBG_BreakPoint(NULL);
                    return;
                }

                bufAddr = RMD_SectorAddress(FAT_ClusterID2SectorID(file.m_tEntry.m_wStartClusterID));

                tExecuteNKNB0(bufAddr, entry.m_dwSize);
            }
            break;
        case KNOWN_TYPE_BIN:
            DBG_TraceStrLine("BIN");
            err = UPD_BurnFileBIN(startBlkID, &file, entry.m_dwSize);
            break;
        case KNOWN_TYPE_EXT:
            DBG_TraceStrLine("EXT");
            bufAddr = RMD_SectorAddress(FAT_ClusterID2SectorID(file.m_tEntry.m_wStartClusterID));

            if(ERR_CODE_NONE != (err = FAT_HandleTraverseCluID(&file, FALSE)))
            {
                ErrCodeDisplay(err);
                DBG_TraceHex("CID", file.m_dwClusterID);
                DBG_BreakPoint(NULL);
                return;
            }

            err = UPD_BurnFileEXT(startBlkID, bufAddr, entry.m_dwSize);
            break;
        case KNOWN_TYPE_SCR:
            DBG_TraceStrLine("SCR");
            err = FAT_FileRead(&file, (PU8)FB_BASE_RGB565_ADDR, FB_BASE_RGB565_SIZE);
            if((ERR_CODE_NONE != err) && ((ERR_CODE_FAT_EOF != err)))
            {
                ErrCodeDisplay(err);
                DBG_BreakPoint(NULL);
            }
            DBG_BreakPoint(NULL);
            break;
#ifdef INCLUDE_MODULE_AUDIO
        case KNOWN_TYPE_WAV:
            DBG_TraceStrLine("WAV");
            bufAddr = RMD_SectorAddress(FAT_ClusterID2SectorID(file.m_tEntry.m_wStartClusterID));

            if(ERR_CODE_NONE != (err = FAT_HandleTraverseCluID(&file, FALSE)))
            {
                ErrCodeDisplay(err);
                DBG_TraceHex("CID", file.m_dwClusterID);
                DBG_BreakPoint(NULL);
                return;
            }

            Audio_PlayWaveFile(bufAddr);
            break;
#endif
         }

        ErrCodeDisplay(err);
    }
}

int FS_Initial(FS_Disk_ID_t tID)
{
    const MENU_REC disk[] = {
        {'r', "RAM", NULL},
        {'s', "SD",  NULL},
        {'\0'}
    };
    const FAT_BlockRead_t pFun[][2] = {
        {RMD_SectorRead, RMD_SectorRead},
        {SD_BlockRead1, SD_BlockReadN}
    };
    int err, i;

    if(tID == FS_DISK_INVALID)
    {
        i = MenuFunction("Select a Disk", disk);
    }
    else i = tID;
    if( i< 0)
    {
        DBG_TraceDec("Fail", abs(i));
        return;
    }

    if(i == 1)
    {
        SD_Initial();
        if(ERR_CODE_NONE != SD_OnCardInsert()) return;
    }

    DBG_TraceHex("FILE Init", err = FAT_Initial(pFun[i][0], pFun[i][1]));
    if(err != ERR_CODE_NONE) return(err);

    if(ERR_CODE_NONE != (err = FAT_CreateHandle((PFAT_DIR_DOS_Entry_t)NULL, &g_CurrentDir, NULL)))
    {
        DBG_TraceStrLine("CD / Fail");
        return(err);
    }

    return(ERR_CODE_NONE);
}

void FS_AutoBatch(FS_Disk_ID_t tID)
{
    RTC_Time_t time;

    time.m_dwTime = RTC_TimeGet();
    RTC_ShowTime(time);

    if(ERR_CODE_NONE != FS_Initial(tID))
    {
        const static char *str = "FS Initial Error";
        CS_PutString((char *)str);
        DBG_BreakPoint((char *)str);
        return;
    }

    tAutoBatch();

    time.m_dwTime = RTC_TimeGet();
    RTC_ShowTime(time);
}

void FILE_Test(void)
{
    const MENU_REC menu[] = {
        {'d', "dir",            tDir},
        {'f', "find",           tFind},
        {'t', "Type",           tDump},
        {'l', "Load",           tLoad},
        {'r', "Run",            tRun},
        {'A', "Auto Batch",     tAutoBatch},
        {'g', "GoThrough",      tGoThrough},
        {'c', "Change",         tChangeDir},

        {'\0'}
    };

    if(ERR_CODE_NONE != FS_Initial(FS_DISK_INVALID)) return;
    FAT_ShowSysParameter();

    MenuFunction("File System", menu);
}

#endif

