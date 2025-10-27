/*
 * stepper.c
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#include "stepper.h"


//원본 함수입니다.

static const uint8_t HALF_STEP_SEQ[8][4]=
{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,0,1,0},
		{0,0,1,1},
		{0,0,0,1},
		{1,0,0,1}

};

void stepMotor(uint8_t step)
{
	HAL_GPIO_WritePin(IN1_GPIO_PORT, IN1_PIN, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_GPIO_PORT, IN2_PIN, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_GPIO_PORT, IN3_PIN, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_GPIO_PORT, IN4_PIN, HALF_STEP_SEQ[step][3]);
}



void rotateSteps(uint16_t steps, uint8_t direction)
{

	for(uint16_t i=0; i<steps; i++)
	{
		uint8_t step;

		//회전방향 설정
		if(direction == DIR_CW)
		{
			step=i%8;		//CW
		}
		else
		{
			step=7-(i%8);	//CCW
		}
		stepMotor(step);

		HAL_Delay(2);	//각 스텝간 지연
	}


}

//커스텀 함수입니다.

void rotateDegrees(uint16_t degrees, uint8_t direction)
{
	//각도계산
	uint16_t steps = (uint16_t)((uint32_t)(degrees*STEPS_PER_REVOLATION)/360);
	rotateSteps(steps,direction);
}

void UP(void)
{
    /* 1. 반시계 540도 회전 */
    rotateDegrees(180, DIR_CCW);
}
void DOWN(void)
{
	/* 2. 시계 방향 540도 회전 */
	rotateDegrees(180, DIR_CW);
}
void STOP(void)
{
    /* 3. 정지 (0도 명령 — 의미상 no move) */
    rotateDegrees(0, DIR_CW);
}

void MOTORTEST(void)
{
	UP();
	STOP();
	HAL_Delay(1000);
	DOWN();

}
