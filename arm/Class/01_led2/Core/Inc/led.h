#ifndef INC_LED_H_
#define INC_LED_H

#include "main.h"


//typedef enum
//{
//  LED_OFF,
//  LED_ON
//}LED_STATE;

typedef struct
{
  GPIO_TypeDef  *port;     //resister 이므로 포인터로 가져와야함
  uint16_t      pinNumber;
  GPIO_PinState	onState;
  GPIO_PinState offState;
}LED_CONTROL;

void ledOn(uint8_t num);
void ledOff(uint8_t num);
void ledToggle(uint8_t num);

void ledLeftShift(uint8_t num);
void ledRightShift(uint8_t num);
void ledFlower(uint8_t num);

#endif /*INC_LED_H_ */
