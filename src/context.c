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
	ptr->myState = NULL;
	return ptr;
}

void Context_dtor(Context *this) {
	free(this);
}

void Context_changeState(Context *this, int flag) {
	printf("\n\n------>Context_changeState\n");

	if(this->myState != NULL) {
		printf("state set -> freeing memory...\n");
		free(this->myState);
	}

	switch(flag) {
	case (0):
			this->myState = State_A_ctor();
			break;
	case (1):
			this->myState = State_B_ctor();
			break;
	}
}

void Context_useStateFunA(Context *this) {
	State_funA(this->myState);
}
void Context_useStateFunB(Context *this) {
	State_funB(this->myState);
}