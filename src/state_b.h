/*
 * state_b.h
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#ifndef STATE_B_H_
#define STATE_B_H_

#include <stdlib.h>
#include "state.h"
#include "state_a.h"

typedef struct {
	State super;
} State_B;

State_B * State_B_ctor();
void State_B_dtor(State_B *this);

#endif /* STATE_B_H_ */
