
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "TimeComplexity.h"

/*
int main() {

	// �� ���� �ð��� ������ ������ ���� ����
	// �پ��� �������� ������ ������ ���� ����
	int sizes[] = { 5000, 15000, 25000, 35000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < num_sizes; i++) {
		int size = sizes[i];
		printf("\nMeasurements for size: %d\n", size);

		// dynamicArray�� ���� �ð� ����
		dArray arr;
		initArray(&arr, size);
		measureDynamicArrayTime(&arr, size);
		freeDynamicArray(&arr);

		// linkedList�� ���� �ð� ����
		listNode list;
		initList(&list);
		measureLinkedListTime(&list, size);
		freeLinkedList(&list);
	}

	return 0;
}
*/

int main() {

	// �� ���� �ð��� ������ ������ ���� ����
	// �پ��� �������� ������ ������ ���� ����
	int sizes[] = { 5000, 15000, 25000, 35000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < num_sizes; i++) {
		int size = sizes[i];
		printf("\nMeasurements for size: %d\n", size);

		// dynamicArray�� ���� �ð� ����
		dArray arr;
		initArray(&arr, size);
		measureDynamicArrayTime(&arr, size);
		freeDynamicArray(&arr);

		// linkedList�� ���� �ð� ����
		listNode list;
		initList(&list);
		measureLinkedListTime(&list, size);
		freeLinkedList(&list);
	}

	return 0;
}