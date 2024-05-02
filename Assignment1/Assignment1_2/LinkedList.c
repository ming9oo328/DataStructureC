#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//assignment 1_1의 코드를 활용하되, 시간복잡도 연산과 무관한 출력문은 주석처리

typedef struct listNode* listPointer;  // 아직 선언 안된 자료형에 대해 포인터 참조만 가능
typedef struct {
	int data;
	int cnt;
	listPointer start;
	listPointer link;
}listNode; // self referential structure

void initList(listNode* list) {
	list->start = (listNode*)malloc(sizeof(listNode*));
	list->cnt = 0;
}

bool ListisEmpty(listNode* list) {
	if (list->cnt <= 0) return true;
	else return false;
}

void addNode(listNode* list, int index, int data) {
	if (ListisEmpty(list)) {
		listNode* newNode = (listNode*)malloc(sizeof(listNode*));
		list->start = newNode;
		newNode->data = data;
		newNode->link = NULL;
		list->cnt++;
	}
	else if (list->cnt + 1 <= index) {
		//printf("잘못된 위치입니다.\n");
		return;
	}
	else {
		listNode* curr = list->start;
		for (int i = 1; i < index; i++) {
			curr = curr->link;
		}
		listNode* addNode = (listNode*)malloc(sizeof(listNode*));
		addNode->data = data;
		addNode->link = curr->link;
		curr->link = addNode;
		list->cnt++;
	}
}

void deleteNode(listNode* list, int index) {
	listNode* curr = list->start;
	listNode* prev = NULL;

	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->link;
		if (curr == NULL) {
			//printf("잘못된 인덱스입니다.\n");
			return;
		}
	}
	if (prev == NULL) {
		list->start = curr->link;
	}
	else {
		prev->link = curr->link;
	}
	free(curr);
	list->cnt--;
}

void accessHead(listNode* list) {
	if (ListisEmpty(list)) {
		//printf("리스트가 비어 있습니다.\n");
		return;
	}

	listNode* first = list->start;
	//printf("Head element of the list : %d\n", first->data);
}


void printNode(listNode* list) {
	if (ListisEmpty(list)) {
		//printf("list가 비어있습니다.\n");
		return;
	}
	listNode* curr = list->start;
	for (curr = list->start; curr != NULL; curr = curr->link) {
		//printf("%d ", curr->data);
	}
	//printf("\n");
}

void freeLinkedList(listNode* list) {
	listNode* curr = list->start;
	while (curr != NULL) {
		listNode* temp = curr;
		curr = curr->link;
		free(temp);
	}
}
