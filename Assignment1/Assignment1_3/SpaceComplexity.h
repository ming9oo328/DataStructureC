#ifndef _SPACECOMPLEXITY_H_
#define _SPACECOMPLEXITY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 동적 배열의 공간 복잡도를 계산하는 함수
int calculateDynamicArraySpaceComplexity(int size, int num_elements);

// 연결 리스트의 공간 복잡도를 계산하는 함수
int calculateLinkedListSpaceComplexity(int num_elements);

// 동적 배열의 데이터가 저장된 공간의 메모리만 계산하는 함수
int calculateDynamicArrayDataSpace(int num_elements);

// 연결 리스트의 데이터가 저장된 공간의 메모리만 계산하는 함수
int calculateLinkedListDataSpace(int num_elements);


#endif