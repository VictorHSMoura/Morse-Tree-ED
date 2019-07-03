typedef struct qcell *qPointer;

typedef struct qcell{
	char text[150];
	qPointer next;
} qCell;

typedef struct {
	qPointer start, end;
} Queue;

void makeEmptyQueue(Queue *q);
int empty(const Queue *q);
void enqueue(char text[], Queue *q);
int dequeue(Queue *q, char text[]);
void freeQueue(Queue *q);
void printQueue(Queue *q);