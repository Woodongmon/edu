/*
 * controller.c
 *
 *  Created on: Oct 19, 2025
 *      Author: user21
 */


#include "controller.h"



/**
 *  엘리베이터의 움직임 상태 및 테스트
 */

void UP(void)
{
    /* 1. 반시계 540도 회전 */
    rotateDegrees(180, DIR_CCW);
}
void DOWN(void)
{
	/* 2. 시계 방향 540도 회전 */
	rotateDegrees(180, DIR_CW);
}
void STOP(void)
{
    /* 3. 정지 (0도 명령 — 의미상 no move) */
    rotateDegrees(0, DIR_CW);
}

void MOTORTEST(void)
{
	UP();
	STOP();
	HAL_Delay(1000);
	DOWN();

}
//
///**
// * 엘리베이터의 현재 층 인식
// */
//
//void Floor_Init(Floor *ctrl) //floor 초기화
//{
//    ctrl->currentFloor = 1
//    ctrl->destinationFloor = 1
//    ctrl->command = MOVE_STOP;
//}
//
//
//void currnetFloor() //현재 층, interrupt를 받아 변화
//{
//
//}
//
//void destinationFloor() //목적지 층, button값으로 결경
//{
//
//}
//
//void contollerRun() //currentFloor와 destnationfloor를 비교하여 이동방향 설정
//{
//	Floor cur = ctrl->currentFloor;
//	Floor dst = ctrl->destinationFloor;
//
//	    if (cur < dst)
//	    {
//	        ctrl->command = MOVE_UP;    // 위로 이동
//	    }
//	    else if (cur > dst)
//	    {
//	        ctrl->command = MOVE_DOWN;  // 아래로 이동
//	    }
//	    else
//	    {
//	        ctrl->command = MOVE_STOP;  // 도착 or 정지
//	    }
//}
