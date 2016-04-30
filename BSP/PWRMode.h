
#define INCLUDE_MODULE_PWRMODE

#define PWR_MODE_S0D0C0_RUN             0
#define PWR_MODE_S0D0C1_IDLE            1
#define PWR_MODE_S0D1C2_LCDREF          2
#define PWR_MODE_S0D2C2_STANDBY         3
#define PWR_MODE_S0D0CS_RINGOSC         5
#define PWR_MODE_S2D3C4_SLEEP           6
#define PWR_MODE_S3D4C4_DSLEEP          7

#define BOOT_UP_CONDITION_ONKEY         (1u << 0)
#define BOOT_UP_CONDITION_VOTAGE        (1u << 1)

void PWRMode_Initial(void);

U32  PWRMode_GetBootupScenario(void);

void PWRMode_SWGPIOReset(void);

void PWRMode_PreStandby(void);
void PWRMode_PostStandby(void);

void PWRMode_PreSleep(void);
void PWRMode_PostSleep(void);

void PWRMode_PreDSleep(void);
void PWRMode_PostDSleep(void);

void TestAutoPWRMode(void);
void TestPWRMode(void);

