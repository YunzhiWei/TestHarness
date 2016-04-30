// 2 Mega, small

#define CAM_PRODUCT_ID                  0x2480
#define CAM_I2C_SLAVE_ADDRESS           0x78

typedef struct
{
    U8 m_cCommandHi;
    U8 m_cCommandLo;
    U8 m_cDataHi;
    U8 m_cDataLo;
}CAM_Command_Format_t;

typedef struct
{
    CAM_Command_Format_t    m_tCommand;
    U16                     m_wDelay;
}CAM_Command_t;

#define CAM_COMMAND_FORMAT(regAddr, regData)  {HIBYTE(regAddr), LOBYTE(regAddr), HIBYTE(regData), LOBYTE(regData)}

const static CAM_Command_t CAM_Command[]={
    {CAM_COMMAND_FORMAT(0x001C, 0x5801), 0},                // MCU_BOOT_MODE
    {CAM_COMMAND_FORMAT(0x001C, 0x5800), 100},              // MCU_BOOT_MODE
    {CAM_COMMAND_FORMAT(0x0016, 0x00FF), 0},                // CLOCKS_CONTROL
    {CAM_COMMAND_FORMAT(0x0018, 0x0028), 0},                // STANDBY_CONTROL
    {CAM_COMMAND_FORMAT(0x301A, 0x12C8), 500},              // RESET_REGISTER
    {CAM_COMMAND_FORMAT(0x301A, 0x12CC), 0},                // RESET_REGISTER
    {CAM_COMMAND_FORMAT(0x0014, 0xB047), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0xB045), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0x2145), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0010, 0x0B1A), 0},                // PLL_DIVIDERS
    {CAM_COMMAND_FORMAT(0x0012, 0x0031), 0},                // PLL_P_DIVIDERS
    {CAM_COMMAND_FORMAT(0x0014, 0x2545), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0x2547), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0x3447), 1},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0x3047), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x0014, 0x3046), 0},                // PLL_CONTROL
    {CAM_COMMAND_FORMAT(0x098C, 0x2703), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x00A0), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2705), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0078), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2707), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0500), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2709), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0400), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x270D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x270F), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2711), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x040D), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2713), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x050D), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2715), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0111), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2717), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x046C), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2719), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x00AC), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x271B), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x01F1), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x271D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x013F), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x271F), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0262), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2721), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0672), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2723), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0004), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2725), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0004), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2727), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x040B), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2729), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x050B), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x272B), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0111), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x272D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0024), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x272F), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x004C), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2731), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x00F9), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2733), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x00A7), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2735), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x04C5), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2737), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0672), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2739), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x273B), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x027F), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x273D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x273F), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x01FF), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2747), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2749), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x04FF), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x274B), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0000), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x274D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x03FF), 0},                // MCU_DATA_0
#ifdef TEST_MODE_RGB
    {CAM_COMMAND_FORMAT(0x098C, 0x2755), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0020), 0},                // MCU_DATA_0
#endif
    {CAM_COMMAND_FORMAT(0x098C, 0x222D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0042), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA408), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x000B), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA409), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x000E), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA40A), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x000D), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA40B), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0010), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2411), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0042), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2413), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x004F), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2415), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0042), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0x2417), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x004F), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA40D), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0002), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA410), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0001), 0},                // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA103), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0006), 500},              // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA103), 0},                // MCU_ADDRESS
    {CAM_COMMAND_FORMAT(0x0990, 0x0005), 500},              // MCU_DATA_0
    {CAM_COMMAND_FORMAT(0x098C, 0xA103), 0},                // MCU_ADDRESS[Return to Preview]
    {CAM_COMMAND_FORMAT(0x0990, 0x0001), 0}                 // SEQ_CMD
};

