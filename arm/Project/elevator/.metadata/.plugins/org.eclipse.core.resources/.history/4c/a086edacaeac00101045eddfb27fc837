/*
 * Button.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user4
 */
// PA_0 1 2 ok
//	   1  2  3 층
// PA 3 4
//    UP Down
// PA 5 6
//	  OP CL
// PA 7
// 	  Em

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define B_1F		0
#define B_2F		1
#define B_3F		2
#define B_UP		3
#define B_DW		4

#define B_OP		5
#define B_CL		6
#define B_EM		7
// 버튼별 번호 할당

#define But_ON 		0
#define But_OFF		1
// 버튼 ON / OFF 번호 할당

#include "main.h"
#include "stdbool.h"


typedef struct{
		GPIO_TypeDef *Port;
		uint16_t Pin;
}Button;
// 버튼의 형식을 받을 구조체


bool Button_Get(uint8_t num); 	// 버튼 눌림 감지 + 디바운싱 함수
								// 입력 > num  => 읽을 버튼 번호
								// 출력 > 해당 버튼 눌리면 1반환	// 아니면 0 반환

void Button_All_Process(uint8_t *button_state, uint8_t *button_on);

// 버튼 1~8번까지 한번에 읽어 처리해주는 함수


#endif /* INC_BUTTON_H_ */
