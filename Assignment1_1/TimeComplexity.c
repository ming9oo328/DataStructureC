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
    printf("Dynamic Array Insertion Time (size %d): %f seconds\n", size, time_taken);

    // deletion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        deleteIndex(arr, 0);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic Array Deletion Time (size %d): %f seconds\n", size, time_taken);


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
    printf("Dynamic Array Access Time (size %d): %f seconds\n", size, time_taken);
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
    printf("Linked List Insertion Time (size %d): %f seconds\n", size, time_taken);

    // deletion ����
    start = clock();
    for (int i = 0; i < size; i++) {
        deleteNode(list, 0);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linked List Deletion Time (size %d): %f seconds\n", size, time_taken);

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
    printf("Linked List Access Time (size %d): %f seconds\n", size, time_taken);
}

