/*
 * controller.h
 *
 *  Created on: Oct 19, 2025
 *      Author: user21
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"
#include "stepper.h"

/**
 *  엘리베이터의 움직임 상태 및 테스트
 */


void UP(void);
void DOWN(void);
void STOP(void);

void MOTORTEST(void);

#endif

///**
// *  엘리베이터의 현재 층 확인
// */
//
//#define CURRENTFLOOR
//#define DESTINATIONFLOOR
//
//void NEXTSTATE
//{
//
//}
