
#define INCLUDE_MODULE_U2D

// U2D Controller
#define U2D_EP0_BUF_SIZE                64
#define U2D_EPD_BUF_SIZE                512

typedef USB_StandardRequest_t           StandardRequest_t  __attribute__ ((aligned (4)));
typedef USB_DeviceDescriptor_t          DeviceDescriptor_t __attribute__ ((aligned (4)));
typedef USB_ConfigDescriptor_t          ConfigDescriptor_t __attribute__ ((aligned (4)));

typedef void (*F_USBDeviceInitial_t)(void);
typedef void (*F_EPxHandle_t)(void);
typedef void (*F_EP0Handle_t)(StandardRequest_t *);

void U2D_DumpStdRequest(StandardRequest_t *pRequest);

U32  U2D_EPxFIFODataSize(U2D_EP_ID_e eEPIndex);
void U2D_EPxDMAFIFOReadWrite(U2D_EP_ID_e dwEPIndex, U32 dwBufferAddr, U32 dwSize, U32 dwWriteFlag);
#define U2D_EPxDMAFIFOWrite(id, addr, size)                 U2D_EPxDMAFIFOReadWrite(id, addr, size, U2DMACMD_XFRDIS | U2DMACMD_PACKCOMP)
#define U2D_EPxDMAFIFORead(id, addr, size)                  U2D_EPxDMAFIFOReadWrite(id, addr, size, 0)

void U2D_EPxClearFlag(U2D_EP_ID_e eEPIndex, U32 dwFlag);
void U2D_EPxSendEmptyPacket(U2D_EP_ID_e eEPIndex);
void U2D_EP0WaitDataPackage(void);
void U2D_EP0FIFORead(U32 *pdwData, U32 dwSize);
void U2D_EP0FIFOWrite(const U32 *pdwData, U32 dwSize);

BOOL U2D_InitialEndPoint(U2D_EP_ID_e eEPIndex, U32 dwConfig, U32 dwEPBufferSize, F_EPxHandle_t pHandle);
void U2D_Initial(const DeviceDescriptor_t *pDevDesc, const ConfigDescriptor_t *pCfgDesc, F_EP0Handle_t pHandle0);
BOOL U2D_InitCheck(void);

void U2D_Handler(void);

void U2D_Disconnect(void);


