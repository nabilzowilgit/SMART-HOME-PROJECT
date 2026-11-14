#ifndef HALL_LCD_LCD_INIT_H_
#define HALL_LCD_LCD_INIT_H_




#define LCD_CMD_CLEAR_DIS         0x01
#define LCD_CMD_RETURN_HOME       0x02
#define LCD_CMD_8BIT_MODE         0x38
#define LCD_CMD_4BIT_MODE         0x28
#define LCD_CMD_ADD_DDRAM         0x80
#define LCD_CMD_ADD_CGRAM         0x40
#define LCD_CMD_SHIFT_DIS_RIGHT   0x1C
#define LCD_CMD_SHIFT_DIS_LEFT    0x18
#define LCD_CMD_ENTRY_MODE_INC    0x06
#define LCD_CMD_ENTRY_MODE_DEC    0x04
#define LCD_CMD_DISPLAY_ON        0x0C
#define LCD_CMD_DISPLAY_OFF       0x08
#define LCD_CMD_CURSOR_ONBLINK    0x0F
#define LCD_CMD_CURSOR_OFFBLINK   0x0E


#define LCD_SEG_ROW1     0
#define LCD_SEG_ROW2     1

/******** 8Bit Function's ********/

void LCD_vid8BitInit();
void LCD_vid8BitWriteCmd(uint8 u8CopyCMD);
void LCD_vid8BitWriteChar(uint8 u8CopyChar);
void LCD_vid8BitWriteStr(uint8 *u8Str);
void LCD_vid8BitWriteInt(sint32 s32CopyNumber);
void LCD_vid8BitGoto(uint8 u8CopyRow,uint8 u8CopyCol);

/******** 4Bit Function's ********/

void LCD_vid4BitInit();
void LCD_vid4BitWriteCmd(uint8 u8CopyCMD);
void LCD_vid4BitWriteChar(uint8 u8CopyChar);
void LCD_vid4BitWriteStr(uint8 *u8Str);
void LCD_vid4BitWriteInt(sint32 s32CopyNumber);
void LCD_vid4BitWriteflt(float f32CopyNumber);
void LCD_vid4BitGoto(uint8 u8CopyRow,uint8 u8CopyCol);
char LCD_vid4BitReadChar(uint8 u8CopyRow,uint8 u8CopyCol);

#endif /* HALL_LCD_LCD_INIT_H_ */
