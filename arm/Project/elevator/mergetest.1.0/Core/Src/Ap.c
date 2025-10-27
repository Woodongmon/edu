
#include "Ap.h"

//#define IDLE_STATE 0
//#define UP_STATE 1
//#define DOWN_STATE 2
//#define ARRIVE_STATE 3



//volatile static uint8_t F_State = 1;
// 층 1 2 3
volatile static uint8_t R_State = 0;


// run 1 2 3 4 // 0: idle 1 : UP 2 : DOWN 3: ARRIVE

uint8_t B_ON_State[8] = {0,0,0,0,0,0,0,0}; 	// 버튼 < led on 상태 // 0 1 2 이 목표층이됨 // 3 4 UP DW
uint8_t B_State[8] = {0,0,0,0,0,0,0,0};		// 버튼 초기화용 값
volatile uint8_t F_State = 1; // 1층으로 초기화
volatile uint8_t B_EM_Flag = 0; // 비상아님

void AP_Init(){
	FND_Init();
	LCD_Init(&hi2c1);
	Buzz_Bell_Start(3, 250);
	LCD_Clear(&hi2c1);
	LCD_SetCursor(&hi2c1, 0, 0);
	LCD_Print(&hi2c1, "home");
	R_State = IDLE_S;
	FND_DisplayNumber(F_State);
	led_Init();
	//while(F_State != 1) motor_dw(); // 최초 원점복귀
	// 각종
	// 초기화 함수

};


void AP_Main(){

	while(1){
		UP();

//		led_State(R_State);
//		Buzz_Bell();
//		Button_All_Process(B_State, B_ON_State); // 버튼 읽기
//		// STATE 판단
//
//
//
//		switch(R_State){
//
//			case IDLE_S:
//				IDLE_f(F_State);
//
//				if(F_State == 1){ // 현재층 1층
//
//					if(B_ON_State[0] == 1){ // 1층에서 1층을 누름
//						B_ON_State[0] = 0;	// 목표층 초기화
//						R_State = IDLE_S;		// IDLE 모드 진입
//					}
//
//					else if(B_ON_State[1] == 1 || B_ON_State[2] == 1 || B_ON_State[B_UP] == 1){
//						R_State = UP_S;
//						if(B_ON_State[B_UP] == 1) B_ON_State[1] = 1;
//					}
//					// 2층 // 3층 // 위 누르면 UP 모드 진입
//
//					else if(B_ON_State[B_DW] == 1){  //1층에서 아래 누름
//						R_State = IDLE_S;			//IDLE 모드 진입
//						B_ON_State[B_DW] = 0;	//DW버튼 OFF
//					}
//				}
//
//				if(F_State == 2){	// 현재층이 2층
//
//					if(B_ON_State[0] == 1 || B_ON_State[B_DW] == 1){ // 2층에서 1층을 누름
//						R_State = DOWN_S;		// down 모드 진입
//						if(B_ON_State[B_DW] == 1) B_ON_State[0] = 1;
//					}
//
//					else if(B_ON_State[1] == 1){ // 2층에서 2층을 누름
//						B_ON_State[1] = 0;	// 목표층 초기화
//						R_State = IDLE_S;		// IDLE 모드 진입
//					}
//					else if(B_ON_State[2] == 1 || B_ON_State[B_UP] == 1){
//						R_State = UP_S;
//						if(B_ON_State[B_UP] == 1) B_ON_State[2] = 1;
//					}
//				}
//
//				if(F_State == 3){	// 현재층이 3층
//					if(B_ON_State[0] == 1 || B_ON_State[1] == 1 || B_ON_State[B_DW] == 1){ 	// 3층에서
//						R_State = DOWN_S;		// down 모드 진입// 1층 2층 아래를 누름
//						if(B_ON_State[B_DW] == 1) B_ON_State[1] = 1;
//					}
//					else if(B_ON_State[2] == 1){ // 3층에서 3층을 누름
//						B_ON_State[2] = 0;	// 목표층 초기화
//						R_State = IDLE_S;		// IDLE 모드 진입
//					}
//					else if(B_ON_State[B_UP] == 1){
//						B_ON_State[B_UP] = 0;
//						R_State = IDLE_S;
//					}
//
//				}
//			break;
//
//			case UP_S:
//				UP_f(F_State);
//				if(B_ON_State[F_State-1] == 1) R_State = ARRIVE_S;
//				// 1 > 2층
//				// f_state = 2
//				//
//				// bon[2-1]
//				// 0>1 1>2
//			break;
//
//
//			case DOWN_S:
//				DOWN_f(F_State);
//				if(B_ON_State[F_State-1] == 1) R_State = ARRIVE_S;
//			break;
//
//			case ARRIVE_S:
//				ARRIVE_f(B_ON_State, F_State);
//				R_State = IDLE_S;
//			break;
//
//			default:
//				R_State = IDLE_S;
//			break;
//		}

	}
};
