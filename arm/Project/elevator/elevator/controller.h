/*
 * stepper.h
 *
 *  Created on: Oct 16, 2025
 *      Author: user21
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_




#include "main.h"

#define UP				DIR_CW
#define STOP
#define DOWN			DIR_CCW

#define BTN_UP_PORT     GPIOA
#define BTN_UP_PIN      GPIO_PIN_5

#define BTN_DOWN_PORT   GPIOA
#define BTN_DOWN_PIN    GPIO_PIN_6

#define BTN_STOP_PORT   GPIOA
#define BTN_STOP_PIN    GPIO_PIN_7

/* 명령(내부 상태) */
typedef enum {
    CMD_STOP = 0,
    CMD_UP,
    CMD_DOWN
} cmd_t;

/* 공유 상태(필요 시 외부에서 볼 수 있게) */
extern volatile cmd_t ButtonState;

/* API */
void controller(void);

/* 외부에 이미 구현돼 있으면 extern만 선언해서 연결 */
void rotateDegrees(uint16_t degrees, uint8_t direction); // 360°, CW/CCW
void stepper_stop(void);                                  // 정지 처리







#endif /* INC_STEPPER_H_ */
