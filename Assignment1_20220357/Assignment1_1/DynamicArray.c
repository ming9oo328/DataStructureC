#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DynamicArray 구조체 선언
typedef struct dynamicArray {
	int* array; // 배열 포인터 선언
	int curr; //현재 배열의 size(element의 개수)
	int capacity; //배열의 용량
}dArray;

//초기화
void initArray(dArray* arr, int initialCap) {
	arr->array = (int*)malloc(initialCap * sizeof(int));
	arr->curr = 0;
	arr->capacity = initialCap;
}

//동적배열이 비어있는지 판단
bool ArrayisEmpty(dArray* arr) {
	if (arr->curr == 0) return true;
	else return false;
}
//동적배열이 가득 찼는지 판단
bool ArrayisFull(dArray* arr) {
	if (arr->curr != 0 && (arr->curr == arr->capacity)) return true;
	else return false;
}

//index와 item을 인자로 받아 동적배열에 추가하는 함수
void addIndex(dArray* arr, int index, int item) {
	//배열이 가득 차 있다면 용량을 2배로 증가
	if (ArrayisFull(arr)) {
		arr->capacity *= 2;
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int));
		printf("Array is full. Multiplized capacity : %d\n", arr->capacity);
	}
	//인자로 받은 index가 유효하지 않은 index인 경우
	if (index < 0 || index > arr->curr) {
		printf("해당 index에는 데이터를 추가할 수 없습니다.\n");
		return;
	}
	//index가 맨앞, 특정 index인 경우
	if (index < arr->curr) {
		for (int i = arr->curr; i > index; i--) { // 뒤에서부터 이동
			arr->array[i] = arr->array[i - 1];
		}
	}
	//모든 경우에 대해 배열이 정렬되었으므로 item 추가
	arr->array[index] = item;
	(arr->curr)+=1;
}

//index를 인자로 받아 해당 데이터를 삭제하는 함수
void deleteIndex(dArray* arr, int index) {
	//비어있는 경우
	if (ArrayisEmpty(arr)) {
		printf("array is empty.\n");
		return;
	}
	//유효하지 않은 index인 경우
	if (index < 0 || index >= arr->curr) {
		printf("해당 index에는 데이터가 없습니다.\n");
		return;
	}
	//index의 데이터를 삭제하기 위해 뒤의 데이터들을 당겨옴
	for (int i = index; i < arr->curr - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}
	(arr->curr)-=1;
	//삭제 후에 배열의 size를 2분의 1로 줄일 수 있다면 배열 size 조정
	if ((arr->curr) < ((arr->capacity) / 2 + 1) && (arr->capacity > 2)) {
		arr->capacity /= 2;
		arr->array =realloc(arr->array, (arr->capacity) * sizeof(int)); // 배열 크기 재조정
		printf("Resized capacity : %d\n", arr->capacity);
	}
}

//index를 인자로 받아 접근하고 데이터를 출력하는 함수
void accessIndex(dArray* arr, int index) {
	if (index >= 0 && index < arr->curr) {
		for (int i = 0; i <= arr->curr; i++) {
			if (i == index) {
				printf("Element in index %d : %d\n", index, arr->array[index]);
				return;
			}
		}
	}
	//유효하지 않은 index인 경우
	printf("해당 index에는 데이터가 존재하지 않습니다.\n");
}

//배열을 출력하는 함수
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

//배열을 free
void freeDynamicArray(dArray* arr) {
	if (arr->array != NULL) { // 배열이 할당되어 있는지 확인
		free(arr->array); // 배열 메모리 해제
		arr->array = NULL; // 배열 포인터를 NULL로 설정
	}
}
