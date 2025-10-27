#include "led.h"

//LED 포트 레지스터에 데이터를 출력하는 함수
// void GPIO_Output(uint8_t data)
// {
//     LED_PORT = data
// }

// //LED 포트 레지스터를 출력모드로 설정하는 함수
// void ledInit(LED *led)
// {
//     // LED_DDR=0xFF;
//     // 구조체를 정의했기 때문에 아래와 같이 사용 가능
//     // 사용할 포트에 대해 ddr레지스터를 출력으로 설정 가능
//     *(led->port-1) |= (1<<led->pinNumber);
//     // led->port-1 //포트주소를 던지면 DDR주소가 됨
//     // led->port-1을 한 값(주소) -> * 포인터로 가리키는 곳의 값을 변경
//     // *(led->port-1)

//     //led->pinNumber << 핀번호를 이야기함
// }

//LED 포트 데이터를 왼쪽으로 shift하는 함수

// void ledOn(LED *led)
// {
//     //포트에 1을 쓰면 출력이 된다.
//     //해당 핀에 1을 씀
//     *(led->port) |= (1<< led->pinNumber);

// }

// void ledOff(LED*led)
// {
//     *(led->port) &= (1<<led->pinNumber);
// }

// void ledLeftShift(LED*led, uint8_t pinNumbr)
// {
    
// }
// //LED 데이터를 우측으로 이동하는 함수
// void ledRightShift()
// {
    
// }

void ledOn(LED *led)
{
    *(led->port) |= (1 << led->pinNumber);
}