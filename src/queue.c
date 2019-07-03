#include "headers/queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//make an empty queue
void makeEmptyQueue(Queue *q) {
	q->start = (qPointer) malloc(sizeof(qCell));
	q->end = q->start;
    q->start->next = NULL;
}

//check if the queue is empty
int empty(const Queue *q) {
	return (q->start == q->end);
}

//add a new cell to the queue
void enqueue(char text[], Queue *q) {
	q->end->next = (qPointer) malloc(sizeof(qCell));
	q->end = q->end->next;
	strcpy(q->end->text, text);
	q->end->next = NULL;
}

/*
remove queue's starting cell and return an error status
0 -> Error
1 -> Ok
*/
int deque(Queue *q, char text[]) {
	//check if the queue is empty
    if (empty(q)) {
		printf("Error: the queue is empty!\n"); //error message
		return 0;
	}
	qPointer p = q->start;
	q->start = q->start->next;
	free(p);
	strcpy(text, q->start->text);
	return 1;
}

//free all the cells on the queue
void freeQueue(Queue *q) {
    qPointer p = q->start;
    
    while (p != NULL) {
        q->start = p->next;
        free(p);
        p = q->start;
    }
}

//print the queue
void printQueue(Queue *q) {
    qPointer p = q->start->next;

    while (p != NULL) {
        printf("%s\n", p->text);
        p = p->next;
    }
}