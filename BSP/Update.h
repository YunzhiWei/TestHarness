#ifdef INCLUDE_MODULE_FLASH
#ifdef INCLUDE_MODULE_FAL
#define INCLUDE_MODULE_UPDATE

int UPD_UpdateImage(U32 dwBlockID, U32 dwBufferAddress, U32 dwSize);
int UPD_LoadImage(U32 dwBlockID, U32 dwBufferAddress, U32 dwSize);
int UPD_BurnFileBIN(U32 dwBlockID, PFAT_FileHandle_t pHandle, U32 dwSize);
int UPD_BurnFileEXT(U32 dwBlockID, U32 dwDataAddr, U32 dwSize);
int UPD_BurnFileRAWDATA(U32 dwBlockID, PFAT_FileHandle_t pHandle, U32 dwSize);

#endif //INCLUDE_MODULE_FAL
#endif //INCLUDE_MODULE_FLASH

