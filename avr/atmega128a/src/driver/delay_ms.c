#include "delay_ms.h"


ISR(TIMER0_OVF_vect)
{
    static uint16_t count;
    if(++count>=countValue) //count값이 countValue값에 도달시
    {
        count=0;
        TCCR0 &= ~((1<<CS02) | (1<<CS00)); //타이머 초기화 
        delayCompleteFlag=1; //delay 완료 플래그 설정
    }
}

void delayInit()
{   
    delayCompleteFlag=0;

    TIMSK |= (1<<TOIE0); //INTERUPT ENABLE
    TCCR0 |= (1<<CS02) | (1<<CS00); // N=1024

    sei(); //global interrupt enable
}


void delay_ms(uint16_t ms)
{
    delayCompleteFlag=0; // flag 초기화
    countValue=ms; ///count값은 ms값을 받음
    TCNT0=256-125; //
    TCCR0 |= (1<<CS02) | (1<<CS00); // N=1024

    while(!delayCompleteFlag); //flag가 1이 될때까지 대기
}