
#include "_type.h"

typedef struct
{
    U32 m_dwVersion;
    U8  m_cIdentifier[4];
    U32 m_dwTrusted;
    U32 m_dwIssueDate;
    U32 m_dwOEMUniqueID;

    U32 m_dwReserved1[5];

    U32 m_dwBootFlashSign;

    U32 m_dwSectionNumber;

    U32 m_dwReserved2;

    U32 m_dwSizeofReserved;

}NTIM_Header;

typedef struct
{
    U8  m_cImageID[4];
    U8  m_cNextImageID[4];
    U32 m_dwNANDSourceAddr;
    U32 m_dwTargetAddr;
    U32 m_dwImageSize;

    U32 m_dwReserved1[10];
}NTIM_Section;

typedef struct
{
    NTIM_Header m_NTIMHeader;
    NTIM_Section m_Sections[2];
}NTIM_Image, *PNTIM_Image;

