/*
 * state_a.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include "state_a.h"
#include "state_b.h"

static inline void State_A_funA_(State * this) {
	printf("\nState_A_funA_ called from %s", this->name);
}

static inline void State_A_funB_(State * this) {
	printf("\nState_A_funB_ called from %s", this->name);
}

static inline State * State_A_execute_(State * this, int flag) {
	printf("\n\tState_A_execute_ called from %s with a flag %d", this->name, flag);
	switch(flag) {
	case 0:
		printf("\n\t\t...i am about to free ");
		State_print(this);
		free(this);
		printf("\n\t\tand transorm to State_B...");
		this = (State *) State_B_ctor();
		break;
	case 1:
		printf("\n\t\tdoing something inside State_A...");
		break;
	}
	return this;
}

State_A * State_A_ctor() {
	printf("\t(State_A_ctor)");
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
