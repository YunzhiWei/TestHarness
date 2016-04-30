/*

*/

#include "_Platform.h"

#ifdef INCLUDE_MODULE_UDSK

#define U2D_EP1_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP2_BUF_SIZE                U2D_EPD_BUF_SIZE

#define UDSK_DEBUG_TRACE_HANDLE

#ifdef UDSK_DEBUG_TRACE_HANDLE
#define DBG_UDSK_RESET                  DBG_PutChar('R');
#define DBG_UDSK_GETMAXLUN              DBG_PutChar('M');

#define DBG_UDSK_CBW_WRITE              //DBG_PutChar('w');
#define DBG_UDSK_CBW_READ               //DBG_PutChar('r');
#define DBG_UDSK_CBW_INQUIRY            DBG_PutChar('i');
#define DBG_UDSK_CBW_READCAP            DBG_PutChar('c');
#define DBG_UDSK_CBW_READFMTCAP         DBG_PutChar('f');
#define DBG_UDSK_CBW_REQUESTSENSE       DBG_PutChar('s');
#define DBG_UDSK_CBW_SCSIMODESENSE      DBG_PutChar('m');
#define DBG_UDSK_CBW_TESTUNITREADY      //DBG_PutChar('t');
#define DBG_UDSK_CBW_VERIFY             DBG_PutChar('v');
#define DBG_UDSK_CBW_MEDIUMREMOVAL      DBG_PutChar('-');
#define DBG_UDSK_CBW_STARTSTOP          DBG_PutChar('|');
#else
#define DBG_UDSK_GETMAXLUN

#define DBG_UDSK_CBW_WRITE
#define DBG_UDSK_CBW_READ
#define DBG_UDSK_CBW_INQUIRY
#define DBG_UDSK_CBW_READCAP
#define DBG_UDSK_CBW_READFMTCAP
#define DBG_UDSK_CBW_REQUESTSENSE
#define DBG_UDSK_CBW_SCSIMODESENSE
#define DBG_UDSK_CBW_TESTUNITREADY
#define DBG_UDSK_CBW_VERIFY
#define DBG_UDSK_CBW_MEDIUMREMOVAL
#define DBG_UDSK_CBW_STARTSTOP
#endif

/*
*/

// USB Disk
#define USB_DISK_BASE                   BUFFER_RAM_DISK_BASE
#define USB_DISK_SIZE                   BUFFER_RAM_DISK_SIZE
#define USB_DISK_SECTOR_SIZE            512
#define USB_DISK_LAST_SECTOR_NUMBER     (USB_DISK_SIZE/USB_DISK_SECTOR_SIZE) - 1

typedef USB_BulkOnlyMassStorage_CBW_t   BOMS_CBW_t __attribute__ ((aligned (4)));
static BOMS_CBW_t                       g_CBW;

static const DeviceDescriptor_t g_DeviceDescriptor = {
    USB_DESCRIPTOR_LENGTH_DEVICE,
    USB_DESCRIPTOR_TYPE_DEVICE,

    USB_DEV_DESC_VERSION_11,

    0x00, 0x00, 0x00,

    U2D_EP0_BUF_SIZE,

    USB_DEV_DESC_VID_STD_DISK,
    USB_DEV_DESC_PID_STD_DISK,

    0,
    0x00, 0x00, 0x00,
    0x01
};

typedef struct __attribute__ ((packed)){
    USB_ConfigDescriptor_t  m_Config;
    USB_FullInterfaceDisk_t m_Interface;
}FullConfigureDescriptor_t __attribute__ ((aligned (4)));

static const FullConfigureDescriptor_t g_FullConfigDescriptor = {
    {
        USB_DESCRIPTOR_LENGTH_CONFIG,
        USB_DESCRIPTOR_TYPE_CONFIG,

        sizeof(FullConfigureDescriptor_t),

        0x01,
        0x01,
        0x00,
        0xC0,

        0 * USB_CNFG_DESC_MAX_POWER_UNIT_2mA
    },
    {
        {
            USB_DESCRIPTOR_LENGTH_INTERFACE,
            USB_DESCRIPTOR_TYPE_INTERFACE,

            0x00, 0x00,

            0x02,
            USB_CNFG_DESC_CLASS_PROTOCOL_STD_DISK,
            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(1) | USB_ENDP_DESC_ADDR_IN, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP1_BUF_SIZE,

            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(2) | USB_ENDP_DESC_ADDR_OUT, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP2_BUF_SIZE,

            0x00
        }
    }
};

/*
*/

static void UDSK_CSWGood(U32 dwLen)
{
    static U32 cswGoodMsg[] = {USB_BOMS_CSW_SIGNATURE, 0, 0, 0};
    cswGoodMsg[1] = g_CBW.m_dwTag;
    cswGoodMsg[2] = dwLen;
    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cswGoodMsg), 13);
}

static void UDSK_CBWOnInquiry(void)
{
#define VENDOR_NAME_P1                  0x64726942          // 'Bird'
#define VENDOR_NAME_P2                  0x20202020
#define PRODUCT_NAME_P1                 0x70797247          // 'Gryp'
#define PRODUCT_NAME_P2                 0x20737568          // 'hus '
#define PRODUCT_NAME_P3                 0x20534D20          // ' MS '
#define PRODUCT_NAME_P4                 0x205A5957          // 'WYZ '
#define PRODUCT_NAME_P5                 0x30303130          // revision '0100'

    const static U32 cbwInquiry[] = {
        0x02028000, 0x0000001F,
        // vendor
        VENDOR_NAME_P1, VENDOR_NAME_P2,
        // product
        PRODUCT_NAME_P1, PRODUCT_NAME_P2, PRODUCT_NAME_P3, PRODUCT_NAME_P4, PRODUCT_NAME_P5
    };

    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cbwInquiry), 36);
    UDSK_CSWGood(0);

#undef VENDOR_NAME_P1
#undef VENDOR_NAME_P2
#undef PRODUCT_NAME_P1
#undef PRODUCT_NAME_P2
#undef PRODUCT_NAME_P3
#undef PRODUCT_NAME_P4
#undef PRODUCT_NAME_P5
}

static void UDSK_CBWOnReadFmtCapacity(U32 dwLen)
{
    const static U32 cbwFmtCap[] = {
        0x08000000, 0x00100000, 0x00020001
    };

    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cbwFmtCap), 12);
    UDSK_CSWGood(dwLen - 12);
}

static void UDSK_CBWOnReadCapacity(void)
{
    const static U32 cbwCap[] = {
        REVERSEDWORD(USB_DISK_LAST_SECTOR_NUMBER),
        REVERSEDWORD(USB_DISK_SECTOR_SIZE)
    };

    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cbwCap), 8);
    UDSK_CSWGood(0);
}

static void UDSK_CBWOnModeSense(U32 dwLen)
{
    const static U32 cbwModeSense[] = {0x00000003};

    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cbwModeSense), 4);
    UDSK_CSWGood(dwLen - 4);
}

static void UDSK_CBWOnRequestSense(void)
{
    const static U32 cbwReqSense[] = {0x00050070, 0x0C000000, 0x00000000, 0x00000020, 0x00000000};

    U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, (U32)(cbwReqSense), 18);
    UDSK_CSWGood(0);
}

inline static void UDSK_CBWOnRead(U32 dwSectIndex, U32 dwSectNum)
{   // PC read from USB Disk
    U32 sectAddr;
#if USB_DISK_SECTOR_SIZE != U2D_EP1_BUF_SIZE
    U32 dataSize;
    dataSize = dwSectNum * USB_DISK_SECTOR_SIZE;
#endif
    sectAddr = dwSectIndex * USB_DISK_SECTOR_SIZE + USB_DISK_BASE;

#if USB_DISK_SECTOR_SIZE != U2D_EP1_BUF_SIZE
    while(dataSize >= U2D_EP1_BUF_SIZE)
#else
    while(dwSectNum-- > 0)
#endif
    {
        U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, sectAddr, U2D_EP1_BUF_SIZE);
        sectAddr += U2D_EP1_BUF_SIZE;
#if USB_DISK_SECTOR_SIZE == U2D_EP1_BUF_SIZE
    }
#else
        dataSize -= U2D_EP1_BUF_SIZE;
    }
    if(dataSize > 0)
    {
        DBG_PutChar('R');
        U2D_EPxDMAFIFOWrite(UDSK_EP_INDEX_BULK_IN, sectAddr, dataSize);
    }
#endif
    UDSK_CSWGood(0);
}

inline static void UDSK_CBWOnWrite(U32 dwSectIndex, U32 dwSectNum)
{   // PC write to USB Disk
    U32 sectAddr;
#if USB_DISK_SECTOR_SIZE != U2D_EP2_BUF_SIZE
    U32 dataSize;
    dataSize = dwSectNum * USB_DISK_SECTOR_SIZE;
#endif
    sectAddr = dwSectIndex * USB_DISK_SECTOR_SIZE + USB_DISK_BASE;

#if USB_DISK_SECTOR_SIZE != U2D_EP2_BUF_SIZE
    while(dataSize >= U2D_EP2_BUF_SIZE)
#else
    while(dwSectNum-- > 0)
#endif
    {
        U2D_EPxDMAFIFORead(UDSK_EP_INDEX_BULK_OUT, sectAddr, U2D_EP2_BUF_SIZE);
        sectAddr += U2D_EP2_BUF_SIZE;
#if USB_DISK_SECTOR_SIZE == U2D_EP2_BUF_SIZE
    }
#else
        dataSize -= U2D_EP2_BUF_SIZE;
    }
    if(dataSize > 0)
    {
        DBG_PutChar('W');
        U2D_EPxDMAFIFORead(UDSK_EP_INDEX_BULK_OUT, sectAddr, dataSize);
    }
#endif
    UDSK_CSWGood(0);
}

void USB_OnOutPkgCompleteUDSK(void)
{
    U2D_EPxDMAFIFORead(UDSK_EP_INDEX_BULK_OUT, (U32)(&g_CBW), sizeof(g_CBW));

    if(g_CBW.m_dwSignature == USB_BOMS_CBW_SIGNATURE)
    {
        U32 m, n;

        switch(g_CBW.m_bCB[0])
        {
        case CBWCB_OPCODE_WRITE:
            DBG_UDSK_CBW_WRITE;
            m = MAKEDWORD(MAKEWORD(g_CBW.m_bCB[5], g_CBW.m_bCB[4]), MAKEWORD(g_CBW.m_bCB[3], g_CBW.m_bCB[2]));
            n = MAKEDWORD(MAKEWORD(g_CBW.m_bCB[8], g_CBW.m_bCB[7]), 0);
            UDSK_CBWOnWrite(m, n);
            break;
        case CBWCB_OPCODE_READ:
            DBG_UDSK_CBW_READ;
            m = MAKEDWORD(MAKEWORD(g_CBW.m_bCB[5], g_CBW.m_bCB[4]), MAKEWORD(g_CBW.m_bCB[3], g_CBW.m_bCB[2]));
            n = MAKEDWORD(MAKEWORD(g_CBW.m_bCB[8], g_CBW.m_bCB[7]), 0);
            UDSK_CBWOnRead(m, n);
            break;
        case CBWCB_OPCODE_INQUIRY:
            DBG_UDSK_CBW_INQUIRY;
            UDSK_CBWOnInquiry();
            break;
        case CBWCB_OPCODE_READCAPACITY:
            DBG_UDSK_CBW_READCAP;
            UDSK_CBWOnReadCapacity();
            break;
        case CBWCB_OPCODE_READFORMATCAPACITY:
            DBG_UDSK_CBW_READFMTCAP;
            UDSK_CBWOnReadFmtCapacity(g_CBW.m_bCB[8]);
            break;
        case CBWCB_OPCODE_REQUESTSENSE:
            DBG_UDSK_CBW_REQUESTSENSE;
            UDSK_CBWOnRequestSense();
            break;
        case CBWCB_OPCODE_SCSIMODESENSE:
            DBG_UDSK_CBW_SCSIMODESENSE;
            UDSK_CBWOnModeSense(g_CBW.m_bCB[4]);
            break;
        case CBWCB_OPCODE_TESTUNITREADY:
/*
            USB host will often test USB client by this command.
*/
            DBG_UDSK_CBW_TESTUNITREADY;
            UDSK_CSWGood(0);
            break;
        case CBWCB_OPCODE_VERIFY:
/*
            This command is not found
*/
            DBG_UDSK_CBW_VERIFY;
            UDSK_CSWGood(0);
            break;
        case CBWCB_OPCODE_PREVENTALLOWMEDIUMREMOVAL:
/*
            Some time USB host will send out this command.
            When USB disk is ejected, USB host will also send this command.
            Not clear the usage.
*/
            DBG_UDSK_CBW_MEDIUMREMOVAL;
            UDSK_CSWGood(0);
            break;
        case CBWCB_OPCODE_STARTSTOP:
/*
            When USB disk is ejected.
*/
            DBG_UDSK_CBW_STARTSTOP;
            UDSK_CSWGood(0);
            SetEvent(MAIN_EVENT_U2D_STARTSTOP);
            break;
        default:
//          DBG_TraceHex("Length", m);
            DBG_TraceMem("ERR: CBW", &g_CBW, 8);
            break;
        }
    }
    else
    {
        DBG_TraceString("Not CBW");
    }
}

static void OnGetMaxLun(StandardRequest_t *pRequest)
{
    const static U32 maxlun[] = {0};

    if(pRequest->wLength == 1)
    {
        U2D_EP0FIFOWrite(maxlun, 1);
    }
    else
    {
        DBG_TraceStrLine("ERR: GetMaxLun");
    }
}

void USB_EP0PkgUnknownUDSK(StandardRequest_t *pRequest)
{
    if(
        (pRequest->bmRequestType == (USB_bmRequestType_DIR_IN | USB_bmRequestType_CLASS | USB_bmRequestType_TARGET_INTERFACE))
        && (pRequest->bRequest == USB_bRequest_BOMS_GET_MAX_LUN)
        )
    {
        DBG_UDSK_GETMAXLUN;
        OnGetMaxLun(pRequest);
    }
    else if(
        (pRequest->bmRequestType == (USB_bmRequestType_DIR_OUT | USB_bmRequestType_CLASS | USB_bmRequestType_TARGET_INTERFACE))
        && (pRequest->bRequest == USB_bRequest_BOMS_RESET)
        )
    {
        DBG_UDSK_RESET;
    }
    else U2D_DumpStdRequest(pRequest);
}

void USB_DiskInitial(void)
{
    DBG_TraceDec("SIZE", sizeof(g_CBW));

    U2D_Initial(
        &g_DeviceDescriptor,
        (ConfigDescriptor_t *)(&g_FullConfigDescriptor),
        USB_EP0PkgUnknownUDSK
        );

    U2D_InitialEndPoint(UDSK_EP_INDEX_BULK_IN,  U2DEN_EN(1) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP1_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP1_BUF_SIZE, NULL);
    U2D_InitialEndPoint(UDSK_EP_INDEX_BULK_OUT, U2DEN_EN(2) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP2_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP2_BUF_SIZE, USB_OnOutPkgCompleteUDSK);

    U2D_InitCheck();
}

#endif //INCLUDE_MODULE_UDSK

