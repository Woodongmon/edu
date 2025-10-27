/*
 * stepper.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_




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

void stepMotor(uint8_t step);
void rotateSteps(uint16_t steps, uint8_t direation);
void rotateDegrees(uint16_t degrees, uint8_t direction);



#endif /* INC_STEPPER_H_ */
