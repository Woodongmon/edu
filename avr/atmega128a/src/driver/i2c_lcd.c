#include "i2c_lcd.h"


uint8_t I2C_LCD_DATA;


void LCD_Data4Bit(uint8_t data)
{
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f)|(data & 0xf0); //상위 4비트 추출해서 1차로 보냄
    LCD_EnablePin();
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f)|((data & 0x0f) << 4); //상위 4비트 추출해서 2차로 보냄
    LCD_EnablePin();
}


void LCD_EnablePin()
{
    I2C_LCD_DATA&= ~(1<<LCD_E); // low로 설정
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);

    I2C_LCD_DATA |= (1<<LCD_E);  // high
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);

    I2C_LCD_DATA &= ~(1<<LCD_E); // low
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);
    _delay_us(1600);           // 데이터가 나갈 시간 필요함
}

void LCD_WriteCommand(uint8_t command)
{
    I2C_LCD_DATA &= ~(1<<LCD_RS); // RS핀을 LOW로
    I2C_LCD_DATA &= ~(1<<LCD_RW); 
    LCD_Data4Bit(command);           // 명령어 데이터를 데이터핀에 출력
}

void LCD_WriteDate(char charData)
{
    I2C_LCD_DATA |= (1<<LCD_RS); //
    I2C_LCD_DATA &= ~(1<<LCD_RW);           
    LCD_Data4Bit(charData);                 

}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
    // 보통 나머지로 위치설정
    col %=16;   // 열 16으로 제한
    row %=2;    // 행을 2로 제한

    uint8_t address = (0x40 * row) + col;
    uint8_t command = 0x80 + address;
    LCD_WriteCommand(command);
}

void LCD_WriteString(char* string) // 문자열 집어넣는 방법
{
    for(uint8_t i = 0; i < string[i] ; i++)
    {
        LCD_WriteDate (string[i]);
    }
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
    LCD_GotoXY(row, col);
    LCD_WriteString(string);
}

void LCD_BackLightOn()
{
    I2C_LCD_DATA |= (1<<LCD_BACKLIGHT);
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);
}

void LCD_Init()
{
    I2C_Init();

    _delay_ms(20);

    LCD_WriteCommand(0x03);
    _delay_ms(5);

    LCD_WriteCommand(0x03);
    _delay_ms(5);
   
    LCD_WriteCommand(0x03);

    LCD_WriteCommand(0x02);
    LCD_WriteCommand(COMMAND_4_BIT_MODE);

    LCD_WriteCommand(COMMAND_DISPLAY_OFF);
    LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
    LCD_WriteCommand(COMMAND_DISPLAY_ON);
    LCD_WriteCommand(COMMAND_ENTRY_MODE);
    LCD_BackLightOn();
}


// #include "i2c_lcd.h"

// uint8_t I2C_LCD_DATA;


// void LCD_Data4bit(uint8_t data)
// {
//     I2C_DATA_PORT = (I2C_DATA_PORT & 0x0f)|(data&0xf0); // port의 하위 4bit만 보존
//     LCD_EnablePin();                                    // + data의 상위 4bit를 추출
//                                                         // = 상위 4bit만 수정하고,
//                                                         //하위 4bit는 기존 port에 있던값 보존

//     I2C_DATA_PORT = (I2C_DATA_PORT & 0xf0)|((data&0x0f)<<4); 
//                                                         // 마찬가지 방법으로 하위 4bit 추출
//                                                         // 추출후, 4bit만큼 shift
//                                                         // 상위 4bit에 2번에 걸친 데이터전송                                                   
// }

// void LCD_EnablePin()
// {
//     I2C_LCD_DATA &= ~(1<<LCD_E);          // E pin set to LOW
//     I2C_LCD_DATA |= (1<<LCD_E);          // E pin set to HIGH
//     I2C_LCD_DATA &= ~(1<<LCD_E);          // E pin set to LOW
//     _delay_ms(1600);                    //data 육안확일을 위한 지연
// }

// void LCD_WriteCommand(uint8_t command)
// {
//     I2C_LCD_DATA &= ~(1<<LCD_RS);           //RS pin set to LOW : 명령어 모드로 설정함 (0)
//     I2C_LCD_DATA &= ~(1<<LCD_RS);             //write mode start
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
//     I2C_Init();

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

