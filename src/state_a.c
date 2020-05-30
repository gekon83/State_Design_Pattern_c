/*
 * state_a.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include "state_a.h"

static inline void State_A_funA_(State * this) {
	printf("\nState_A_funA_ called from %s", this->name);
}

static inline void State_A_funB_(State * this) {
	printf("\nState_A_funB_ called from %s", this->name);
}

static inline void State_A_execute_(State * this, int flag) {
	printf("\nState_A_execute_ called from %s with a flag %d", this->name, flag);
}

State_A * State_A_ctor() {
	printf("\tState_A_ctor");
	State_A *ptr = malloc(sizeof(ptr));
	sprintf(ptr->super.name, "State_A");
	static struct StateVtbl const vbtl = {
				&State_A_funA_,
				&State_A_funB_,
				&State_A_execute_
		};
	ptr->super.vptr = &vbtl;
	return ptr;
}

void State_A_dtor(State_A *this) {
	printf("\tState_A_dtor");
	free(this);
}
