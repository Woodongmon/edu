#include "../common/def.h"

volatile uint32_t timer0_Millis; //1ms마다 증가하는 변수

void millisInit();
uint32_t millis();