#ifndef INC_DELAY_US_H_
#define INC_DELAY_US_H_


//#include "main.h"             //아래와 같은 거야 커서 놓고 f3으로 따라 가보면 저게 나온다고
#include "stm32f4xx_hal.h"      //4xx 면 4백번대 공통 사항이라는 거임, 1백번대면 1xx 겠지

#include "tim.h"

void delay_us(uint16_t us);





#endif /* INC_DELAY_US_H_ */
