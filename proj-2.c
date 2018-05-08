//Name: Seyedehbehnaz Sadat
//CSE330 Project1 - Spring 2018

//#include "threads.h"
#include "sem.h"

int buffer[4];

struct SEM fullSem;
struct SEM emptySem;
struct SEM mutexSem;
//int num0 = 0;
//int num1 = 1;
//int num2 = 2;


int in = 0;
int out = 0;

void producer() {
	int num;
	while (1) {
		num = 7;
		P(emptySem);
		P(mutexSem);
		buffer[in] = num;
		in = (in+1) % 2;
		V(mutexSem);
		V(fullSem);
		printf("val: %d\n", num);
	}
	
}

void consumer() {
	int num;
	while (1) {
		P(fullSem);
		P(mutexSem);
		num = buffer[out];
		out = (out+1) % 2;
		V(mutexSem);
		V(emptySem);
	}
	printf("val: %d\n", num);
}

int main() {
	initSem(fullSem, 0);
	initSem(emptySem, 2);
	initSem(mutexSem, 1);
	RunQ = NULL;
	waitQ = NULL;
	initQueue(RunQ);
	initQueue(waitQ);
	start_thread(&producer);
	start_thread(&consumer);
}