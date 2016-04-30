
#include "_Platform.h"

#ifdef INCLUDE_MODULE_BAD_BLOCK_MANAGER
/*

    Caution:

    1. If the sector does not contain a valid Table, Nand_ReadSector will return ERR_CODE_NAND_DBERR!!!

*/

#define BBM_SECTOR_NUMBER_PER_BLOCK               (NAND_BLOCK_SIZE/NAND_SECTOR_SIZE)
#define BBM_BLOCK_NUMBER_IN_TOTAL                 (NAND_TOTAL_SIZE/NAND_BLOCK_SIZE)

#define BBM_RESERVED_BLOCKID_MAX                  (BBM_BLOCK_NUMBER_IN_TOTAL - 1)

#define BBM_RELOCTABLE_STORAGE_POS_SECTORID_MAX   (BBM_SECTOR_NUMBER_PER_BLOCK - 1)
#define BBM_RELOCTABLE_STORAGE_POS_SECTORID_MIN   (BBM_RELOCTABLE_STORAGE_POS_SECTORID_MAX - BBM_NUMBER_RESERVED_SECTORS_FOR_TABLE + 1)
#define BBM_RELOCTABLE_STORAGE_POS_BLOCKID        0

#define BBM_RELOCTABLE_HEADER_FLAG                0x524E

#define RELOCATE_ITEM_INVALID_FLAG                0
#define TABLE_POS_SECTOR_INVALID_FLAG             0

static RelocateTable_T bbm_tRelocateTable;
static U32 bbm_dwNextValidSectorID4Table;

// First function needs to be invoked
static int BBM_FindRelocateTable(void)
{
    int err;
    U32 secID;

    bbm_dwNextValidSectorID4Table = TABLE_POS_SECTOR_INVALID_FLAG;

    for(secID = BBM_RELOCTABLE_STORAGE_POS_SECTORID_MIN;secID <= BBM_RELOCTABLE_STORAGE_POS_SECTORID_MAX;secID++)
    {
        err = Nand_ReadSector(BBM_RELOCTABLE_STORAGE_POS_BLOCKID, secID, (U32*)(&bbm_tRelocateTable), NULL);
//      If the sector does not contain a valid Table, return ERROR_CODE will be ERR_CODE_NAND_DBERR
//      DBG_TraceStrLine("["); DBG_TraceHex(NULL, secID); DBG_TraceString("] "); DBG_TraceHex(NULL, r);

        if(ERR_CODE_NONE != err)
        {
            continue;
        }

        if(bbm_tRelocateTable.m_wHeaderFlag == BBM_RELOCTABLE_HEADER_FLAG)
        {
            if(secID != BBM_RELOCTABLE_STORAGE_POS_SECTORID_MIN)
            {
                bbm_dwNextValidSectorID4Table = secID - 1;
            }

            return(ERR_CODE_SUCCESS);
        }
    }

    return(ERR_CODE_BBM_NOFOUND);
}

// BBM_FindRelocateTable must be invoked and success
static int BBM_CheckRelocateTable(void)
{
    U32 i, blockID;

    if(bbm_tRelocateTable.m_wHeaderFlag != BBM_RELOCTABLE_HEADER_FLAG)
    {
        return(ERR_CODE_BBM_NOFOUND);
    }

    if(bbm_tRelocateTable.m_wRelocItemCount > BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE)
    {
        DBG_TraceDec("Unexpected Item Count", bbm_tRelocateTable.m_wRelocItemCount);
        return(ERR_CODE_BBM_PARAMETER);
    }

    for( blockID = BBM_RESERVED_BLOCKID_MAX, i=0;
         i<bbm_tRelocateTable.m_wRelocItemCount;
         blockID--, i++)
    {
        if(blockID != bbm_tRelocateTable.m_tRelocateItem[i].m_wPhysicalID)
        {
            DBG_TraceStrLine("Unexpected Block ID");
            return(ERR_CODE_BBM_PARAMETER);
        }
    }

    return(ERR_CODE_SUCCESS);
}

U32 BBM_QueryPhysicalBlockID(U32 dwLogicalBlockID)
{
    U32 i;

//    DBG_TraceStrLine("BBM_QueryPhysicalBlockID +");

    if(dwLogicalBlockID == 0) return(dwLogicalBlockID);

    for(i=0;i < bbm_tRelocateTable.m_wRelocItemCount;i++)
    {
        if(bbm_tRelocateTable.m_tRelocateItem[i].m_wLogicID == dwLogicalBlockID)
        {
//            DBG_TraceHex("BBM_QueryPhysicalBlockID - #", bbm_tRelocateTable.m_tRelocateItem[i].m_wPhysicalID);
            return(bbm_tRelocateTable.m_tRelocateItem[i].m_wPhysicalID);
        }
    }

//    DBG_TraceHex("BBM_QueryPhysicalBlockID - :", dwLogicalBlockID);
    return(dwLogicalBlockID);
}

int BBM_Init(void)
{
    int err;

//  DBG_TraceStrLine("BBM @ " __DATE__ " " __TIME__);

    if((err = BBM_FindRelocateTable()) != ERR_CODE_SUCCESS)
    {
        DBG_BreakPoint("BBM_FindRelocateTable");
        return(err);
    }

    if((err = BBM_CheckRelocateTable()) != ERR_CODE_SUCCESS)
    {
        DBG_BreakPoint("BBM_CheckRelocateTable");
        return(err);
    }

    return(ERR_CODE_SUCCESS);
}

void BBM_GetRelocationTable(PRelocateTable_t pTable)
{
    MemCopy((PBYTE)pTable, (PBYTE)(&bbm_tRelocateTable), sizeof(RelocateTable_T));
}

static int BBM_RelocateTableAppend(U32 dwLogicalBlock)
{
    long i;

    if(bbm_tRelocateTable.m_wRelocItemCount >= BBM_NUMBER_RESERVED_BLOCKS_FOR_RELOCATE)
    {
        DBG_BreakPoint("BBM_RelocateTableAppend");

        return(ERR_CODE_BBM_APPEND_FAIL);
    }

    // Append the new record at the end of array.

    i = bbm_tRelocateTable.m_wRelocItemCount;

    bbm_tRelocateTable.m_tRelocateItem[i].m_wLogicID    = dwLogicalBlock;
    bbm_tRelocateTable.m_tRelocateItem[i].m_wPhysicalID = BBM_RESERVED_BLOCKID_MAX - i;
    bbm_tRelocateTable.m_wRelocItemCount++;

    // If the logic was broken before, update the record.

    for(i--;i>=0;i--)
    {
        if(dwLogicalBlock == bbm_tRelocateTable.m_tRelocateItem[i].m_wLogicID)
        {
            DBG_TraceStrLine("Reserved Block broken!");

            bbm_tRelocateTable.m_tRelocateItem[i].m_wLogicID = RELOCATE_ITEM_INVALID_FLAG;
        }
    }

    return(ERR_CODE_SUCCESS);
}

static int BBM_RelocateTableWriteBack(void)
{
    int err;

    if(bbm_dwNextValidSectorID4Table < BBM_RELOCTABLE_STORAGE_POS_SECTORID_MIN)
    {
        return(ERR_CODE_BBM_WR_BACK_FAIL);
    }

    if(ERR_CODE_NONE != (err = Nand_WriteSector(BBM_RELOCTABLE_STORAGE_POS_BLOCKID, bbm_dwNextValidSectorID4Table, (U32*)(&bbm_tRelocateTable), NULL)))
    {
        DBG_TraceStrLine("Nand_WriteSector FAIL");
        return(err);
    }

    bbm_dwNextValidSectorID4Table--;

    return(ERR_CODE_SUCCESS);
}

int BBM_UpdateTableOnBadBlock(U32 dwLogicalBlock)
{
    int err;

    if((err = BBM_RelocateTableAppend(dwLogicalBlock)) != ERR_CODE_SUCCESS)
    {
        DBG_BreakPoint("BBM_RelocateTableAppend");
        return(err);
    }

    if((err = BBM_RelocateTableWriteBack()) != ERR_CODE_SUCCESS)
    {
        DBG_BreakPoint("BBM_RelocateTableWriteBack");
        return(err);
    }

    return(ERR_CODE_SUCCESS);
}

#endif //INCLUDE_MODULE_BAD_BLOCK_MANAGER

