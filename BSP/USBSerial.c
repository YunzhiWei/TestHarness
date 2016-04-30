/*

*/

#include "_Platform.h"

#ifdef INCLUDE_MODULE_SERIAL

#define U2D_EP1_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP2_BUF_SIZE                U2D_EPD_BUF_SIZE
#define U2D_EP3_BUF_SIZE                U2D_EPD_BUF_SIZE

#define SERIAL_DEBUG_TRACE_HANDLE

#ifdef SERIAL_DEBUG_TRACE_HANDLE
#define DBG_GET_LINE_CODING             DBG_PutChar('c')
#define DBG_GET_SERIAL_STATE            DBG_PutChar('s')
#define DBG_SET_LINE_CODING             DBG_PutChar('C')
#define DBG_CONTROL_STATE               DBG_PutChar('S')
#define DBG_SEND_BREAK                  DBG_PutChar('B')
#else
#define DBG_GET_LINE_CODING
#define DBG_GET_SERIAL_STATE
#define DBG_SET_LINE_CODING
#define DBG_CONTROL_STATE
#define DBG_SEND_BREAK
#endif

/*
*/

static const DeviceDescriptor_t g_DeviceDescriptor = {
    USB_DESCRIPTOR_LENGTH_DEVICE,
    USB_DESCRIPTOR_TYPE_DEVICE,

    USB_DEV_DESC_VERSION_20,

    0x02, 0x00, 0x00,

    U2D_EP0_BUF_SIZE,

    USB_DEV_DESC_VID_SERIAL,
    USB_DEV_DESC_PID_SERIAL,

    0,
    0x00, 0x00, 0x00,
    0x01
};

typedef struct __attribute__ ((packed)){
    USB_ConfigDescriptor_t    m_Config;
    USB_FullInterfaceSerial_t m_Interface;
}FullConfigureDescriptor_t __attribute__ ((aligned (4)));

static const FullConfigureDescriptor_t g_FullConfigDescriptor = {
    {
        USB_DESCRIPTOR_LENGTH_CONFIG,
        USB_DESCRIPTOR_TYPE_CONFIG,

        sizeof(FullConfigureDescriptor_t),

        0x01,
        0x01,
        0x00,
        0x00,

        50 * USB_CNFG_DESC_MAX_POWER_UNIT_2mA
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
    }
};

/*
*/

// USB Serial

#define EP0_SETUP_GET_LINE_CODING           0x21
#define EP0_SETUP_GET_SERIAL_STATE          0x20
#define EP0_SETUP_SET_LINE_CODING           0x20
#define EP0_SETUP_CONTROL_LINE_STATE        0x22
#define EP0_SETUP_SEND_BREAK                0x23

#define USB_SERIAL_LINCODE_STOPBITS_ONE     0x00
#define USB_SERIAL_LINCODE_STOPBITS_HALF    0x01
#define USB_SERIAL_LINCODE_STOPBITS_TWO     0x02

#define USB_SERIAL_LINCODE_PARITY_NONE      0x00
#define USB_SERIAL_LINCODE_PARITY_ODD       0x01
#define USB_SERIAL_LINCODE_PARITY_EVEN      0x02
#define USB_SERIAL_LINCODE_PARITY_MARK      0x03
#define USB_SERIAL_LINCODE_PARITY_SPACE     0x04

#define USB_SERIAL_LINCODE_DATABITS_5       0x05
#define USB_SERIAL_LINCODE_DATABITS_6       0x06
#define USB_SERIAL_LINCODE_DATABITS_7       0x07
#define USB_SERIAL_LINCODE_DATABITS_8       0x08
#define USB_SERIAL_LINCODE_DATABITS_16      0x10

#define USB_SERIAL_LINCODE_BAUDRATE_9600    0x00002580
#define USB_SERIAL_LINCODE_BAUDRATE_115200  0x0001C200
#define USB_SERIAL_LINCODE_BAUDRATE_921600  0x000E1000

#define USB_SERIAL_LINESTATE_DTE_DTR        (1 << 0)
#define USB_SERIAL_LINESTATE_DTE_RTS        (1 << 1)

typedef struct{
    U32 m_dwBaudRate;
    U8  m_bParity;
    U8  m_bStopBitNum;
    U8  m_bDataBitNum;
    U8  m_bDummy;
}USBSerialLineCode_t __attribute__ ((aligned (4)));
#define USB_SERIAL_LINE_CODE_SIZE           7

static USBSerialLineCode_t g_LineCoding = {
    USB_SERIAL_LINCODE_BAUDRATE_921600,
    USB_SERIAL_LINCODE_PARITY_NONE,
    USB_SERIAL_LINCODE_STOPBITS_ONE,
    USB_SERIAL_LINCODE_DATABITS_8,
    0
    };
static U16 g_wLineState;

static void OnSendBreak(void)
{
    U2D_EPxSendEmptyPacket(U2D_EP_ID_0);
}

static void OnGetSerialState(void)
{
    U2D_EPxSendEmptyPacket(U2D_EP_ID_0);
}

static void OnSetControlLineState(StandardRequest_t *pRequest)
{
    U2D_EPxSendEmptyPacket(U2D_EP_ID_0);

    g_wLineState = pRequest->wValue;

    if(
          (USB_SERIAL_LINESTATE_DTE_RTS | USB_SERIAL_LINESTATE_DTE_DTR) ==
        ( (USB_SERIAL_LINESTATE_DTE_RTS | USB_SERIAL_LINESTATE_DTE_DTR) & g_wLineState)
        )
    {
        SetEvent(MAIN_EVENT_USB_HYPERT_OPEN);
    }
    else if(
          (USB_SERIAL_LINESTATE_DTE_RTS) ==
        ( (USB_SERIAL_LINESTATE_DTE_RTS | USB_SERIAL_LINESTATE_DTE_DTR) & g_wLineState)
        )
    {
        SetEvent(MAIN_EVENT_USB_HYPERT_CLOSE);
    }
}

static void OnGetLineCode(void)
{
    U2D_EP0FIFOWrite((U32*)(&g_LineCoding), USB_SERIAL_LINE_CODE_SIZE);
}

static void OnSetLineCode(void)
{
    // USB Serial is opened !!!
    FIFO_Clear(FIFO_ID_USBSERIAL);

    U2D_EP0WaitDataPackage();
    U2D_EP0FIFORead((U32*)(&g_LineCoding), USB_SERIAL_LINE_CODE_SIZE);
    U2D_EPxClearFlag(U2D_EP_ID_0, U2DCSR0_OPC);

    U2D_EPxSendEmptyPacket(U2D_EP_ID_0);

}

void USB_EP0PkgUnknownSerial(StandardRequest_t *pRequest)
{
    switch(pRequest->bmRequestType)
    {
    case (USB_bmRequestType_DIR_IN | USB_bmRequestType_CLASS | USB_bmRequestType_TARGET_INTERFACE):
        if(pRequest->bRequest == EP0_SETUP_GET_LINE_CODING)
        {
            DBG_GET_LINE_CODING;
            OnGetLineCode();
        }
        else if(pRequest->bRequest ==  EP0_SETUP_GET_SERIAL_STATE)
        {
            DBG_GET_SERIAL_STATE;
            OnGetSerialState();
        }
        else U2D_DumpStdRequest(pRequest);
        break;
    case (USB_bmRequestType_DIR_OUT | USB_bmRequestType_CLASS | USB_bmRequestType_TARGET_INTERFACE):
        if(pRequest->bRequest == EP0_SETUP_SET_LINE_CODING)
        {
            DBG_SET_LINE_CODING;
            OnSetLineCode();
        }
        else if(pRequest->bRequest == EP0_SETUP_CONTROL_LINE_STATE)
        {
            DBG_CONTROL_STATE;
            OnSetControlLineState(pRequest);
        }
        else if(pRequest->bRequest == EP0_SETUP_SEND_BREAK)
        {
            DBG_SEND_BREAK;
            OnSendBreak();
        }
        else U2D_DumpStdRequest(pRequest);
        break;
    default:
        U2D_DumpStdRequest(pRequest);
        break;
    }
}

void USB_OnOutPkgCompleteSerial(void)
{
    U32 size;
    U32 tmp[U2D_EPD_BUF_SIZE/sizeof(U32)];

    U2D_EPxDMAFIFORead(SERIAL_EP_INDEX_BULK_OUT, (U32)tmp, size = U2D_EPxFIFODataSize(SERIAL_EP_INDEX_BULK_OUT));

//  DBG_TraceDec(NULL, size);

    if(size > FIFO_In(FIFO_ID_USBSERIAL, (PU8)tmp, size)) DBG_BreakPoint("Serial FIFO Overflow!");
}

void SERIAL_Send(PU8 pdwBuffer, U32 dwSize)
{
    U2D_EPxDMAFIFOWrite(SERIAL_EP_INDEX_BULK_IN, (U32)pdwBuffer, dwSize);
}

U32 SERIAL_Receive(PU8 pbBuffer, U32 dwSize)
{
    return(FIFO_Out(FIFO_ID_USBSERIAL, pbBuffer, dwSize));
}

U32 SERIAL_ValidDataSize(void)
{
    FIFO_ValidDataSize(FIFO_ID_USBSERIAL);
}

void SERIAL_PutChar(U8 c)
{
    U2D_EPxDMAFIFOWrite(SERIAL_EP_INDEX_BULK_IN, (U32)(&c), 1);
}

U8 SERIAL_GetChar(void)
{
    U8 c;

    while(0 == SERIAL_ValidDataSize()) { ; }

    FIFO_Out(FIFO_ID_USBSERIAL, &c, 1);

    return(c);
}

void SERIAL_Dump(void)
{
    DBG_TraceStrLine("DTR "); (g_wLineState & USB_SERIAL_LINESTATE_DTE_DTR) ? DBG_TraceString("SET") : DBG_TraceString("CLR");
    DBG_TraceStrLine("RTS "); (g_wLineState & USB_SERIAL_LINESTATE_DTE_RTS) ? DBG_TraceString("SET") : DBG_TraceString("CLR");

    DBG_TraceHex("Baud Rate", g_LineCoding.m_dwBaudRate);
    DBG_TraceHex("Parity",    g_LineCoding.m_bParity);
    DBG_TraceHex("Stop Bit",  g_LineCoding.m_bStopBitNum);
    DBG_TraceHex("Data Bit",  g_LineCoding.m_bDataBitNum);
}

void USB_SerialInitial(void)
{
    U2D_Initial(
        &g_DeviceDescriptor,
        (ConfigDescriptor_t *)(&g_FullConfigDescriptor),
        USB_EP0PkgUnknownSerial
        );
    U2D_InitialEndPoint(SERIAL_EP_INDEX_BULK_IN,  U2DEN_EN(1) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP1_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP1_BUF_SIZE, NULL);
    U2D_InitialEndPoint(SERIAL_EP_INDEX_BULK_OUT, U2DEN_EN(2) | U2DEN_ET(ET_BLK) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP2_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_OUT), U2D_EP2_BUF_SIZE, USB_OnOutPkgCompleteSerial);
    U2D_InitialEndPoint(SERIAL_EP_INDEX_INT_IN,   U2DEN_EN(3) | U2DEN_ET(ET_INT) | U2DEN_CN(1) | U2DEN_IN(0) | U2DEN_AISN(0) | U2DEN_MPS(U2D_EP3_BUF_SIZE)| U2DEN_HBW(2) | U2DEN_ED(ED_IN),  U2D_EP3_BUF_SIZE, NULL);
    U2D_InitCheck();
}

#endif //INCLUDE_MODULE_SERIAL

