#include "_type.h"
#include "APIStub.h"

//Register Value
#define REG_U2DCR                       (*MH_U2DCR)         // U2D Control register
#define REG_U2DICR                      (*MH_U2DICR)        // U2D Interrupt Control register
#define REG_U2DICR2                     (*MH_U2DICR2)       // U2D Interrupt Control register(Endpoints H-P)
#define REG_U2DISR                      (*MH_U2DISR)        // U2D Interrupt Status register
#define REG_U2DISR2                     (*MH_U2DISR2)       // U2D Interrupt Status register(Endpoints H-P)
#define REG_U2DOTGCR                    (*MH_U2DOTGCR)      // U2D OTG Control register
#define REG_U2DOTGICR                   (*MH_U2DOTGICR)     // U2D OTG Interrupt Control/Enable register
#define REG_U2DOTGUSR                   (*MH_U2DOTGUSR)     // U2D OTG ULPI Status register
#define REG_U2DOTGUCR                   (*MH_U2DOTGUCR)     // U2D OTG ULPI Control register
#define REG_U2DCSR0                     (*MH_U2DCSR0)       // U2D Control/Status register - Endpoint 0
#define REG_U2DCSRA                     (*MH_U2DCSRA)       // U2D Control/Status register - Endpoint A
#define REG_U2DCSRB                     (*MH_U2DCSRB)       // U2D Control/Status register - Endpoint B
#define REG_U2DCSRC                     (*MH_U2DCSRC)       // U2D Control/Status register - Endpoint C
#define REG_U2DMACSR0                   (*MH_U2DMACSR0)     // U2D Control/Status register for channel 0
#define REG_U2DCRA                      (*MH_U2DCRA)        // U2D Configuration register - Endpoint A
#define REG_U2DCRB                      (*MH_U2DCRB)        // U2D Configuration register - Endpoint B
#define REG_U2DCRC                      (*MH_U2DCRC)        // U2D Configuration register - Endpoint C
#define REG_U2DEN0                      (*MH_U2DNE0)        // U2D Endpoint Information register - Endpoint 0
#define REG_U2DENA                      (*MH_U2DNEA)        // U2D Endpoint Information register - Endpoint A
#define REG_U2DENB                      (*MH_U2DNEB)        // U2D Endpoint Information register - Endpoint B
#define REG_U2DENC                      (*MH_U2DNEC)        // U2D Endpoint Information register - Endpoint C
#define REG_U2DBCR0                     (*MH_U2DBCR0)       // U2D Byte Count register - Endpoint 0
#define REG_U2DMADADR0                  (*MH_U2DMADADR0)    // U2D Descriptor Address register channel 0
#define REG_U2DMASADR0                  (*MH_U2DMASADR0)    // U2D Source Address register channel 0
#define REG_U2DMATADR0                  (*MH_U2DMATADR0)    // U2D Target Address register channel 0
#define REG_U2DMACMD0                   (*MH_U2DMACMD0)     // U2D Command Address register channel 0
#define REG_U2DMADADR1                  (*MH_U2DMADADR1)    // U2D Descriptor Address register channel 1
#define REG_U2DMASADR1                  (*MH_U2DMASADR1)    // U2D Source Address register channel 1
#define REG_U2DMATADR1                  (*MH_U2DMATADR1)    // U2D Target Address register channel 1
#define REG_U2DMACMD1                   (*MH_U2DMACMD1)     // U2D Command Address register channel 1
#define REG_U2DMADADR2                  (*MH_U2DMADADR2)    // U2D Descriptor Address register channel 2
#define REG_U2DMASADR2                  (*MH_U2DMASADR2)    // U2D Source Address register channel 2
#define REG_U2DMATADR2                  (*MH_U2DMATADR2)    // U2D Target Address register channel 2
#define REG_U2DMACMD2                   (*MH_U2DMACMD2)     // U2D Command Address register channel 2
#define REG_U2DMACSR0                   (*MH_U2DMACSR0)     // U2D Control/Status register for channel 0
#define REG_U2DMACSR1                   (*MH_U2DMACSR1)     // U2D Control/Status register for channel 1
#define REG_U2DMACSR2                   (*MH_U2DMACSR2)     // U2D Control/Status register for channel 2
#define REG_U2DDR0_LONG                 (*MH_U2DDR0)        // U2D Data register - Endpoint 0
#define REG_U2DDR0_WORD                 (*((U16 *)MH_U2DDR0))
#define REG_U2DDR0_BYTE                 (*((U8 *)MH_U2DDR0))

static void tRegDump(void)
{
    DBG_TraceStrLine("Dump U2D Reg....");
    DBG_TraceHex("REG_U2DCR",REG_U2DCR);
    DBG_TraceHex("REG_U2DICR",REG_U2DICR);
    DBG_TraceHex("REG_U2DISR",REG_U2DISR);

    DBG_TraceHex("REG_U2DCSRA",REG_U2DCSRA);
    DBG_TraceHex("REG_U2DCSRB",REG_U2DCSRB);

    DBG_TraceHex("REG_U2DEN0",REG_U2DEN0);
    DBG_TraceHex("REG_U2DENA",REG_U2DENA);
    DBG_TraceHex("REG_U2DENB",REG_U2DENB);
    DBG_TraceHex("REG_U2DCRA",REG_U2DCRA);
    DBG_TraceHex("REG_U2DCRB",REG_U2DCRB);

    DBG_TraceHex("REG_U2DMACSR0",REG_U2DMACSR0);
    DBG_TraceHex("REG_U2DMACSR1",REG_U2DMACSR1);
    DBG_TraceHex("REG_U2DMACSR2",REG_U2DMACSR2);

    DBG_TraceHex("REG_U2DMADADR1",REG_U2DMADADR1);
    DBG_TraceHex("REG_U2DMASADR1",REG_U2DMASADR1);
    DBG_TraceHex("REG_U2DMATADR1",REG_U2DMATADR1);
    DBG_TraceHex("REG_U2DMACMD1", REG_U2DMACMD1);

    DBG_TraceHex("REG_U2DMADADR2",REG_U2DMADADR2);
    DBG_TraceHex("REG_U2DMASADR2",REG_U2DMASADR2);
    DBG_TraceHex("REG_U2DMATADR2",REG_U2DMATADR2);
    DBG_TraceHex("REG_U2DMACMD2 ",REG_U2DMACMD2);

    DBG_TraceStrLine("Dump U2D Reg finish.");
}

static void tDisconnect(void)
{
    // Pull up the D+ pin at the internal transceiver.
    REG_U2DCR &= ~U2DCR_ADD;

    DBG_TraceStrLine("USB soft disconnect.");
}

static MENU_REC l_Module[] = {
    {'r', "RegDump",    tRegDump},
    {'s', "Disconnect", tDisconnect},
//    {'i', "Plug In/Initial",        U2D_Initial},
    {'\0'}
};

void Main(void)
{
//    DBG_BreakPoint("Hello");
//    DBG_CountDown(3);

    MenuFunction("U2D Test", l_Module);
    DBG_BreakPoint("Bye");
//    DBG_CountDown(3);
}
