/*
 * Buzz.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user4
 */

#ifndef INC_BUZZ_H_
#define INC_BUZZ_H_
#include "main.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim1;

#define Buzz_Pin 	GPIO_PIN_15
#define Buzz_Port	GPIOA

#define Buzz_ON_Time 500
#define Buzz_OFF_Time 500



void Buzz_Init(void);		// Buzz 초기화
void Buzz_SW(uint8_t sw);	// 단순 ON / OFF
void Buzz_Bell();	// 반복 + non block
void Buzz_Bell_Start(uint8_t times, uint16_t ms);
// times < 반복횟수
// ms < buzz 동작 시간
// if 3, 500 넣으면 삐-삐-삐- 삐 시간이 500

/////////////////////////////////////
void Buzzer(uint8_t times);//////////
//// Buzzer(반복횟수)/////////////////
////////////////////////////////////
void Buzzer_test();

extern uint8_t Buzz_Count; 		//동작 횟수
extern uint16_t Buzz_Half_Period;	//울리는 시간?


#endif /* INC_BUZZ_H_ */
