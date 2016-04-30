
#define INCLUDE_MODULE_RAMDISK

U32  RMD_SectorAddress(U32 dwSecID);
void RMD_SectorRead(U32 dwSecID, PBYTE pBuffer, U32 dwSize);
void RMD_Format(void);

