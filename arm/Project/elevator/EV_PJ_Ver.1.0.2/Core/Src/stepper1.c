/*
 * stepper1.c
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#include "stepper1.h"


//원본 함수입니다.

static const uint8_t HALF_STEP_SEQ1[8][4]=
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

void stepMotor1(uint8_t step1)
{
	HAL_GPIO_WritePin(IN1_GPIO_PORT, IN1_PIN, HALF_STEP_SEQ1[step1][0]);
	HAL_GPIO_WritePin(IN2_GPIO_PORT, IN2_PIN, HALF_STEP_SEQ1[step1][1]);
	HAL_GPIO_WritePin(IN3_GPIO_PORT, IN3_PIN, HALF_STEP_SEQ1[step1][2]);
	HAL_GPIO_WritePin(IN4_GPIO_PORT, IN4_PIN, HALF_STEP_SEQ1[step1][3]);
}



void rotateSteps1(uint16_t steps1, uint8_t direction)
{

	for(uint16_t i=0; i<steps1; i++)
	{
		uint8_t step1;

		//회전방향 설정
		if(direction == DIR_CW)
		{
			step1=i%8;		//CW
		}
		else
		{
			step1=7-(i%8);	//CCW
		}
		stepMotor1(step1);

		HAL_Delay(2);	//각 스텝간 지연
	}


}

void rotateDegrees1(uint16_t degrees, uint8_t direction)
{
	//각도계산
	uint16_t steps1 = (uint16_t)((uint32_t)(degrees*STEPS_PER_REVOLATION)/360);
	rotateSteps1(steps1,direction);
}


//stepper1에 사용되는 커스텀 함수입니다.

void UP(void)
{
    /* 1. 반시계 540도 회전 */
    rotateDegrees1(180, DIR_CCW);
}
void DOWN(void)
{
	/* 2. 시계 방향 540도 회전 */
	rotateDegrees1(180, DIR_CW);
}
void UPDOWNSTOP(void)
{
    /* 3. 정지 (0도 명령 — 의미상 no move) */
    rotateDegrees1(0, DIR_CW);
}

void MOTOR1TEST(void)
{
	UP();
	UPDOWNSTOP();
	HAL_Delay(1000);
	DOWN();

}
