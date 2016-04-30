
#define INCLUDE_MODULE_NAND

void Nand_ControllerInit(void);

int Nand_GetID(U32 *pdwID);
int Nand_GetStatus(U32 *pdwStatus);
int Nand_ReadSector(U32 dwPhysicalBlockID, U32 dwSectorID, U32 *pdwData, U32 *pdwSpare);
int Nand_WriteSector(U32 dwPhysicalBlockID, U32 dwSectorID, U32 *pdwData, POEM_SectorInfo_t pOEMSecInfo);
int Nand_EraseBlock(U32 dwPhysicalBlockNumber);

