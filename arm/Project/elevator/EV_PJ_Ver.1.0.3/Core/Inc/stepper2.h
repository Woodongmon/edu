/*
 * stepper.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#ifndef INC_STEPPER2_H_
#define INC_STEPPER2_H_


//원본 모터의 config입니다.
//IN1~IN4가 IN5~IN7으로, GPIOB 13,14,15,1이 GPIOC 1,0,2,3으로 변경되었습니다.


#include "main.h"

#define STEPS_PER_REVOLATION	4096
#define DIR_CW					0
#define DIR_CCW					1


#define IN5_PIN 		GPIO_PIN_1
#define IN5_GPIO_PORT	GPIOC

#define IN6_PIN 		GPIO_PIN_0
#define IN6_GPIO_PORT	GPIOC

#define IN7_PIN 		GPIO_PIN_2
#define IN7_GPIO_PORT	GPIOC

#define IN8_PIN 		GPIO_PIN_3
#define IN8_GPIO_PORT	GPIOC

void stepMotor2(uint8_t step2);
void rotateSteps2(uint16_t steps2, uint8_t direction);
void rotateDegrees2(uint16_t degrees2, uint8_t direction);


// 커스텀 함수화 한 부분입니다.

void OPEN(void);
void CLOSE(void);
void LEFTRIGHTSTOP(void);
void MOTOR2TEST(void);


#endif /* INC_STEPPER2_H_ */
