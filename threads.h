#include "q.h"

struct TCB_t *RunQ;

void start_thread (void (*function)(void)) {
	void *stack = malloc(8192);
	struct TCB_t *tb = malloc(sizeof(struct TCB_t));
	init_TCB(tb, function, stack, 8192);
	addQueue (&RunQ, tb);
}

void run () {   // real code
    ucontext_t parent;     // get a place to store the main context, for faking
    getcontext(&parent);   // magic sauce
    swapcontext(&parent, &((RunQ)->context));  // start the first thread
}

void yield () {
	ucontext_t parent;
	getcontext(&parent);
	rotateQ(&RunQ);
	swapcontext(&parent, &((RunQ)->context));
}


