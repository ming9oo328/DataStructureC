#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//assignment 1_1�� �ڵ带 Ȱ���ϵ�, �ð����⵵ ����� ������ ��¹��� �ּ�ó��

typedef struct dynamicArray {
	int* array; // �迭 ������ ����
	int curr; //���� �迭�� size(element�� ����)
	int capacity; //�迭�� �뷮
}dArray;

void initArray(dArray* arr, int initialCap) {
	arr->array = (int*)malloc(initialCap * sizeof(int));
	arr->curr = 0;
	arr->capacity = initialCap;
}

bool ArrayisEmpty(dArray* arr) {
	if (arr->curr == 0) return true;
	else return false;
}

bool ArrayisFull(dArray* arr) {
	if (arr->curr != 0 && (arr->curr == arr->capacity)) return true;
	else return false;
}

void addIndex(dArray* arr, int index, int item) {
	if (ArrayisFull(arr)) {
		arr->capacity *= 2;
		arr->array = realloc(arr->array, (arr->capacity) * sizeof(int));
		//printf("Array is full. Multiplized capacity : %d\n", arr->capacity);
	}
	if (index < 0 || index > arr->curr) {
		//printf("�ش� index���� �����͸� �߰��� �� �����ϴ�.\n");
		return;
	}
	if (index < arr->curr) {
		for (int i = arr->curr; i > index; i--) {
			arr->array[i] = arr->array[i - 1];
		}
	}
	arr->array[index] = item;
	(arr->curr) += 1;
}

void deleteIndex(dArray* arr, int index) {
	if (ArrayisEmpty(arr)) {
		//printf("array is empty.\n");
		return;
	}
	if (index < 0 || index >= arr->curr) {
		//printf("�ش� index���� �����Ͱ� �����ϴ�.\n");
		return;
	}
	for (int i = index; i < arr->curr - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}
	(arr->curr) -= 1;

	if ((arr->curr) < ((arr->capacity) / 2 + 1) && (arr->capacity>2)) {
		arr->capacity /= 2;
		arr->array = realloc(arr->array, (arr->capacity) * sizeof(int));
		//printf("Resized capacity : %d\n", arr->capacity);
	}
}

void accessIndex(dArray* arr, int index) {
	if (index >= 0 && index < arr->curr) {
		for (int i = 0; i <= arr->curr; i++) {
			if (i == index) {
				//printf("Element in index %d : %d\n", index, arr->array[index]);
				return;
			}
		}
	}

	//printf("�ش� index���� �����Ͱ� �������� �ʽ��ϴ�.\n");
}

void printarr(dArray* arr) {
	if (ArrayisEmpty(arr)) {
		//printf("array is empty.\n");
		return;
	}
	//printf(">>");
	for (int i = 0; i < arr->curr; i++) {
		//printf("%d ", arr->array[i]);
	}
	//printf("\n");
}

void freeDynamicArray(dArray* arr) {
	if (arr->array != NULL) {
		free(arr->array);
		arr->array = NULL;
	}
}
