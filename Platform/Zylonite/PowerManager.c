
static void tEnterIdle(void)
{
    DBG_TraceStrLine("Idle...");
    DBG_CountDown(3);

    // Any Interrupt will wake up idle
    PWRMode_Set(PWR_MODE_S0D0C1_IDLE);

    DBG_TraceStrLine("Run...");
}

static void tEnterStandby(void)
{
    // This program must be executing in SRAM
    PWRMode_PreStandby();

    DBG_TraceStrLine("Standby...");
    DBG_CountDown(3);

    PWRMode_Set(PWR_MODE_S0D2C2_STANDBY);

	{
        const MMU_Mapping_t vpMapping[] = {
            {MMU_ADDR_FORMAT(0x00000000),        MMU_ADDR_FORMAT(EXE_IMAGE_BASE),       1,                                  MMU_MAPPING_TYPE_UNCATCH},  // This program is running in this space and the vector table is at the beginning
            {MMU_ADDR_FORMAT(0x40000000),        MMU_ADDR_FORMAT(0x40000000),           512,                                MMU_MAPPING_TYPE_UNCATCH},  // 0x40000000 ~ 0x5FFFFFFF: MH IO registers
            {MMU_ADDR_FORMAT(SYS_SDRAM_BASE),    MMU_ADDR_FORMAT(PHISICAL_SDRAM_BASE),  PHISICAL_SDRAM_SIZE/(1024 * 1024),  MMU_MAPPING_TYPE_UNCATCH},  // We map all physical memory to logical virtual memory
            {0,0,0,0},                                          // End of MMU Table
        };

        MMUTableSetup(vpMapping);
	}
    DDRSDRAMInitial();

    PWRMode_PostStandby();
}

static void tEnterSleep(void)
{
    PWRMode_PreSleep();

    DBG_TraceStrLine("Sleep...");
    DBG_CountDown(3);

    PWRMode_Set(PWR_MODE_S2D3C4_SLEEP);

    PWRMode_PostSleep();
}

static void tEnterDeepSleep(void)
{
    PWRMode_PreDSleep();

    DBG_TraceStrLine("DS...");
    DBG_CountDown(3);

    PWRMode_Set(PWR_MODE_S3D4C4_DSLEEP);

    PWRMode_PostDSleep();
}

#if 0
static void tEnterIdleRingOscillator(void)
{
    U32 delay = 0;

    REG_MDCNFG |= MDCNFG_HWFREQ;
    REG_DDRHCAL |= DDRHCAL_HCEN;

    REG_ACCR |= ACCR_D0CS;
    while(!(REG_ACCR & ACCR_D0CS))  ;

    PWRMode_Set(PWR_MODE_S0D0CS_RINGOSC);

    while(!(REG_ACSR & ACSR_RO_S))  ;

    delay = TIMER_FREE_COUNTER + 325;
    while(TIMER_FREE_COUNTER < delay)   ;

    REG_ACCR |= ACCR_XPDIS | ACCR_SPDIS;

    while((REG_ACSR & (ACSR_XPDIS | ACSR_SPDIS)) != (ACSR_XPDIS | ACSR_SPDIS))  ;
}

static void tExitIdleRingOscillator(void)
{
    REG_MDCNFG |= MDCNFG_HWFREQ;
    REG_DDRHCAL |= DDRHCAL_HCEN;

    if(REG_ACSR & (ACSR_XPDIS | ACSR_SPDIS))
    {
        REG_ACCR &= ~(ACCR_SPDIS | ACCR_XPDIS);
        while(REG_ACCR & (ACCR_SPDIS | ACCR_XPDIS))  ;

        while((REG_ACSR & (ACSR_XPDIS | ACSR_SPDIS)) != (ACSR_XPDIS | ACSR_SPDIS))  ;
    }

    REG_ACCR &= ~ACCR_D0CS;
    while(REG_ACCR & ACCR_D0CS)  ;

    PWRMode_Set(PWR_MODE_S0D0CS_RINGOSC);
}
#endif

void TestPWRMode(void)
{
    const MENU_REC menu[] = {
    {'i', "idle",      tEnterIdle},
    {'b', "standby",   tEnterStandby},
    {'s', "sleep",     tEnterSleep},
    {'D', "Dsleep",    tEnterDeepSleep},
    {'r', "SW Reset",  PWRMode_SWGPIOReset},

//    {'0', "enter D0CS",tEnterIdleRingOscillator},
//    {'x', "exit D0CS", tExitIdleRingOscillator},

    {'\0'}
};

    MenuFunction("Power mode", menu);
}


