/*
 * stepper.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#ifndef INC_STEPPER1_H_
#define INC_STEPPER1_H_


//원본 모터의 config입니다.


#include "main.h"

#define STEPS_PER_REVOLATION	4096
#define DIR_CW					0
#define DIR_CCW					1


#define IN1_PIN 		GPIO_PIN_1
#define IN1_GPIO_PORT	GPIOB

#define IN2_PIN 		GPIO_PIN_15
#define IN2_GPIO_PORT	GPIOB

#define IN3_PIN 		GPIO_PIN_14
#define IN3_GPIO_PORT	GPIOB

#define IN4_PIN 		GPIO_PIN_13
#define IN4_GPIO_PORT	GPIOB

void stepMotor1(uint8_t step1);
void rotateSteps1(uint16_t steps1, uint8_t direation1);
void rotateDegrees1(uint16_t degrees1, uint8_t direction1);


// 커스텀 함수화 한 부분입니다.

void UP(void);
void DOWN(void);
void UPDOWNSTOP(void);
void MOTOR1TEST(void);


#endif /* INC_STEPPER1_H_ */
