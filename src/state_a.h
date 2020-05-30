/*
 * state_a.h
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#ifndef STATE_A_H_
#define STATE_A_H_

#include "state.h"

typedef struct {
	State super;
} State_A;

State_A * State_A_ctor();
void State_A_dtor(State_A *this);

#endif /* STATE_A_H_ */
