
/*
 * 엘리베이터 led 작동하기
 * 처음엔 1층(1층에 도착해 있음으로 led가 켜져 있음)부터 시작
 * 가고 싶은 층에 버튼을 눌렀다고 가정하고(1층에서 2층)엘리베이터가 올라가면서 led 가 아래에서 위로 순차적으로 올라감
 * 버튼 누르고 또 문이 닫히고 해당 층 버튼 누르면 엘리베이터가 또 출발하면서 led가 올라감
 */

#include "LED.h"

static uint32_t Last_Tick = 0;
static int8_t LED_P = 0;

LED_CONTROL led[4] = { {GPIOA, GPIO_PIN_0, GPIO_PIN_SET, GPIO_PIN_RESET },
                       {GPIOA, GPIO_PIN_1, GPIO_PIN_SET, GPIO_PIN_RESET },
	                     {GPIOA, GPIO_PIN_4, GPIO_PIN_SET, GPIO_PIN_RESET },
                       {GPIOB, GPIO_PIN_0, GPIO_PIN_SET, GPIO_PIN_RESET },
};

void led_Init(){ 	// led 꺼주고 / 틱받아주고
	Last_Tick = HAL_GetTick();
	ledOff();
}

void led_State(uint8_t state){
	if((state == 0) || (state == 3)){ // idle arrive ㅗ
		ledOff();
		return;
	}
	uint32_t Curr_Tick = HAL_GetTick();
	if(state == 1){				// up
		if(Curr_Tick - Last_Tick > 250){
			Last_Tick = Curr_Tick;
			if(LED_P != 4){
				HAL_GPIO_WritePin(led[LED_P].port, led[LED_P].pinNumber,1);
				LED_P++;
			}
			else{
				LED_P = 0;
				ledOff();
			}
		}
	}
	if(state == 2){				// down
		if(Curr_Tick - Last_Tick > 250){
			Last_Tick = Curr_Tick;
			if(LED_P != -1){
				HAL_GPIO_WritePin(led[LED_P].port, led[LED_P].pinNumber,1);
				LED_P--;
			}
			else{
				LED_P = 3;
				ledOff();
			}
		}
	}
}

 	void ledOn()   //led 켜기
	{
	 for (uint8_t i = 0; i < 4; i++)
	 {

	  HAL_GPIO_WritePin(led[i].port, led[i].pinNumber,led[i].onstate);  //포트,핀번호,led 상태

		 }
		}

	 void ledOff()  //LED 끄기
	 {

	   for(uint8_t i = 0; i < 4; i++)

	   {
	   HAL_GPIO_WritePin(led[i].port,led[i] .pinNumber,led[i].offstate);

		}
	  }

	void ledToggle()   //LED토글
	 {

	   for(uint8_t i = 0; i < 4; i++)
	 {
		 HAL_GPIO_TogglePin(led[i].port,led[i].pinNumber);
	  }

 }
	void ledRightShift(void)   // LED가 오른쪽→왼쪽으로 순차 점등 (엘리베이터가 올라감)
	{
	    while (1)   // 무한 반복
	    {
	        for (int8_t i = 3; i >= 0; i--)  // 오른쪽(3)부터 왼쪽(0)으로 이동
	        {
	            // 모든 LED 끄기
	            for (uint8_t j = 0; j < 4; j++)
	            {
	                HAL_GPIO_WritePin(led[j].port, led[j].pinNumber, GPIO_PIN_RESET);
	            }

	            // 현재 LED 켜기
	            HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, GPIO_PIN_SET);

	            HAL_Delay(100);  // 층 이동 속도
	        }
	    }
	}

 void ledLeftShift(void)   // LED가 왼쪽→오른쪽으로 순차 점등 (엘리베이터가 내려감)
 {
     while (1)   // 무한 반복
     {
         for (uint8_t i = 0; i < 4; i++)
         {
             // 모든 LED 끄기
             for (uint8_t j = 0; j < 4; j++)
             {
                 HAL_GPIO_WritePin(led[j].port, led[j].pinNumber, GPIO_PIN_RESET);
             }

             // 현재 LED 켜기
             HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, GPIO_PIN_SET);

             HAL_Delay(100);  // 층 이동 속도
         }
     }
 }

 void ledUp()
 {
	 ledRightShift();
 }

 void ledDown()
 {
	 ledLeftShift();
 }
