#include "../common/def.h"


//최적화 방지, 전역변수
volatile uint8_t delayCompleteFlag;
uint16_t countValue;


void delayInit();
void delay_ms(uint16_t ms);