
#define INCLUDE_MODULE_TIMER

/*
    Basic Functions
    Supported by other Modules
*/

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

#define TIMER_FREE_COUNTER              (* MH_OSCR0)

typedef enum
{
    // Please refer to the Developer Manual about the vaule!!!
    e_TIMER_UNIT_Stop   = 0,
    e_TIMER_UNIT_32768  = 1,
    e_TIMER_UNIT_1mS    = 2,
    e_TIMER_UNIT_1S     = 3,
    e_TIMER_UNIT_1uS    = 4
}t_TIMER_UNIT;

void Timer_Delay(U32 dwID, t_TIMER_UNIT tUnit, U32 dwCount);
void OSTimer01_INTHandler(void);

void Timer_Start(U32 dwID, t_TIMER_UNIT tUnit);
U32  Timer_Stop(U32 dwID);


