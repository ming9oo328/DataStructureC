#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int top;
	int capacity;
	float* arr;
}stack;

bool isEmpty(stack *s) {
	if (s->top == -1)
		return true;
	else 
		return false;
}

bool isFull(stack *s) {
	if (s->top >= s->capacity - 1)
		return true;
	else
		return false;
}

void stackEmpty() {
	printf("Element is Empty.\n");
}

void stackFull(stack *s) {
	printf("Element is Full. Double the s->capacity.\n");
	s->arr = (float*)realloc(s->arr, 2 * s->capacity * sizeof(*s->arr));
	s->capacity *= 2;
}

void push(stack *s, float item) {
	if (isFull(s)) {
		stackFull(s);
	}
	s->top += 1;
	s->arr[s->top] = item;
}

void pop(stack *s) {
	if (isEmpty(s)) {
		stackEmpty();
	}
	else s->top--;
}
void printStack(stack *s) {
	if (isEmpty(s)) {
		stackEmpty();
	}
	else {
		int i;
		printf("------\n");
		for (i = s->top; i >= 0; i--) {
			printf(" %.2f\n", s->arr[i]);
		}
		printf("------\n");
	}
}

int main() {
	stack s = { -1, 100, (float*)malloc(100 * sizeof(float)) };
	pop(&s);
	push(&s,3);
	push(&s,5);
	push(&s, 4.0);
	printStack(&s);
	pop(&s);
	pop(&s);
	printStack(&s);

	return 0;
}