/*
*/

#include "_platform.h"

/*
    Two kinds of Menu: Function Menu & Option Menu
        Function Menu: Function pointer of Menu Item is valid ;
        Option Menu  : Function pointer of Menu Item is NULL
*/

/*
    Basic Functions
    Supported by other Modules
*/

#define MENU_INPUT_CHAR                 (OnMenuIdle())
#define MENU_OUTPUT_STRING(str)         DBG_TraceString(str)

/*
    Private Functions
*/

static void MenuShow(const MENU_REC *pMenu)
{
    int i;
    static char menu[] = "\r\n [ ]\t";

    MENU_OUTPUT_STRING("\r\n Esc\tExit");

    for(i=0;pMenu[i].m_cMenu!='\0';i++)
    {
        menu[4] = pMenu[i].m_cMenu;
        MENU_OUTPUT_STRING(menu);
        MENU_OUTPUT_STRING(pMenu[i].m_Name);
    }
    MENU_OUTPUT_STRING("\r\n");
}

/*
    For Option Menu, return the Menu ID
    For Function Menu, return the short charactor or the menu item
*/
static int OnMenuSel(const MENU_REC *pMenu, char sel)
{
    int i;

    if(sel == ASCII_CODE_ESC) return(MENU_SEL_EXIT);

    for(i=0;pMenu[i].m_cMenu!='\0';i++)
    {
        if(pMenu[i].m_cMenu == sel)
        {
            if(pMenu[i].m_pFunc != NULL)
            {
                pMenu[i].m_pFunc();
                return(pMenu[i].m_cMenu);
            }
            else return(i);
        }
    }

    return(MENU_SEL_NONE);
}

/*
    Public Functions
    Export to other Modules
*/
int MenuFunction(char *pTitle, const MENU_REC *pMenu)
{
    // The menu item number should not more than 32 (' ' = 0x20)
    // The menu select char should be normal ASCII code ( >= ' ' )
    // Read the switch/case/default, you will know why

    int  r;
    char c;

    MENU_OUTPUT_STRING("\r\n");
    MENU_OUTPUT_STRING(pTitle);
    MENU_OUTPUT_STRING("\r\n");

    while(1)
    {
        MenuShow(pMenu);

        while((c = MENU_INPUT_CHAR) == ASCII_CODE_NAK) { ; }

        switch(r = OnMenuSel(pMenu, c)) {
        case MENU_SEL_EXIT:
            MENU_OUTPUT_STRING("\r\n Bye \r\n");
            return(r);
        case MENU_SEL_NONE:
            MENU_OUTPUT_STRING("\r\n Invalid command\r\n");
            break;
        default:
            if(r < ' ') return(r);                          // for Option Menu, return the ID
            else break;                                     // for Function Menu, just ignore the invalid selection
        }
    }
}


