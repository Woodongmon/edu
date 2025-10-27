#include "swTimer.h"

// 소프트웨어 타이머 배열 선언

swTimer_tbl softTimer[TIMER_COUNT] = {0};

/**
 * 주기적으로 호출할 인터럽트 서비스 루틴
 * 이놈은 systick 핸들러나 타이머 인터럽트에서 호출하면 됨
 */
void softTimer_ISR()
{
  for(uint8_t i = 0; i < TIMER_COUNT; i++)
    {
      if(softTimer[i].isRunning == true)
	{
	  if(softTimer[i].time >= softTimer[i].setTime)
	    {
	      softTimer[i].timeout = true; // 타이머 완료
	    }
	  else
	    {
	      softTimer[i].time++;	   // 시간 카운트 중가
	    }
	}
      else
	{
	  // 타이머가 동작되지 않으면 초기화
	  softTimer[i].timeout = false;
	  softTimer[i].time = 0;
	}
    }
}

/**
 * 소프트웨어 타이머 초기화
 * TimerID: 사용할 타이머 ID
 * time: 설정 할 시간(Tick -> ms)
 */
void softTimer_Init(swTimerID_tbl timerID, uint32_t time)
{
  if(timerID < TIMER_COUNT)
    {
      softTimer[timerID].time = 0;
      softTimer[timerID].isRunning = true;
      softTimer[timerID].setTime = time;
      softTimer[timerID].timeout = false;
    }
}

/**
 * 소프트타이머 동작상태 반환
 * 반환값: true 동작중. false 정지상태
 */
bool softTimer_GetStatus(swTimerID_tbl timerID)	    		// 타이머 동작 상태 확인
{
  if(timerID < TIMER_COUNT)
    {
      return softTimer[timerID].isRunning;
    }
  return false;
}

/**
 * 소프트타이머 완료여부 반환
 * 반환값: true 만료, false 만료 X
 */
bool softTimer_IsTimeOut(swTimerID_tbl timerID)	    		// 타이머 만료 여부 확인
{
  if(timerID < TIMER_COUNT)
    {
      return softTimer[timerID].timeout;
    }
  return false;
}

/**
 * 소프트타이머 재시작
 * 현재 카운트 초기화
 */
void softTimer_Reset(swTimerID_tbl timerID)		    	// 타이머 리셋
{
  if(timerID < TIMER_COUNT)
    {
      softTimer[timerID].time = 0;
      softTimer[timerID].isRunning = true;
      softTimer[timerID].timeout = false;
    }

}

















