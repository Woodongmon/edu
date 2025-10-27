#include "../common/def.h"


void uart0_int_init()
{
    UBRR0H=0x00;
    UBRR0L=0xCF; //9600bps, 11001111

    UCSR0A |= (1<<U2X0); //2배속
    UCSR0B |= (1<<RXCIE0); //수신 인터럽트 활성화
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //UART RX, TX 활성화
    
}

void uart0_int_transmit(char data)
{
    while (!(UCSR0A & (1<<UDRE0))) //전송버퍼가 비어있으면(0) while문을 탈출
    {
        
    }
    UDR0 = data; //데이터 전송 시작
}

unsigned char uart0_int_receive()
{
    while (!(UCSR0A & (1<<RXC0))) //데이터 수신시 while문 탈출
    {
        
    }
    return UDR0; //수신된 데이터 리턴
}