/*
 * state_b.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include "state_b.h"

static inline void State_B_funA_(State * this) {
	printf("\nB is awsome...State_B_funA_");
	printf(this->name);
}

static inline void State_B_funB_(State * this) {
	printf("\nB is much funnier...State_B_funB_");
	printf(this->name);
}

State_B * State_B_ctor() {
	printf("\tState_B_ctor");
	State_B *ptr = malloc(sizeof(ptr));
	sprintf(ptr->super.name, "State_B");
	static struct StateVtbl const vbtl = {
				&State_B_funA_,
				&State_B_funB_
		};
	ptr->super.vptr = &vbtl;
	return ptr;
}

void State_B_dtor(State_B *this) {
	printf("\tState_B_dtor");
	free(this);
}

