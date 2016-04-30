
#define INCLUDE_MODULE_USB

// Standard Request

typedef struct __attribute__ ((packed)){
    U8  bmRequestType;
    U8  bRequest;
    U16 wValue;                                                                 // Depends on different Request Type
    U16 wIndex;                                                                 // Depends on different Request Type
    U16 wLength;                                                                // Data Length in Data Transaction
}USB_StandardRequest_t;

#define USB_bmRequestType_DIR_MASK                      (1 << 7)
#define USB_bmRequestType_DIR_OUT                       (0 << 7)
#define USB_bmRequestType_DIR_IN                        (1 << 7)
#define USB_bmRequestType_TYPE_MASK                     (3 << 5)
#define USB_bmRequestType_STANDARD                      (0 << 5)
#define USB_bmRequestType_CLASS                         (1 << 5)
#define USB_bmRequestType_MANUFACTRY                    (2 << 5)
#define USB_bmRequestType_RESERVE                       (3 << 5)
#define USB_bmRequestType_TARGET_MASK                   (0x1F)
#define USB_bmRequestType_TARGET_DEVICE                 (0)
#define USB_bmRequestType_TARGET_INTERFACE              (1)
#define USB_bmRequestType_TARGET_ENDPOINT               (2)
#define USB_bmRequestType_TARGET_OTHERS                 (3)

#define USB_bRequest_GET_STATUS                         (0)
#define USB_bRequest_CLEAR_FEATURE                      (1)
#define USB_bRequest_SET_FEATURE                        (3)
#define USB_bRequest_SET_ADDRESS                        (5)
#define USB_bRequest_GET_DESCRIPTOR                     (6)
#define USB_bRequest_SET_DESCRIPTOR                     (7)
#define USB_bRequest_GET_CONFIGURATION                  (8)
#define USB_bRequest_SET_CONFIGURATION                  (9)
#define USB_bRequest_GET_INTERFACE                      (10)
#define USB_bRequest_SET_INTERFACE                      (11)
#define USB_bRequest_SYNCH_FRAME                        (12)

#define USB_DESCRIPTOR_TYPE_DEVICE                      1
#define USB_DESCRIPTOR_TYPE_CONFIG                      2
#define USB_DESCRIPTOR_TYPE_STRING                      3
#define USB_DESCRIPTOR_TYPE_INTERFACE                   4
#define USB_DESCRIPTOR_TYPE_ENDPOINT                    5

#define USB_DESCRIPTOR_LENGTH_DEVICE                    18
#define USB_DESCRIPTOR_LENGTH_CONFIG                    9
#define USB_DESCRIPTOR_LENGTH_INTERFACE                 9
#define USB_DESCRIPTOR_LENGTH_ENDPOINT                  7

// Bulk Only Mass Storage Specific Request

#define USB_bRequest_BOMS_RESET                         (0xFF)
#define USB_bRequest_BOMS_GET_MAX_LUN                   (0xFE)

// Standard Descriptor

// Device Descriptor

typedef struct __attribute__ ((packed)){
    U8  m_bLength;                                                              // Length of Device Descriptor = 18
    U8  m_bDescriptorType;                                                      // Type Define of Device Descriptor = 1

    U16 m_wBCDVersion;                                                          // USB Protocol Version !!! When using this, must make sure it is 2Byte align !!!

    U8  m_bDeviceClass;                                                         // 0 for specified in the Interface Descriptor, FF for Manufactry Define
    U8  m_bDeviceSubClass;                                                      // 0 for specified in the Interface Descriptor, FF for Manufactry Define
    U8  m_bDeviceProtocol;                                                      // 0 for specified in the Interface Descriptor, FF for Manufactry Define
    U8  m_bMaxPacketSize0;                                                      // EndPoint0 Buffer size

    U16 m_wVID;                                                                 // !!! When using this, must make sure it is 2Byte align !!!
    U16 m_wPID;                                                                 // !!! When using this, must make sure it is 2Byte align !!!

    U16 m_wBCDDevice;                                                           // Device Version !!! When using this, must make sure it is 2Byte align !!!

    U8  m_bManufactureID;                                                       // Index to String Descriptor
    U8  m_bProductID;                                                           // Index to String Descriptor
    U8  m_bSerialNumberID;                                                      // Index to String Descriptor

    U8  m_bNumConfigurations;                                                   // How many configurations
}USB_DeviceDescriptor_t;

#define USB_DEV_DESC_VERSION_11                         0x0110
#define USB_DEV_DESC_VERSION_20                         0x0200

#define USB_DEV_DESC_VID_STD_DISK                       0x8086
#define USB_DEV_DESC_PID_STD_DISK                       0x0000

#define USB_DEV_DESC_VID_SERIAL                         0x9197
#define USB_DEV_DESC_PID_SERIAL                         0x1100

#define USB_DEV_DESC_VID_MS_SYNC                        0x045E
#define USB_DEV_DESC_PID_MS_SYNC                        0x00CE

#define USB_DEV_DESC_VID_MS_COMPOSITE                   0x9998
#define USB_DEV_DESC_PID_MS_COMPOSITE                   0x6600

// Config Descriptor

typedef struct __attribute__ ((packed)){
    U8  m_bLengthCfg;
    U8  m_bDescriptorTypeCfg;

    U16 m_wTotalLength;                                                         // !!! When using this, must make sure it is 2Byte align !!!

    U8  m_bNumInterfaces;                                                       // How many Interfaces
    U8  m_bConfigValue;                                                         // Parameter used by SetConfiguration() to select this configuration
    U8  m_bConfigurationID;                                                     // Index to String Descriptor
    U8  m_bAttributes;                                                          // Bit7 Fixed as 1, Bit6: Self-Powered, Bit5: Remote Wakeup

    U8  m_bMaxPower;                                                            // 2mA units
}USB_ConfigDescriptor_t;

#define USB_CNFG_DESC_MAX_POWER_UNIT_2mA                1

// Interface Descriptor

typedef struct __attribute__ ((packed)){
    U8 m_bLengthIntf;
    U8 m_bDescriptorTypeIntf;

    U8 m_bInterfaceNumber;
    U8 m_bAltSetting;

    U8 m_bNumEndpoints;                                                         // How many Endpoints

    U8 m_bInterfaceClass;
    U8 m_bInterfaceSubClass;
    U8 m_bInterfaceProtocol;

    U8 m_bInterfaceID;                                                          // Index to String Descriptor
}USB_InterfaceDescriptor_t;

#define USB_CNFG_DESC_CLASS_PROTOCOL_UNKNOWN            0xFF, 0xFF, 0xFF
#define USB_CNFG_DESC_CLASS_PROTOCOL_STD_DISK           0x08, 0x06, 0x50        // 0x08 for MASS STORAGE, // 0x06 for SCSI, 0x04 for UFI, // 0x50 for BULK ONLY TRANSPORT
#define USB_CNFG_DESC_CLASS_PROTOCOL_SERIAL             0x02, 0x02, 0x01

// End Point Descriptor

typedef struct __attribute__ ((packed)){
    U8  m_bLength;
    U8  m_bDescriptorType;

    U8  m_bAddress;                                                             // Bit[7]: IN, Bit[6:4]: Fixed as 0, Bit[3:0]: ID
    U8  m_bAttributes;

    U16 m_wMaxPacketSize;                                                       // !!! When using this, must make sure it is 2Byte align !!!
    U8  m_bInterval;                                                            // 0 for BULK
}USB_EndPointDescriptor_t;

#define USB_ENDP_DESC_ADDR_IN                           (1 << 7)
#define USB_ENDP_DESC_ADDR_OUT                          (0 << 7)
#define USB_ENDP_DESC_ADDR_ID(x)                        (x & 0xF)
#define USB_ENDP_DESC_ATTR_BULK                         2
#define USB_ENDP_DESC_ATTR_INT                          3

// CDC Class Specific Descriptor

#define USB_DESCRIPTOR_TYPE_CS_INTERFACE                0x24
#define USB_DESCRIPTOR_TYPE_CS_SUB_HEADER               0                       // Header Functional Descriptor
#define USB_DESCRIPTOR_TYPE_CS_SUB_CALLMNG              1                       // Call Manage Function Descriptor
#define USB_DESCRIPTOR_TYPE_CS_SUB_ACMMNG               2                       // Abstract Control Management Function Descriptor
#define USB_DESCRIPTOR_TYPE_CS_SUB_UNION                6                       // Union Functional Descriptor

#define USB_DESCRIPTOR_LENGTH_HEADERFUNC                5
#define USB_DESCRIPTOR_LENGTH_CALLMNG                   5
#define USB_DESCRIPTOR_LENGTH_ACM                       4
#define USB_DESCRIPTOR_LENGTH_UNION                     5

typedef struct __attribute__ ((packed)){
    U8  m_bFunctionLength;
    U8  m_bDescriptorType;
    U8  m_bDescriptorSubtype;
    U16 m_wBCDCDC;                                                              // !!! When using this, must make sure it is 2Byte align !!!
}USB_HeaderFunctionDescriptor_t;

typedef struct __attribute__ ((packed)){
    U8 m_bFunctionLength;
    U8 m_bDescriptorType;
    U8 m_bDescriptorSubtype;
    U8 m_bCapabilities;
    U8 m_bDataInterface;
}USB_CallManageFunctionDescriptor_t;

typedef struct __attribute__ ((packed)){
    U8 m_bFunctionLength;
    U8 m_bDescriptorType;
    U8 m_bDescriptorSubtype;
    U8 m_bCapabilities;
}USB_ACMManageFunctionDescriptor_t;

typedef struct __attribute__ ((packed)){
    U8 m_bFunctionLength;
    U8 m_bDescriptorType;
    U8 m_bDescriptorSubtype;
    U8 m_bMasterInterface;
    U8 m_bSlaveInterface;
}USB_UnionFunctionDescriptor_t;

// Complete Config Descriptor of Mass Storage

typedef struct __attribute__ ((packed)){
    USB_InterfaceDescriptor_t  m_Interface;
    USB_EndPointDescriptor_t   m_EndPointBulkIN;
    USB_EndPointDescriptor_t   m_EndPointBulkOUT;
}USB_FullInterfaceDisk_t;

// Complete Config Descriptor of MS Sync

typedef struct __attribute__ ((packed)){
    USB_InterfaceDescriptor_t  m_Interface;
    USB_EndPointDescriptor_t   m_EndPointBulkIN;
    USB_EndPointDescriptor_t   m_EndPointBulkOUT;
}USB_FullInterfaceMSSync_t;

// Complete Config Descriptor of USB Serial

typedef struct __attribute__ ((packed)){
    USB_InterfaceDescriptor_t           m_Interface;
    USB_HeaderFunctionDescriptor_t      m_HeaderFunction;
    USB_CallManageFunctionDescriptor_t  m_CallManageFunction;
    USB_ACMManageFunctionDescriptor_t   m_ACMManageFunction;
    USB_UnionFunctionDescriptor_t       m_UnionFunction;
    USB_EndPointDescriptor_t            m_EndPointBulkIN;
    USB_EndPointDescriptor_t            m_EndPointBulkOUT;
    USB_EndPointDescriptor_t            m_EndPointINT;
}USB_FullInterfaceSerial_t;

// Bulk Only Mass Storage Data Structure

typedef struct __attribute__ ((packed)){
    U32 m_dwSignature;                                                          // "USBC" -- 0x55, 0x53, 0x42, 0x43
    U32 m_dwTag;
    U32 m_dwCBWDataLength;
    U8  m_bFlags;
    U8  m_bLUN;
    U8  m_bCBLength;
    U8  m_bCB[16];
}USB_BulkOnlyMassStorage_CBW_t;

#define USB_BOMS_CBW_SIGNATURE                          0x43425355              // "USBC"

#define CBWCB_OPCODE_INQUIRY                            0x12
#define CBWCB_OPCODE_READCAPACITY                       0x25
#define CBWCB_OPCODE_REQUESTSENSE                       0x03
#define CBWCB_OPCODE_READ                               0x28
#define CBWCB_OPCODE_TESTUNITREADY                      0x00
#define CBWCB_OPCODE_PREVENTALLOWMEDIUMREMOVAL          0x1E
#define CBWCB_OPCODE_READFORMATCAPACITY                 0x23
#define CBWCB_OPCODE_UFIMODESENSE                       0x5A
#define CBWCB_OPCODE_SCSIMODESENSE                      0x1A
#define CBWCB_OPCODE_VERIFY                             0x2F
#define CBWCB_OPCODE_STARTSTOP                          0x1B
#define CBWCB_OPCODE_WRITE                              0x2A

typedef struct __attribute__ ((packed)){
    U32 m_dwSignature;                                                          // "USBS" -- 0x55, 0x53, 0x42, 0x53
    U32 m_dwTag;
    U32 m_dwCSWDataResidue;
    U8  m_bStatus;
}USB_BulkOnlyMassStorage_CSW_t;

#define USB_BOMS_CSW_SIGNATURE                          0x53425355              // "USBS"


