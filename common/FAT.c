
//*****************************************************************************
// We do not support multiple file operation, because we have only one Catch for file data.
//
// You must create file handle for any file operations, include dir operations.
// Before you finished one file operation, you cannot start another.


#include "_Platform.h"

#ifdef INCLUDE_MODULE_FAT

#define FAT_TYPE_FAT16

static FAT_BlockRead_t g_pfReadSector;
static FAT_BlockRead_t g_pfReadCluster;

#define BLOCK_DEVICE_READ_SECTOR(secID, bufferAddr, bufferSize)     g_pfReadSector(secID, bufferAddr, bufferSize)
#define BLOCK_DEVICE_READ_CLUSTER(secID, bufferAddr, bufferSize)    g_pfReadCluster(secID, bufferAddr, bufferSize)

// Global Buffer
/*
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   !!! So far, we can not dynamic allocate memory.                    !!!
   !!! So we can only use static size catch                           !!!
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   !!! For those clients, which do not provide catch for File Handle, !!!
   !!! FAT can provide one catch for file and one for Dir.            !!!
   !!! So the client cannot use more than one File at the same time   !!!
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#define CATCH_SIZE_FATTABLE             512
#define CATCH_SIZE_CLUSTER              (32 * 1024)

static U32 g_CatchFATTableSector[CATCH_SIZE_FATTABLE/sizeof(U32)];
static U32 g_CatchClusterFile[CATCH_SIZE_CLUSTER/sizeof(U32)];
static U32 g_CatchClusterDir[CATCH_SIZE_CLUSTER/sizeof(U32)];

// File System Parameter
static U32  g_LogicSectorZeroID;
static U32  g_SectorSize;
static U32  g_ClusterSize;
static U32  g_SectorsPerCluster;
static U32  g_DVMTSectorSize;                               // Optimize 'Divid' or 'Multiple' operation with 'Shift' operation
static U32  g_DVMTClusterSize;                              // Optimize 'Divid' or 'Multiple' operation with 'Shift' operation
static U32  g_DVMTSectPerClut;                              // Optimize 'Divid' or 'Multiple' operation with 'Shift' operation
static U32  g_FirstFATSectorID;
static U32  g_FirstDataSectorID;
static U32  g_RootDirSectorID;
static U32  g_RootDirEntryNumber;

static U32  g_CachedSectorID;

/*************************************************************************/
inline void FAT_ShowSysParameter(void)
{
    DBG_TraceHex("Logic 0",             g_LogicSectorZeroID);
//    DBG_TraceHex("Catch ID",            g_CachedSectorID);
//    DBG_TraceHex("Catch FAT",           ((U32)g_CatchFATTableSector));
//    DBG_TraceHex("Catch Clu",           ((U32)g_CatchClusterDir));
//    DBG_TraceHex("Catch Clu",           ((U32)g_CatchClusterFile));
//    DBG_TraceHex("Shift Sec",           g_DVMTSectorSize);
//    DBG_TraceHex("Shift Clu",           g_DVMTClusterSize);
//    DBG_TraceHex("Shift SPC",           g_DVMTSectPerClut);
    DBG_TraceHex("bytes/Sector",        g_SectorSize);
    DBG_TraceHex("bytes/Cluster",       g_ClusterSize);
    DBG_TraceHex("sectors/cluster",     g_SectorsPerCluster);
    DBG_TraceHex("Root Dir Entr Num",   g_RootDirEntryNumber);
    DBG_TraceHex("1st FAT Sector ID",   g_FirstFATSectorID);        DBG_PutChar(' '); DBG_TraceHex(NULL,  g_FirstFATSectorID << g_DVMTSectorSize);
    DBG_TraceHex("RootDIR Sector ID",   g_RootDirSectorID);         DBG_PutChar(' '); DBG_TraceHex(NULL,  g_RootDirSectorID << g_DVMTSectorSize);
    DBG_TraceHex("1st DAT Sector ID",   g_FirstDataSectorID);       DBG_PutChar(' '); DBG_TraceHex(NULL,  g_FirstDataSectorID << g_DVMTSectorSize);

    DBG_BreakPoint(NULL);
}

void FAT_ShowEntryInformation(const PFAT_DIR_DOS_Entry_t pEntry, const PBYTE pLongName)
{
    PFAT_Time_bit_t pMT;
    PFAT_Date_bit_t pMD;
    U32             size;
    char            k;

    if(pEntry->m_dwSize > 1024)
    {
        size = pEntry->m_dwSize >> 10;
        k    = 'K';
    }
    else
    {
        size = pEntry->m_dwSize;
        k    = ' ';
    }

    pMT = (PFAT_Time_bit_t)(&(pEntry->m_wMTime));
    pMD = (PFAT_Date_bit_t)(&(pEntry->m_wMDate));

    DBG_TraceStrLine("");

    DBG_TraceDec(NULL, pMT->m_bHour);                               DBG_PutChar(':');
    DBG_TraceDec(NULL, pMT->m_bMinute);                             DBG_PutChar(':');
    DBG_TraceDec(NULL, pMT->m_bSecond << FAT_TIME_SECOND_SHIFT);    DBG_PutChar(' ');
    DBG_TraceDec(NULL, pMD->m_bYear + FAT_DATE_YEAR_BASE);          DBG_PutChar('-');
    DBG_TraceDec(NULL, pMD->m_bMonth);                              DBG_PutChar('-');
    DBG_TraceDec(NULL, pMD->m_bDay);                                DBG_PutChar(' ');

    (pEntry->m_cAttributes & FAT_ATTR_VOLUME)?                      DBG_PutChar('V') : DBG_PutChar('-');
    (pEntry->m_cAttributes & FAT_ATTR_DIRECTORY)?                   DBG_PutChar('D') : DBG_PutChar('-');
    (pEntry->m_cAttributes & FAT_ATTR_READONLY)?                    DBG_PutChar('R') : DBG_PutChar('-');
    (pEntry->m_cAttributes & FAT_ATTR_HIDDEN)?                      DBG_PutChar('H') : DBG_PutChar('-');
    (pEntry->m_cAttributes & FAT_ATTR_SYSTEM)?                      DBG_PutChar('S') : DBG_PutChar('-');
    (pEntry->m_cAttributes & FAT_ATTR_ARCHIVE)?                     DBG_PutChar('A') : DBG_PutChar('-');

    DBG_PutChar(' ');DBG_TraceDec(NULL, size); DBG_PutChar(k);DBG_PutChar(' ');

    DBG_TraceHex(NULL, pEntry->m_wStartClusterID);

    if(pLongName != NULL) DBG_TraceString(pLongName);
    else for(k=0;k<11;k++) DBG_PutChar(pEntry->m_cName[k]);
}
#if 0
void FAT_ShowHandle(const PFAT_FileHandle_t pHandle)
{
    FAT_ShowEntryInformation(&(pHandle->m_tEntry), NULL);
    DBG_TraceHex("CLU", pHandle->m_dwClusterID);
    DBG_TraceHex("SEC", pHandle->m_dwSectorID);
    DBG_TraceHex("POS", pHandle->m_dwPosition);

    DBG_BreakPoint(NULL);
}
#endif
/*************************************************************************/
#ifdef  FAT_TYPE_FAT16
typedef U16 CLUSTERID_TYPE_t, *PCLUSTERID_TYPE_t;
#define CLUSTERID_TYPE_SIZE_SHIFT       1
#define FAT_CLUST_MASK                  FAT16_MASK
#define FAT_CLUSTER_ID_EOFE             (FAT_CLUST_EOFE & FAT_CLUST_MASK)
#endif

#ifdef  FAT_TYPE_FAT32
typedef U32 CLUSTERID_TYPE_t, *PCLUSTERID_TYPE_t;
#define CLUSTERID_TYPE_SIZE_SHIFT       2
#define FAT_CLUST_MASK                  FAT32_MASK
#define FAT_CLUSTER_ID_EOFE             (FAT_CLUST_EOFE & FAT_CLUST_MASK)
#endif

inline static U32 CatchFATTableSector(U32 dwSectorID)
{
    if (dwSectorID != g_CachedSectorID)
    {
        BLOCK_DEVICE_READ_SECTOR(dwSectorID, (PBYTE)g_CatchFATTableSector, g_SectorSize);
        g_CachedSectorID = dwSectorID;
    }

    return((U32)g_CatchFATTableSector);
}

inline void FAT_CatchFATTableFlush(void)
{
    g_CachedSectorID = 0;
}

static CLUSTERID_TYPE_t NextClusterID(CLUSTERID_TYPE_t tClusterID)
{
    PCLUSTERID_TYPE_t   pBase;
    U32                 secID;
    U32                 offset;
    u32                 index;

    if(tClusterID == FAT_CLUSTER_ID_EOFE) return(tClusterID);

    offset  = ((U32)tClusterID) << CLUSTERID_TYPE_SIZE_SHIFT;           // Equals to : iClusterID *= sizeof(CLUSTERID_TYPE)
    secID   = (offset >> g_DVMTSectorSize) + g_FirstFATSectorID;
    index   = (offset % g_SectorSize) >> CLUSTERID_TYPE_SIZE_SHIFT;     // Equals to : /sizeof(CLUSTERID_TYPE)
    pBase   = (PCLUSTERID_TYPE_t)CatchFATTableSector(secID);

    return(pBase[index]);
}

inline U32 FAT_ClusterID2SectorID(U32 dwClusterID)
{
    // This function is used for normal file and sub dir
    // not for ROOT dir
    if(dwClusterID < FAT_CLUST_FIRST)
    {
        DBG_TraceHex("Error ID", dwClusterID);
//        if(FAT_MSDOSFSROOT == dwClusterID) return(g_RootDirSectorID);
//      else
        DBG_BreakPoint("STOP!");
        return(0);
    }
    return ((dwClusterID - FAT_CLUST_FIRST) << g_DVMTSectPerClut) + g_FirstDataSectorID;
}

/*************************************************************************/

int FAT_CreateHandle(const PFAT_DIR_DOS_Entry_t pEntry, PFAT_FileHandle_t pHandle, PU32 pCatch)
{
    if(pHandle == NULL) return(ERR_CODE_FAT_PARAMETER);

    MemSet((PBYTE)(pHandle), 0, sizeof(FAT_FileHandle_t));

    if((pEntry == NULL) || (FAT_MSDOSFSROOT == pEntry->m_wStartClusterID))
    {   // Root Dir
        pHandle->m_dwClusterID                  = FAT_MSDOSFSROOT;
        pHandle->m_dwSectorID                   = g_RootDirSectorID;
        if(pCatch != NULL) pHandle->m_pdwCatch  = pCatch;
        else               pHandle->m_pdwCatch  = g_CatchClusterDir;

        pHandle->m_tEntry.m_cName[0]            = '/';
        pHandle->m_tEntry.m_cAttributes         = FAT_ATTR_DIRECTORY;
        pHandle->m_tEntry.m_wStartClusterID     = FAT_MSDOSFSROOT;
    }
    else
    {   // Normal File or Sub-Dir
        MemCopy((PBYTE)(&(pHandle->m_tEntry)), (PBYTE)(pEntry), sizeof(FAT_DIR_DOS_Entry_t));

        pHandle->m_dwClusterID  = pEntry->m_wStartClusterID;
        if(pCatch != NULL) pHandle->m_pdwCatch  = pCatch;
        else if(0 != (FAT_ATTR_DIRECTORY & (pHandle->m_tEntry.m_cAttributes)))
        {
            pHandle->m_pdwCatch  = g_CatchClusterDir;
        }
        else
        {
            pHandle->m_pdwCatch  = g_CatchClusterFile;
        }
    }

    return(ERR_CODE_NONE);
}

int FAT_HandleTraverseCluID(const PFAT_FileHandle_t pHandle, BOOL bShowID)
{
    CLUSTERID_TYPE_t cluID, cntID;

    if(pHandle == NULL) return(ERR_CODE_FAT_PARAMETER);

    cluID = (CLUSTERID_TYPE_t) pHandle->m_dwClusterID;
    cntID = cluID;

    while(cluID != FAT_CLUSTER_ID_EOFE)
    {
        if(bShowID) DBG_TraceHex("CID", cluID);

        if(cluID < FAT_CLUST_FIRST)
        {
            pHandle->m_dwClusterID = cluID;
            return(ERR_CODE_FAT_INVALID);
        }

        if(cluID != cntID)
        {
            pHandle->m_dwClusterID = cluID;
            return(ERR_CODE_FAT_CLUID_BREAK);
        }

        cluID = NextClusterID(cluID);
        cntID++;
    }

    return(ERR_CODE_NONE);
}

int FAT_FilePointerForward(PFAT_FileHandle_t pHandle, U32 dwByteCount)
{
    // For system performance, we do not check any parameter here
    // Any functions invoke this function should check the parameter

    // We do not check the file size here, because for the Dir Entry, the file size is zero;
    // This function support FILE and sub DIR, DOES NOT support Root DIR !!!

    CLUSTERID_TYPE_t    cluID;
    U32                 byteCnt, offset;

    offset  = (pHandle->m_dwPosition) % g_ClusterSize;
    byteCnt = dwByteCount + offset;

    if(byteCnt < g_ClusterSize)
    {
        pHandle->m_dwPosition  += dwByteCount;
        return(ERR_CODE_NONE);
    }
    // else
    cluID = (CLUSTERID_TYPE_t)(pHandle->m_dwClusterID);
    while(byteCnt >= g_ClusterSize)
    {
        cluID    = NextClusterID(cluID);
        if(cluID == FAT_CLUSTER_ID_EOFE)
        {
            pHandle->m_dwClusterID  = FAT_CLUSTER_ID_EOFE;
            pHandle->m_dwPosition  += 0;
            return(ERR_CODE_FAT_EOF);
        }

        byteCnt -= g_ClusterSize;
    }
    pHandle->m_dwClusterID  = cluID;
    pHandle->m_dwPosition  += dwByteCount;
    return(ERR_CODE_NONE);
}

int FAT_FileRead(PFAT_FileHandle_t pHandle, PBYTE pBuffer, U32 dwSize)
{
    // This function support FILE and sub DIR, DOES NOT support Root DIR !!!

    CLUSTERID_TYPE_t    cluID;
    U32                 byteCnt, offset;
    int                 err;

    if(
        (pHandle == NULL) || (pBuffer == NULL) || (dwSize == 0)
        )
    {
        return(ERR_CODE_FAT_PARAMETER);
    }
    if(
        (pHandle->m_dwClusterID == FAT_CLUSTER_ID_EOFE)
        )
    {
        return(ERR_CODE_FAT_EOF);
    }

//  FAT_ShowHandle(pHandle);
    offset  = (pHandle->m_dwPosition) % g_ClusterSize;

    if(offset > 0)
    {
        byteCnt = g_ClusterSize - offset;
        if(byteCnt >= dwSize)
        {   // All data here !!!
            MemCopy(pBuffer, ((PBYTE)(pHandle->m_pdwCatch)) + offset, (int)(dwSize));
            return(FAT_FilePointerForward(pHandle, dwSize));
        }
        else
        {
            MemCopy(pBuffer, ((PBYTE)(pHandle->m_pdwCatch)) + offset, (int)(byteCnt));
            if((err = FAT_FilePointerForward(pHandle, byteCnt)) != ERR_CODE_NONE)
            {
                return(err);
            }
            else
            {
                dwSize  -= byteCnt;
                pBuffer += byteCnt;
            }
        }
    }

    byteCnt = dwSize;
    cluID = (CLUSTERID_TYPE_t)(pHandle->m_dwClusterID);
    while(byteCnt >= g_ClusterSize)
    {
        BLOCK_DEVICE_READ_CLUSTER(FAT_ClusterID2SectorID(cluID), pBuffer, g_ClusterSize);

        byteCnt -= g_ClusterSize;
        pBuffer += g_ClusterSize;
        cluID    = NextClusterID(cluID);

        if(cluID == FAT_CLUSTER_ID_EOFE)
        {
            pHandle->m_dwClusterID  = FAT_CLUSTER_ID_EOFE;
            pHandle->m_dwPosition  += 0;

            if(byteCnt > 0) return(ERR_CODE_FAT_EOF);
            else return(ERR_CODE_NONE);
        }
    }
    if(byteCnt > 0)
    {
        BLOCK_DEVICE_READ_CLUSTER(FAT_ClusterID2SectorID(cluID), (PBYTE)(pHandle->m_pdwCatch), g_ClusterSize);
        MemCopy(pBuffer, (PBYTE)(pHandle->m_pdwCatch), byteCnt);
    }
    pHandle->m_dwClusterID  = cluID;
    pHandle->m_dwPosition  += dwSize;

    return(ERR_CODE_NONE);
}

static int DirRootGetNextEntry(PFAT_FileHandle_t pHandle, PBYTE pEntry, U32 dwSizeDummy)
{
    // For system performance, we do not check any parameter here
    // Any functions invoke this function should check the parameter

    U32 offset;

    if(pHandle->m_dwPosition >= (g_RootDirEntryNumber * sizeof(FAT_DIR_DOS_Entry_t))) return(ERR_CODE_FAT_EOF);

    offset  = (pHandle->m_dwPosition) % g_SectorSize;
    pHandle->m_dwPosition += sizeof(FAT_DIR_DOS_Entry_t);

    if(offset > 0)
    {
        if(((pHandle->m_dwPosition) % g_SectorSize) == 0) pHandle->m_dwSectorID++;
        MemCopy(pEntry, ((PBYTE)(pHandle->m_pdwCatch)) + offset, sizeof(FAT_DIR_DOS_Entry_t));
    }
    else
    {
        BLOCK_DEVICE_READ_SECTOR(pHandle->m_dwSectorID, (PBYTE)(pHandle->m_pdwCatch), g_SectorSize);
        MemCopy(pEntry, (PBYTE)(pHandle->m_pdwCatch), sizeof(FAT_DIR_DOS_Entry_t));
    }

    return(ERR_CODE_NONE);
}

int FAT_DirGetNextEntry(PFAT_FileHandle_t pHandle, PFAT_DIR_DOS_Entry_t pEntry, PBYTE pLongName)
{
    int     (*pfGetEntry)(PFAT_FileHandle_t, PBYTE, U32);
    PBYTE   fnbPtr;
    BOOL    longnameflag;
    U32     i;
    PFAT_DIR_WIN_Entry_t we;

//    FAT_ShowHandle(pHandle);

    if(
        (pHandle == NULL) || (pEntry == NULL) ||
        ((pHandle->m_tEntry.m_cAttributes & FAT_ATTR_DIRECTORY) == 0)
        )
    {
        return(ERR_CODE_FAT_PARAMETER);
    }
    if(pHandle->m_dwClusterID == FAT_CLUSTER_ID_EOFE)
    {
        return(ERR_CODE_FAT_EOF);
    }

    if(pHandle->m_dwClusterID == FAT_MSDOSFSROOT)
    {   // Root Dir
        pfGetEntry = DirRootGetNextEntry;
    }
    else pfGetEntry = FAT_FileRead;

    longnameflag = FALSE;
    while(1)
    {
        pfGetEntry(pHandle, (PBYTE)pEntry, sizeof(FAT_DIR_DOS_Entry_t));

        switch(pEntry->m_cName[0])
        {
        case 0x00:      // slot is empty and this is the end of directory
            pHandle->m_dwClusterID = FAT_CLUSTER_ID_EOFE;
            return(ERR_CODE_FAT_EOF);
        case 0xE5:      // slot is deleted, try next
            break;
        default:        // slot is a valid entry
            if(pEntry->m_cAttributes == FAT_ATTR_LONG_FILENAME)
            {
                longnameflag = TRUE;

                if(pLongName != NULL)
                {
                    we = (PFAT_DIR_WIN_Entry_t) pEntry;

                    fnbPtr = pLongName + FAT_WIN_ENTRY_CHARS * ( ((we->weID) & FAT_WIN_WEID_MASK) - 1);
                    for (i=0;i<5;i++)   *fnbPtr++ = we->wePart1[i*2];
                    for (i=0;i<6;i++)   *fnbPtr++ = we->wePart2[i*2];
                    for (i=0;i<2;i++)   *fnbPtr++ = we->wePart3[i*2];
                    if (we->weID & FAT_WIN_WEID_FLAG_LAST) *fnbPtr = '\0';              // in case dirnamelength is multiple of 13, add termination
                }
                // The current entry DOES NOT have file information
                // We shall goto next entry directly here
                continue;
            }
            else if(longnameflag == FALSE)
            {   // The current entry is a short name (8.3 format)
                // And it has correct file information
                if(pLongName != NULL)
                {
                    fnbPtr = pLongName;
                    for (i=0;i<8;i++)   *fnbPtr++ = pEntry->m_cName[i];      // copy name
                    *fnbPtr++ = '.';                                    // insert '.'
                    for (i=0;i<3;i++)   *fnbPtr++ = pEntry->m_cExtension[i]; // copy extension
                    *fnbPtr = 0;                                        // null-terminate
                }
                return(ERR_CODE_NONE);
            }
            else
            {   // The current entry is the Long Name File Entry, but the File Name is 8.3 format compatible
                // It has correct file information
                // And because we support long file name, and we should got the file name already
                // So we do not need to get the 8.3 format file name here
                // The only thing we need to do is just to clear the flag

                // longnameflag = FALSE;
                return(ERR_CODE_NONE);
            }
            break;
        }
    }
}

void FAT_ParseBootSector(PFAT_BootSector710_t pBootSector, PFAT_DiskParameter_t pDiskParameter)
{
    pDiskParameter->m_dwSectorSize           = (U32)MAKEWORD(pBootSector->bpbBytesPerSec[0], pBootSector->bpbBytesPerSec[1]);
    pDiskParameter->m_dwSectorsPerCluster    = (U32)(pBootSector->bpbSecPerClust);
    pDiskParameter->m_dwClusterSize          = pDiskParameter->m_dwSectorSize * pDiskParameter->m_dwSectorsPerCluster;
    pDiskParameter->m_dw1stFATSectorID       = (U32)MAKEWORD(pBootSector->bpbResSectors[0], pBootSector->bpbResSectors[1]);
    pDiskParameter->m_dwRootDirEntryNumber   = (U32)MAKEWORD(pBootSector->bpbRootDirEnts[0], pBootSector->bpbRootDirEnts[1]);
    pDiskParameter->m_dwFATsPerDisk          = pBootSector->bpbFATs;
    pDiskParameter->m_dwSectorsPerFAT        = (U32)MAKEWORD(pBootSector->bpbFATsecs[0], pBootSector->bpbFATsecs[1]);
    if((pDiskParameter->m_dwSectorsPerFAT) == 0)
    {
        pDiskParameter->m_dwSectorsPerFAT = MAKEDWORD(MAKEWORD(pBootSector->bpbBigFATsecs[0], pBootSector->bpbBigFATsecs[1]), MAKEWORD(pBootSector->bpbBigFATsecs[2], pBootSector->bpbBigFATsecs[3]));
    }

    pDiskParameter->m_dwFATSize          = pDiskParameter->m_dwSectorsPerFAT * pDiskParameter->m_dwSectorSize;
    pDiskParameter->m_dwRootDirSectorID  = pDiskParameter->m_dwFATsPerDisk * pDiskParameter->m_dwSectorsPerFAT + pDiskParameter->m_dw1stFATSectorID;
    pDiskParameter->m_dw1stDATSectorID   = pDiskParameter->m_dwRootDirSectorID + ((pDiskParameter->m_dwRootDirEntryNumber * sizeof(FAT_DIR_DOS_Entry_t)) / pDiskParameter->m_dwSectorSize);
}

int FAT_Initial(FAT_BlockRead_t pReadSector, FAT_BlockRead_t pReadCluster)
{
    PFAT_BootSector710_t    pBootSec;
    U32                     tmp;
    char*                   pStr;
    FAT_DiskParameter_t     para;

    g_pfReadSector  = pReadSector;
    g_pfReadCluster = pReadCluster;

    pBootSec = (PFAT_BootSector710_t)g_CatchFATTableSector;

    DBG_TraceStrLine("Search BPB ... \r\n");
#define INITIAL_SEARCH_ID_MAX           250
    for(g_LogicSectorZeroID=0;g_LogicSectorZeroID<INITIAL_SEARCH_ID_MAX;g_LogicSectorZeroID++)
    {
        BLOCK_DEVICE_READ_SECTOR(g_LogicSectorZeroID, (PBYTE)pBootSec, sizeof(FAT_BootSector710_t) );
        if(
            ( (pBootSec->bsJump[0] == 0xE9) || ((pBootSec->bsJump[0] == 0xEB) && (pBootSec->bsJump[2] == 0x90)) ) &&
            ( (pBootSec->bsBootSectSig0 == 0x55) && (pBootSec->bsBootSectSig1 == 0xAA) )
            )
        {
            pBootSec->bpbDummy[11] = '\0';
            pStr = strstr(pBootSec->bpbDummy, "FAT");
            if(pStr == NULL)
            {
                pBootSec->bsExtBPB[25] = '\0';
                pStr = strstr(pBootSec->bsExtBPB + 16, "FAT");
                if (pStr == NULL) continue;
            }

            pStr[5] = '\0';

            break;
        }
    }
    if(g_LogicSectorZeroID >= INITIAL_SEARCH_ID_MAX)
    {
        DBG_TraceMem("Sect", pBootSec, 8);
        DBG_TraceMem("Dummy", pBootSec->bpbDummy, 5);
        return(ERR_CODE_FAT_NOFOUND);
    }

    DBG_TraceStrLine(pBootSec->bsOEMName); DBG_TraceString("  "); DBG_TraceString(pStr);

    FAT_ParseBootSector(pBootSec, &para);

    g_SectorSize         = para.m_dwSectorSize;
    g_SectorsPerCluster  = para.m_dwSectorsPerCluster;
    g_ClusterSize        = para.m_dwClusterSize;
    g_FirstFATSectorID   = para.m_dw1stFATSectorID;
    g_RootDirEntryNumber = para.m_dwRootDirEntryNumber;
    g_RootDirSectorID    = para.m_dwRootDirSectorID;
    g_FirstDataSectorID  = para.m_dw1stDATSectorID;

    if( (g_SectorSize > CATCH_SIZE_FATTABLE) || (g_ClusterSize > CATCH_SIZE_CLUSTER) || (g_SectorSize != sizeof(FAT_BootSector710_t)))
    {
        DBG_TraceStrLine("Not support!");
        DBG_TraceDec("Sec Size", g_SectorSize);
        DBG_TraceDec("Clu Size", g_ClusterSize);
        return(ERR_CODE_FAT_INVALID);
    }

    for(g_DVMTSectorSize = 8;;g_DVMTSectorSize++)
    {
        if((g_SectorSize>>g_DVMTSectorSize) == 1) break;
    }
    for(g_DVMTClusterSize = g_DVMTSectorSize;;g_DVMTClusterSize++)
    {
        if((g_ClusterSize>>g_DVMTClusterSize) == 1) break;
    }
    for(g_DVMTSectPerClut = 0;;g_DVMTSectPerClut++)
    {
        if((g_SectorsPerCluster>>g_DVMTSectPerClut) == 1) break;
    }

    FAT_CatchFATTableFlush();

    g_FirstFATSectorID  += g_LogicSectorZeroID;
    g_FirstDataSectorID += g_LogicSectorZeroID;
    g_RootDirSectorID   += g_LogicSectorZeroID;

    return(ERR_CODE_NONE);
}

#endif

