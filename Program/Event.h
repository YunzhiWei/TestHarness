
#define INCLUDE_MODULE_EVENT

typedef enum
{
    MAIN_EVENT_U2D_STARTSTOP            = (1 << 0),
    MAIN_EVENT_MMCSD_INSERT             = (1 << 1),
    MAIN_EVENT_PMIC_EVENT               = (1 << 2),
    MAIN_EVENT_POWER_OFF                = (1 << 3),
    MAIN_EVENT_TOUCH_DOWN               = (1 << 4),
    MAIN_EVENT_TOUCH_READY              = (1 << 5),
    MAIN_EVENT_CAMERA                   = (1 << 6),
    MAIN_EVENT_USB_CABLE_IN             = (1 << 7),
    MAIN_EVENT_USB_HYPERT_OPEN          = (1 << 8),
    MAIN_EVENT_USB_HYPERT_CLOSE         = (1 << 9),

    MAIN_EVENT_NULL                     = 0,
    MAIN_EVENT_ALL                      = 0xFFFFFFFF
}Event_Flag_t;

char OnMenuIdle(void);

