#include "uart0.h"

// 통신속도 : 9600bps
// async, 2배속, 8bit, parity bit 없음, stop bit 1개

void UART0_Init()
{
    UBRR0H=0x00;
    UBRR0L=207;

    //둘은 합쳐서 Baud rate

    UCSR0A |= (1<<U2X0); //2배속
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //송수신 활성화
    // UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); //8bit인데, default값
    // asynchronous
    //(1<<UMSEL00) | (1<<UMSEL01);
}

void UART0_Transmit(char data)
{
    while(!(UCSR0A & (1<<UDRE0))); //전송버퍼가 비어있으면(0) while문을 탈출하고
    UDR0 = data; //데이터 전송을 시작                                                                                                                                                                                                                              


}

unsigned UART0_Receive()
{
    while(!(UCSR0A & (1<<RXC0))); //데이터 수신 대기
    return UDR0; //수신된 데이터 리턴
}