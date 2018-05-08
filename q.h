#include "tcb.h"
#include <stdlib.h>
#include <stdio.h>

/*structTCB_t {

	structTCB_t *next;
	structTCB_t *prev;
	int data;

};*/

//structTCB_t* head;


struct TCB_t* newItem (int num) {
	struct TCB_t *qElem = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	qElem->next = NULL;
	qElem->prev = NULL;
	//qElem->data = num;

	return qElem;
}

void initQueue (struct TCB_t *h) {
	h = NULL;
	//h->next = h;
	//h->prev = h;
	//h = head;
	/*if (h == NULL) {
		printf("it's null");
	}*/
}

void addQueue (struct TCB_t **h, struct TCB_t *n) {
	//printf("add0\n");
	//structTCB_t *temp = h;
	struct TCB_t *last = NULL;
	//printf("add1\n");
	if ((*h) == NULL) {
		//printf("add2\n");
		(*h) = n;
		//printf("add3\n");
		(*h)->next = (*h);
		//printf("add4\n");
		(*h)->prev = (*h);
		
	}
	else {
		//printf("add5\n");
		last = (*h)->prev;
		//printf("add6\n");
		n->next = (*h);
		//printf("add7\n");
		(*h)->prev = n;
		//printf("add8\n");
		n->prev = last;
		//printf("add9\n");
		last->next = n;
		//printf("add10\n");
	}
	
}

struct TCB_t* delQueue (struct TCB_t **h) {
	struct TCB_t *last = NULL;
	struct TCB_t *node = NULL;
	//h = h->next;
	if ((*h)->next == (*h)) {
		(*h)->next = NULL;
		(*h)->prev = NULL;
		//node = h;
		//h = NULL;
		return *h;
	}
	else {
		last = (*h)->prev;
		node = *h;
		(*h) = (*h)->next;
		last->next = *h;
		(*h)->prev = last;
		return node;
	}
	//free(temp);
}

void rotateQ (struct TCB_t **h) {
	//structTCB_t *temp = h->next;
	//structTCB_t *last = h->prev;

	//last->next = temp;
	//temp->prev = 


	//h = temp;
	//temp->next = h;
	//h->prev = temp;
	struct TCB_t *node = delQueue(h);
	addQueue(h, node);
}


void printQ (struct TCB_t *h) {
	struct TCB_t *temp = h;
	int counter = 0;
	//temp = temp->next;
	while (temp->next != h) {
		printf("%d ", counter);
		counter++;
		temp = temp->next;
	}
	printf("%d ", counter);
}

