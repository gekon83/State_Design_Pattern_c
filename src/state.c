/*
 * state.c
 *
 *  Created on: 30 maj 2020
 *      Author: grzko
 */

#include <assert.h>
#include "state.h"


static void State_funA_(State * me) {
    assert(0); /* purely-virtual function should never be called */
}

static void State_funB_(State * me) {
    assert(0); /* purely-virtual function should never be called */
}
