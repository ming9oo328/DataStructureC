#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicArray {
	int* array; // 배열 포인터 선언
	int curr; //현재 배열의 size(element의 개수)
	int capacity; //배열의 용량
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
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int));
		printf("Array is full. Multiplized capacity : %d\n", arr->capacity);
	}
	if (index < 0 || index > arr->curr) {
		printf("해당 index에는 데이터를 추가할 수 없습니다.\n");
		return;
	}
	if (index < arr->curr) {
		for (int i = arr->curr; i > index; i--) { // 뒤에서부터 이동
			arr->array[i] = arr->array[i - 1];
		}
	}
	arr->array[index] = item;
	(arr->curr)+=1;
}

void deleteIndex(dArray* arr, int index) {
	if (ArrayisEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	if (index < 0 || index >= arr->curr) {
		printf("해당 index에는 데이터가 없습니다.\n");
		return;
	}
	for (int i = index; i < arr->curr - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}
	(arr->curr)-=1;

	if ((arr->curr) < ((arr->capacity) / 2 + 1) && (arr->capacity > 2)) {
		arr->capacity /= 2;
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int)); // 배열 크기 재조정
		printf("Resized capacity : %d\n", arr->capacity);
	}
}

void accessIndex(dArray* arr, int index) {
	if (index >= 0 && index < arr->curr) {
		for (int i = 0; i <= arr->curr; i++) {
			if (i == index) {
				printf("Element in index %d : %d\n", index, arr->array[index]);
				return;
			}
		}
	}

	printf("해당 index에는 데이터가 존재하지 않습니다.\n");
}

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

void freeDynamicArray(dArray* arr) {
	if (arr->array != NULL) { // 배열이 할당되어 있는지 확인
		free(arr->array); // 배열 메모리 해제
		arr->array = NULL; // 배열 포인터를 NULL로 설정
	}
	// 나머지 필요한 해제 작업 수행 (예: 기타 자원 해제)
}
