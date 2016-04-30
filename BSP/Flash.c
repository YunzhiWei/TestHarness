#include "_platform.h"

#ifdef INCLUDE_MODULE_FLASH

#define FLASH_SECTOR_NUMBER_PER_BLOCK   (NAND_SECTOR_NUMBER_PER_BLOCK)
#define FLASH_BLOCK_NUMBER_IN_TOTAL     (NAND_BLOCK_NUMBER_IN_TOTAL)

#define FLASH_RETRY_TIME                NAND_BADBLOCK_NUMBER_MAX

int Flash_ReadBlock(U32 dwLogicalBlockID, U32 *pdwData)
{
    int err, i;
    U32 blkID, secID;
    PU8 pData;

    pData  = (PU8)pdwData;
    blkID  = BBM_QueryPhysicalBlockID(dwLogicalBlockID);

    for(i = FLASH_RETRY_TIME; i > 0; i--)
    {
        for(secID = 0;secID < NAND_SECTOR_NUMBER_PER_BLOCK;secID++)
        {
            if((err = Nand_ReadSector(blkID, secID, (U32*)pData, NULL)) != ERR_CODE_NONE)
            {
                DBG_TraceHex("Read Error @#", secID);
                ErrCodeDisplay(err);
                DBG_BreakPoint(NULL);
                break;
#if 0
                if((r != ERR_CODE_NAND_SBERR) && (r != ERR_CODE_NAND_DBERR))
                {   // We want the whole block data, so we ignore the sector Single bit or Double bit error.
                    break;
                }
#endif
            }
            pData += NAND_SECTOR_SIZE;
        }

        switch(err)
        {
        case ERR_CODE_NONE:
        case ERR_CODE_NAND_PARAMETER:
        case ERR_CODE_NAND_TIMEOUT:
            return(err);
        case ERR_CODE_NAND_BADBLOCK:
        case ERR_CODE_NAND_DBERR:
        case ERR_CODE_NAND_SBERR:
            DBG_BreakPoint("Flash_ReadBlock");

//          I don't think it is neccesary to Update Relocate Table when READ error hanppen.
///           if((r = BBM_UpdateTableOnBadBlock(dwLogicalBlock)) != ERR_CODE_SUCCESS)
            {
                return(err);
            }
            break;
        default:
            return(ERR_CODE_FLASH_INVALID);
        }
    }

    return(ERR_CODE_FLASH_FAIL);
}

int Flash_WriteBlock(U32 dwLogicalBlockID, U32 *pdwData)
{
    int err, i;
    U32 blkID, secID;
    PU8 pData;
    OEM_SectorInfo_t secInfor;

    pData = (PU8)pdwData;
    blkID = BBM_QueryPhysicalBlockID(dwLogicalBlockID);
    FAL_OEMFormat(&secInfor, NULL);

    for(i = FLASH_RETRY_TIME; i > 0; i--)
    {
        for(secID = 0;secID < NAND_SECTOR_NUMBER_PER_BLOCK;secID++)
        {
            if((err = Nand_WriteSector(blkID, secID, (U32*)pData, &secInfor)) != ERR_CODE_NONE)
            {
                DBG_TraceHex("Write Error @#", secID);
                ErrCodeDisplay(err);
                DBG_BreakPoint(NULL);
                break;
            }
            pData += NAND_SECTOR_SIZE;
        }

        switch(err)
        {
        case ERR_CODE_NONE:
        case ERR_CODE_NAND_PARAMETER:
        case ERR_CODE_NAND_TIMEOUT:
            return(err);
        case ERR_CODE_NAND_BADBLOCK:
        case ERR_CODE_NAND_DBERR:
        case ERR_CODE_NAND_SBERR:
            DBG_BreakPoint("UpdateTableOnBadBlock");

            if((err = BBM_UpdateTableOnBadBlock(dwLogicalBlockID)) != ERR_CODE_SUCCESS)
            {
                return(err);
            }
            break;
        default:
            return(ERR_CODE_FLASH_INVALID);
        }
    }

    return(ERR_CODE_FLASH_FAIL);
}

int Flash_EraseBlock(U32 dwLogicalBlockID)
{
    int err, i;

//    DBG_TraceStrLine("Flash_EraseBlock +");

    for(i = FLASH_RETRY_TIME; i > 0; i--)
    {
        err = Nand_EraseBlock(BBM_QueryPhysicalBlockID(dwLogicalBlockID));
//        DBG_TraceHex("CmdErase", r);

        switch(err)
        {
        case ERR_CODE_NONE:
        case ERR_CODE_NAND_PARAMETER:
        case ERR_CODE_NAND_TIMEOUT:
            return(err);
        case ERR_CODE_NAND_BADBLOCK:
        case ERR_CODE_NAND_DBERR:
        case ERR_CODE_NAND_SBERR:
            DBG_BreakPoint("Flash_EraseBlock");

            if((err = BBM_UpdateTableOnBadBlock(dwLogicalBlockID)) != ERR_CODE_SUCCESS)
            {
                return(err);
            }
            break;
        default:
            return(ERR_CODE_FLASH_INVALID);
        }
    }

//    DBG_TraceStrLine("Flash_EraseBlock -");

    return(ERR_CODE_FLASH_FAIL);
}

#endif //INCLUDE_MODULE_FLASH

