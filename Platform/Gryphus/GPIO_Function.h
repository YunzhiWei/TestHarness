
void GPIO_INTHandler(void);
void GPIO_INTHandlerGPIO1(void);

void GPIO_PanelReset(void);

void GPIO_CameraReset(void);
void GPIO_CameraPowerON(void);
void GPIO_CameraPowerOFF(void);

void GPIO_ModemOnKeyHi(void);
void GPIO_ModemOnKeyLo(void);
void GPIO_ModemResetHi(void);
void GPIO_ModemResetLo(void);
void GPIO_ModemReset(void);
void GPIO_ModemONKEY(U32 dwPulse);
U32  GPIO_ModemStatus(void);

void GPIO_SPKEnable(void);
void GPIO_SPKDisable(void);

#define GPIO_MODEMPOWERON               GPIO_ModemONKEY(100)
#define GPIO_MODEMPOWEROFF              GPIO_ModemONKEY(1200)

