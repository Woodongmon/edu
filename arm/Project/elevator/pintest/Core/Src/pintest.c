/*
 * pintest.c
 *
 *  Created on: Oct 20, 2025
 *      Author: user21
 */

#include "pintest.h"

void toggletest()
{
    GPIOA->MODER = 0x55555555;      // GPIOA 모든 핀을 출력 모드
    GPIOB->MODER = 0x55555555;      // GPIOB 모든 핀을 출력 모드
    GPIOC->MODER = 0x55555555;      // GPIOA 모든 핀을 출력 모드

      // 필요시 다른 포트도 동일하게 설정

	  GPIOB->ODR = 0x0000;		// 모든 pin을 0으로
	  HAL_Delay(500);

	  GPIOB->ODR = 0xffff;		//모든 pin을 1로
	  HAL_Delay(500);

}
