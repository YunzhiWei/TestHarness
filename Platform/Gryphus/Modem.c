static U32 tModemKey(void)
{
#define DBG_MSG_POS_ACTION              0, 200

    U32 r;
    U32 scode[KP_SCAN_CODE_NUMBER];
    U32 row, col;

    r = KP_MatrixScan(&row, &col, scode);

    if(ERR_CODE_KP_SINGLE == r)
    {
        U8 str[] = "    ";
        str[0] = KP_MatrixTranslate(row, col);
        MY_TraceStrLine(str);

        if(str[0] == 'k')
        {
            MY_TraceStrLine("RST");
            GPIO_ModemReset();
        }
        else if(str[0] == 'a')
        {
            MY_TraceStrLine("On");
            GPIO_MODEMPOWERON ;
        }
        else if(str[0] == 'b')
        {
            MY_TraceStrLine("Off");
            GPIO_MODEMPOWEROFF ;
        }
        else if(str[0] == 'q')
        {
            MY_TraceStrLine("KHi");
            GPIO_ModemOnKeyHi();
        }
        else if(str[0] == 'r')
        {
            MY_TraceStrLine("KLo");
            GPIO_ModemOnKeyLo();
        }
        else if(str[0] == 'i')
        {
            GPIO_ModemResetHi();
            MY_TraceStrLine("RHi");
        }
        else if(str[0] == 'j')
        {
            GPIO_ModemResetLo();
            MY_TraceStrLine("RLo");
        }
    }

    return(r);
}

static U32 tModemStatus(U32 dwLastStatus)
{
#define DBG_MSG_POS_STATUS              0, 300
    U32 status;

    status = GPIO_ModemStatus();

    if(status == dwLastStatus) return(status);

    if(status)
    {
        MY_TraceStrLine("Modem OFF");
    }
    else
    {
        MY_TraceStrLine("Modem ON");
    }

    return(status);
}

static void tFullControl(U32 dwBaud, U32 dwEPSPEN)
{
    U32 status;

    DBG_TraceHex("Parity", dwEPSPEN);
//    DBG_CountDown(3);

    UART_Initial(UART_ID_DBG,   115200,   dwEPSPEN, 0);
    UART_Initial(UART_ID_MODEM, dwBaud,   dwEPSPEN, 0);//UART_FLOW_CONTROL_AUTO);

    status = tModemStatus((U32)(-1));

    while(1)
    {
        if(UART_IsDataReady(UART_ID_MODEM))
        {
            UART_PutChar(UART_ID_DBG, UART_GetChar(UART_ID_MODEM));
        }
        if(UART_IsDataReady(UART_ID_DBG))
        {
            UART_PutChar(UART_ID_MODEM, UART_GetChar(UART_ID_DBG));
        }
        if(ERR_CODE_KP_MULTI == tModemKey()) break;
        status = tModemStatus(status);
    }

    DBG_TraceStrLine("Parity - None\r\n\r\n");
//    DBG_CountDown(3);

    UART_Initial(UART_ID_DBG, 115200, 0, 0);
}

static void tUpdateFirmware(void)
{
    U32  baud;

    baud = DBG_GetDecDef("Baud", 6, 115200);

    tFullControl(baud, (LCR_PEN | LCR_EPS(LCR_EPS_EVEN)));
}

static void tATCmd(void)
{
    U32  baud;

    baud = DBG_GetDecDef("Baud", 6, 460800);

    tFullControl(baud, 0);
}

static MENU_REC l_Module[] = {
    {'a', "AT",        tATCmd},
    {'U', "Update",    tUpdateFirmware},

    {'\0'}
};

void TestModem(void)
{
//#define AUTO_FULL_CONTROL
#ifdef  AUTO_FULL_CONTROL

    static U32  t = 3000;

    tModemStatus();

    if(t < 2000)
    {
        DBG_TraceStrLine("Reset");
        GPIO_ModemReset();
        msSleep(t);
        GPIO_MODEMPOWERON ;
    }

    tFullControl(460800, 0);
#endif

    MenuFunction("Modem Test", l_Module);

#ifdef  AUTO_FULL_CONTROL
    DBG_TraceDec("t", t);
    t = DBG_GetDecDef("next t", 5, t);
#endif
}

