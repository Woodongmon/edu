// #include "lcd_4bit.h"

// // void LCD_Data(uint8_t data)
// // {
// //     LCD_DATA_PORT = data; // 데이터핀에 데이터 출력
// // }

// void LCD_Data4Bit(uint8_t_data);
// {
//     LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f)|(data&0xf0); // port의 하위 4bit만 보존
//     LCD_EnablePin();                                    // + data의 상위 4bit를 추출
//                                                         // = 상위 4bit만 수정하고,
//                                                         //하위 4bit는 기존 port에 있던값 보존

//     LCD_DATA_PORT = (LCD_DATA_PORT & 0xf0)|(data&0x0f); // 마찬가지 방법으로 하위 4bit 수정                                                   
//     LCD_EnablePin();

// }

// void LCD_WritePin()
// {
//     LCD_RW_PORT &= ~(1<<LCD_RW); // 쓰기 모드로 진입
// }

// // 읽기모드 진입하려면 아래 코드 필요
// // void LCD_ReadPin()
// // {
// //     LCD_RW_PORT |= (1<<LCD_RW);  
// // }

// void LCD_EnablePin()
// {
//     LCD_E_PORT &= ~(1<<LCD_E); // low로 설정
//     LCD_E_PORT |= (1<<LCD_E);  // high
//     LCD_E_PORT &= ~(1<<LCD_E); // low
//     _delay_us(1600);           // 데이터가 나갈 시간 필요함
// }

// void LCD_WriteCommand(uint8_t command)
// {
//     LCD_RS_PORT &= ~(1<<LCD_RS); // 명령어 모드
//     LCD_WritePin();              // 쓰기 모드로 진입
//     LCD_Data(command);           // 명령어 데이터를 데이터핀에 출력
//     LCD_EnablePin();             // LCD 동작 신호를 전송
// }

// void LCD_WriteDate(char charData)
// {
//     LCD_RS_PORT |= (1<<LCD_RS); // 데이터 모드
//     LCD_WritePin();              
//     LCD_Data(charData);        
//     LCD_EnablePin();             

// }

// void LCD_GotoXY(uint8_t row, uint8_t col)
// {
//     // 보통 나머지로 위치설정
//     col %=16;   // 열 16으로 제한
//     row %=2;    // 행을 2로 제한

//     uint8_t address = (0x40 * row) + col;
//     uint8_t command = 0x80 + address;
//     LCD_WriteCommand(command);
// }

// void LCD_WriteString(char* string) // 문자열 집어넣는 방법
// {
//     for(uint8_t i = 0; i < string[i] ; i++)
//     {
//         LCD_WriteDate (string[i]);
//     }
// }

// void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
// {
//     LCD_GotoXY(row, col);
//     LCD_WriteString(string);
// }

// void LCD_Init()
// {
//     LCD_DATA_DDR = 0xff;
//     LCD_RS_DDR |= (1<<LCD_RS);
//     LCD_RW_DDR |= (1<<LCD_RW);
//     LCD_E_DDE |= (1<<LCD_E);
//     _delay_ms(20);

//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     _delay_ms(5);

//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     _delay_ms(5);
   
//     LCD_WriteCommand(COMMAND_8_BIT_MODE);

//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     LCD_WriteCommand(COMMAND_DISPLAY_OFF);
//     LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
//     LCD_WriteCommand(COMMAND_DISPLAY_ON);
//     LCD_WriteCommand(COMMAND_ENTRY_MODE);
    
// }