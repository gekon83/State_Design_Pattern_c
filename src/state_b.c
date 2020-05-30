/*
 * state_b.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include "state_a.h"
#include "state_b.h"

static inline void State_B_funA_(State * this) {
	printf("\nB is awsome...State_B_funA_ called from %s", this->name);
}

static inline void State_B_funB_(State * this) {
	printf("\nB is much funnier...State_B_funB_ called from %s", this->name);
}

static inline State * State_B_execute_(State * this, int flag) {
	printf("\n\tState_B_execute_ called from %s with a flag %d", this->name, flag);
	switch(flag) {
	case 0:
		printf("\n\t\tdoing something inside State_B...");
		break;
	case 1:
		printf("\n\t\t...i am about to free ");
		State_print(this);
		free(this);
		printf("\n\t\tand transorm to State_A...");
		this = (State *) State_A_ctor();
		break;
	}
	return this;
}

State_B * State_B_ctor() {
	printf("\t(State_B_ctor)");
	State_B *ptr = malloc(sizeof(ptr));
	sprintf(ptr->super.name, "State_B");
	static struct StateVtbl const vbtl = {
				&State_B_funA_,
				&State_B_funB_,
				&State_B_execute_
		};
	ptr->super.vptr = &vbtl;
	return ptr;
}

void State_B_dtor(State_B *this) {
	printf("\tState_B_dtor");
	free(this);
}

