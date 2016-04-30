/*

*/

#include "_Platform.h"

/*
    This module is not a standard Microsoft Active Sync device driver!!!
*/

#ifdef INCLUDE_MODULE_MSSYNC

#define U2D_EP1_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP2_BUF_SIZE                U2D_EPD_BUF_SIZE

#define MSSYNC_DEBUG_TRACE_HANDLE

#ifdef MSSYNC_DEBUG_TRACE_HANDLE
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

    USB_DEV_DESC_VID_MS_SYNC,
    USB_DEV_DESC_PID_MS_SYNC,

    0,
    0x00, 0x00, 0x00,
    0x01
};

typedef struct __attribute__ ((packed)){
    USB_ConfigDescriptor_t    m_Config;
    USB_FullInterfaceMSSync_t m_Interface;
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
            USB_CNFG_DESC_CLASS_PROTOCOL_UNKNOWN,
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

void USB_OnOutPkgCompleteMSSYNC(void)
{
    // This is just a test program

    U32 buf[MSSYNC_EP_INDEX_BULK_OUT/4];
    U32 i;

    U2D_EPxDMAFIFORead(MSSYNC_EP_INDEX_BULK_OUT, (U32)buf, i = U2D_EPxFIFODataSize(MSSYNC_EP_INDEX_BULK_OUT));

    if(i < 4) return;

    for(i = MAKEDWORD(MAKEWORD(buf[0], buf[1]), MAKEWORD(buf[0], buf[1])) / MSSYNC_EP_INDEX_BULK_OUT;
        i > 0;i--)
    {
        U2D_EPxDMAFIFORead(MSSYNC_EP_INDEX_BULK_OUT, (U32)buf, MSSYNC_EP_INDEX_BULK_OUT);
    }
}

void USB_EP0PkgUnknownMSSYNC(StandardRequest_t *pRequest)
{
    U2D_DumpStdRequest(pRequest);
}

void USB_MSSyncInitial(void)
{
    U2D_Initial(
        &g_DeviceDescriptor,
        (ConfigDescriptor_t *)(&g_FullConfigDescriptor),
        USB_EP0PkgUnknownMSSYNC
        );

    U2D_InitialEndPoint(MSSYNC_EP_INDEX_BULK_IN,  U2DEN_EN(1) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP1_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP1_BUF_SIZE, NULL);
    U2D_InitialEndPoint(MSSYNC_EP_INDEX_BULK_OUT, U2DEN_EN(2) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP2_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP2_BUF_SIZE, USB_OnOutPkgCompleteMSSYNC);

    U2D_InitCheck();
}

#endif //INCLUDE_MODULE_MSSYNC


