#include "stdint.h"

void delay_count(unsigned int timeCount)
{
	for(;timeCount>0; timeCount--);
}

int main()
{	//RCC_AHB1 레지스터의 GPIOAEN 비트 활성화
	(*(volatile unsigned *)0x40023830) |= 0x01;
	// volatile unsigned : unsigned 데이터가 컴파일되는 것을 방지하는 용도
	// (volatile unsigned *) 0x40023830 : 레지스터 0x40023830을 지칭하는 unsigned 포인터
	// (*(volatile unsigned *)0x40023830) :
	// 레지스터 0x40023830을 지칭하는 unsigned 포인터의 저장된 값을 읽음

	//bit 초기화
	(*(volatile unsigned *)0x40020000) &= ~(0x3 << 10);

	//mode:11 (analog)//
	(*(volatile unsigned *)0x40020000) |=  (0x1 << 10);

	while(1)
	{
	//출력
	(*(volatile unsigned *)0x40020014) |= (1 << 5);
	delay_count(0xffff);
	(*(volatile unsigned *)0x40020014) &= ~(1 << 5);
	delay_count(0xffff);
	}
}

