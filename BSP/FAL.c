
#include "_platform.h"

#ifdef INCLUDE_MODULE_FAL

int FAL_OEMFormat(POEM_SectorInfo_t pTarget, PFAL_SectorInfo_t pSource)
{
    const FAL_SectorInfo_t oemReserve = FAL_OEM_RESERVED_FLAG;
    int   err;

    err = ERR_CODE_FAL_NORMAL;

    if(pSource == NULL)
    {
        err = ERR_CODE_FAL_RESERVE;
        pSource = (PFAL_SectorInfo_t)(&oemReserve);
    }
    else
    {
        if(pSource->m_dwReserved1 == 0xFFFFFFFF)
        {
            MemSet((PBYTE)pTarget, 0xFF, sizeof(OEM_SectorInfo_t));
            return(ERR_CODE_FAL_FFFFFFFF);
        }

        if(
            (pSource->m_bBadBlock != ((U8)FAL_BADBLOCK_FLAG)) ||
            ((~(pSource->m_wReserved2) & FAL_RESERVE2_DIRTY))
            )
        {
            err = ERR_CODE_FAL_INVALID;
        }

        pSource->m_wReserved2 &= ~ FAL_RESERVE2_WRITE_IN_PROGRESS;
    }

    MemSet(pTarget->m_bDirtyBit, 0xFF, FAL_DIRTY_BIT_FIELD_SIZE);
    pTarget->m_wDummy       = 0xFFFF;

    pTarget->m_wBadBlock16  = pSource->m_bBadBlock | 0xFE00;// Just follow the current stupid rule (in BSP & EBoot) !!! ???
    pTarget->m_bBadBlock8   = pSource->m_bBadBlock;
    pTarget->m_bOEMReserved = pSource->m_bOEMReserved;

    pTarget->m_wReserved1Lo = LOWORD(pSource->m_dwReserved1);
    pTarget->m_wReserved1Hi = HIWORD(pSource->m_dwReserved1);
    pTarget->m_bReserved2Lo = LOBYTE(pSource->m_wReserved2);
    pTarget->m_bReserved2Hi = HIBYTE(pSource->m_wReserved2);

    return(err);
}
#if 0
void FAL_BlockSparePrepare(U32 *pTarget, PFAL_SectorInfo_t pFALSecInfo)
{
    PBYTE pT;
    U32   i;

    pT = (PBYTE)pTarget;

    MemSet(pT, 0xFF, NAND_SPARE_SIZE_PER_BLOCK);

    for(i=0;i < NAND_SECTOR_NUMBER_PER_BLOCK;i++)
    {
        FAL_OEMFormat((POEM_SectorInfo_t)(pT), pFALSecInfo);

        pT += NAND_SPAREAREA_SIZE;
        if(pFALSecInfo != NULL) pFALSecInfo++;
    }
}
#endif

#endif

