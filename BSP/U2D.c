/*

*/

#include "_Platform.h"

/*
    In this program, End Point Error Interrupt will not be enable nor be detected !!!
*/

#ifdef INCLUDE_MODULE_U2D

#define U2D_DEBUG_TRACE_HANDLE

#ifdef U2D_DEBUG_TRACE_HANDLE
#define DBG_U2D_INT_ENTRANCE            //DBG_PutChar(':');
#define DBG_U2D_INT_RESET               DBG_PutChar('!');
#define DBG_U2D_INT_SUSPEND             DBG_PutChar('~');
#define DBG_U2D_INT_RESUME              DBG_PutChar('@');
#define DBG_U2D_INT_CONFIG              DBG_PutChar('%');

#define DBG_U2D_EP0_EMPTYPACKAGE        DBG_PutChar('E');
#define DBG_U2D_EP0_INTOKEN             DBG_PutChar('I');

#define DBG_U2D_DEVDESCRIPT             DBG_PutChar('D')
#define DBG_U2D_CONDESCRIPT             DBG_PutChar('C');

#define DBG_U2D_EP0_SEND                DBG_PutChar('S');

#else
#define DBG_U2D_INT_ENTRANCE
#define DBG_U2D_INT_RESET
#define DBG_U2D_INT_SUSPEND
#define DBG_U2D_INT_RESUME
#define DBG_U2D_INT_CONFIG

#define DBG_U2D_EP0_EMPTYPACKAGE
#define DBG_U2D_EP0_INTOKEN

#define DBG_U2D_DEVDESCRIPT
#define DBG_U2D_CONDESCRIPT

#endif

/*
*/

/**
 * DMA Descriptor
 **/
typedef DMA_Descriptor_t                U2D_DMA_Descriptor_t __attribute__ ((aligned (16)));

//Register Value
#define REG_U2DCR                       (*MH_U2DCR)         // U2D Control register
#define REG_U2DICR                      (*MH_U2DICR)        // U2D Interrupt Control register
#define REG_U2DICR2                     (*MH_U2DICR2)       // U2D Interrupt Control register(Endpoints H-P)
#define REG_U2DISR                      (*MH_U2DISR)        // U2D Interrupt Status register
#define REG_U2DISR2                     (*MH_U2DISR2)       // U2D Interrupt Status register(Endpoints H-P)
#define REG_U2DOTGCR                    (*MH_U2DOTGCR)      // U2D OTG Control register
#define REG_U2DOTGICR                   (*MH_U2DOTGICR)     // U2D OTG Interrupt Control/Enable register
#define REG_U2DOTGUSR                   (*MH_U2DOTGUSR)     // U2D OTG ULPI Status register
#define REG_U2DOTGUCR                   (*MH_U2DOTGUCR)     // U2D OTG ULPI Control register
#define REG_U2DCSR0                     (*MH_U2DCSR0)       // U2D Control/Status register - Endpoint 0
#define REG_U2DCSRA                     (*MH_U2DCSRA)       // U2D Control/Status register - Endpoint A
#define REG_U2DCSRB                     (*MH_U2DCSRB)       // U2D Control/Status register - Endpoint B
#define REG_U2DCSRC                     (*MH_U2DCSRC)       // U2D Control/Status register - Endpoint C
#define REG_U2DMACSR0                   (*MH_U2DMACSR0)     // U2D Control/Status register for channel 0
#define REG_U2DCRA                      (*MH_U2DCRA)        // U2D Configuration register - Endpoint A
#define REG_U2DCRB                      (*MH_U2DCRB)        // U2D Configuration register - Endpoint B
#define REG_U2DCRC                      (*MH_U2DCRC)        // U2D Configuration register - Endpoint C
#define REG_U2DEN0                      (*MH_U2DNE0)        // U2D Endpoint Information register - Endpoint 0
#define REG_U2DENA                      (*MH_U2DNEA)        // U2D Endpoint Information register - Endpoint A
#define REG_U2DENB                      (*MH_U2DNEB)        // U2D Endpoint Information register - Endpoint B
#define REG_U2DENC                      (*MH_U2DNEC)        // U2D Endpoint Information register - Endpoint C
#define REG_U2DBCR0                     (*MH_U2DBCR0)       // U2D Byte Count register - Endpoint 0
#define REG_U2DBCRA                     (*MH_U2DBCRA)       // U2D Byte Count register - Endpoint A
#define REG_U2DBCRB                     (*MH_U2DBCRB)       // U2D Byte Count register - Endpoint B
#define REG_U2DMADADR0                  (*MH_U2DMADADR0)    // U2D Descriptor Address register channel 0
#define REG_U2DMASADR0                  (*MH_U2DMASADR0)    // U2D Source Address register channel 0
#define REG_U2DMATADR0                  (*MH_U2DMATADR0)    // U2D Target Address register channel 0
#define REG_U2DMACMD0                   (*MH_U2DMACMD0)     // U2D Command Address register channel 0
#define REG_U2DMADADR1                  (*MH_U2DMADADR1)    // U2D Descriptor Address register channel 1
#define REG_U2DMASADR1                  (*MH_U2DMASADR1)    // U2D Source Address register channel 1
#define REG_U2DMATADR1                  (*MH_U2DMATADR1)    // U2D Target Address register channel 1
#define REG_U2DMACMD1                   (*MH_U2DMACMD1)     // U2D Command Address register channel 1
#define REG_U2DMADADR2                  (*MH_U2DMADADR2)    // U2D Descriptor Address register channel 2
#define REG_U2DMASADR2                  (*MH_U2DMASADR2)    // U2D Source Address register channel 2
#define REG_U2DMATADR2                  (*MH_U2DMATADR2)    // U2D Target Address register channel 2
#define REG_U2DMACMD2                   (*MH_U2DMACMD2)     // U2D Command Address register channel 2
#define REG_U2DMACSR0                   (*MH_U2DMACSR0)     // U2D Control/Status register for channel 0
#define REG_U2DMACSR1                   (*MH_U2DMACSR1)     // U2D Control/Status register for channel 1
#define REG_U2DMACSR2                   (*MH_U2DMACSR2)     // U2D Control/Status register for channel 2
#define REG_U2DMACSR3                   (*MH_U2DMACSR3)     // U2D Control/Status register for channel 3

#define REG_U2DDR0_LONG                 (*MH_U2DDR0)        // U2D Data register - Endpoint 0
#define REG_U2DDR0_WORD                 (*((U16 *)MH_U2DDR0))
#define REG_U2DDR0_BYTE                 (*((U8 *)MH_U2DDR0))

/**
 * Mask of all writable bits in DCSR; others must be written as 0
 **/
#define U2DMACSR_WRITABLES_MSK          (U2DMACSR_BUSERRINTR | U2DMACSR_STARTINTR | U2DMACSR_ENDINTR | U2DMACSR_RASINTR | U2DMACSR_EORINTR | U2DMACSR_RASIRQEN | U2DMACSR_EORSTOPEN | U2DMACSR_EORJMPEN | U2DMACSR_EORIRQEN | U2DMACSR_STOPIRQEN | U2DMACSR_RUN)

/*
*/

static volatile U2D_DMA_Descriptor_t    g_U2DDMADesc[U2D_ENDPOINT_NUMBER];

static F_EP0Handle_t                    g_pOnEP0PackageUnknown = NULL;
static F_EPxHandle_t                    g_pOnEPxPackageComplete[U2D_ENDPOINT_NUMBER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static DeviceDescriptor_t              *g_pDevDesc = NULL;
static ConfigDescriptor_t              *g_pCfgDesc = NULL;

// This code covers a silicon bug... Tibet ID 2017404
// we must clear
// the descriptor Start, Stop and/or EOR interrupts
// even though we may not be enabling these interrupts...
// write 1 to clear the interrupt status bits
//--------------------------------------------------------
inline void U2D_WaitForEPxEndOrStopped(U2D_EP_ID_e eEPIndex)
{
  // Wait for the Endpoint to be in the EOR or STOPPED state
  //--------------------------------------------------------
  while( ((MH_U2DMACSRx)[eEPIndex] & (U2DMACSR_EORINTR | U2DMACSR_STOPINTR)) == 0 )
  {}

  (MH_U2DMACSRx)[eEPIndex] = (MH_U2DMACSRx)[eEPIndex];
}

void U2D_EPxDMAFIFOReadWrite(U2D_EP_ID_e eEPIndex, U32 dwBufferAddr, U32 dwSize, U32 dwWriteFlag)
{
    // This function just support ONE TIME DMA transfer from FIFO.
    // So we must make sure the parameter is correct.

#if 0 // !!! Because we remove the defination from this source file, we have to remove the parameter check here !!!
    if(dwSize > U2D_EP1_BUF_SIZE)
    {
        // !!! If we use USB Serial for Debugging, we cannot output debug message from USB !!!
        // Else, do-loop will happen.
//        DBG_TraceStrLine("ERR: EP1 Size");
        return;
    }
#endif

//  Because this function will wait
//    while(!(REG_U2DMACSR1 & U2DMACSR_STOPINTR)) DBG_TraceStrLine("DMA not finished!!!");

    g_U2DDMADesc[eEPIndex].m_dwTargetAddr  = dwBufferAddr;
    g_U2DDMADesc[eEPIndex].m_dwSourceAddr  = dwBufferAddr;
    g_U2DDMADesc[eEPIndex].m_dwCommand     = dwSize | dwWriteFlag;
    g_U2DDMADesc[eEPIndex].m_dwCommand     = g_U2DDMADesc[eEPIndex].m_dwCommand;    // Dummy read to make sure the content is written to the DDR

    (MH_U2DDMAADDR)[eEPIndex].m_dwDescAddr = (U32)(&g_U2DDMADesc[eEPIndex]);
    (MH_U2DMACSRx)[eEPIndex]              |= U2DMACSR_RUN | U2DMACSR_EORSTOPEN;
    U2D_WaitForEPxEndOrStopped(eEPIndex);
    (MH_U2DCSRx)[eEPIndex]                 = (MH_U2DCSRx)[eEPIndex];                // Clear any setting flag
}

U32 U2D_EPxFIFODataSize(U2D_EP_ID_e eEPIndex)
{
    // !!! Please note: only End Point A ~ G support MH_U2DBCRx !!!
    return((MH_U2DBCRx)[eEPIndex]);
}

void U2D_EPxClearFlag(U2D_EP_ID_e eEPIndex, U32 dwFlag)
{
    // Clear OPC will flush the data in the EndPoint FIFO !!!

    (MH_U2DCSRx)[eEPIndex] = dwFlag;
}

void U2D_EPxSendEmptyPacket(U2D_EP_ID_e eEPIndex)
{
    (MH_U2DCSRx)[eEPIndex] = U2DCSR0_IPR;
}

void U2D_EP0WaitDataPackage(void)
{
    while(!DBG_GotEvent)
    {
        if(REG_U2DCSR0 & U2DCSR0_OPC)
        {
            break;
        }

//        DBG_TraceHex("WAIT EP0 DT", REG_U2DCSR0);
    }
}

void U2D_EP0FIFORead(U32 *pdwData, U32 dwSize)
{
    U32 numDWORD, i;
    U32 flag;

    numDWORD = (dwSize + 3) >> 2;

    for(i=0;i<numDWORD;i++) *pdwData++ = REG_U2DDR0_LONG;
}

void U2D_EP0FIFOWrite(const U32 *pdwData, U32 dwSize)
{
    U32 numDWORD, i;
    U32 flag;

    while(dwSize > U2D_EP0_BUF_SIZE)
    {
        for(i=0;i<(U2D_EP0_BUF_SIZE >> 2);i++)  REG_U2DDR0_LONG = *pdwData++;

        // !!! ???
        // According to the PXA310 spec, we do not need to set the IPR flag here (IPR is only needed when the FIFO is not full).
        // But according to the trial, we have to set this flag to make the package send.
        // !!! ???
        REG_U2DCSR0 = U2DCSR0_IPR;

        dwSize -= U2D_EP0_BUF_SIZE;

        for(REG_U2DISR = REG_U2DISR;!DBG_GotEvent;)
        {
            if(REG_U2DISR & U2DISR_IE0(U2DISR_IEx_PC))
            {
                REG_U2DISR = U2DISR_IE0(U2DISR_IEx_PC);
                break;
            }

            DBG_U2D_EP0_SEND;
        }
    }

    numDWORD = dwSize >> 2;
    flag     = U2DCSR0_IPR;

    for(i=0;i<numDWORD;i++) REG_U2DDR0_LONG = *pdwData++;

    if(3 == (dwSize & 3))
    {
        REG_U2DDR0_LONG = *pdwData++;
        flag = U2DCSR0_IPR | U2DCSR0_IPA;
    }
    else if(2 == (dwSize & 3))
    {
        REG_U2DDR0_WORD = (WORD)(*((WORD*)pdwData));
    }
    else if(1 == (dwSize & 3))
    {
        REG_U2DDR0_BYTE = (BYTE)(*((BYTE*)pdwData));
    }

    if(dwSize < U2D_EP0_BUF_SIZE) REG_U2DCSR0 = flag;
}

void U2D_DumpStdRequest(StandardRequest_t *pRequest)
{
    DBG_TraceMem("Unknown Request", pRequest, sizeof(StandardRequest_t));
}

static void U2D_OnDevDescriptor(void)
{
    U2D_EP0FIFOWrite((U32*)(g_pDevDesc), (U32)(g_pDevDesc->m_bLength));
}

static void U2D_OnConfDescriptor(U32 dwLength)
{
    if(dwLength == USB_DESCRIPTOR_LENGTH_CONFIG)
    {
        U2D_EP0FIFOWrite((U32*)(g_pCfgDesc), USB_DESCRIPTOR_LENGTH_CONFIG);
    }
    else // len = 0x00FF or = 0x0109
    {
        // !!! When using this, must make sure m_wTotalLength is 2Byte align !!!
        U2D_EP0FIFOWrite((U32*)(g_pCfgDesc), (U32)(g_pCfgDesc->m_wTotalLength));
    }
}

static void U2D_EP0OnPackageComplete(void)
{
    StandardRequest_t setupPackage;
    U32 s;

    s = REG_U2DCSR0 & (U2DCSR0_OPC | U2DCSR0_SA);
    if(s == (U2DCSR0_OPC))
    {   // Not a Setup package
        // Should be an empty OUT package
        DBG_U2D_EP0_EMPTYPACKAGE;
        U2D_EPxClearFlag(U2D_EP_ID_0, U2DCSR0_OPC);
        return;
    }
    else if(s == 0)
    {   // Should be an IN token
        DBG_U2D_EP0_INTOKEN;
        return;
    }

    U2D_EP0FIFORead((U32*)(&setupPackage), sizeof(StandardRequest_t));

    U2D_EPxClearFlag(U2D_EP_ID_0, U2DCSR0_OPC | U2DCSR0_SA);

    if(
        (setupPackage.bmRequestType == (USB_bmRequestType_DIR_IN | USB_bmRequestType_STANDARD | USB_bmRequestType_TARGET_DEVICE))
        && (setupPackage.bRequest == USB_bRequest_GET_DESCRIPTOR)
        )
    {
        switch(HIBYTE(setupPackage.wValue))
        {
        case USB_DESCRIPTOR_TYPE_DEVICE:
            DBG_U2D_DEVDESCRIPT;
            U2D_OnDevDescriptor();
            break;
        case USB_DESCRIPTOR_TYPE_CONFIG:
            DBG_U2D_CONDESCRIPT;
            U2D_OnConfDescriptor((U32)(setupPackage.wLength));
            break;
        case USB_DESCRIPTOR_TYPE_STRING:
            break;
        default:
            g_pOnEP0PackageUnknown(&setupPackage);
            break;
        }
    }
    else g_pOnEP0PackageUnknown(&setupPackage);
}

void U2D_Handler(void)
{
    U32 u2disr,u2disr2;

    DBG_U2D_INT_ENTRANCE;

    u2disr  = REG_U2DISR;
    u2disr2 = REG_U2DISR2;

    if(u2disr2)
    {
        REG_U2DISR2 = u2disr2;
        msSleep(10);
        DBG_BreakPoint("We do not support EPH ~ EP0 ISR2 so far!");
    }

    if ( u2disr & U2DISR_IRRU)
    {   // Resume Detected
        DBG_U2D_INT_RESUME;

        REG_U2DISR = u2disr;
        return;
    }
    else if (u2disr & U2DISR_IRSU)
    { // Suspend Detected.
        DBG_U2D_INT_SUSPEND;

        REG_U2DISR = u2disr;
        return;
    }
    else if ( u2disr & U2DISR_IRRS)
    {   // Reset Detected
        DBG_U2D_INT_RESET;

        REG_U2DISR = u2disr;
        return;
    }
    else if(u2disr & U2DISR_IRCC)
    {
       DBG_U2D_INT_CONFIG;

       REG_U2DCR |= U2DCR_SMAC;
       REG_U2DISR = u2disr;
       return;
    }

    if (u2disr & U2DISR_IRDPE)
    {
        DBG_TraceString("ERR: DP");
        REG_U2DISR = U2DISR_IRDPE;
        return;
    }
    {
        int i;

        for(i=U2D_EP_ID_0;i<=U2D_EP_ID_G;i++)
        {
            if(u2disr & U2DISR_IE_NORMAL_X(i))
            {
                if(g_pOnEPxPackageComplete[i] != NULL) g_pOnEPxPackageComplete[i]();
                REG_U2DISR = U2DISR_IE_NORMAL_X(i);
                return;
            }

            // Because we did not enable any ERROR interrupt,
            // We did not do any ERROR proecess here.
        }
    }
}

void U2D_Disconnect(void)
{
    DBG_TraceStrLine("Disconnect USB device!");

    REG_U2DOTGCR = 0;

    REG_U2DCR    = 0;

    {
        U2D_EP_ID_e i;
        for(i=U2D_EP_ID_A;i<U2D_EP_ID_LIMIT;i++)        (MH_U2DCRx)[i] = 0;
    }
}

BOOL U2D_InitialEndPoint(U2D_EP_ID_e eEPIndex, U32 dwConfig, U32 dwEPBufferSize, F_EPxHandle_t pHandle)
{
    if( (eEPIndex > U2D_EP_ID_G) && (pHandle != NULL)   )
    {
        DBG_TraceStrLine("U2D_EPInitial error.");
        return(FALSE);
    }

    (MH_U2DENx)[eEPIndex]    = dwConfig;
    (MH_U2DCRx)[eEPIndex]    = U2DCR_BS(dwEPBufferSize) | U2DCR_EE;

    (MH_U2DCSRx)[eEPIndex]   = U2DCSR_DME;
    (MH_U2DMACSRx)[eEPIndex] = 0;
    (MH_U2DCSRx)[eEPIndex]   = (MH_U2DCSRx)[eEPIndex];                              // Clear any flags, and make sure the register access is finished
    (MH_U2DMACSRx)[eEPIndex] = (MH_U2DMACSRx)[eEPIndex];                            // Clear any flags, and make sure the register access is finished

    g_U2DDMADesc[eEPIndex].m_dwDescLinkAddr = (U32)(&g_U2DDMADesc[eEPIndex]) | U2DMADADR_STOP;

    g_pOnEPxPackageComplete[eEPIndex] = pHandle;
    if(pHandle != NULL) REG_U2DICR |= U2DICR_IE_NORMAL_X(eEPIndex);      // Enable End Point Interrupt if the Handle is valid

    return(TRUE);
}

void U2D_Initial(const DeviceDescriptor_t *pDevDesc, const ConfigDescriptor_t *pCfgDesc, F_EP0Handle_t pHandle0)
{
#define EP0_64MPS                       (0x1u<<25)          //EP0 must be 0x02000000

    g_pDevDesc = (DeviceDescriptor_t *)pDevDesc;
    g_pCfgDesc = (ConfigDescriptor_t *)pCfgDesc;
    g_pOnEP0PackageUnknown  = pHandle0;
    g_pOnEPxPackageComplete[U2D_EP_ID_0] = U2D_EP0OnPackageComplete;

    REG_U2DOTGCR = U2DOTGCR_ULAF | U2DOTGCR_ULE;
    while(!(REG_U2DOTGCR & U2DOTGCR_ULE)) {;}

    REG_U2DICR      = 0;
    REG_U2DICR2     = 0;
    REG_U2DISR      = (U32)(-1);
    REG_U2DISR2     = (U32)(-1);

    REG_U2DCR      |= U2DCR_UDE;

    REG_U2DICR     |= U2DICR_IECC | U2DICR_IERU | U2DICR_IESU | U2DICR_IERS |
                        U2DICR_IE_NORMAL_X (U2D_EP_ID_0);

    REG_U2DEN0      = EP0_64MPS;

    REG_U2DCSR0     = U2DCSR0_SA | U2DCSR0_SST | U2DCSR0_FTF | U2DCSR0_OPC;

#undef EP0_64MPS
}

BOOL U2D_InitCheck(void)
{
    DBG_TraceStrLine("U2D Initial ");
    if(REG_U2DCR & U2DCR_EMCE)
    {
        DBG_TraceString("failed!");
        REG_U2DCR = U2DCR_EMCE;
        return(FALSE);
    }
    else
    {
        DBG_TraceString("Done!");
        return(TRUE);
    }
}

#endif //INCLUDE_MODULE_U2D

