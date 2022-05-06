#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
// how to use
// declare struct _stack* st
// st=initStack()
// use:
// push(st,10);
// pop(st);
// _top(st);
// isEmpty(st);
// clear(st);
// then destroy
// destroy(st);

int main()
{
	struct _stack* st = initStack();
	push(st,10);
	push(st,20);
	printf("%d ", _top(st));
	pop(st);
	printf("%d ", _top(st));
	pop(st);
	printf("%d ", _top(st));
	push(st,20);
	clear(st);
	printf("%d ", _top(st));
	destroy(st);
	return 0;
}
