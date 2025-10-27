#include "fnd.h"                             // fnd.h 헤더 파일 포함 (구조체와 함수 선언 사용)
//================================================================

// 🔹 각 세그먼트를 배열로 정의
//    - FND의 a~g, dp 각 세그먼트가 어느 포트와 핀에 연결되어 있는지 명시
static Segment_t segments[8] =
{
    {GPIOA, GPIO_PIN_8},   	// a 세그먼트 → PA8 -> 7
    {GPIOB, GPIO_PIN_10},   // b 세그먼트 → PB10 -> 6
    {GPIOB, GPIO_PIN_3},   	// c 세그먼트 → PB3 -> 4
    {GPIOB, GPIO_PIN_5},   	// d 세그먼트 → PB5 -> 2
    {GPIOB, GPIO_PIN_4},  	// e 세그먼트 → PB4 -> 1
    {GPIOA, GPIO_PIN_9},   	// f 세그먼트 → PA9 -> 9
    {GPIOC, GPIO_PIN_7},   	// g 세그먼트 → PC7 -> 10
    {GPIOA, GPIO_PIN_10}    // dp(소수점) → PA10 -> 5
	};
//================================================================

// 🔹 숫자 0~9의 각 세그먼트 점등 패턴
//    - 0 = 켜짐, 1 = 꺼짐 (공통 캐소드 방식)
//    - 각 행은 숫자 하나를 나타냄, 각 열은 세그먼트 a~dp 순서에 대응
static const uint8_t FND_Font[10][8] =
{
  // a  b  c  d  e  f  g  dp
    {0, 0, 0, 0, 0, 0, 1, 1}, // 0 표시 (a,b,c,d,e,f ON / g,dp OFF)
    {1, 0, 0, 1, 1, 1, 1, 1}, // 1 표시 (b,c ON)
    {0, 0, 1, 0, 0, 1, 0, 1}, // 2 표시 (a,b,d,e,g ON)
    {0, 0, 0, 0, 1, 1, 0, 1}, // 3 표시 (a,b,c,d,g ON)
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4 표시 (b,c,f,g ON)
    {0, 1, 0, 0, 1, 0, 0, 1}, // 5 표시 (a,c,d,f,g ON)
    {0, 1, 0, 0, 0, 0, 0, 1}, // 6 표시 (a,c,d,e,f,g ON)
    {0, 0, 0, 1, 1, 1, 1, 1}, // 7 표시 (a,b,c ON)
    {0, 0, 0, 0, 0, 0, 0, 1}, // 8 표시 (모두 ON)
    {0, 0, 0, 0, 1, 0, 0, 1}  // 9 표시 (a,b,c,d,f,g ON)
};
//================================================================

void FND_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // GPIO 설정 구조체 생성 및 초기화

    // 🔹 ① GPIO 클록 활성화
    //     - 각 포트(GPIOA, GPIOB, GPIOC)를 사용하기 전에 클록을 켜야 동작함
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // 🔹 ② GPIO 기본 설정
    //     - 출력 모드 설정 (푸시풀 출력)
    //     - 내부 풀업/풀다운 저항 사용 안 함
    //     - 속도는 LOW (7세그먼트라 빠른 스위칭 불필요)
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    // 🔹 ③ 각 세그먼트 핀을 초기화
    //     - segments 배열에 저장된 포트와 핀을 순차적으로 설정
    for (int i = 0; i < 8; i++)
    {
        GPIO_InitStruct.Pin = segments[i].pin;                  // 현재 세그먼트 핀 지정
        HAL_GPIO_Init(segments[i].port, &GPIO_InitStruct);      // HAL 함수를 이용해 GPIO 초기화
    }

    FND_Clear(); // 🔹 ④ 초기화 완료 후 모든 세그먼트 OFF
}
//================================================================

void FND_Clear()
{
    // 🔹 모든 세그먼트를 꺼주는 함수
    //     - 초기 상태를 OFF로 유지하여 불필요한 전류 흐름 방지
    for (int i = 0; i < 8; i++)
    {
        HAL_GPIO_WritePin(segments[i].port, segments[i].pin, GPIO_PIN_SET); // LOW 출력 → LED OFF
    }
}
//================================================================

void FND_DisplayNumber(uint8_t num)
{
    if (num > 9) return; // 🔹 예외 처리: 0~9 이외의 숫자는 무시

    // 🔹 해당 숫자의 세그먼트 패턴을 불러와 점등 제어
    for (int i = 0; i < 8; i++)
    {
        // FND_Font[num][i] 값이 0이면 켜짐, 1이면 꺼짐
        // HAL_GPIO_WritePin(포트, 핀, 상태) 함수를 이용해 출력 제어
        HAL_GPIO_WritePin(
            segments[i].port,
            segments[i].pin,
            FND_Font[num][i] ? GPIO_PIN_SET : GPIO_PIN_RESET
        );
    }
}
//================================================================
void fndInit()
{
	FND_Init();
}
//=================================================================
void fndClear()
{
	FND_Clear();
}
//=================================================================
void fndDisplay1()
{
    FND_DisplayNumber(1);
}
//=================================================================
void fndDisplay2()
{
    FND_DisplayNumber(2);
}
//=================================================================
void fndDisplay3()
{
    FND_DisplayNumber(3);
}
//=================================================================
void fndTest()
{
	fndDisplay1();
	HAL_Delay(250);
	fndDisplay2();
	HAL_Delay(250);
	fndDisplay3();
	HAL_Delay(250);
	fndClear();
	HAL_Delay(250);
}
