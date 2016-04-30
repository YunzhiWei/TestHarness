
//*****************************************************************************
// Refer to AVR lib

#define     INCLUDE_MODULE_FAT

// Some useful cluster numbers
#define     FAT_MSDOSFSROOT             0                   // cluster 0 means the root dir
#define     FAT_CLUST_FREE              0                   // cluster 0 also means a free cluster
#define     FAT_MSDOSFSFREE             FAT_CLUST_FREE
#define     FAT_CLUST_FIRST             2                   // first legal cluster number
#define     FAT_CLUST_RSRVD             0xfffffff6          // reserved cluster range
#define     FAT_CLUST_BAD               0xfffffff7          // a cluster with a defect
#define     FAT_CLUST_EOFS              0xfffffff8          // start of eof cluster range
#define     FAT_CLUST_EOFE              0xffffffff          // end of eof cluster range

#define     FAT12_MASK                  0x00000fff          // mask for 12 bit cluster numbers
#define     FAT16_MASK                  0x0000ffff          // mask for 16 bit cluster numbers
#define     FAT32_MASK                  0x0fffffff          // mask for FAT32 cluster numbers

typedef struct {
    BYTE    bsJump[3];                                      // [00][00] jump inst E9xxxx or EBxx90
    CHAR    bsOEMName[8];                                   // [03][03] OEM name and version

//  BPB for DOS 7.10 (FAT32).                               // BIOS parameter block
//  CHAR    bsBPB[53];
    // DOS 3.3
    BYTE    bpbBytesPerSec[2];                              // [11][0B] bytes per sector
    BYTE    bpbSecPerClust;                                 // [13][0D] sectors per cluster
    BYTE    bpbResSectors[2];                               // [14][0E] number of reserved sectors
    BYTE    bpbFATs;                                        // [16][10] number of FATs
    BYTE    bpbRootDirEnts[2];                              // [17][11] number of root directory entries
    BYTE    bpbSectors[2];                                  // [19][13] total number of sectors
    BYTE    bpbMedia;                                       // [21][15] media descriptor
    BYTE    bpbFATsecs[2];                                  // [22][16] number of sectors per FAT
    BYTE    bpbSecPerTrack[2];                              // [24][18] sectors per track
    BYTE    bpbHeads[2];                                    // [26][1A] number of heads
    BYTE    bpbHiddenSecs[4];                               // [28][1C] # of hidden sectors
    // DOS 5.0
    BYTE    bpbHugeSectors[4];                              // [32][20] # of sectors if bpbSectors == 0
    // DOS 7.1
    BYTE    bpbBigFATsecs[4];                               // [36][24] like bpbFATsecs for FAT32
    BYTE    bpbExtFlags[2];                                 // [40][28] extended flags:
    BYTE    bpbFSVers[2];                                   // [42][2A] filesystem version
    BYTE    bpbRootClust[4];                                // [44][2C] start cluster for root directory
    BYTE    bpbFSInfo[2];                                   // [48][30] filesystem info structure sector
    BYTE    bpbBackup[2];                                   // [50][32] backup boot sector
    BYTE    bpbDummy[12];                                   // [52][34] 12 bytes filled here to make BPB structure is 53 bytes
//  End of BPB

    CHAR    bsExtBPB[26];                                   // [64][40] Bootsector Extension
    CHAR    bsBootCode[418];                                // pad so structure is 512b
    BYTE    bsBootSectSig2;                                 // 2 & 3 are only defined for FAT32?
    BYTE    bsBootSectSig3;
    BYTE    bsBootSectSig0;                                 // boot sector signature byte 0x55
    BYTE    bsBootSectSig1;                                 // boot sector signature byte 0xAA
}FAT_BootSector710_t, *PFAT_BootSector710_t;
#define     FAT_BOOTSIG0                0x55
#define     FAT_BOOTSIG1                0xaa
#define     FAT_BOOTSIG2                0
#define     FAT_BOOTSIG3                0

// Structure of a DOS directory entry.
#define     FAT_SLOT_EMPTY              0x00                // slot has never been used
#define     FAT_SLOT_E5                 0x05                // the real value is 0xE5
#define     FAT_SLOT_DELETED            0xE5                // file in this slot deleted

#define     FAT_ATTR_NORMAL             0x00                // normal file
#define     FAT_ATTR_READONLY           0x01                // file is readonly
#define     FAT_ATTR_HIDDEN             0x02                // file is hidden
#define     FAT_ATTR_SYSTEM             0x04                // file is a system file
#define     FAT_ATTR_VOLUME             0x08                // entry is a volume label
#define     FAT_ATTR_LONG_FILENAME      0x0F                // this is a long filename entry
#define     FAT_ATTR_DIRECTORY          0x10                // entry is a directory name
#define     FAT_ATTR_ARCHIVE            0x20                // file is new or modified

#define     FAT_LCASE_BASE              0x08                // filename base in lower case
#define     FAT_LCASE_EXT               0x10                // filename extension in lower case

typedef struct {
    // [00][00]
    BYTE    m_cName[8];                                     // filename, blank filled
    BYTE    m_cExtension[3];                                // extension, blank filled
    BYTE    m_cAttributes;                                  // file attributes
    // [12][0C]
    BYTE    m_cLowerCase;                                   // NT VFAT lower case flags  (set to zero)
    BYTE    m_cCHundredth;                                  // hundredth of seconds in CTime
    // [14][0E]
    WORD    m_wCTime;                                       // create time
    // [16][10]
    WORD    m_wCDate;                                       // create date
    // [18][12]
    WORD    m_wADate;                                       // access date
    // [20][14]
    WORD    m_wHighClust;                                   // high bytes of cluster number
    // [22][16]
    WORD    m_wMTime;                                       // last update time
    // [24][18]
    WORD    m_wMDate;                                       // last update date
    // [26][1A]
    WORD    m_wStartClusterID;                              // starting cluster of file
    // [28][1C]
    DWORD   m_dwSize;                                   // size of file in bytes
}FAT_DIR_DOS_Entry_t, *PFAT_DIR_DOS_Entry_t;

#define     FAT_TIME_SECOND_SHIFT       1
typedef struct{
    WORD    m_bSecond: 5;                                   // seconds divided by 2
    WORD    m_bMinute: 6;
    WORD    m_bHour:   5;
}FAT_Time_bit_t, *PFAT_Time_bit_t;

#define     FAT_DATE_YEAR_BASE          1980
typedef struct{
    WORD    m_bDay:    5;
    WORD    m_bMonth:  4;
    WORD    m_bYear:   7;                                   // Year - 1980
}FAT_Date_bit_t, *PFAT_Date_bit_t;


// Structure of a VFAT (Long File Name support) directory entry
// Maximum filename length in Win95
// Note: Must be < sizeof(dirent.d_name)
#define     FAT_WIN_NAME_MAXLEN         255
#define     FAT_WIN_ENTRY_CHARS         13                  // Number of chars per winentry
#define     FAT_WIN_WEID_FLAG_LAST      0x40
#define     FAT_WIN_WEID_MASK           0x3f
#define     FAT_ATTR_WIN95              0x0f
typedef struct {
    BYTE    weID;                                           // Entry Flag & Entry ID
    BYTE    wePart1[10];                                    // Last 5 characters in this entry
    BYTE    weAttributes;
    BYTE    weReserved1;
    BYTE    weChksum;
    BYTE    wePart2[12];                                    // Middle 6 characters in this entry
    BYTE    weReserved2[2];
    BYTE    wePart3[4];                                     // First 2 characters in this entry
}FAT_DIR_WIN_Entry_t, *PFAT_DIR_WIN_Entry_t;;

typedef struct {
    FAT_DIR_DOS_Entry_t m_tEntry;
    U32                 m_dwSectorID;                       // For FAT16 Root Dir use only (ClusterID == 0)
    U32                 m_dwClusterID;
    U32                 m_dwPosition;
    PU32                m_pdwCatch;
}FAT_FileHandle_t, *PFAT_FileHandle_t;

typedef struct {
    U32  m_dwSectorSize;

    U32  m_dwSectorsPerCluster;
    U32  m_dwClusterSize;

    U32  m_dwFATsPerDisk;
    U32  m_dwSectorsPerFAT;
    U32  m_dwFATSize;

    U32  m_dw1stFATSectorID;
    U32  m_dw1stDATSectorID;
    U32  m_dwRootDirSectorID;

    U32  m_dwRootDirEntryNumber;
}FAT_DiskParameter_t, *PFAT_DiskParameter_t;

typedef void (*FAT_BlockRead_t)(U32, PBYTE, U32);

inline void FAT_ShowSysParameter(void);
void        FAT_ShowEntryInformation(const PFAT_DIR_DOS_Entry_t pEntry, const PBYTE pLongName);
inline void FAT_CatchFATTableFlush(void);
inline U32  FAT_ClusterID2SectorID(U32 dwClusterID);

int         FAT_CreateHandle(const PFAT_DIR_DOS_Entry_t pEntry, PFAT_FileHandle_t pHandle, PU32 pCatch);
int         FAT_HandleTraverseCluID(const PFAT_FileHandle_t pHandle, BOOL bShowID);
int         FAT_FilePointerForward(PFAT_FileHandle_t pHandle, U32 dwByteCount);
int         FAT_FileRead(PFAT_FileHandle_t pHandle, PBYTE pBuffer, U32 dwSize);
int         FAT_DirGetNextEntry(PFAT_FileHandle_t pHandle, PFAT_DIR_DOS_Entry_t pEntry, PBYTE pLongName);
void        FAT_ParseBootSector(PFAT_BootSector710_t pBootSector, PFAT_DiskParameter_t pDiskParameter);
int         FAT_Initial(FAT_BlockRead_t pReadSector, FAT_BlockRead_t pReadCluster);

