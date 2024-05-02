#ifndef _LINKEDLIST_H_
#define __LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode* listPointer;  // 아직 선언 안된 자료형에 대해 포인터 참조만 가능
typedef struct {
	int data;
	int cnt;
	listPointer start;
	listPointer link;
}listNode; // self referential structure

void initList(listNode* list);

bool ListisEmpty(listNode* list);

void addNode(listNode* list, int index, int data);

void deleteNode(listNode* list, int index);

void accessHead(listNode* list);

void printNode(listNode* list);

void freeLinkedList(listNode* list);

#endif