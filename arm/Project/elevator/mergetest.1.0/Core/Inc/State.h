/*
 * State.h
 *
 *  Created on: Oct 21, 2025
 *      Author: user4
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

#include "Ap.h"

void IDLE_f(uint8_t F_State);

void UP_f(uint8_t F_State);

void DOWN_f(uint8_t F_State);

void ARRIVE_f(uint8_t *button_on_state, uint8_t F_State);

#endif /* INC_STATE_H_ */
