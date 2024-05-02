#ifndef _DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicArray {
	int* array; // 배열 포인터 선언
	int curr; //현재 배열의 size(element의 개수)
	int capacity; //배열의 용량
}dArray;

void initArray(dArray* arr, int initialCap);

bool ArrayisEmpty(dArray* arr);

bool ArrayisFull(dArray* arr);

void addIndex(dArray* arr, int index, int item);

void deleteIndex(dArray* arr, int index);

void accessIndex(dArray* arr, int index);

void printarr(dArray* arr);

void freeDynamicArray(dArray* arr);

#endif
