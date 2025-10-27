// #include "lcd_4bit.h"

// /*
// void LCD_Data(uint8_t data)
// {
//     LCD_DATA_PORT = data;               //data pin output
// }
// */

// void LCD_Data4bit(uint8_t data)
// {
//     LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f)|(data&0xf0); // port의 하위 4bit만 보존
//     LCD_EnablePin();                                    // + data의 상위 4bit를 추출
//                                                         // = 상위 4bit만 수정하고,
//                                                         //하위 4bit는 기존 port에 있던값 보존

//     LCD_DATA_PORT = (LCD_DATA_PORT & 0xf0)|((data&0x0f)<<4); 
//                                                         // 마찬가지 방법으로 하위 4bit 추출
//                                                         // 추출후, 4bit만큼 shift
//                                                         // 상위 4bit에 2번에 걸친 데이터전송                                                   
//     LCD_EnablePin();

// }


// void LCD_WritePin()
// {
//     LCD_RW_PORT &= ~(1<<LCD_RW);        //RW pin to set LOW : write mode
// }

// /* 만약 REad 일 경우에는 이렇게 설정하면 됨
// void LCD_ReadPin()
// {
//     LCD_RW_PORT |= (1<<LCD_RW);
// }
// */
// void LCD_EnablePin()
// {
//     LCD_E_PORT &= ~(1<<LCD_E);          // E pin set to LOW
//     LCD_E_PORT |= (1<<LCD_E);          // E pin set to HIGH
//     LCD_E_PORT &= ~(1<<LCD_E);          // E pin set to LOW
//     _delay_ms(1600);                    //data 육안확일을 위한 지연
// }

// void LCD_WriteCommand(uint8_t command)
// {
//     LCD_RS_PORT &= ~(1<<LCD_RS);           //RS pin set to LOW : 명령어 모드로 설정함 (0)
//     LCD_WritePin();                        //write mode start
//     LCD_Data4bit(command);                     //명령어 데이터를 데이터핀에 출력함 
//    // LCD_EnablePin();                        //lcd 동작 신호를 전송 (triger)
// }

// void LCD_WriteData(char charData)
// {
//     LCD_RS_PORT |= (1<<LCD_RS);             //High 설정해서 데이터 모드로 설정 (1)
//     LCD_WritePin();                         //write mode start
//     LCD_Data4bit(charData);                     //명령어 데이터를 데이터핀에 출력함 
//     //LCD_EnablePin();                        //lcd 동작 신호를 전송 (triger)
// }

// void LCD_GotoXY(uint8_t row, uint8_t col)
// {
//     col %= 16;      //col 16으로 제한
//     row %= 2;       //row 2로 제한

//     uint8_t address = (0x40*row) + col;
//     uint8_t command = 0x80 + address;
//     LCD_WriteCommand(command);
    
// }

// //string 포인터에 직접 문자열을 집어넣음
// //배열의 이름은 첫주소값으로 사용될수 있기 때문
// void LCD_WriteString(char *string)
// {
//     for(uint8_t i=0;i<string[i];i++)
//     {
//         LCD_WriteData(string[i]);       
//     }
// }

// void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
// {
//     LCD_GotoXY(row,col);
//     LCD_WriteString(string);
// }

// void LCD_Init()
// {
//     LCD_DATA_DDR = 0xff;        //PF 포트를 출력으로 설정
//     LCD_RS_DDR |= (1<<LCD_RS);
//     LCD_RW_DDR |= (1<<LCD_RW);
//     LCD_E_DDR |= (1<<LCD_E);

//     _delay_ms(20);

//     LCD_WriteCommand(0x03);           
//     _delay_ms(5);

//     LCD_WriteCommand(0x03);
//     _delay_ms(5);

//     LCD_WriteCommand(0x03);
//     _delay_ms(5);

//     LCD_WriteCommand(0x02);
//     LCD_WriteCommand(COMMAND_4_BIT_MODE);

//     LCD_WriteCommand(COMMAND_DISPLAY_OFF);
//     LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
//     LCD_WriteCommand(COMMAND_DISPLAY_ON);           //this is custom 
//     LCD_WriteCommand(COMMAND_ENTRY_MODE);


// }