#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"


typedef struct
{
  GPIO_TypeDef     *port;
  uint16_t          pinNumber;
  GPIO_PinState     onstate;
  GPIO_PinState     offstate;

}LED_CONTROL;

void ledOn();                 //LED 켜짐
void ledOff();                //LED 꺼짐
void ledToggle();             //토글
void ledLeftShift();          //LED가 왼쪽으로 순차적으로 켜짐
void ledRightShift();         //LED가 오른쪽으로 순차적으로 켜짐
void led_State(uint8_t state); //
void led_Init();
//void ledFlower(uint8_t num);

//==========================================
// 커스텀 함수들 (가져다가 쓰세요~)
void ledUp();		// 위층으로 올라가기
void ledDown();		// 아래칭으로 내려가기



#endif /* INC_LED_H_ */
