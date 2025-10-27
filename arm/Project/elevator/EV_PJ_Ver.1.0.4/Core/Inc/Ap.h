/*
 * Ap.h
 *
 *  Created on: Oct 21, 2025
 *      Author: user4
 */

#ifndef INC_AP_H_
#define INC_AP_H_

#include "main.h"
#include "Button.h"
#include "lcd_i2c.h"
#include "Buzz.h"
#include "Photo.h"
#include "fnd.h"
#include "i2c.h"
#include "motor.h"
#include "LED.h"
#include "State.h"
#include "stepper1.h"
#include "stepper2.h"


enum{
	IDLE_S = 0,
	UP_S,
	DOWN_S,
	ARRIVE_S
};

extern volatile uint8_t F_State;
extern volatile uint8_t B_EM_Flag;					// EM_Flag 초기화 안함



void AP_Init();
void AP_Main();



#endif /* INC_AP_H_ */
