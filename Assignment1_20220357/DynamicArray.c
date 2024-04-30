#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	if (index < 0 || index > arr->curr) {
		printf("�ش� index���� �����͸� �߰��� �� �����ϴ�.\n");
		return;
	}
	if (index < arr->curr) {
		for (int i = arr->curr; i > index; i--) { // �ڿ������� �̵�
			arr->array[i] = arr->array[i - 1];
		}
	}
	arr->array[index] = item;
	arr->curr++;
}

void deleteIndex(dArray* arr, int index) {
	if (isEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	if (index < 0 || index >= arr->curr) {
		printf("�ش� index���� �����Ͱ� �����ϴ�.\n");
		return;
	}
	for (int i = index; i < arr->curr - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}
	arr->curr--;

	if (arr->curr <= arr->capacity / 2) {
		arr->capacity /= 2;
		arr->array = realloc(arr->array, arr->capacity * sizeof(int*)); // �迭 ũ�� ������
		printf("Resized capacity : %d\n", arr->capacity);
	}
}

void printIndex(dArray* arr, int index) {
	for (int i = 0; i <= arr->curr; i++) {
		if (i == index) {
			printf("Element in index %d : %d\n", index, arr->array[index]);
			return;
		}
	}
	printf("�ش� index���� �����Ͱ� �������� �ʽ��ϴ�.\n");
}

void printarr(dArray* arr) {
	if (isEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	printf(">>");
	for (int i = 0; i < arr->curr; i++) {
		printf("%d ", arr->array[i]);
	}
	printf("\n");
}

void freeDynamicArray(dArray* arr) {
	free(arr->array); // �迭 �޸� free
	arr->array = NULL; // �����͸� NULL�� �����Ͽ� dangling pointer ����
}


int main() {
	dArray arr;
	initArray(&arr, 5); // �ʱ� �뷮�� 5�� ���� �迭 ����

	// ��� �߰�
	addIndex(&arr, 0, 10);  // �迭�� �ε��� 0�� ��� �߰�
	addIndex(&arr, 1, 20);  // �迭�� �ε��� 1�� ��� �߰�
	addIndex(&arr, 2, 30);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 3, 40);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 4, 50);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 5, 60);  // �迭�� �ε��� 2�� ��� �߰�


	// �迭 ���
	printarr(&arr); // >> 10 20 30 40 50 60

	// ��� ����
	deleteIndex(&arr, 6); // �迭�� �ε��� 1���� ��� ����
	deleteIndex(&arr, 5); // �迭�� �ε��� 1���� ��� ����
	addIndex(&arr, 3, 40);  // �迭�� �ε��� 2�� ��� �߰�

	// ���� �� �迭 ���
	printarr(&arr); // >> 10 20 30 50 60

	// �迭���� Ư�� �ε����� ��� ���
	printIndex(&arr, 1); // Element in index 1 : 20

	// �迭�� �޸� ����
	freeDynamicArray(&arr);

	return 0;
}
