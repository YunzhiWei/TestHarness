#ifdef INCLUDE_MODULE_NAND
#define INCLUDE_MODULE_BAD_BLOCK_MANAGER

#define BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE   (NAND_BADBLOCK_NUMBER_MAX)
#define BBM_NUMBER_RESERVED_SECTORS_FOR_TABLE     BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE

typedef struct
{
    U16 m_wLogicID;
    U16 m_wPhysicalID;
}RelocateItem_T __attribute__ ((aligned (4)));

typedef struct
{
    U16 m_wHeaderFlag;
    U16 m_wRelocItemCount;
    RelocateItem_T m_tRelocateItem[BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE];

    // The size of RelocateTable_t must be smaller than sector size. So, add dummy here
    U8  dummy[NAND_SECTOR_SIZE - sizeof(U16) - sizeof(U16) - (sizeof(RelocateItem_T) * BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE)];
}RelocateTable_T, *PRelocateTable_t __attribute__ ((aligned (4)));

U32 BBM_QueryPhysicalBlockID(U32 dwLogicalBlockID);
void BBM_GetRelocationTable(PRelocateTable_t pTable);
int BBM_UpdateTableOnBadBlock(U32 dwLogicalBlock);
int BBM_Init(void);

#endif //INCLUDE_MODULE_NAND

