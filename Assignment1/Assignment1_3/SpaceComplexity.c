#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"
#include "LinkedList.h"

// 동적 배열의 공간 복잡도를 계산하는 함수
// 추가 구조적 데이터를 고려
int calculateDynamicArraySpaceComplexity(int size, int num_elements) {
    // 배열의 크기 = 요소의 개수 * sizeof(int)
    // + 배열의 구조적 데이터를 저장하기 위해 sizeof(dArray)
    int array_size = num_elements * sizeof(int) + sizeof(dArray);
    return array_size;
}

// 연결 리스트의 공간 복잡도를 계산하는 함수
// 각 노드마다 데이터와 포인터 저장
int calculateLinkedListSpaceComplexity(int num_elements) {
    // 각 노드의 크기 = 데이터의 크기
    // + 다음 노드를 가리키는 포인터의 크기
    int node_size = sizeof(int) + sizeof(listNode*);
    // 총 연결 리스트의 크기 = 각 노드의 크기 * 요소의 개수
    int linked_list_size = node_size * num_elements;
    return linked_list_size;
}


// 동적 배열의 데이터가 저장된 공간의 메모리만 계산하는 함수
int calculateDynamicArrayDataSpace(int num_elements) {
    // 데이터가 저장된 공간 = 요소의 개수 * 데이터 형식의 크기(int)
    int data_space = num_elements * sizeof(int);
    return data_space;
}

// 연결 리스트의 데이터가 저장된 공간의 메모리만 계산하는 함수
int calculateLinkedListDataSpace(int num_elements) {
    // 데이터가 저장된 공간 = 요소의 개수 * 데이터 형식의 크기(int)
    int data_space = num_elements * sizeof(int);
    return data_space;
}
