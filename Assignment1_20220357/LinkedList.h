#ifndef _LINKEDLIST_H_
#define __LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode* listPointer;  // ���� ���� �ȵ� �ڷ����� ���� ������ ������ ����
typedef struct {
	int data;
	int cnt;
	listPointer start;
	listPointer link;
}listNode; // self referential structure

void initList(listNode* list);

bool ListisEmpty(listNode* list);

bool ListisFull(listNode* list);

void addNode(listNode* list, int index, int data);

void deleteNode(listNode* list, int data);

void printNode(listNode* list);


#endif