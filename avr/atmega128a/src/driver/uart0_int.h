#include "../common/def.h"


void uart0_int_init();
void uart0_int_transmit(char data);
unsigned uart0_int_receive();

extern FILE OUTPUT; //출력 스트림 표준입출력
extern int8_t rxFlag; //수신완료 플래그
extern char rxBfuff[00]; //수신버퍼
