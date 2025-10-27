#include "lcd_i2c.h"
//====================================================================
// 내부에서만 사용하는 함수 (파일 내부용)
static void LCD_SendCommand(I2C_HandleTypeDef *hi2c, uint8_t cmd);
static void LCD_SendData(I2C_HandleTypeDef *hi2c, uint8_t data);
static void LCD_Write(I2C_HandleTypeDef *hi2c, uint8_t data, uint8_t isData);
//====================================================================
/*
 * LCD_Write()
 * ----------------
 * LCD로 8비트 데이터를 전송합니다.
 * 4비트 모드이므로 상위 4비트와 하위 4비트를 나누어 전송합니다.
 * isData = 0 → 명령(Command), isData = 1 → 데이터(Character)
 */
static void LCD_Write(I2C_HandleTypeDef *hi2c, uint8_t data, uint8_t isData)
{
    uint8_t highNibble = data & 0xF0;          // 상위 4비트 추출
    uint8_t lowNibble  = (data << 4) & 0xF0;   // 하위 4비트를 상위 위치로 이동
    uint8_t rsFlag     = (isData ? 0x01 : 0x00); // RS 비트: 데이터면 1, 명령이면 0
    uint8_t buffer[4];                         // 전송용 버퍼 (4개의 전송 단계)

    // EN(Enable) 신호를 통해 LCD가 데이터를 읽도록 트리거
    buffer[0] = highNibble | 0x0C | rsFlag;    // EN=1, RS 설정
    buffer[1] = highNibble | 0x08 | rsFlag;    // EN=0 (데이터 확정)
    buffer[2] = lowNibble  | 0x0C | rsFlag;    // 하위 4비트 전송 (EN=1)
    buffer[3] = lowNibble  | 0x08 | rsFlag;    // EN=0 (데이터 확정)

    // I2C로 4단계 버퍼 전송 (HAL 함수 사용)
    HAL_I2C_Master_Transmit(hi2c, LCD_I2C_ADDRESS, buffer, 4, HAL_MAX_DELAY);
}
//====================================================================
/*
 * LCD_SendCommand()
 * ----------------
 * LCD로 명령(command)을 전송합니다.
 * 예: 화면 클리어(0x01), 커서 이동(0x80 + 위치)
 */
static void LCD_SendCommand(I2C_HandleTypeDef *hi2c, uint8_t cmd)
{
    LCD_Write(hi2c, cmd, 0);   // 명령 모드로 Write 실행
}
//================#include "lcd_i2c.h"
//====================================================================
// 내부에서만 사용하는 함수 (파일 내부용)
static void LCD_SendCommand(I2C_HandleTypeDef *hi2c, uint8_t cmd);
static void LCD_SendData(I2C_HandleTypeDef *hi2c, uint8_t data);
static void LCD_Write(I2C_HandleTypeDef *hi2c, uint8_t data, uint8_t isData);
//====================================================================
/*
 * LCD_Write()
 * ----------------
 * LCD로 8비트 데이터를 전송합니다.
 * 4비트 모드이므로 상위 4비트와 하위 4비트를 나누어 전송합니다.
 * isData = 0 → 명령(Command), isData = 1 → 데이터(Character)
 */
//static void LCD_Write(I2C_HandleTypeDef *hi2c, uint8_t data, uint8_t isData)
//{
//    uint8_t highNibble = data & 0xF0;          // 상위 4비트 추출
//    uint8_t lowNibble  = (data << 4) & 0xF0;   // 하위 4비트를 상위 위치로 이동
//    uint8_t rsFlag     = (isData ? 0x01 : 0x00); // RS 비트: 데이터면 1, 명령이면 0
//    uint8_t buffer[4];                         // 전송용 버퍼 (4개의 전송 단계)
//
//    // EN(Enable) 신호를 통해 LCD가 데이터를 읽도록 트리거
//    buffer[0] = highNibble | 0x0C | rsFlag;    // EN=1, RS 설정
//    buffer[1] = highNibble | 0x08 | rsFlag;    // EN=0 (데이터 확정)
//    buffer[2] = lowNibble  | 0x0C | rsFlag;    // 하위 4비트 전송 (EN=1)
//    buffer[3] = lowNibble  | 0x08 | rsFlag;    // EN=0 (데이터 확정)
//// ====================================================
/*
 * LCD_SendData()
 * ----------------
 * LCD로 문자(character) 데이터를 전송합니다.
 * 화면에 실제로 보이는 문자를 출력할 때 사용합니다.
 */

static void LCD_Write_Nibble(I2C_HandleTypeDef *hi2c, uint8_t nibble)
{
    // nibble은 0x30, 0x20 처럼 이미 상위 비트로 마스킹되어 있어야 함
    uint8_t data_t[2];
    data_t[0] = nibble | 0x0C; // EN=1, RS=0 (명령), 백라이트 ON
    data_t[1] = nibble | 0x08; // EN=0, RS=0 (명령), 백라이트 ON

    // E 펄스를 1-0으로 확실히 만들기 위해 1바이트씩 2번 전송
    HAL_I2C_Master_Transmit(hi2c, LCD_I2C_ADDRESS, &data_t[0], 1, HAL_MAX_DELAY);
    HAL_Delay(1); // 펄스 유지 시간
    HAL_I2C_Master_Transmit(hi2c, LCD_I2C_ADDRESS, &data_t[1], 1, HAL_MAX_DELAY);
    HAL_Delay(1); // 다음 명령 전송 전 대기
}


static void LCD_SendData(I2C_HandleTypeDef *hi2c, uint8_t data)
{
    LCD_Write(hi2c, data, 1);  // 데이터 모드로 Write 실행
}
//====================================================================
/*
 * LCD_Init()
 * ----------------
 * LCD를 초기화하는 함수입니다.
 * 전원 안정화 후 LCD를 4비트 모드로 설정하고, 표시 옵션을 정합니다.
 */
void LCD_Init(I2C_HandleTypeDef *hi2c)
{
    // 1. 전원 안정화 대기
    HAL_Delay(50); // 넉넉하게 50ms 대기

    // 2. 8비트 -> 4비트 모드 핸드셰이크 (가장 중요!)
    // LCD_Write_Nibble 함수를 사용해야 함!
    LCD_Write_Nibble(hi2c, 0x30); // 8비트 모드로 Function Set 시도
    HAL_Delay(5); // 4.1ms 이상 대기

    LCD_Write_Nibble(hi2c, 0x30); // 두 번째 시도
    HAL_Delay(1); // 100µs 이상 대기

    LCD_Write_Nibble(hi2c, 0x30); // 세 번째 시도
    HAL_Delay(1);

    LCD_Write_Nibble(hi2c, 0x20); // 4비트 모드로 전환 명령
    HAL_Delay(1);

    // 3. 4비트 모드 설정 완료
    // 이제부터는 8비트 명령을 보내도 LCD_Write가 알아서 4비트씩 잘라 보냄
    LCD_SendCommand(hi2c, 0x28); // Function Set: 4비트, 2라인, 5x8 폰트
    HAL_Delay(1);

    LCD_SendCommand(hi2c, 0x0C); // Display Control: 화면 ON, 커서 OFF, 깜빡임 OFF
    HAL_Delay(1);

    LCD_SendCommand(hi2c, 0x06); // Entry Mode Set: 커서 오른쪽 자동 이동
    HAL_Delay(1);

    LCD_Clear(hi2c); // 화면 전체 클리어 (내부에 2ms 딜레이 포함됨)
}

//====================================================================
/*
 * LCD_Clear()
 * ----------------
 * LCD의 전체 화면을 지우는 명령을 보냅니다.
 * 모든 문자가 사라지고 커서는 (0,0)으로 이동합니다.
 */
void LCD_Clear(I2C_HandleTypeDef *hi2c)
{
    LCD_SendCommand(hi2c, 0x01);     // 화면 클리어 명령
    HAL_Delay(2);                    // 클리어 동작 완료까지 약간의 지연 필요
}
//====================================================================
/*
 * LCD_SetCursor()
 * ----------------
 * LCD의 커서를 지정된 위치로 이동시킵니다.
 * row: 0 → 첫 번째 줄, 1 → 두 번째 줄
 * col: 열 위치 (0~15)
 */
void LCD_SetCursor(I2C_HandleTypeDef *hi2c, uint8_t row, uint8_t col)
{
    uint8_t address = (row == 0) ? 0x80 : 0xC0;  // 각 줄의 시작 주소
    LCD_SendCommand(hi2c, address + col);        // 주소 이동 명령 전송
}
//====================================================================
/*
 * LCD_Print()
 * ----------------
 * LCD에 문자열을 출력합니다.
 * 문자열의 각 문자를 순서대로 데이터 전송합니다.
 */
void LCD_Print(I2C_HandleTypeDef *hi2c, char *str)
{
    while (*str) {                     // 문자열의 끝(NULL)까지 반복
        LCD_SendData(hi2c, *str);      // 한 글자씩 출력
        str++;                         // 다음 문자로 이동
    }
}
