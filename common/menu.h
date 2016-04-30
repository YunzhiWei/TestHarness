
/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

typedef struct{
    char    m_cMenu;
    char    *m_Name;
    void    (*m_pFunc)(void);
}MENU_REC;

#define MENU_SEL_EXIT                   (-1)
#define MENU_SEL_NONE                   (-2)

int MenuFunction(char *pTitle, const MENU_REC *pMenu);

