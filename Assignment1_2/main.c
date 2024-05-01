
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "TimeComplexity.h"

/*
int main() {

	// 각 연산 시간을 측정할 데이터 구조 생성
	// 다양한 사이즈의 데이터 구조에 대해 측정
	int sizes[] = { 5000, 15000, 25000, 35000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < num_sizes; i++) {
		int size = sizes[i];
		printf("\nMeasurements for size: %d\n", size);

		// dynamicArray에 대한 시간 측정
		dArray arr;
		initArray(&arr, size);
		measureDynamicArrayTime(&arr, size);
		freeDynamicArray(&arr);

		// linkedList에 대한 시간 측정
		listNode list;
		initList(&list);
		measureLinkedListTime(&list, size);
		freeLinkedList(&list);
	}

	return 0;
}
*/

int main() {

	// 각 연산 시간을 측정할 데이터 구조 생성
	// 다양한 사이즈의 데이터 구조에 대해 측정
	int sizes[] = { 5000, 15000, 25000, 35000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < num_sizes; i++) {
		int size = sizes[i];
		printf("\nMeasurements for size: %d\n", size);

		// dynamicArray에 대한 시간 측정
		dArray arr;
		initArray(&arr, size);
		measureDynamicArrayTime(&arr, size);
		freeDynamicArray(&arr);

		// linkedList에 대한 시간 측정
		listNode list;
		initList(&list);
		measureLinkedListTime(&list, size);
		freeLinkedList(&list);
	}

	return 0;
}