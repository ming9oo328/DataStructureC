#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> // Windows에서 시간 측정을 위해 추가
#include "DynamicArray.h"
#include "LinkedList.h"
#include "TimeComplexity.h"

//size가 작은 경우 초단위일 때 0초로 나타나는 경우가 있어 밀리초로 변환 후 출력

// 동적 배열에 대한 각 연산의 실행 시간을 측정하는 함수
void measureDynamicArrayTime(dArray* arr, int size) {
    LARGE_INTEGER frequency, start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency); // Performance Counter의 주파수를 가져옴

    // insertion 측정
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Dynamic Array Insertion Time (size %d): %f milliseconds\n", size, time_taken);

    // deletion 측정
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        deleteIndex(arr, 0);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Dynamic Array Deletion Time (size %d): %f milliseconds\n", size, time_taken);

    // access 측정
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        accessIndex(arr, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Dynamic Array Access Time (size %d): %f milliseconds\n", size, time_taken);
}

// 연결 리스트에 대한 각 연산의 실행 시간을 측정하는 함수
void measureLinkedListTime(listNode* list, int size) {
    LARGE_INTEGER frequency, start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency); // Performance Counter의 주파수를 가져옴

    // insertion 측정
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Linked List Insertion Time (size %d): %f milliseconds\n", size, time_taken);

    // deletion 측정
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        deleteNode(list, 0);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Linked List Deletion Time (size %d): %f milliseconds\n", size, time_taken);

    // access 측정
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        accessHead(list);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // 밀리초로 변환
    printf("Linked List Access Time (size %d): %f milliseconds\n", size, time_taken);
}