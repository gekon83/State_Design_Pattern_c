/*
 ============================================================================
 Name        : test_State.c
 Author      : gekon83
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "state_a.h"
#include "state_b.h"
#include "context.h"

void ClientCode() {
	Context *context = Context_ctor();

	Context_input(context, 0);
	Context_useStateFunA(context);
	Context_useStateFunB(context);

	Context_input(context, 1);
	Context_useStateFunB(context);
	Context_useStateFunA(context);

	Context_input(context, 0);
	Context_useStateFunB(context);/**/
	free(context);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	ClientCode();
	return EXIT_SUCCESS;
}
