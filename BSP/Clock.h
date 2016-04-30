#define INCLUDE_MODULE_CLOCK

#define CLOCK_REG_SET_A                 0
#define CLOCK_REG_SET_B                 1
#define CLOCK_REG_SET_LAST              CLOCK_REG_SET_B

void Clock_Initial(void);
void Clock_Enable(U32 dwRegSet, U32 dwMask, BOOL bTrue);
void TestClock(void);

