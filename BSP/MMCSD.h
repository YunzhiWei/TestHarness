
#define INCLUDE_MODULE_MMCSD

#define MMCSD_BLOCK_NUMBER              1
#define MMCSD_BLOCK_SIZE                512

// clock rate constant
typedef enum {
  SD_19_5MHz  = 0x0,
  SD_9_75MHz  = 0x1,
  SD_4_88MHz  = 0x2,
  SD_2_44MHz  = 0x3,
  SD_1_22MHz  = 0x4,
  SD_609KHz   = 0x5,
  SD_304KHz   = 0x6,
  SD_26MHz    = 0x7
}SD_CLOCK_SPEED;

// response size
typedef enum {
  SD_RESPONSE_SIZE_32 = 0,
  SD_RESPONSE_SIZE_120
}SD_RESP_SIZE;

// response TYPE
typedef enum {
 SD_RESPONSE_TYPE_NONE = 0,
 SD_RESPONSE_TYPE_R1   = 1,
 SD_RESPONSE_TYPE_R2   = 2,
 SD_RESPONSE_TYPE_R3   = 3,
 SD_RESPONSE_TYPE_R6   = 6
}SD_Response_Type_t;

// Flags used to send command
// command types
enum {
  SD_NORMAL_COMMAND  = 1L,
  SD_INIT_COMMAND    = 2L,  // first command require 80 clock preceded
  SD_STOP_COMMAND    = 3L,  // stop command, including CMD12,CMD52
  SD_SUSPEND_COMMAND = 4L,  // sdio CMD52, supend current transfer
  SD_RESUME_COMMAND  = 5L,  // sdio CMD52, resume a suspended transfer
  SD_CMDTYPE_MASK    = 0x000000FF
};

// response types
enum {
  SD_RESPONSE_NONE = 1L<<8,
  SD_RESPONSE_R1 = 2L<<8,
  SD_RESPONSE_R1B = 3L<<8,
  SD_RESPONSE_R2 = 4L<<8,
  SD_RESPONSE_R3 = 5L<<8,
  SD_RESPONSE_R4 = 6L<<8,
  SD_RESPONSE_R5 = 7L<<8,
  SD_RESPONSE_R5B = 8L<<8,
  SD_RESPONSE_R6 = 9L<<8,
  SD_RESPONSE_MASK = 0x0000FF00
};

// transfer types
enum {
  SD_4BIT_ENABLE = 0x01L<<16,
  SD_DMA_ENABLE = 0x02L<<16,
  SD_DATA_ENABLE = 0x04L<<16,
  SD_DATA_WRITE =  0x08L<<16,
  SD_STREAM_MODE = 0x10L<<16,
  SD_SDIO_INT_ENABLE = 0x20<<16,
  SD_SPI_MODE = 0x40<<16,
  SD_TRANSFER_MODE_MASK = 0x00FF0000
};

typedef enum
{
    SD_CMD0     = 0x0,  // go idle state
    SD_CMD1     = 0x1,  // send op command
    SD_CMD2     = 0x2,  // all send cid
    SD_CMD3     = 0x3,  // set relative addr to MMC card; ask SD card to publish a new RCA
    SD_CMD4     = 0x4,  // set dsr
    SD_CMD6     = 0x6,  // SET bus width
    SD_CMD7     = 0x7,  // select/deselect card: Set the card into transfer state.
    SD_CMD8     = 0x8,  // SDHC support
    SD_CMD9     = 0x9,  // send csd
    SD_CMD10    = 0xa,  // send cid
    SD_CMD11    = 0xb,  // read data until stop
    SD_CMD12    = 0xc,  // stop transmission
    SD_CMD13    = 0xd,  // send status
    SD_CMD15    = 0xf,  // go inactive state
    SD_CMD16    = 0x10, // set block length
    SD_CMD17    = 0x11, // read single block
    SD_CMD18    = 0x12, // read multiple block
    SD_CMD20    = 0x14, // write data until stop
    SD_CMD24    = 0x18, // write block
    SD_CMD25    = 0x19, // write multiple block
    SD_CMD26    = 0x1a, // program CID
    SD_CMD27    = 0x1b, // program CSD
    SD_CMD28    = 0x1c, // set write prot
    SD_CMD29    = 0x1d, // clr write prot
    SD_CMD30    = 0x1e, // send write prot
    SD_CMD32    = 0x20, // tag sector start
    SD_CMD33    = 0x21, // tag sector end
    SD_CMD34    = 0x22, // untag sector
    SD_CMD35    = 0x23, // tag erase group start
    SD_CMD36    = 0x24, // tag erase group end
    SD_CMD37    = 0x25, // untag erase group
    SD_CMD38    = 0x26, // erase
    SD_CMD39    = 0x27, // fast IO
    SD_CMD40    = 0x28, // go irq state
    APP_ACMD41  = 0x29, // Send HCS(Host capacity support information) and ask card to send
                                //OCR content in the response.
                                //SD card use ACMD41 to poll whether card is ready
    SD_CMD42    = 0x2a, // lock-unlock
    SD_CMD55    = 0x37, // app cmd
    SD_CMD56    = 0x38, // gen cmd
    SPI_CMD58   = 0x3a, // read ocr
    SPI_CMD59   = 0x3b, // crc on-off
    SD_CMD60    = 0x3c, // reserved for manufacturer
    SD_CMD61    = 0x3d, // reserved for manufacturer
    SD_CMD62    = 0x3e, // reserved for manufacturer
    SD_CMD63    = 0x3f, // reserved for manufacturer
    SD_ACMD6    = 0x146,// Define the data bus width('00'=1bit or '10'=4bit)
    SD_ACMD13   = 0x14D,
    SD_ACMD22   = 0x156,
    SD_ACMD23   = 0x157,
    SD_ACMD41   = 0x169,
    SD_ACMD42   = 0x16a,
    SD_ACMD51   = 0x173
} SD_CMD;

typedef enum{
    UNKNOW_CARD=0,
    CARD_TYPE_MMC,
    CARD_TYPE_SD,
    CARD_TYPE_SDHC,
    CARD_TYPE_SDIO
}CARD_TYPE;

typedef struct{
    U16 m_bOIDH: 8;         // OEM/Application ID
    U16 m_bMID:  8;         // Manufacturer ID
    U16 m_bPNMH: 8;         // Product name
    U16 m_bOIDL: 8;         // OEM/Application ID
    U16 m_bPNMM: 16;        // Product name
    U16 m_bPNML: 16;        // Product name
    U16 m_bPSNH: 8;         // Product serial number
    U16 m_bPRV:  8;         // Product revision
    U16 m_bPSNM: 16;        // Product serial number
    U16 m_bMDTH: 8;         // Manufacturing date
    U16 m_bPSNL: 8;         // Product serial number
    U16 m_bCRC:  8;         // CRC7 checksum
    U16 m_bMDTL: 8;         // Manufacturing date
}CID_bit_t, *PCID_bit_t;


typedef struct{
    U32 m_dwMID;            // Manufacturer ID
    U32 m_dwOID;            // OEM/Application ID
    U32 m_dwPNM[2];         // Product name
    U32 m_dwPRV;            // Product revision
    U32 m_dwPSN;            // Product serial number
    U32 m_dwMDT;            // Manufacturing date
}CID_t, *PCID_t;


typedef struct{
    U16 m_bReserved_3F      : 8;
    U16 m_bCSD_STRUCTURE    : 8;

    U16 m_bNSAC             : 8;
    U16 m_bTAAC             : 8;

    U16 m_bCCCH             : 8;
    U16 m_bTRANSPEED        : 8;

    U16 m_bCSizeH           : 2;
    U16 m_bReserved         : 2;
    U16 m_bDSR_IMP          : 1;
    U16 m_bReadBLKMisalign  : 1;
    U16 m_bWriteBLKMisalign : 1;
    U16 m_bReadBLKPartial   : 1;
    U16 m_bReadBLLength     : 4;
    U16 m_bCCCL             : 4;

    U16 m_bVDD_R_CURR_MAX   : 3;
    U16 m_bVDD_R_CURR_MIN   : 3;
    U16 m_bCSizeL           : 10;

    U16 m_bNoused           : 6;
    U16 m_bEraseBlkEn       : 1;
    U16 m_bCSzieMult        : 3;
    U16 m_bVDD_W_CURR_MAX   : 3;
    U16 m_bVDD_W_CURR_MIN   : 3;
}CSD_bit_t, *PCSD_bit_t;

typedef struct{
    U32 m_dwTranSpeed;
    U32 m_dwReadBlockLength;
    U32 m_dwCSize;
    U32 m_dwCSizeMult;
    U32 m_dwTAAC;
    U32 m_dwNSAC;
    U32 m_dwCCC;
}CSD_t, *PCSD_t;

typedef struct{
    U16 m_bOCRH         : 8;
    U16 m_bReserved_3F  : 6;
    U16 m_bTransmission : 1;
    U16 m_bStart        : 1;
    U16 m_bOCRM         : 16;
    U16 m_bCRCDummy     : 8;
    U16 m_bOCRL         : 8;
}Response_R3_bit_t, *PResponse_R3_bit_t;

typedef struct{
    U32 m_dwOCR;
}Response_R3_t, *PResponse_R3_t;

typedef struct{
    U16 m_bCardStatusH  : 8;
    U16 m_bCommandIndex : 6;
    U16 m_bTransmission : 1;
    U16 m_bStart        : 1;
    U16 m_bCardStatusM  : 16;
    U16 m_bCRCDummy     : 8;
    U16 m_bCardStatusL  : 8;
}Response_R1_bit_t, *PResponse_R1_bit_t;

typedef struct{
    U32 m_dwCommandIndex;
    U32 m_dwCardStatus;
}Response_R1_t, *PResponse_R1_t;

typedef struct{
    U16 m_bR2H          : 8;
    U16 m_bReserved     : 6;
    U16 m_bTransmission : 1;
    U16 m_bStart        : 1;
    CID_bit_t m_bCID;
}Response_R2_bit_t, *PResponse_R2_bit_t;

/*
typedef struct{
    U16 m_bR2H          : 8;
    U16 m_bReserved     : 6;
    U16 m_bTransmission : 1;
    U16 m_bStart        : 1;
}CSD_bit_t, *PCSD_bit_t;
*/

typedef struct{
    U32 m_dwR2[4];
    CID_t m_CID;
}Response_R2_t, *PResponse_R2_t;

typedef struct{
    U16 m_bArgumentH    : 8;
    U16 m_bCommandIndex : 6;
    U16 m_bTransmission : 1;
    U16 m_bStart        : 1;
    U16 m_bArgumentM    : 16;
    U16 m_bCRCDummy     : 8;
    U16 m_bArgumentL    : 8;
}Response_R6_bit_t, *PResponse_R6_bit_t;

typedef struct{
    U32 m_dwCommandIndex;
    U32 m_dwRCA;
    U32 m_dwCardStatus;
}Response_R6_t, *PResponse_R6_t;

void SD_Initial(void);
int  SD_OnCardInsert(void);
void SD_BlockRead1(U32 dwBlockID, U8 *pBuffer, U32 dwSize);
void SD_BlockReadN(U32 dwBlockID, U8 *pBuffer, U32 dwSize);
void SD_BlockWrite(U32 dwBlockID, U8 *pBuffer, U32 dwSize);
void SD_BlockErase(U32 dwStartID, U32 dwEndID);

