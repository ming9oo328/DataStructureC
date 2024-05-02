#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DynamicArray ����ü ����
typedef struct dynamicArray {
	int* array; // �迭 ������ ����
	int curr; //���� �迭�� size(element�� ����)
	int capacity; //�迭�� �뷮
}dArray;

//�ʱ�ȭ
void initArray(dArray* arr, int initialCap) {
	arr->array = (int*)malloc(initialCap * sizeof(int));
	arr->curr = 0;
	arr->capacity = initialCap;
}

//�����迭�� ����ִ��� �Ǵ�
bool ArrayisEmpty(dArray* arr) {
	if (arr->curr == 0) return true;
	else return false;
}
//�����迭�� ���� á���� �Ǵ�
bool ArrayisFull(dArray* arr) {
	if (arr->curr != 0 && (arr->curr == arr->capacity)) return true;
	else return false;
}

//index�� item�� ���ڷ� �޾� �����迭�� �߰��ϴ� �Լ�
void addIndex(dArray* arr, int index, int item) {
	//�迭�� ���� �� �ִٸ� �뷮�� 2��� ����
	if (ArrayisFull(arr)) {
		arr->capacity *= 2;
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int));
		printf("Array is full. Multiplized capacity : %d\n", arr->capacity);
	}
	//���ڷ� ���� index�� ��ȿ���� ���� index�� ���
	if (index < 0 || index > arr->curr) {
		printf("�ش� index���� �����͸� �߰��� �� �����ϴ�.\n");
		return;
	}
	//index�� �Ǿ�, Ư�� index�� ���
	if (index < arr->curr) {
		for (int i = arr->curr; i > index; i--) { // �ڿ������� �̵�
			arr->array[i] = arr->array[i - 1];
		}
	}
	//��� ��쿡 ���� �迭�� ���ĵǾ����Ƿ� item �߰�
	arr->array[index] = item;
	(arr->curr)+=1;
}

//index�� ���ڷ� �޾� �ش� �����͸� �����ϴ� �Լ�
void deleteIndex(dArray* arr, int index) {
	//����ִ� ���
	if (ArrayisEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	//��ȿ���� ���� index�� ���
	if (index < 0 || index >= arr->curr) {
		printf("�ش� index���� �����Ͱ� �����ϴ�.\n");
		return;
	}
	//index�� �����͸� �����ϱ� ���� ���� �����͵��� ��ܿ�
	for (int i = index; i < arr->curr - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}
	(arr->curr)-=1;
	//���� �Ŀ� �迭�� size�� 2���� 1�� ���� �� �ִٸ� �迭 size ����
	if ((arr->curr) < ((arr->capacity) / 2 + 1) && (arr->capacity > 2)) {
		arr->capacity /= 2;
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int)); // �迭 ũ�� ������
		printf("Resized capacity : %d\n", arr->capacity);
	}
}

//index�� ���ڷ� �޾� �����ϰ� �����͸� ����ϴ� �Լ�
void accessIndex(dArray* arr, int index) {
	if (index >= 0 && index < arr->curr) {
		for (int i = 0; i <= arr->curr; i++) {
			if (i == index) {
				printf("Element in index %d : %d\n", index, arr->array[index]);
				return;
			}
		}
	}
	//��ȿ���� ���� index�� ���
	printf("�ش� index���� �����Ͱ� �������� �ʽ��ϴ�.\n");
}

//�迭�� ����ϴ� �Լ�
void printarr(dArray* arr) {
	if (ArrayisEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	printf(">>");
	for (int i = 0; i < arr->curr; i++) {
		printf("%d ", arr->array[i]);
	}
	printf("\n");
}

//�迭�� free
void freeDynamicArray(dArray* arr) {
	if (arr->array != NULL) { // �迭�� �Ҵ�Ǿ� �ִ��� Ȯ��
		free(arr->array); // �迭 �޸� ����
		arr->array = NULL; // �迭 �����͸� NULL�� ����
	}
}
