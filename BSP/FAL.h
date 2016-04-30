
#define INCLUDE_MODULE_FAL

/*
    FAL Sector Information & OEM Sector Information
*/

#define FAL_OEM_RESERVE_RESERVED        (1 << 0)
#define FAL_OEM_RESERVE_READONLY        (1 << 1)

#define FAL_RESERVE2_FREE               (0xFFFF)
#define FAL_RESERVE2_DIRTY              (1 << 0)
#define FAL_RESERVE2_WRITE_IN_PROGRESS  (1 << 1)
#define FAL_RESERVE2_WRITE_COMPLETE     (1 << 2)
#define FAL_RESERVE2_COMPACT_IN_PROGRESS (1 << 3)
#define FAL_RESERVE2_COMPACT_COMPLETE    (1 << 4)

typedef struct{
  DWORD m_dwReserved1;
  BYTE  m_bOEMReserved;
  BYTE  m_bBadBlock;
  WORD  m_wReserved2;
} FAL_SectorInfo_t, *PFAL_SectorInfo_t __attribute__ ((aligned (4)));
#define FAL_SECTORINFO_SIZE             (sizeof(FAL_SectorInfo_t))
#define FAL_OEM_RESERVED_FLAG           {0, ~(FAL_OEM_RESERVE_RESERVED | FAL_OEM_RESERVE_READONLY), (BYTE)(-1), 0}
#define FAL_BADBLOCK_FLAG               (-1)

#define FAL_DIRTY_BIT_FIELD_SIZE        (NAND_SECTOR_NUMBER_PER_BLOCK / 8)
typedef struct{
  WORD  m_wBadBlock16;
  BYTE  m_bOEMReserved;
  BYTE  m_bReserved2Lo;
  BYTE  m_bReserved2Hi;
  BYTE  m_bBadBlock8;
  WORD  m_wReserved1Lo;
  WORD  m_wReserved1Hi;
  BYTE  m_bDirtyBit[FAL_DIRTY_BIT_FIELD_SIZE];
  WORD  m_wDummy;
} OEM_SectorInfo_t, *POEM_SectorInfo_t __attribute__ ((aligned (4)));

// {0xFF, 0xFE, 0xFC, 0, 0, 0xFF, 0, 0, 0, 0, 0xFE, 0xFF};    // OEM Reserve

int FAL_OEMFormat(POEM_SectorInfo_t pTarget, const PFAL_SectorInfo_t pSource);

