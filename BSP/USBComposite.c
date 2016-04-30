/*

*/

#include "_Platform.h"

#ifdef INCLUDE_MODULE_COMPOSITE

#define U2D_EP1_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP2_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP3_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP4_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP5_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP6_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP7_BUF_SIZE                U2D_EPD_BUF_SIZE

#define COMPOSITE_DEBUG_TRACE_HANDLE

#ifdef COMPOSITE_DEBUG_TRACE_HANDLE
#else
#endif

/*
*/

static const DeviceDescriptor_t g_DeviceDescriptor = {
    USB_DESCRIPTOR_LENGTH_DEVICE,
    USB_DESCRIPTOR_TYPE_DEVICE,

    USB_DEV_DESC_VERSION_20,

    0x00, 0x00, 0x00,

    U2D_EP0_BUF_SIZE,

    USB_DEV_DESC_VID_MS_COMPOSITE,
    USB_DEV_DESC_PID_MS_COMPOSITE,

    0,
    0x00, 0x00, 0x00,
    0x01
};

typedef struct{
    USB_ConfigDescriptor_t    m_Config;
    USB_FullInterfaceSerial_t m_InterfaceSerial;
    USB_FullInterfaceDisk_t   m_InterfaceUDisk;
    USB_FullInterfaceMSSync_t m_InterfaceMSSync;
}FullConfigureDescriptor_t __attribute__ ((aligned (4)));

static const FullConfigureDescriptor_t g_FullConfigDescriptor = {
    {
        USB_DESCRIPTOR_LENGTH_CONFIG,
        USB_DESCRIPTOR_TYPE_CONFIG,

        sizeof(FullConfigureDescriptor_t),

        0x03,
        0x01,
        0x00,
        0x00,

        50 * USB_CNFG_DESC_MAX_POWER_UNIT_2mA,
    },
    {
        {
            USB_DESCRIPTOR_LENGTH_INTERFACE,
            USB_DESCRIPTOR_TYPE_INTERFACE,

            0x00, 0x00,

            0x03,
            USB_CNFG_DESC_CLASS_PROTOCOL_SERIAL,
            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_HEADERFUNC,
            USB_DESCRIPTOR_TYPE_CS_INTERFACE,
            USB_DESCRIPTOR_TYPE_CS_SUB_HEADER,
            0x0110
        },
        {
            USB_DESCRIPTOR_LENGTH_CALLMNG,
            USB_DESCRIPTOR_TYPE_CS_INTERFACE,
            USB_DESCRIPTOR_TYPE_CS_SUB_CALLMNG,
            0x00, //bmCapabilities
            0x00 //bDataInterface= no data interface for call management
        },
        {
            USB_DESCRIPTOR_LENGTH_ACM,
            USB_DESCRIPTOR_TYPE_CS_INTERFACE,
            USB_DESCRIPTOR_TYPE_CS_SUB_ACMMNG,
            0x02 //bmCapabilities,support Set_Line_Coding|Set_Control_Line_State|Get_Line_Coding|Serial_State
        },
        {
            USB_DESCRIPTOR_LENGTH_UNION,
            USB_DESCRIPTOR_TYPE_CS_INTERFACE,
            USB_DESCRIPTOR_TYPE_CS_SUB_UNION,
            0x00, //MasterInterface
            0x01 //SlaveInterface
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
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(3) | USB_ENDP_DESC_ADDR_IN, USB_ENDP_DESC_ATTR_INT,
            U2D_EP3_BUF_SIZE ,

            0x0A
        }
    },
    {
        {
            USB_DESCRIPTOR_LENGTH_INTERFACE,
            USB_DESCRIPTOR_TYPE_INTERFACE,

            0x01, 0x00,

            0x02,
            USB_CNFG_DESC_CLASS_PROTOCOL_STD_DISK,
            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(4) | USB_ENDP_DESC_ADDR_IN, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP4_BUF_SIZE,

            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(5) | USB_ENDP_DESC_ADDR_OUT, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP5_BUF_SIZE,

            0x00
        }
    },
    {
        {
            USB_DESCRIPTOR_LENGTH_INTERFACE,
            USB_DESCRIPTOR_TYPE_INTERFACE,

            0x02, 0x00,

            0x02,
            USB_CNFG_DESC_CLASS_PROTOCOL_UNKNOWN,
            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(6) | USB_ENDP_DESC_ADDR_IN, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP6_BUF_SIZE,

            0x00
        },
        {
            USB_DESCRIPTOR_LENGTH_ENDPOINT,
            USB_DESCRIPTOR_TYPE_ENDPOINT,

            USB_ENDP_DESC_ADDR_ID(7) | USB_ENDP_DESC_ADDR_OUT, USB_ENDP_DESC_ATTR_BULK,
            U2D_EP7_BUF_SIZE,

            0x00
        }
    }
};

/*
*/

void CPST_EP0OnPackageUnknown(StandardRequest_t *pRequest)
{
    U16 interfaceID;

    interfaceID = pRequest->wIndex;

    if(interfaceID == 0)      USB_EP0PkgUnknownSerial(pRequest);
    else if(interfaceID == 1) USB_EP0PkgUnknownUDSK(pRequest);
    else U2D_DumpStdRequest(pRequest);
}

void USB_CompositeInitial(void)
{
    U2D_Initial(
        &g_DeviceDescriptor,
        (ConfigDescriptor_t *)(&g_FullConfigDescriptor),
        CPST_EP0OnPackageUnknown
        );

    U2D_InitialEndPoint(SERIAL_EP_INDEX_BULK_IN,  U2DEN_EN(1) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP1_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP1_BUF_SIZE, NULL);
    U2D_InitialEndPoint(SERIAL_EP_INDEX_BULK_OUT, U2DEN_EN(2) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP2_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP2_BUF_SIZE, USB_OnOutPkgCompleteSerial);
    U2D_InitialEndPoint(SERIAL_EP_INDEX_INT_IN,   U2DEN_EN(3) | U2DEN_ET(ET_INT) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP3_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP3_BUF_SIZE, NULL);

    U2D_InitialEndPoint(UDSK_EP_INDEX_BULK_IN,    U2DEN_EN(4) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP4_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP4_BUF_SIZE, NULL);
    U2D_InitialEndPoint(UDSK_EP_INDEX_BULK_OUT,   U2DEN_EN(5) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP5_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP5_BUF_SIZE, USB_OnOutPkgCompleteUDSK);

    U2D_InitialEndPoint(MSSYNC_EP_INDEX_BULK_IN,  U2DEN_EN(6) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP1_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP1_BUF_SIZE, NULL);
    U2D_InitialEndPoint(MSSYNC_EP_INDEX_BULK_OUT, U2DEN_EN(7) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP2_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP2_BUF_SIZE, USB_OnOutPkgCompleteMSSYNC);

    U2D_InitCheck();
}

#endif //INCLUDE_MODULE_SERIAL

