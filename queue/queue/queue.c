#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
	int front;
	int rear;
	int arr[MAX];
}queue;

bool isEmpty(queue* q) {
	if (q->front == q->rear) return true;
	else return false;
}

bool isFull (queue* q) {
	if (q->rear >= MAX-1) return true;
	else return false;
}

void add(queue* q, int item) {
	if (isFull(q)) {
		printf("queue is full.\n");
		return;
	}
	q->rear += 1;
	q->arr[q->rear] = item;
}

void delete(queue* q){
	if (isEmpty(q)) {
		printf("queue is empty.\n");
		return;
	}
	q->front++;
}

void printQ(queue* q) {
	if (isEmpty(q)) {
		printf("queue is empty.\n");
		return;
	}
	printf(">>");
	for (int i = q->front+1; i <= q->rear; i++) {
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}

int main() {
	queue q;
	q.front = 0;
	q.rear = 0;

	add(&q, 1);
	add(&q, 3);
	add(&q, 5);
	add(&q, 7);
	printQ(&q);
	delete(&q);
	printQ(&q);

	return 0;
}