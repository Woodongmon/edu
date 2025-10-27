/*
 * pintest.c
 *
 *  Created on: Oct 20, 2025
 *      Author: user21
 */

#include "pintest.h"

void toggletest()
{
//    GPIOA->MODER = 0x55555555;      // GPIOA 모든 핀을 출력 모드
    GPIOB->MODER = 0x55555555;      // GPIOB 모든 핀을 출력 모드
    GPIOC->MODER = 0x55555555;      // GPIOC 모든 핀을 출력 모드

      // 필요시 다른 포트도 동일하게 설정

    GPIOB->BSRR = 0x0000FFFFu << 16;		// 모든 pin을 0으로
	GPIOC->BSRR = 0x0000FFFFu << 16;
	HAL_Delay(1000);

	GPIOB->BSRR = 0x0000FFFF;		//모든 pin을 1로
	GPIOC->BSRR = 0x0000FFFF;
	  HAL_Delay(500);



}
