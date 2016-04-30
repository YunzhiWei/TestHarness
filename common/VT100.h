
/*

VT100 语法:
            <escape>[<属性>;<属性>;<属性>m
            属性分隔符为";"

关闭回显可以使用echo " xxxx "
如闪烁红色 : echo "<ctrl-v><escape>[31;5m测试"

前景/背景              颜色
---------------------------------------
    30/40               黑色
    31/41               紅色
    32/42               綠色
    33/43               黃色
    34/44               藍色
    35/45               紫紅色
    36/46               青藍色
    37/47               白色

代码                    意义
-------------------------
    0                   OFF
    1                   高亮
    4                   下划线
    5                   闪烁
    7                   反白
    8                   不可见

对于Windows 超级终端: !!!
  1. echo似乎不起作用
  2. VT100 自动识别，不需要初始化
*/

#define VT100_ATTR_CLR_FT_BLACK         "30"
#define VT100_ATTR_CLR_FT_RED           "31"
#define VT100_ATTR_CLR_FT_GREEN         "32"
#define VT100_ATTR_CLR_FT_YELLOW        "33"
#define VT100_ATTR_CLR_FT_BLUE          "34"
#define VT100_ATTR_CLR_FT_MAUVE         "35"
#define VT100_ATTR_CLR_FT_CYAN          "36"
#define VT100_ATTR_CLR_FT_WHITE         "37"
#define VT100_ATTR_CLR_CK_BLACK         "40"
#define VT100_ATTR_CLR_CK_RED           "41"
#define VT100_ATTR_CLR_CK_GREEN         "42"
#define VT100_ATTR_CLR_CK_YELLOW        "43"
#define VT100_ATTR_CLR_CK_BLUE          "44"
#define VT100_ATTR_CLR_CK_MAUVE         "45"
#define VT100_ATTR_CLR_CK_CYAN          "46"
#define VT100_ATTR_CLR_CK_WHITE         "47"

#define VT100_ATTR_OFF_ALL              "0"
#define VT100_ATTR_BOLD_ON              "1"
#define VT100_ATTR_UNDERSCORE_ON        "4"
#define VT100_ATTR_BLINK_ON             "5"
#define VT100_ATTR_REVERSE_ON           "7"
#define VT100_ATTR_BOLD_OFF             "21"
#define VT100_ATTR_UNDERSCORE_OFF       "24"
#define VT100_ATTR_BLINK_OFF            "25"
#define VT100_ATTR_REVERSE_OFF          "27"

#define VT100_ATTR_START                "\x1B["
#define VT100_ATTR_AND                  ";"
#define VT100_ATTR_END                  "m"

//! vt100Init() initializes terminal and vt100 library
///     Run this init routine once before using any other vt100 function.
#define VT100_CMD_INITIAL   			"\x1Bc"
#define VT100_CMD_CLEARSCREEN			"\x1B[2J"

#if 0
//! vt100SetCursorMode() sets the cursor to visible or invisible
void vt100SetCursorMode(BYTE cVisible)
{
    if(visible)
        // ESC [ ? 25 h
        rprintf("\x1B[?25h");
    else
        // ESC [ ? 25 l
        rprintf("\x1B[?25l");
}

//! vt100SetCursorPos() sets the cursor position
///     All text which is written to the terminal after a SetCursorPos command
///     will begin at the new location of the cursor.
void vt100SetCursorPos(BYTE cLine, BYTE cCol)
{
    // ESC [ Pl ; Pc H
    rprintf("\x1B[%d;%dH",line,col);
}
#endif


