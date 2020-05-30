/*
 * state.h
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#ifndef STATE_H_
#define STATE_H_

#include <stddef.h>
#include <stdio.h>
//#include "context.h"

enum types {
	CHANGE,
	WORK
};

struct StateVtbl;

typedef struct {
	struct StateVtbl const *vptr;
	char name[10];
} State;

struct StateVtbl {
	void (*funA)(State * this);
	void (*funB)(State * this);
	State * (*execute)(State * this, int flag);
};

void State_print(State * this);

static inline void State_funA(State * this) {
	(*this->vptr->funA)(this);
}

static inline void State_funB(State * this) {
	(*this->vptr->funB)(this);
}

static inline State * State_execute(State * this, int flag) {
	(*this->vptr->execute)(this, flag);
}

#endif /* STATE_H_ */
