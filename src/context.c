/*
 * context.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include "context.h"

Context * Context_ctor() {
	printf("Context_ctor\n");
	Context *ptr = malloc(sizeof(ptr));
	ptr->myState = (State *) State_A_ctor();
	return ptr;
}

void Context_dtor(Context *this) {
	free(this);
}

void Context_input(Context *this, int flag) {
	printf("\n\n------> Context_input");
	State_print(this->myState);
	this->myState = State_execute(this->myState, flag);
	State_print(this->myState);
}

void Context_useStateFunA(Context *this) {
	State_funA(this->myState);
}
void Context_useStateFunB(Context *this) {
	State_funB(this->myState);
}
