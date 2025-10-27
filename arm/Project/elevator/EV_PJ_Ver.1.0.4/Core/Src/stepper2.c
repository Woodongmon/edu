/*
 * stepper2.c
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#include "stepper2.h"


//원본 함수입니다.

static const uint8_t HALF_STEP_SEQ2[8][4]=
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

void stepMotor2(uint8_t step2)
{
	HAL_GPIO_WritePin(IN5_GPIO_PORT, IN5_PIN, HALF_STEP_SEQ2[step2][0]);
	HAL_GPIO_WritePin(IN6_GPIO_PORT, IN6_PIN, HALF_STEP_SEQ2[step2][1]);
	HAL_GPIO_WritePin(IN7_GPIO_PORT, IN7_PIN, HALF_STEP_SEQ2[step2][2]);
	HAL_GPIO_WritePin(IN8_GPIO_PORT, IN8_PIN, HALF_STEP_SEQ2[step2][3]);
}



void rotateSteps2(uint16_t steps2, uint8_t direction)
{

	for(uint16_t i=0; i<steps2; i++)
	{
		uint8_t step2;

		//회전방향 설정
		if(direction == DIR_CW)
		{
			step2=i%8;		//CW
		}
		else
		{
			step2=7-(i%8);	//CCW
		}
		stepMotor2(step2);

		HAL_Delay(2);	//각 스텝간 지연
	}


}

void rotateDegrees2(uint16_t degrees, uint8_t direction)
{
	//각도계산
	uint16_t steps2 = (uint16_t)((uint32_t)(degrees*STEPS_PER_REVOLATION)/360);
	rotateSteps2(steps2,direction);
}


//stepper2에 사용되는 커스텀 함수입니다.

void OPEN(void)
{
    /* 1. 반시계 540도 회전 */
    rotateDegrees2(90, DIR_CCW);
}
void CLOSE(void)
{
	/* 2. 시계 방향 540도 회전 */
	rotateDegrees2(90, DIR_CW);
}
void LEFTRIGHTSTOP(void)
{
    /* 3. 정지 (0도 명령 — 의미상 no move) */
    rotateDegrees2(0, DIR_CW);
}

void MOTOR2TEST(void)
{
	OPEN();
	CLOSE();
	HAL_Delay(1000);
	LEFTRIGHTSTOP();

}
