
// Camera on Main Board

#define CAM_PRODUCT_ID                  0x2620
#define CAM_I2C_SLAVE_ADDRESS           0x60

#define CAM_DELAY_FIX_TIME              1

typedef struct
{
    U8 m_cRegAddress;
    U8 m_cRegData;
}CAM_Command_Format_t;

typedef struct
{
    CAM_Command_Format_t 	m_tCommand;
}CAM_Command_t;

#define CAM_COMMAND_FORMAT(regAddr, regData)  {regAddr, regData}

const static CAM_Command_t CAM_Command[]={
    {CAM_COMMAND_FORMAT(0x12, 0x80)},
    {CAM_COMMAND_FORMAT(0x12, 0x20)}
};


