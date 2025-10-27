#include "Photo.h"

Photo Floor[4] = {	// 사용할 포트 / 핀 설정
		{GPIOC,GPIO_PIN_10}, // 1층
		{GPIOC,GPIO_PIN_11}, // 2층
		{GPIOD,GPIO_PIN_2},	 // 3층
		{GPIOA,GPIO_PIN_6}
};

bool Photo_Get(uint8_t num){	// 딱히 디바운싱은 필요 없을 듯  // 포토에서 값 읽어서 바로 반환 해줌
	bool Photo_Val = HAL_GPIO_ReadPin(Floor[num].port, Floor[num].pin);
	return Photo_Val;
};
