
#include "_Platform.h"

#define GPIO_REG_GPDR0                  (*MH_GPDR0)
#define GPIO_REG_GPDR1                  (*MH_GPDR1)
#define GPIO_REG_GPDR2                  (*MH_GPDR2)
#define GPIO_REG_GPDR3                  (*MH_GPDR3)

#define GPIO_REG_GPSR0                  (*MH_GPSR0)
#define GPIO_REG_GPSR1                  (*MH_GPSR1)
#define GPIO_REG_GPSR2                  (*MH_GPSR2)
#define GPIO_REG_GPSR3                  (*MH_GPSR3)

#define GPIO_REG_GPCR0                  (*MH_GPCR0)
#define GPIO_REG_GPCR1                  (*MH_GPCR1)
#define GPIO_REG_GPCR2                  (*MH_GPCR2)
#define GPIO_REG_GPCR3                  (*MH_GPCR3)

#define GPIO_REG_GSRER0                 (*MH_GSRER0)
#define GPIO_REG_GSRER1                 (*MH_GSRER1)
#define GPIO_REG_GSRER2                 (*MH_GSRER2)
#define GPIO_REG_GSRER3                 (*MH_GSRER3)

#define GPIO_REG_GSFER0                 (*MH_GSFER0)
#define GPIO_REG_GSFER1                 (*MH_GSFER1)
#define GPIO_REG_GSFER2                 (*MH_GSFER2)
#define GPIO_REG_GSFER3                 (*MH_GSFER3)

#define GPIO_REG_GPLR0                  (*MH_GPLR0)
#define GPIO_REG_GPLR1                  (*MH_GPLR1)
#define GPIO_REG_GPLR2                  (*MH_GPLR2)
#define GPIO_REG_GPLR3                  (*MH_GPLR3)

#define GPIO_REG_GEDR0                  (*MH_GEDR0)
#define GPIO_REG_GEDR1                  (*MH_GEDR1)
#define GPIO_REG_GEDR2                  (*MH_GEDR2)
#define GPIO_REG_GEDR3                  (*MH_GEDR3)

#include "GPIO_Function.c"

void GPIO_Initial(void)
{
#define REG_GPDR0_VAL                   (REG_GPCR0_VAL | REG_GPSR0_VAL)
#define REG_GPDR1_VAL                   (REG_GPCR1_VAL | REG_GPSR1_VAL)
#define REG_GPDR2_VAL                   (REG_GPCR2_VAL | REG_GPSR2_VAL)
#define REG_GPDR3_VAL                   (REG_GPCR3_VAL | REG_GPSR3_VAL)

    // Output clear
    GPIO_REG_GPCR0 = REG_GPCR0_VAL;
    GPIO_REG_GPCR1 = REG_GPCR1_VAL;
    GPIO_REG_GPCR2 = REG_GPCR2_VAL;
    GPIO_REG_GPCR3 = REG_GPCR3_VAL;

    // Output set
    GPIO_REG_GPSR0 = REG_GPSR0_VAL;
    GPIO_REG_GPSR1 = REG_GPSR1_VAL;
    GPIO_REG_GPSR2 = REG_GPSR2_VAL;
    GPIO_REG_GPSR3 = REG_GPSR3_VAL;

    // Direction
    GPIO_REG_GPDR0 = REG_GPDR0_VAL;
    GPIO_REG_GPDR1 = REG_GPDR1_VAL;
    GPIO_REG_GPDR2 = REG_GPDR2_VAL;
    GPIO_REG_GPDR3 = REG_GPDR3_VAL;

    // Rasing Interrupt Enable
    GPIO_REG_GSRER0 = REG_GSRER0_VAL;
    GPIO_REG_GSRER1 = REG_GSRER1_VAL;
    GPIO_REG_GSRER2 = REG_GSRER2_VAL;
    GPIO_REG_GSRER3 = REG_GSRER3_VAL;

    // Falling Interrupt Enable
    GPIO_REG_GSFER0 = REG_GSFER0_VAL;
    GPIO_REG_GSFER1 = REG_GSFER1_VAL;
    GPIO_REG_GSFER2 = REG_GSFER2_VAL;
    GPIO_REG_GSFER3 = REG_GSFER3_VAL;
}

