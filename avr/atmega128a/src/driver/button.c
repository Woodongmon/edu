#include "button.h"


//button이라는 데이터형의 변수 btn0n선언과 동시에 메모리 확보
//buttonInit함수를 호출하고, btn0n변수의 주소를 보냄

// typedef struct 
// {
//     volatile uint8_t *ddr;
//     volatile uint8_t *pin;
//     uint8_t btnPin;
//     uint8_t prevState; //이전 상태
// } BUTTON;    

void buttonInit (BUTTON             *button, 
                volatile uint8_t    *ddr, 
                volatile uint8_t    *pin,
                         uint8_t     pinNum)
{
    button->ddr=ddr;
    button->pin=pin;
    button->btnPin=pinNum;
    button->prevState=RELEASED;
    *button->ddr &= (1 <<button->btnPin);

}
uint8_t buttonGetState(BUTTON *button)
{
    uint8_t currState = *button->pin &(1<<button->btnPin);      //pin 레지스터에 저장된 값 중, 선택한 pin정보만을 확인
        if((currState == PUSHED)&(button->prevState==RELEASED)) //버튼이 high->low로 변화할시
    {
        _delay_ms(50);              //debounce code
        button->prevState=PUSHED;   //버튼 상태를 누른 상태로 변환
        return ACT_PUSH;            //버튼이 눌렸음을 반환
    }
    else if((currState != PUSHED)&&(button->prevState==PUSHED)) //버튼이 low->high로 변화할시
    {
        _delay_ms(50);              //debounce code
        button->prevState=RELEASED; //버튼에서 손을 뗌
        return ACT_RELEASE;         //버튼이 release됐음을 반환
    }
    return NO_ACT;
}