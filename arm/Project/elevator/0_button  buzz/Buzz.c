/*
 * Buzz.c
 *
 *  Created on: Oct 16, 2025
 *      Author: user4
 *      #define SIREN_MIN		500
#define SIREN_MAX		1500
#define SIREN_STEP 10
#define SIREN_DELAY 2
 */

#include "main.h"
#include "Buzz.h"

uint8_t Buzz_Count = 0;
uint16_t Buzz_Half_Period = 0;

static uint32_t Buzz_Last_Toggle = 0;
static bool Buzz_On = false;

//void Play_Siren_Cyecle(TIM_HandleTypeDef *htim, uint32_t channel){
//	uint32_t Timer_Clock = HAL_RCC_GetPCLK1Freq() * 2;
//	uint32_t Prescaler = htim1->Instance->PSC;
//	uint32_t Arr_Value;
//
//	for(uint32_t Freq = SIREN_MIN; Freq <= SIREN_MAX; Freq +=SIREN_STEP){
//		Arr_Value = (Timer_Clock/(Prescaler+1)/freq)-1;
//		__HAL_TIM_SET_AUTORELOAD(htim1, Arr_Value);
//		__HAL_TIM_SET_COMPARE(htim1, channel, Arr_Value / 2);
//		HAL_Delay(SIREN_DELAY);
//	}
//	for(uint32_t Freq = SIREN_MAX; Freq >= SIREN_MIN; Freq -=SIREN_STEP){
//			Arr_Value = (Timer_Clock/(Prescaler+1)/freq)-1;
//			__HAL_TIM_SET_AUTORELOAD(htim1, Arr_Value);
//			__HAL_TIM_SET_COMPARE(htim1, channel, Arr_Value / 2);
//			HAL_Delay(SIREN_DELAY);
//		}
//
//}

void Buzz_Init(void){	// buzz 초기화 함수
	Buzz_On = false;
	Buzz_Last_Toggle = HAL_GetTick(); // 최초값 받기
	Buzz_SW(Buzz_On);	//buzz 끄기
}

void Buzz_SW(uint8_t sw){	// SW 1 / 0 >>> ON / OFF // led랑 동작 방식이 똑같음
	HAL_GPIO_WritePin(Buzz_Port, Buzz_Pin, sw);
}
void Buzz_Bell(){	// non-block 함수	// 삐-삐- 동작

	if(Buzz_Count == 0 && Buzz_On == false){	// 울릴 조건이 없으면
		return;
	}
	uint32_t Curr_Time = HAL_GetTick(); // 현재시간 받기
	if(Buzz_On == true){	//buzz on이면
		if(Curr_Time -Buzz_Last_Toggle > Buzz_Half_Period){
			Buzz_SW(0);	// 끄기
			// 업데이트
			Buzz_On = false;
			Buzz_Last_Toggle = Curr_Time;

			Buzz_Count--;	// 실행횟수 차감
		}
	}
	else{	// buzz_on > false
		if(Curr_Time - Buzz_Last_Toggle > Buzz_Half_Period){
			if(Buzz_Count == 0){
				return;
			}
			Buzz_SW(1);
			//업데이트
			Buzz_On = true;
			Buzz_Last_Toggle = Curr_Time;

		}
	}
}

void Buzz_Bell_Start(uint8_t times, uint16_t ms){	//buzz 벨 실행조건 설정 함수
													//이 함수에 값을 넣어 buzz 실행
	Buzz_Count = times;
	Buzz_Half_Period = ms;
	Buzz_On = false;
	Buzz_Last_Toggle = 0;
}

