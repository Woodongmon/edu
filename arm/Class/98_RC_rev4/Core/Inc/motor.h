/*
 * motor.h
 *
 *  Created on: Oct 28, 2025
 *      Author: user21
 */


#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
#include "tim.h"

#define IN1_PIN 		GPIO_PIN_1
#define IN1_GPIO_PORT	GPIOB

#define IN2_PIN 		GPIO_PIN_15
#define IN2_GPIO_PORT	GPIOB

#define IN3_PIN 		GPIO_PIN_14
#define IN3_GPIO_PORT	GPIOB

#define IN4_PIN 		GPIO_PIN_13
#define IN4_GPIO_PORT	GPIOB

#define ENA_TIMER        htim2
#define ENA_CHANNEL      TIM_CHANNEL_1

#define ENB_TIMER        htim2
#define ENB_CHANNEL      TIM_CHANNEL_2


void MOTOR_Init();
void FOWARD();
void BACKWARD();

void STOP();
void LV1();
void LV2();
void LV3();

void LEFT();
void RIGHT();



#endif /* INC_MOTOR_H_ */


