/*
 * context.h
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <stdlib.h>
#include "state.h"
#include "state_a.h"
#include "state_b.h"

typedef struct {
	State * myState;
} Context;

Context * Context_ctor();
void Context_dtor(Context *this);
void Context_changeState(Context *this, int flag);
void Context_useStateFunA(Context *this);
void Context_useStateFunB(Context *this);

#endif /* CONTEXT_H_ */
