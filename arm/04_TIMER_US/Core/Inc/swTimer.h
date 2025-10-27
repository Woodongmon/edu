#ifndef INC_SWTIMER_H_
#define INC_SWTIMER_H_

#include "stdint.h"  // int 사용
#include "stdbool.h" // True, False 사용

#define TIMER_COUNT	4	// 사용가능한 소프트웨어 타이머 갯수

typedef enum
{
  swTimerID1 = 0,	// 첫 번째 타이머
  swTimerID2,
  swTimerID3,
  swTimerID4,
  swTimerMAX,
}swTimerID_tbl;

typedef struct
{
  bool		isRunning;	// 타이머 동작 여부
  volatile bool timeout;	// 타이머 만료
  uint32_t	setTime;	// 설정 시간 (단위: Tick -> ms)
  uint32_t	time;		// 현재 카운트된 시간
}swTimer_tbl;

// 외부에서 사용하기 위한 extern 선언
extern swTimer_tbl softTimer[TIMER_COUNT];

// 사용할 함수 선언
void softTimer_ISR();		// 주기적으로 호출할 인터럽트 서비스 루틴
void softTimer_Init(swTimerID_tbl timerID, uint32_t time);  // 타이머 초기화
bool softTimer_GetStatus(swTimerID_tbl timerID);	    // 타이머 동작 상태 확인
bool softTimer_IsTimeOut(swTimerID_tbl timerID);	    // 타이머 만료 여부 확인
void softTimer_Reset(swTimerID_tbl timerID);		    // 타이머 리셋


#endif /* INC_SWTIMER_H_ */
