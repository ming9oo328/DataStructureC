#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicArray{
	int *array; // 배열 포인터 선언
	int curr; //현재 배열의 size(element의 개수)
	int capacity; //배열의 용량
}dArray;

void initArray(dArray* arr, int initialCap) {
	arr->array = (int*)malloc(initialCap * sizeof(int));
	arr->curr = 0;
	arr->capacity = initialCap;
}

bool isEmpty(dArray* arr) {
	if (arr->curr == 0) return true;
	else return false;
}

bool isFull(dArray* arr) {
	if (arr->curr == arr->capacity) return true;
	else return false;
}

void addIndex(dArray* arr, int index, int item) {
	if (isFull(arr)) {
		arr->capacity *= 2;
		printf("Array is full. Multiplized capacity : %d\n", arr->capacity);
	}
	if (index != arr->curr-1) {
		for (int i = index; i < arr->curr - 1; i++) {
			arr->array[i + 1] = arr->array[i];
		}
	}
	arr->array[index] = item;
}

void delete(dArray* arr) {
	if (isEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	arr->front++;
}

void printarr(dArray* arr) {
	if (isEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	printf(">>");
	for (int i = arr->front + 1; i <= arr->rear; i++) {
		printf("%d ", arr->arr[i]);
	}
	printf("\n");
}