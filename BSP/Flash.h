#ifdef INCLUDE_MODULE_NAND
#ifdef INCLUDE_MODULE_BAD_BLOCK_MANAGER
#define INCLUDE_MODULE_FLASH

#define FLASH_BLOCK_ID_MAX                          (NAND_BLOCK_NUMBER_IN_TOTAL - NAND_BADBLOCK_NUMBER_MAX - 1)

int Flash_ReadBlock(U32 dwLogicalBlockID, U32 *pdwData);
int Flash_WriteBlock(U32 dwLogicalBlockID, U32 *pdwData);
int Flash_EraseBlock(U32 dwLogicalBlockID);

#endif //INCLUDE_MODULE_BAD_BLOCK_MANAGER
#endif //INCLUDE_MODULE_NAND

