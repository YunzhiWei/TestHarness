
#define INCLUDE_MODULE_LCD

//
// functions in lcd.c
//

void LCD_FBBaseSet(U32 dwAddress);
void LCD_BaseBranch(void);

BOOL LCD_Initial(void);

void LCD_Enable(void);
void LCD_Disable(void);

void LCD_QuickEnable(void);
void LCD_QuickDisable(void);

void LCD_Overlay1Enable(void);
void LCD_Overlay1Disable(void);

void LCD_Overlay2Enable(void);
void LCD_Overlay2Disable(void);

void LCD_BaseFrameDMAOff(U32 dwRed, U32 dwGreen, U32 dwBlue);
void LCD_BaseFrameDMAOn(void);

