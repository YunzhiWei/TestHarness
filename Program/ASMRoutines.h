
void JumpToRun(U32 dwAddress);

void WriteClkCfg(U32 r0);
U32  ReadClkCfg(void);

void PWRMode_Set(U32 dwPowerMode);

U32  GetPC(void);
U32  GetCPUInformation(void);

void MMUBaseSet(U32 dwAddr);
void MMUEnable(void);

void EnableICache(void);
void EnableDCache(void);

void DDRSDRAMInitial(void);

