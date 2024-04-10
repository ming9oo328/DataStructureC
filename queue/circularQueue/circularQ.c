#include <stdio.h>
#include <stdbool.h>
#define MAX 6

typedef struct {
	int front;
	int rear;
	int arr[MAX];
}queue;

bool isEmpty(queue* q) {
	if (q->front == q->rear) return true;
	else return false;
}

bool isFull(queue* q) {
	if ((q->rear+1)%MAX == (q->front)%MAX) return true;
	else return false;
}

void add(queue* q, int item) {
	if (isFull(q)) {
		printf("queue is full.\n");
		return;
	}
	q->rear  = (q->rear+1)%MAX;
	q->arr[q->rear] = item;
}

void delete(queue* q) {
	if (isEmpty(q)) {
		printf("queue is empty.\n");
		return;
	}
	q->front = (q->front+1)%MAX;
}

void printQ(queue* q) {
	if (isEmpty(q)) {
		printf("queue is empty.\n");
		return;
	}
	printf(">>");
	if (q->rear < q->front) {
		for (int i = q->front+1; i <MAX; i++) {
			printf("%d ", q->arr[i]);
		}
		for (int i = 0; i <= q->rear; i++) {
			printf("%d ", q->arr[i]);
		}
	}
	else {
		for (int i = q->front+1; i <= q->rear; i++) {
			printf("%d ", q->arr[i]);
		}
	}
	printf("\n");
}

int main() {
	queue q;
	q.front = 0;
	q.rear = 0;

	add(&q, 1);
	add(&q, 2);
	add(&q, 3);
	add(&q, 4);
	add(&q, 5);
	add(&q, 6);
	printQ(&q);
	delete(&q);
	printQ(&q);
	add(&q, 0);
	printQ(&q);

	return 0;
}