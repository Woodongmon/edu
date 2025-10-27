#include "led.h"

LED_CONTROL led[8]=
{
		{GPIOA,GPIO_PIN_5,GPIO_PIN_SET,GPIO_PIN_RESET},
		{GPIOA,GPIO_PIN_6,GPIO_PIN_SET,GPIO_PIN_RESET},
		{GPIOA,GPIO_PIN_7,GPIO_PIN_SET,GPIO_PIN_RESET},
		{GPIOA,GPIO_PIN_8,GPIO_PIN_SET,GPIO_PIN_RESET},
		{GPIOA,GPIO_PIN_9,GPIO_PIN_SET,GPIO_PIN_RESET},

		{GPIOB,GPIO_PIN_6,GPIO_PIN_SET,GPIO_PIN_RESET},
		{GPIOB,GPIO_PIN_10,GPIO_PIN_SET,GPIO_PIN_RESET},

		{GPIOC,GPIO_PIN_7,GPIO_PIN_SET,GPIO_PIN_RESET}
};


void ledOn(uint8_t num)
{
	//한꺼번에 NUM개 켜기
	for(uint8_t i=0;i<num;i++)
	{
		HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, led[i].onState);
	}

}

void ledOff(uint8_t num)
{
	HAL_GPIO_WritePin(led[num].port, led[num].pinNumber, led[num].offState);
}

void ledToggle(uint8_t num)
{
	for(uint8_t i=0;i<num;i++)
	{
		ledOn(i);
		HAL_Delay(100);
	}
	HAL_Delay(500);

	for(uint8_t i=0;i<num;i++)
	{
		ledOff(i);
	}
}

void ledLeftShift(uint8_t num)
{

}

void ledRightShift(uint8_t num)
{

}

void ledFlower(uint8_t num)
{

}
