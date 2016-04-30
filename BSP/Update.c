
#include "_Platform.h"

#ifdef INCLUDE_MODULE_UPDATE

static int UPD_UpdateNTIM(U32 dwSize)
{
    U32 ntim[NAND_SECTOR_SIZE/sizeof(U32)];
    U32 table[NAND_SECTOR_SIZE/sizeof(U32)];
    U32 r;
    OEM_SectorInfo_t secInfor;

    DBG_TraceStrLine("UPD_UpdateNTIM +");

    if(sizeof(NTIM_Image) > NAND_SECTOR_SIZE)
    {
        return(ERR_CODE_UPD_INVALID);
    }

    BBM_GetRelocationTable((PRelocateTable_t)table);

    if((r = Nand_ReadSector(UPD_STORE_POS_BLOCK_ID_NTIM, UPD_STORE_POS_SECTOR_ID_NTIM, ntim, NULL)) != ERR_CODE_NONE)
    {
        DBG_TraceHex("Read NTIM", r);
        return(r);
    }

    {
        PNTIM_Image p;
        p = (PNTIM_Image)ntim;
        p->m_Sections[1].m_dwImageSize = dwSize;
    }

    if((r = Flash_EraseBlock(UPD_STORE_POS_BLOCK_ID_NTIM)) != ERR_CODE_SUCCESS)
    {
        DBG_TraceHex("EraseBlock", r);
        return(r);
    }

    if((r = Nand_WriteSector(UPD_STORE_POS_BLOCK_ID_TABLE, UPD_STORE_POS_SECTOR_ID_TABLE, table, NULL)) != ERR_CODE_NONE)
    {
        DBG_TraceHex("Write Table", r);
        return(r);
    }

    FAL_OEMFormat(&secInfor, NULL);
    if((r = Nand_WriteSector(UPD_STORE_POS_BLOCK_ID_NTIM, UPD_STORE_POS_SECTOR_ID_NTIM, ntim, &secInfor)) != ERR_CODE_NONE)
    {
        DBG_TraceHex("Write NTIM", r);
        return(r);
    }

    DBG_TraceStrLine("UPD_UpdateNTIM -");
    return(ERR_CODE_SUCCESS);
}

int UPD_UpdateImage(U32 dwBlockID, U32 dwBufferAddress, U32 dwSize)
{
#define IMAGE_PLATFORM_NAME_PT_ADDR     0x20

    int err;
    U32 size;
    PBYTE pB;

    pB   = (PBYTE)dwBufferAddress;
    size = dwSize;

    if(dwBlockID == UPD_STORE_POS_BLOCK_ID_MOBM)
    {   // If it is MOBM, NTIM shall be update also
        {
            extern const U8 g_PlatformName[];
            PU32 addr;

            // Get the Platform Name in the new Image
            addr = (PU32)(dwBufferAddress + IMAGE_PLATFORM_NAME_PT_ADDR);
            addr = (PU32)((*addr) - RUNTIME_PROGRAM_BASE + dwBufferAddress);

            if(0 != StrCompare((const char *)g_PlatformName, (const char *)addr))
            {
                MY_TraceStrLine("Platform not match!");
                MY_TraceStrLine((PU8)addr);
                MY_TraceStrLine((PU8)g_PlatformName);
                return(ERR_CODE_UPD_PARAMETER);
            }
        }

        if((dwSize >= NAND_BLOCK_SIZE))
        {
            return(ERR_CODE_UPD_PARAMETER);
        }
    }
    if(size == 0) return(ERR_CODE_UPD_PARAMETER);

    DBG_TraceStrLine("Update...");DBG_TraceStrLine("");
    while(size > 0)
    {
        DBG_TraceString("\r");
        DBG_TraceDec(NULL, dwBlockID);

        if((err = Flash_EraseBlock(dwBlockID)) != ERR_CODE_SUCCESS)           return(err);
        if((err = Flash_WriteBlock(dwBlockID, (PU32)pB)) != ERR_CODE_SUCCESS) return(err);

        if(size <= NAND_BLOCK_SIZE)
        {
            break;
        }
        // else
        dwBlockID++;
        size -= NAND_BLOCK_SIZE;
        pB   += NAND_BLOCK_SIZE;
    }
    DBG_TraceString("Done");

    if(
        (dwBlockID == UPD_STORE_POS_BLOCK_ID_MOBM) &&
        (err == ERR_CODE_SUCCESS)
        )
    {
        DBG_TraceHex("SIZE", dwSize);
        return(UPD_UpdateNTIM(dwSize));
    }
    else
    {
        return(err);
    }
}

int UPD_LoadImage(U32 dwBlockID, U32 dwBufferAddress, U32 dwSize)
{
    int err;
    PBYTE pB;

    pB = (PBYTE)dwBufferAddress;

    while(dwSize > 0)
    {
        if((err = Flash_ReadBlock(dwBlockID, (PU32)pB)) != ERR_CODE_SUCCESS)
        {
//            DBG_TraceHex("UPD_LoadImage -", r);
            return(err);
        }

        if(dwSize <= NAND_BLOCK_SIZE) break;

        dwBlockID++;
        dwSize -= NAND_BLOCK_SIZE;
        pB     += NAND_BLOCK_SIZE;
    }

    return(err);
}

inline static int EraseAll(U32 dwStartID)
{
    int err;

    for(;dwStartID <= FLASH_BLOCK_ID_MAX;dwStartID++)
    {
        if((err = Flash_EraseBlock(dwStartID)) != ERR_CODE_SUCCESS) return(err);
    }

    return(err);
}

typedef struct{
    U32 m_dwAddr;
    U32 m_dwSize;
    U32 m_dwCheckSum;
}BIN_Record_t, *PBIN_Record_t;

#define BINFILE_FAL_RECORD_SIZE         (NAND_BLOCK_SIZE + NAND_SECTOR_NUMBER_PER_BLOCK * sizeof(FAL_SectorInfo_t))
#define BINFILE_HEADER_SIZE             8
#define BINFILE_SIGNATURE_SIZE          7
#define EXTFILE_SIGNATURE_SIZE          (BINFILE_SIGNATURE_SIZE + 9)

inline static int BinRecordWrite(U32 dwDataAddr)
{
    // dwDataAddr must be align with 4!!!

#define BIN_FILE_REC_SEC_SIZE           (NAND_SECTOR_SIZE + sizeof(FAL_SectorInfo_t))

    PBIN_Record_t pRec;
    U32 i, sum;
    int err;
    U32 blkID, pID, secID;
    OEM_SectorInfo_t secInfor;
    MY_PutChar('.');

    {   // Check Record Header
        pRec = (PBIN_Record_t)dwDataAddr;
        dwDataAddr += sizeof(BIN_Record_t);

        if(
            (0 == pRec->m_dwAddr) &&
            (0 == pRec->m_dwCheckSum)
            )
        {   // File End
            return(ERR_CODE_DONE);
        }
        if(BINFILE_FAL_RECORD_SIZE != pRec->m_dwSize)
        {
            DBG_TraceHex("Unexpected Size!!!", pRec->m_dwSize);
            DBG_TraceMem("pRec", pRec, 8);
            return(ERR_CODE_UPD_BINREC_INVALID);
        }
#if 0
        sum  = MemSum((PBYTE)dwDataAddr, pRec->m_dwSize, 0);
        if(sum != pRec->m_dwCheckSum)
        {
            DBG_TraceHex("Checksum Error!!!", sum);
            DBG_TraceMem("pRec", pRec, 8);
            DBG_TraceMem("data", dwDataAddr, 8);
            return(ERR_CODE_UPD_BINREC_CHKSUM);
        }
#endif
        blkID = (pRec->m_dwAddr) / BINFILE_FAL_RECORD_SIZE;
    }

    // Logic ID to Physical ID
    pID = BBM_QueryPhysicalBlockID(blkID);

    // Physical Sector Write
    for(secID = 0;secID < NAND_SECTOR_NUMBER_PER_BLOCK;secID++, dwDataAddr += BIN_FILE_REC_SEC_SIZE)
    {
        if(ERR_CODE_FAL_NORMAL != (err = FAL_OEMFormat(&secInfor, (PFAL_SectorInfo_t)(dwDataAddr + NAND_SECTOR_SIZE))))
        {
            PU32 p;

            switch(err)
            {
            case ERR_CODE_FAL_FFFFFFFF:

                p = (PU32)dwDataAddr;

                for(i=0;i < (NAND_SECTOR_SIZE/sizeof(U32));i++)
                {
                    if(p[i] != 0xFFFFFFFF)
                    {
                        MY_PutChar('?');
//                        DBG_TraceMem("NONE", (PBYTE)dwDataAddr, 16);
                        break;
                    }
                }
                if(i < (NAND_SECTOR_SIZE/sizeof(U32)) )
                {   // Do not know why, in some case, the Block Spare is FFFFFFFF but the data is not
                    if((err = Nand_WriteSector(pID, secID, (U32*)dwDataAddr, NULL)) != ERR_CODE_NONE)
                    {
                        DBG_BreakPoint("GOD!");
                        return(err);
                    }
                }
                break;
            case ERR_CODE_FAL_INVALID:
                DBG_TraceDec("BID", pID);
                DBG_TraceDec("SID", secID);
                DBG_TraceHex("MYF", i);
                DBG_TraceMem("DAT", (PBYTE)(dwDataAddr), 8);
                DBG_TraceMem("INV", (PBYTE)(dwDataAddr + NAND_SECTOR_SIZE), 8);
                break;
            default:
                DBG_BreakPoint("??Format");
                break;
            }
            continue;
        }

        if((err = Nand_WriteSector(pID, secID, (U32*)dwDataAddr, &secInfor)) != ERR_CODE_NONE)
        {
            DBG_TraceDec("Error @#", pID);
            DBG_TraceDec("#", secID);
            ErrCodeDisplay(err);
            DBG_BreakPoint(NULL);
            return(err);
        }
    }

    return((int)blkID);
}

inline static void RAMFileRead(PU32 pFilePointer, PU8 *pBuffer, U32 dwSize)
{
    *pBuffer       = (PU8)(*pFilePointer);
    *pFilePointer += dwSize;
}

int UPD_BurnFileEXT(U32 dwBlockID, U32 dwFilePointer, U32 dwSize)
{
    PU8 pSignature;
    PU8 pBuffer;

    int err;
    U32 eofAddr;

    eofAddr = dwFilePointer + dwSize;

    DBG_TraceHex("START", dwFilePointer);
//  DBG_TraceHex("SIZE ", dwSize);
//  DBG_TraceHex("STOP ", eofAddr);
//  DBG_BreakPoint(NULL);

    RAMFileRead(&dwFilePointer, &pSignature, EXTFILE_SIGNATURE_SIZE);
    pSignature[EXTFILE_SIGNATURE_SIZE - 1] = '\0';
    MY_TraceStrLine(pSignature);

    RAMFileRead(&dwFilePointer, &pBuffer, BINFILE_HEADER_SIZE);

    DBG_TraceDec("Erase from ", dwBlockID);
    if(ERR_CODE_NONE == (err = EraseAll(dwBlockID))) DBG_TraceString(" Done!");
    else { ErrCodeDisplay(err); return(err); }

    MY_TraceStrLine("Writing ");
    while(dwFilePointer < eofAddr)
    {
        RAMFileRead(&dwFilePointer, &pBuffer, BINFILE_FAL_RECORD_SIZE + sizeof(BIN_Record_t));

        err = BinRecordWrite((U32)pBuffer);
        if(err == ERR_CODE_DONE) return(err);
        else if(err < ERR_CODE_DONE)
        {
            ErrCodeDisplay(err);
            DBG_BreakPoint(NULL);
            return(err);
        }
    }

    MY_TraceStrLine("Done!");

    return(ERR_CODE_SUCCESS);
}

int UPD_BurnFileBIN(U32 dwBlockID, PFAT_FileHandle_t pHandle, U32 dwSize)
{
    U8 signature[BINFILE_SIGNATURE_SIZE + 1];
    PU8 pBuffer;
    int err;

    pBuffer = (PU8)BUFFER_SHARED_UNION_BASE;

    FAT_FileRead(pHandle, signature, BINFILE_SIGNATURE_SIZE);
    signature[BINFILE_SIGNATURE_SIZE - 1] = '\0';
    MY_TraceStrLine(signature);

    FAT_FileRead(pHandle, pBuffer, BINFILE_HEADER_SIZE);

    DBG_TraceDec("Erase from ", dwBlockID);
    if(ERR_CODE_NONE == (err = EraseAll(dwBlockID))) DBG_TraceString(" Done!");
    else { ErrCodeDisplay(err); return(err); }

    MY_TraceStrLine("Writing ");
    while(ERR_CODE_NONE == FAT_FileRead(pHandle, pBuffer, BINFILE_FAL_RECORD_SIZE + sizeof(BIN_Record_t)))
    {
        err = BinRecordWrite((U32)pBuffer);
        if(err == ERR_CODE_DONE) return(err);
        else if(err < ERR_CODE_DONE)
        {
            ErrCodeDisplay(err);
            DBG_BreakPoint(NULL);
            return(err);
        }
    }

    MY_TraceStrLine("Done!");

    return(ERR_CODE_SUCCESS);
}

int UPD_BurnFileRAWDATA(U32 dwBlockID, PFAT_FileHandle_t pHandle, U32 dwSize)
{
    int err;

    if(dwSize > BUFFER_SHARED_UNION_SIZE)
    {
        MY_TraceStrLine("File size > buffer size!");
        return(ERR_CODE_UPD_BINREC_INVALID);
    }

    err = FAT_FileRead(pHandle, (PU8)BUFFER_SHARED_UNION_BASE, dwSize);
    if((ERR_CODE_NONE != err) && ((ERR_CODE_FAT_EOF != err)))
    {
        return(err);
    }

    return(UPD_UpdateImage(dwBlockID, BUFFER_SHARED_UNION_BASE, dwSize));
}

#endif

