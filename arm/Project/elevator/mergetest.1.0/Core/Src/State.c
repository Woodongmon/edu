/*
 * State.c
 *
 *  Created on: Oct 21, 2025
 *      Author: user4
 *
 *      레지스터
 *      출력
 */

#include "State.h"

void IDLE_f(uint8_t F_State){

	UPDOWNSTOP();					// 모터 멈춰!
	LCD_Clear(&hi2c1);				// lcd 동작표시

	LCD_SetCursor(&hi2c1, 0, 0);
	LCD_Print(&hi2c1, "idle");
	HAL_Delay(5);
};

void UP_f(uint8_t F_State){

	LCD_Clear(&hi2c1);				// lcd 동작표시
	LCD_SetCursor(&hi2c1, 0, 0);
	LCD_Print(&hi2c1, "up");
	HAL_Delay(5);

	//ledOn();						// led 올라가는 표시
	UP();							// 모터 올려줌




};

void DOWN_f(uint8_t F_State){

	LCD_Clear(&hi2c1);				// lcd 동작표시
	LCD_SetCursor(&hi2c1, 0, 0);
	LCD_Print(&hi2c1, "Down");
	HAL_Delay(5);
	//ledOn();				// led 내려가는 표시
	DOWN();




};

void ARRIVE_f(uint8_t *button_on_state, uint8_t F_State){

	button_on_state[B_UP] = 0;
	button_on_state[B_DW] = 0;
	button_on_state[F_State-1] = 0;	// 도착했으니 해당층을 눌렀던 버튼 리셋
	Buzz_Bell_Start(2, 250);

	//Buzzer(3);						// 부저 3번 on
	motor_stop();					// 모터 멈추고
	door_motor();					// 문 열고 닫고
	ledOff();						// led 끄고

	LCD_Clear(&hi2c1);				// lcd 동작표시
	LCD_SetCursor(&hi2c1, 0, 0);
	LCD_Print(&hi2c1, "arrive");
	HAL_Delay(5);
};
