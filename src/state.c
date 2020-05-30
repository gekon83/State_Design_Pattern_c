/*
 * state.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include <assert.h>
#include "state.h"


void State_print(State * this) {
	printf("%s", this->name);
}

/*
// purely-virtual functions should never be called
static void State_funA_(State * me) {
    assert(0);
}

static void State_funB_(State * me) {
    assert(0);
}

static inline State * State_execute_(State * this, int flag) {
    assert(0);
}/**/
