#ifndef _SPACECOMPLEXITY_H_
#define _SPACECOMPLEXITY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 동적 배열의 공간 복잡도를 계산하는 함수
// 추가 메타데이터를 고려하여 배열의 크기와 요소의 개수를 고려합니다.
int calculateDynamicArraySpaceComplexity(int size, int num_elements);

// 연결 리스트의 공간 복잡도를 계산하는 함수
// 연결 리스트의 경우 각 노드마다 데이터와 다음 노드를 가리키는 포인터를 저장해야 합니다.
int calculateLinkedListSpaceComplexity(int num_elements);

// 동적 배열의 데이터가 저장된 공간의 메모리를 계산하는 함수
int calculateDynamicArrayDataSpace(int num_elements);

// 연결 리스트의 데이터가 저장된 공간의 메모리를 계산하는 함수
int calculateLinkedListDataSpace(int num_elements);


#endif