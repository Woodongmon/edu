#include "ap.h"

void apInit()
{

}

void apMain()
{
  LCD_Init();

  LCD_GotoXY(0,0);
  LCD_WriteString("HELLO I2C");
  LCD_GotoXY(1,0);
  LCD_WriteString("HELLO 4bit LCD");

  // char buff[30];

  // sprintf(buff, "asdfgh");
  // LCD_WriteStringXY(0,0,buff);

  // int count = 0;

  while (1)
  {
    // sprintf(buff, "Count : %02d", count++);
    // LCD_WriteStringXY(1, 0, buff);
    // _delay_ms(1000);
    // if (count>=100)
    // {
    //   count = 0;
    // }
  }
}


void idlestate()
{
  //input 정의
  static uint8_t input_State[8] = {1,1,1,1,1,1,1,1};

  //output 정의
  static uint8_t Out_State[8] = {1,1,1,1,1,1,1,1};

  //동작 정의

  if(button~~~)
  {
    
  }

}


void upstate()
{

  //input 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //output 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //동작 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;
}


void downstate()
{

  //input 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //output 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //동작 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;
}

void arrivestate()
{

  //input 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //output 정의
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;

  //동작 정의
    
    if(button,photo ~)
    fnd = ~;
    lcd = ~;
    led = ~;
    motor = ~;
    buzzer = ~;
}


if (input = ~~)

upstate =< arrivestate