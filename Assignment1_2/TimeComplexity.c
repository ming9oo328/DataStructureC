/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "DynamicArray.h"
#include "LinkedList.h"

// ���� �迭�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureDynamicArrayTime(dArray* arr, int size) {
    clock_t start, end;
    double time_taken;

    // insertion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic Array Insertion Time (size %d): %f milliseconds\n", size, time_taken*1000);

    // deletion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        deleteIndex(arr, 0);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic Array Deletion Time (size %d): %f milliseconds\n", size, time_taken * 1000);


    // access ����
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    start = clock();
    for (int i = 0; i < size; i++) {
        accessIndex(arr, i);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic Array Access Time (size %d): %f milliseconds\n", size, time_taken * 1000);
}

// ���� ����Ʈ�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureLinkedListTime(listNode* list, int size) {
    clock_t start, end;
    double time_taken;

    // insertion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linked List Insertion Time (size %d): %f milliseconds\n", size, time_taken * 1000);

    // deletion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        deleteNode(list, 0);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linked List Deletion Time (size %d): %f milliseconds\n", size, time_taken * 1000);

    // access ����
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    start = clock();
    for (int i = 0; i < size; i++) {
        accessHead(list);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linked List Access Time (size %d): %f milliseconds\n", size, time_taken * 1000);
}


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> // Windows���� �ð� ������ ���� �߰��� ���
#include "DynamicArray.h"
#include "LinkedList.h"
#include "TimeComplexity.h"

// ���� �迭�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureDynamicArrayTime(dArray* arr, int size) {
    LARGE_INTEGER frequency, start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency); // Performance Counter�� ���ļ��� ������

    // insertion ����
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Dynamic Array Insertion Time (size %d): %f milliseconds\n", size, time_taken);

    // deletion ����
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        deleteIndex(arr, 0);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Dynamic Array Deletion Time (size %d): %f milliseconds\n", size, time_taken);

    // access ����
    for (int i = 0; i < size; i++) {
        addIndex(arr, i, i);
    }
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        accessIndex(arr, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Dynamic Array Access Time (size %d): %f milliseconds\n", size, time_taken);
}

// ���� ����Ʈ�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureLinkedListTime(listNode* list, int size) {
    LARGE_INTEGER frequency, start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency); // Performance Counter�� ���ļ��� ������

    // insertion ����
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Linked List Insertion Time (size %d): %f milliseconds\n", size, time_taken);

    // deletion ����
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        deleteNode(list, 0);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Linked List Deletion Time (size %d): %f milliseconds\n", size, time_taken);

    // access ����
    for (int i = 0; i < size; i++) {
        addNode(list, i, i);
    }
    QueryPerformanceCounter(&start);
    for (int i = 0; i < size; i++) {
        accessHead(list);
    }
    QueryPerformanceCounter(&end);
    time_taken = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0; // �и��ʷ� ��ȯ
    printf("Linked List Access Time (size %d): %f milliseconds\n", size, time_taken);
}