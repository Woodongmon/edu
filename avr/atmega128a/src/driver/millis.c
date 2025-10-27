#include "millis.h"

ISR(TIMER0_COMP_vect)
{
    timer0_Millis++; //Timer0가 발생시키는 인터럽트를 받아 timer0_Millis 의 count를+1
}

void millisInit()
{
    TCCR0 |= (1<<WGM01); //CTC모드

    TCCR0 |= (1<<CS02);

    OCR0=249; //count=250도달 = 1ms마다 인터럽트 발생

    TIMSK |= (1<<OCIE0); //interrupt enable

    sei(); //global interrupt enable

}

uint32_t millis()
{
    uint32_t ms;
    cli(); //interrupt disable
    ms = timer0_Millis;
    sei(); //interrupt enable
    return ms;
}