
#ifdef  INCLUDE_MODULE_FAT
#define INCLUDE_MODULE_FSYS
#endif

typedef void (*PCallBackTraverseDir_t)(U32);
typedef void (*PCallBackTraverseFile_t)(PBYTE, U32);

typedef enum {
    FS_DISK_RAM      = 0,
    FS_DISK_SD       = 1,
    FS_DISK_INVALID
}FS_Disk_ID_t;

void FILE_Test(void);

int FS_Initial(FS_Disk_ID_t tID);
void FS_AutoBatch(FS_Disk_ID_t tID);


