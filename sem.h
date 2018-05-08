#include "threads.h"

struct TCB_t *waitQ;

typedef struct SEM {
     int value;
} SEM;


void initSem(SEM sem, int val) {
	sem.value = val;
}

void P(SEM sem) {

	struct TCB_t *item;
	if (sem.value <= 0) {
		item = delQueue(&RunQ);
		addQueue(&waitQ, item);
		yield();
	}
	else {
		sem.value--;
	}

}

void V(SEM sem) {
	
	struct TCB_t *item;
	sem.value++;
	item = delQueue(&waitQ);
	addQueue(&RunQ, item);
	yield();
	
}



