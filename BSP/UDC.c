
#include "_Platform.h"

#ifdef INCLUDE_MODULE_UDC

#define USB_DEBUG_TRACE_HANDLE

#define UDC_DEVDESCRIPT0                DBG_PutChar('{')
#define UDC_DEVDESCRIPT1                DBG_PutChar('}')
#define UDC_DEVDESCRIPT2                DBG_PutChar('.')
#define UDC_CONDESCRIPT0                DBG_PutChar('[');
#define UDC_CONDESCRIPT1                DBG_PutChar(']')
#define UDC_CONDESCRIPT2                DBG_PutChar('/');
#define UDC_ENDDESCRIPT                 DBG_PutChar('\\');

/*

*/

// USB Disk

#define UDC_DISK_BASE                   BUFFER_RAM_DISK_BASE
#define UDC_DISK_SIZE                   BUFFER_RAM_DISK_SIZE

#define UDC_DISK_SECTOR_SIZE            512

#define UDC_DISK_LAST_SECTOR_NUMBER     (UDC_DISK_SIZE/UDC_DISK_SECTOR_SIZE) - 1

// UDC Controller

#define UDC_EP0_BUF_SIZE                16
#define UDC_EP1_BUF_SIZE                64
#define UDC_EP2_BUF_SIZE                64

DeviceDescriptor_t g_DeviceDescriptor = {
    0x12, 0x01,

    0x10, 0x01,

    0x00, 0x00, 0x00, UDC_EP0_BUF_SIZE,

    0x86, 0x80,
    0x00, 0x00,

    0x00, 0x00,

    0x00, 0x00, 0x00,
    0x01
};

ConfigDescriptor_t g_ConfigDescriptor = {
    // -------
    0x09, 0x02,

    0x20, 0x00,

    0x01,
    0x01,
    0x00,
    0xC0,

    0x01,

    //--------
    0x09, 0x04,

    0x00, 0x00,

    0x02, 0x08, 0x06, 0x50,
    0x00,

    //-------
    0x07, 0x05,

    0x81, 0x02,
    UDC_EP1_BUF_SIZE, 0x00,

    0x00,

    //-------
    0x07, 0x05,

    0x02, 0x02,
    UDC_EP2_BUF_SIZE, 0x00,

    0x00
};

/*
    Register Value
*/

static volatile U32  *s_USB_EP_CSR      = (U32 *)MH_UDCCSR0;
static volatile U32  *s_USB_EP_BCR      = (U32 *)MH_UDCBCR0;
static volatile U32  *s_USB_EP_CCR      = (U32 *)MH_UDCCR0;
static volatile U32  *s_USB_EP_Data     = (U32 *)MH_UDCDR0;
#define   s_USB_EP0_BData               (*((U8 *)MH_UDCDR0))
#define   s_USB_EP1_BData               (*((U8 *)MH_UDCDRA))

#define REG_UDCCR                       (*MH_UDCCR)
#define REG_UDCICR0                     (*MH_UDCICR0)
#define REG_UDCICR1                     (*MH_UDCICR1)
#define REG_UDCISR0                     (*MH_UDCISR0)
#define REG_UDCISR1                     (*MH_UDCISR1)
#define REG_UDCUP2OCR                   (*MH_UP2OCR)

static union{
    U32 m_dwV32[8];
    U8  m_bV8[32];
}uEPOut;

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

void UDC_Initial(void)
{
    REG_UDCCR       = 0;

    REG_UDCUP2OCR   = (0 * UP2OCR_SEOS) | UP2OCR_HXOE | UP2OCR_DPPUE;

    // EP1
    s_USB_EP_CCR[1] = UDCCRZ_EE | \
                      UDCCRZ_DE | \
                      (1 * UDCCRZ_EN) | (1 * UDCCRZ_CN) | (0 * UDCCRZ_IN) | (0 * UDCCRZ_AISN) | \
                      (ED_IN * UDCCRZ_ED)   | (ET_BLK * UDCCRZ_ET) | \
                      (UDC_EP1_BUF_SIZE * UDCCRZ_MPS);

    // EP2
    s_USB_EP_CCR[2] = UDCCRZ_EE | \
                      UDCCRZ_DE | \
                      (2 * UDCCRZ_EN) | (1 * UDCCRZ_CN) | (0 * UDCCRZ_IN) | (0 * UDCCRZ_AISN) | \
                      (ED_OUT * UDCCRZ_ED)   | (ET_BLK * UDCCRZ_ET) | \
                      (UDC_EP2_BUF_SIZE * UDCCRZ_MPS);

    REG_UDCCR       = UDCCR_UDE | (1<<13);

    if(REG_UDCCR & UDCCR_EMCE)
    {
        DBG_TraceStrLine("Initial failed.");

        REG_UDCCR = UDCCR_EMCE;
    }
    else
    {
        DBG_TraceStrLine("Initial Done.");

        REG_UDCICR0     = ((UDCICSR_IRQ_P + UDCICSR_IRQ_E) * UDCICSR0_IRQ_B) | \
                          ((UDCICSR_IRQ_P + UDCICSR_IRQ_E) * UDCICSR0_IRQ_0);
        REG_UDCICR1     = UDCICSR1_IRRU | UDCICSR1_IRRS | UDCICSR1_IRCC;
    }
}

static void UDC_DevDescriptor(void)
{
    U32 *devDesc;

    devDesc = (U32*)(&g_DeviceDescriptor);                  // g_DeviceDescriptor must be 4Byte aligned.

    if(uEPOut.m_bV8[6] == 0x12)
    {
        UDC_DEVDESCRIPT1;

        s_USB_EP_Data[0] = devDesc[0];
        s_USB_EP_Data[0] = devDesc[1];
        s_USB_EP_Data[0] = devDesc[2];
        s_USB_EP_Data[0] = devDesc[3];

        // uEPOut.m_bV8[6] = 0x12;                             // To be continued
    }
    else
    {
        UDC_DEVDESCRIPT0;

        s_USB_EP_Data[0] = devDesc[0];
        s_USB_EP_Data[0] = devDesc[1];

        s_USB_EP_CSR[0] = UDCCSR0_IPR;
    }
}

static void UDC_DevDescriptor_2(void)
{
    U32 *devDesc;

    devDesc = (U32*)(&g_DeviceDescriptor);                  // g_DeviceDescriptor must be 4Byte aligned.

//    if(uEPOut.m_bV8[6] == 0x12)
    {
        // Continue
        DBG_PutChar('d');

        s_USB_EP0_BData = LLBYTE(devDesc[4]);
        s_USB_EP0_BData = LHBYTE(devDesc[4]);
        s_USB_EP_CSR[0] = UDCCSR0_IPR;

        uEPOut.m_bV8[6] = 0;                                // to indicate that the descriptor is over
    }
}

static void UDC_ConfDescriptor(void)
{
    U32 *confDesc;

    confDesc = (U32*)(&g_ConfigDescriptor);                 // g_ConfigDescriptor must be 4Byte aligned.

    if(uEPOut.m_bV8[6] == 0x09)
    {
        UDC_CONDESCRIPT0;

        s_USB_EP_Data[0] = confDesc[0];
        s_USB_EP_Data[0] = confDesc[1];

        s_USB_EP0_BData = LLBYTE(confDesc[2]);

        s_USB_EP_CSR[0] |= UDCCSR0_IPR;
    }
    else
    {
        UDC_CONDESCRIPT1;

        s_USB_EP_Data[0] = confDesc[0];
        s_USB_EP_Data[0] = confDesc[1];
        s_USB_EP_Data[0] = confDesc[2];
        s_USB_EP_Data[0] = confDesc[3];

        uEPOut.m_bV8[6] = 0x10;                             // To be continued
    }
}

static void UDC_ConfDescriptor_2(void)
{
    U32 *confDesc;

    confDesc = (U32*)(&g_ConfigDescriptor);                 // g_ConfigDescriptor must be 4Byte aligned.

    // if(uEPOut.m_bV8[6] == 0x10)
    {
        // Continue
        UDC_CONDESCRIPT2;

        s_USB_EP_Data[0] = confDesc[4];
        s_USB_EP_Data[0] = confDesc[5];
        s_USB_EP_Data[0] = confDesc[6];
        s_USB_EP_Data[0] = confDesc[7];

        uEPOut.m_bV8[6] = 0xEE;                             // An empty package is needed to indicate the end of the descriptor
    }
}

static void UDC_EndDescriptor(void)
{
    // if(uEPOut.m_bV8[6] == 0xEE)
    {
        // Send an empty package out
        UDC_ENDDESCRIPT;

        s_USB_EP_CSR[0] |= UDCCSR0_IPR;

        uEPOut.m_bV8[6] = 0;                                // to indicate that the descriptor is over
    }
}

static void UDC_GetMaxLun(void)
{
    if(uEPOut.m_bV8[6] == 1)
    {
        s_USB_EP0_BData = 0;
        s_USB_EP_CSR[0] |= UDCCSR0_IPR;

        uEPOut.m_bV8[6] = 0;                                // to indicate that the descriptor is over
    }
    else
    {
        DBG_TraceStrLine("GETMAXLUN_ERR");
    }
}

#define CSW_SIGNATURE                               0x53425355          // "SBWU"

#define CBW_SIGNATURE                               0x43425355          // "CBWU"
#define CBW_TAG                                     uEPOut.m_dwV32[1]
#define CBW_DataLength                              uEPOut.m_dwV32[2]
#define CBW_FLAG                                    uEPOut.m_bV8[12]
#define CBWCB_OPCODE                                uEPOut.m_bV8[15]

// With result back
#define CBWCB_OPCODE_INQUIRY                        0x12
#define CBWCB_OPCODE_READCAPACITY                   0x25
#define CBWCB_OPCODE_REQUESTSENSE                   0x03
#define CBWCB_OPCODE_READ                           0x28
#define CBWCB_OPCODE_TESTUNITREADY                  0x00
#define CBWCB_OPCODE_PREVENTALLOWMEDIUMREMOVAL      0x1E
#define CBWCB_OPCODE_READFORMATCAPACITY             0x23
#define CBWCB_OPCODE_UFIMODESENSE                   0x5A
#define CBWCB_OPCODE_SCSIMODESENSE                  0x1A
#define CBWCB_OPCODE_VERIFY                         0x2F
#define CBWCB_OPCODE_STARTSTOP                      0x1B
#define CBWCB_OPCODE_WRITE                          0x2A

static void UDC_CBWOnNotSupport(void)
{
    s_USB_EP_CSR[1] = UDCCSR_FST;

    while(!(s_USB_EP_CSR[1] & UDCCSR_SST)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_SST;

    s_USB_EP_Data[1] = USB_BOMS_CSW_SIGNATURE;
    s_USB_EP_Data[1] = CBW_TAG;
    s_USB_EP_Data[1] = 0x0;
    s_USB_EP1_BData = 0x01;

    s_USB_EP_CSR[1] = UDCCSR_SP;
}

static void UDC_CSWGood(U32 dwLen)
{
    // dwLen: tell the host how many byte did not sent
    // This part is not exactly compatible with the protocol.
    s_USB_EP_Data[1] = USB_BOMS_CSW_SIGNATURE;
    s_USB_EP_Data[1] = CBW_TAG;
    s_USB_EP_Data[1] = dwLen;
    s_USB_EP1_BData = 0x0;

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;
}

static void UDC_CBWOnInquiry(void)
{
    s_USB_EP_Data[1] = 0x02028000;
    s_USB_EP_Data[1] = 0x0000001F;

    // vendor
    s_USB_EP_Data[1] = 0x53205455;                          // 'UT Star'
    s_USB_EP_Data[1] = 0x20726174;
    // product
    s_USB_EP_Data[1] = 0x20363853;                          // 'S86 '
    s_USB_EP_Data[1] = 0x4C445442;                          // 'BTDL'
    s_USB_EP_Data[1] = 0x20534D20;                          // ' MS '
    s_USB_EP_Data[1] = 0x205A5957;                          // 'WYZ '

    s_USB_EP_Data[1] = 0x30303130;                          // revision '0100'

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;

    UDC_CSWGood(0);
}

static void UDC_CBWOnReadFmtCapacity(U32 dwLen)
{
    s_USB_EP_Data[1] = 0x08000000;
    s_USB_EP_Data[1] = 0x00100000;
    s_USB_EP_Data[1] = 0x00020001;                          // unformatted media // 00020003 no cartridge in drive ;00020002 formateed media ?????

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;

    UDC_CSWGood(dwLen - 12);
}

static void UDC_CBWOnReadCapacity(void)
{
    const static U32 cbwCap[] = {
        REVERSEDWORD(UDC_DISK_LAST_SECTOR_NUMBER),
        REVERSEDWORD(UDC_DISK_SECTOR_SIZE)
    };

    s_USB_EP_Data[1] = cbwCap[0];
    s_USB_EP_Data[1] = cbwCap[1];

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;

    UDC_CSWGood(0);
}

static void UDC_CBWOnModeSense(U32 dwLen)
{
    s_USB_EP_Data[1] = 0x00000003;

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;

    UDC_CSWGood(dwLen - 4);
}

static void UDC_CBWOnRequestSense(void)
{
    s_USB_EP_Data[1] = 0x00050070; // 0x00050070;
    s_USB_EP_Data[1] = 0x0C000000;
    s_USB_EP_Data[1] = 0x00000000;
    s_USB_EP_Data[1] = 0x00000020; // 0x00000020;
    s_USB_EP1_BData = 0x00;
    s_USB_EP1_BData = 0x00;

    s_USB_EP_CSR[1] = UDCCSR_SP;

    while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
    s_USB_EP_CSR[1] = UDCCSR_PC;

    UDC_CSWGood(0);
}

static PU32 UDC_SendOneSector(PU32 pdwSectAddr)
{
    U32 i, j;

    for(i=0;i<(UDC_DISK_SECTOR_SIZE / UDC_EP1_BUF_SIZE);i++)
    {
        for(j=0;j<(UDC_EP1_BUF_SIZE / sizeof(U32));j++)
        {
            s_USB_EP_Data[1] = *pdwSectAddr++;
        }
        while(!(s_USB_EP_CSR[1] & UDCCSR_PC)) { ; }
        s_USB_EP_CSR[1] = UDCCSR_PC;
    }

    return(pdwSectAddr);
}

static void UDC_CBWOnRead(U32 dwSectIndex, U32 dwSectNum)
{
    PU32 sectAddr;

    sectAddr = (PU32)(dwSectIndex * UDC_DISK_SECTOR_SIZE + UDC_DISK_BASE);

    while(dwSectNum-- > 0)
    {
        sectAddr = UDC_SendOneSector(sectAddr);
    }

    UDC_CSWGood(0);
}

static PU32 UDC_ReceiveOneSector(PU32 pdwSectAddr)
{
    U32 i, j;

    for(i=0;i<(UDC_DISK_SECTOR_SIZE / UDC_EP2_BUF_SIZE);i++)
    {
        while(!(s_USB_EP_CSR[2] & UDCCSR_PC)) { ; }
        if(s_USB_EP_BCR[2] != UDC_EP2_BUF_SIZE)
        {
            //DBG_TraceStrLine(" receive package is not 512 bytes");
            return((PU32)(-1));
        }

        for(j=0;j<(UDC_EP2_BUF_SIZE / sizeof(U32));j++)
        {
            *pdwSectAddr++ = s_USB_EP_Data[2];
        }

        s_USB_EP_CSR[2] = UDCCSR_PC;
    }

    return(pdwSectAddr);
}

static void UDC_CBWOnWrite(U32 dwSectIndex, U32 dwSectNum)
{
    PU32 sectAddr;

    sectAddr = (PU32)(dwSectIndex * UDC_DISK_SECTOR_SIZE + UDC_DISK_BASE);

    while(dwSectNum-- > 0)
    {
        sectAddr = UDC_ReceiveOneSector(sectAddr);
    }

    UDC_CSWGood(0);
}

#ifdef USB_DEBUG_TRACE_HANDLE

#define DBG_UDC_INT_ENTRANCE            //DBG_TraceStrLine(":");
#define DBG_UDC_INT_RESET               DBG_PutChar('!');
#define DBG_UDC_INT_SUSPEND             DBG_PutChar('~');
#define DBG_UDC_INT_RESUME              DBG_PutChar('@');
#define DBG_UDC_INT_CONFIG              DBG_PutChar('%');

#define DBG_UDC_EP0_EMPTYPACKAGE        DBG_PutChar('E');
#define DBG_UDC_EP0_INTOKEN             DBG_PutChar('I');

#define DBG_UDC_DEVDESCRIPT             DBG_PutChar('D')
#define DBG_UDC_CONDESCRIPT             DBG_PutChar('C');
#define DBG_UDC_GETMAXLUN               DBG_PutChar('M');

#define DBG_UDC_CBW_WRITE               //DBG_PutChar('w');
#define DBG_UDC_CBW_READ                //DBG_PutChar('r');
#define DBG_UDC_CBW_INQUIRY             DBG_PutChar('i');
#define DBG_UDC_CBW_READCAP             DBG_PutChar('c');
#define DBG_UDC_CBW_READFMTCAP          DBG_PutChar('f');
#define DBG_UDC_CBW_REQUESTSENSE        DBG_PutChar('s');
#define DBG_UDC_CBW_SCSIMODESENSE       DBG_PutChar('m');
#define DBG_UDC_CBW_TESTUNITREADY       //DBG_PutChar('t');
#define DBG_UDC_CBW_VERIFY              DBG_PutChar('v');
#define DBG_UDC_CBW_MEDIUMREMOVAL       DBG_PutChar('-');
#define DBG_UDC_CBW_STARTSTOP           DBG_PutChar('|');

#else

#define DBG_UDC_INT_ENTRANCE
#define DBG_UDC_INT_RESET
#define DBG_UDC_INT_SUSPEND
#define UDC_INT_RESUME
#define UDC_INT_CONFIG

#define UDC_EP0_EMPTYPACKAGE
#define UDC_EP0_INTOKEN

#define UDC_DEVDESCRIPT
#define UDC_CONDESCRIPT
#define UDC_GETMAXLUN

#define DBG_UDC_CBW_WRITE
#define DBG_UDC_CBW_READ
#define DBG_UDC_CBW_INQUIRY
#define DBG_UDC_CBW_READCAP
#define DBG_UDC_CBW_READFMTCAP
#define DBG_UDC_CBW_REQUESTSENSE
#define DBG_UDC_CBW_SCSIMODESENSE
#define DBG_UDC_CBW_TESTUNITREADY
#define DBG_UDC_CBW_VERIFY
#define DBG_UDC_CBW_MEDIUMREMOVAL
#define DBG_UDC_CBW_STARTSTOP

#endif

static void UDC_EP2OnPackageComplete(void)
{
    U32 i, m, n;

    m = s_USB_EP_BCR[2];
    n = (s_USB_EP_BCR[2] + 3) >> 2;                         // How many word in FIFO

    if(m == 0)
    {
        DBG_TraceStrLine("Empty Pack");

        s_USB_EP_CSR[2] = UDCCSR_PC;

        return;
    }

    for(i=0; i < n; i++)
    {  // Host know the endpoint FIFO size, so it asumed the n will not be bigger than the uEPOut.
        uEPOut.m_dwV32[i] = s_USB_EP_Data[2];
    }

    s_USB_EP_CSR[2] = UDCCSR_PC;

    if(uEPOut.m_dwV32[0] == USB_BOMS_CBW_SIGNATURE)
    {
//        DBG_TraceHex(NULL, CBWCB_OPCODE);

        switch(CBWCB_OPCODE)
        {
        case CBWCB_OPCODE_WRITE:
            m = uEPOut.m_bV8[17];
            m <<=8;
            m += uEPOut.m_bV8[18];
            m <<=8;
            m += uEPOut.m_bV8[19];
            m <<=8;
            m += uEPOut.m_bV8[20];
            n = uEPOut.m_bV8[22];
            n <<=8;
            n += uEPOut.m_bV8[23];
            UDC_CBWOnWrite(m, n);
            break;
        case CBWCB_OPCODE_READ:
            m = uEPOut.m_bV8[17];
            m <<=8;
            m += uEPOut.m_bV8[18];
            m <<=8;
            m += uEPOut.m_bV8[19];
            m <<=8;
            m += uEPOut.m_bV8[20];
            n = uEPOut.m_bV8[22];
            n <<=8;
            n += uEPOut.m_bV8[23];
            UDC_CBWOnRead(m, n);
            break;
        case CBWCB_OPCODE_INQUIRY:
            UDC_CBWOnInquiry();
            break;
        case CBWCB_OPCODE_READCAPACITY:
            UDC_CBWOnReadCapacity();
            break;
        case CBWCB_OPCODE_READFORMATCAPACITY:
            UDC_CBWOnReadFmtCapacity(uEPOut.m_bV8[15 + 8]);
            break;
        case CBWCB_OPCODE_REQUESTSENSE:
            UDC_CBWOnRequestSense();
            break;
        case CBWCB_OPCODE_SCSIMODESENSE:
            UDC_CBWOnModeSense(uEPOut.m_bV8[15 + 4]);
            break;
        case CBWCB_OPCODE_TESTUNITREADY:
/*
            USB host will often test USB client by this command.
*/
            DBG_UDC_CBW_TESTUNITREADY;
            UDC_CSWGood(0);
            break;
        case CBWCB_OPCODE_VERIFY:
/*
            This command is not found
*/
            DBG_UDC_CBW_VERIFY;
            UDC_CSWGood(0);
            break;
        case CBWCB_OPCODE_PREVENTALLOWMEDIUMREMOVAL:
/*
            Some time USB host will send out this command.
            When USB disk is ejected, USB host will send this command too.
            Not clear the usage.
*/
            DBG_UDC_CBW_MEDIUMREMOVAL;
            UDC_CSWGood(0);
            break;
        case CBWCB_OPCODE_STARTSTOP:
/*
            When USB disk is ejected.
*/
            DBG_UDC_CBW_STARTSTOP;
            UDC_CSWGood(0);

            SetEvent(MAIN_EVENT_U2D_STARTSTOP);

            break;
        default:
            DBG_TraceHex("Length", m);
            DBG_TraceMem("CBW", &uEPOut, 8);
            break;
        }
    }
    else
    {
        DBG_TraceString("Not a CBW");
    }
}

static void UDC_EP0OnPackageComplete(void)
{

    U32 s;

    // Process CSR0

    s = s_USB_EP_CSR[0] & (UDCCSR0_OPC | UDCCSR0_SA);

    if(s == (UDCCSR0_OPC))
    {
        // Not a Setup package
        // Should be an empty OUT package
        DBG_UDC_EP0_EMPTYPACKAGE;

        s_USB_EP_CSR[0] = UDCCSR0_OPC;
        return;
    }
    else if(s == 0)
    {
        // Should be an IN token
        DBG_UDC_EP0_INTOKEN;

        if(uEPOut.m_bV8[6] == 0x10)
        {
            UDC_ConfDescriptor_2();
        }
        else if(uEPOut.m_bV8[6] == 0x12)
        {
            UDC_DevDescriptor_2();
        }
        else if(uEPOut.m_bV8[6] == 0xEE)
        {
            UDC_EndDescriptor();
        }

        return;
    }

    uEPOut.m_dwV32[0] = s_USB_EP_Data[0];
    uEPOut.m_dwV32[1] = s_USB_EP_Data[0];

    s_USB_EP_CSR[0] = UDCCSR0_OPC | UDCCSR0_SA;             // Clear OPC will flush the data in the EndPoint FIFO

    if((uEPOut.m_bV8[0] == 0x80) && (uEPOut.m_bV8[1] == 0x06))
    {
        switch(uEPOut.m_bV8[3])
        {
        case 0x01:                                          // Device Descriptor
            DBG_UDC_DEVDESCRIPT;
            UDC_DevDescriptor();
            break;
        case 0x02:                                          // Configuration Descriptor
            DBG_UDC_CONDESCRIPT;
            UDC_ConfDescriptor();
            break;
        default:
            DBG_TraceStrLine("Unknow Type");
            break;
        }
    }
    else if((uEPOut.m_bV8[0] == 0xA1) && (uEPOut.m_bV8[1] == 0xFE))
    {
        DBG_UDC_GETMAXLUN;
        UDC_GetMaxLun();
    }
    else
    {
        DBG_TraceMem("Un-support", &uEPOut, 8);
    }
}

void UDC_Handler(void)
{
    U32 udcisr0, udcisr1;

    DBG_UDC_INT_ENTRANCE;

    udcisr0 = REG_UDCISR0;
    udcisr1 = REG_UDCISR1;

    if(udcisr1)
    {   // USB event
        if(udcisr1 & UDCICSR1_IRRS)
        {
            DBG_UDC_INT_RESET;
        }
        else if(udcisr1 & UDCICSR1_IRRU)
        {
            DBG_UDC_INT_RESUME;
        }
        else if(udcisr1 & UDCICSR1_IRSU)
        {
            DBG_UDC_INT_SUSPEND;
        }
        else if(udcisr1 & UDCICSR1_IRCC)
        {
            DBG_UDC_INT_CONFIG;

            REG_UDCCR |= UDCCR_SMAC;
        }

        REG_UDCISR0 = udcisr0;
        REG_UDCISR1 = udcisr1;

        return;
    }

    // EP 2
    if(udcisr0 & (UDCICSR_IRQ_E * UDCICSR0_IRQ_B))
    {
        DBG_TraceStrLine("EP2 Error");
        DBG_TraceHex("udcisr0", udcisr0);

        REG_UDCISR0 = udcisr0;
        return;
    }
    else if(udcisr0 & (UDCICSR_IRQ_P * UDCICSR0_IRQ_B))
    {
        UDC_EP2OnPackageComplete();

        REG_UDCISR0 = (UDCICSR_IRQ_P * UDCICSR0_IRQ_B);
        return;
    }

    // EP 0
    if(udcisr0 & (UDCICSR_IRQ_E * UDCICSR0_IRQ_0))
    {
        DBG_TraceStrLine("EP0 Error");
        DBG_TraceHex("udcisr0", udcisr0);

        REG_UDCISR0 = udcisr0;
        return;
    }
    else if(udcisr0 & (UDCICSR_IRQ_P * UDCICSR0_IRQ_0))
    {
        UDC_EP0OnPackageComplete();

        REG_UDCISR0 = (UDCICSR_IRQ_P * UDCICSR0_IRQ_0);
        return;
    }

    {  // The program should not be here because all of the cases have been processed already.
       DBG_TraceStrLine("Unknown INT");
    }
}

/*
    Test USB Client
*/

static void tPlugOUT(void)
{
    REG_UDCCR     = 0;                                      // disable UDC
    REG_UDCUP2OCR = UP2OCR_HXOE|UP2OCR_DMPDE|UP2OCR_DPPDE;  // pull down D+/D- to simulate a device plug out.
}

#endif



