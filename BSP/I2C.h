#define INCLUDE_MODULE_I2C

void I2C_Initial(void);
int  I2C_Write(U8 bSlaveAddr, U8 * pBuf, U32 dwSize, BOOL isSendStop);
int  I2C_Read(U8 bSlaveAddr, U8 * pBuf, U32 dwSize, BOOL isSendStop);

