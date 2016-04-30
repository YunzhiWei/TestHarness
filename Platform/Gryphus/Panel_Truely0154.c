#define PANEL_CMD_TRUELY_0154_INIT

//#define ROTATE_180

static PANEL_COMMAND_t TRUELY0154_Initial[]=
{
    PANEL_COMMAND(0x80,0x008D,0)
    PANEL_COMMAND(0x92,0x0010,0)
    PANEL_COMMAND(0x11,0x001C,0)
    PANEL_COMMAND(0x12,0x4111,0)
    PANEL_COMMAND(0x13,0x0076,0)
    PANEL_COMMAND(0x14,0x4A46,0)
    PANEL_COMMAND(0x10,0x0800,15)
    PANEL_COMMAND(0x11,0x011C,15)
    PANEL_COMMAND(0x11,0x031C,15)
    PANEL_COMMAND(0x11,0x071C,15)
    PANEL_COMMAND(0x11,0x0F1C,32)
    PANEL_COMMAND(0x11,0x0F3C,40)
    PANEL_COMMAND(0x01,0x1128,0)
    PANEL_COMMAND(0x02,0x0100,0)
#ifdef ROTATE_180
    PANEL_COMMAND(0x03,0x1000,0)
#else
    PANEL_COMMAND(0x03,0x1030,0)
#endif
    PANEL_COMMAND(0x07,0x1012,0)
    PANEL_COMMAND(0x08,0x0808,0)
    PANEL_COMMAND(0x0B,0x1105,0)
    PANEL_COMMAND(0x0C,0x0110,0)
    PANEL_COMMAND(0x0F,0x1A01,15)
    PANEL_COMMAND(0x15,0x0070,0)
    PANEL_COMMAND(0x36,0x00EF,0)
    PANEL_COMMAND(0x37,0x0000,0)
    PANEL_COMMAND(0x38,0x013F,0)
    PANEL_COMMAND(0x39,0x0000,0)
    PANEL_COMMAND(0x50,0x0101,0)
    PANEL_COMMAND(0x51,0x0500,0)
    PANEL_COMMAND(0x52,0x0500,0)
    PANEL_COMMAND(0x53,0x0500,0)
    PANEL_COMMAND(0x54,0x0805,0)
    PANEL_COMMAND(0x55,0x0909,0)
    PANEL_COMMAND(0x56,0x0000,0)
    PANEL_COMMAND(0x57,0x0000,0)
    PANEL_COMMAND(0x58,0x0700,0)
    PANEL_COMMAND(0x59,0x0500,0)
    PANEL_COMMAND(0x07,0x0012,15)
    PANEL_COMMAND(0x07,0x0013,15)
    PANEL_COMMAND(0x07,0x0017,25)
    PANEL_COMMAND(0x20,0x0000,0)
    PANEL_COMMAND(0x21,0x0000,0)
    PANEL_COMMAND(0x22,0x0000,0)

    PANEL_COMMAND(0x00, 0x0000, PANEL_COMMAND_END_FLAG)
};

static PANEL_COMMAND_t TRUELY0154_Sleep[]=
{
    PANEL_COMMAND(0x15,0x0000,10)
    PANEL_COMMAND(0x07,0x0016,20)
    PANEL_COMMAND(0x07,0x0000,20)
    PANEL_COMMAND(0x10,0x0002,10)

    PANEL_COMMAND(0x00, 0x0000, PANEL_COMMAND_END_FLAG)
};

#undef ROTATE_180
