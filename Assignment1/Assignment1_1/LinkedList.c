#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ListNode 구조체 선언
typedef struct listNode* listPointer;  // 아직 선언 안된 자료형에 대해 포인터 참조만 가능
typedef struct {
	int data;
	int cnt;
	listPointer start;
	listPointer link;
}listNode; // self referential structure

//초기화
void initList(listNode* list) {
	list->start = (listNode*)malloc(sizeof(listNode*));
	list->cnt = 0;
}

//list가 비어있는 경우
bool ListisEmpty(listNode* list) {
	if (list->cnt<=0) return true;
	else return false;
}

//index와 data를 인자로 받아와 list에 추가
void addNode(listNode* list, int index, int data) {
	//list가 비어있는 경우 새로운 노드 생성
	if (ListisEmpty(list)){
		listNode* newNode = (listNode*)malloc(sizeof(listNode*));
		list->start = newNode;
		newNode->data = data;
		newNode->link = NULL;
		list->cnt++;
	}
	//비어있지는 않지만 유효하지 않은 index인 경우
	else if (list->cnt + 1 <= index) {
		printf("잘못된 위치입니다.\n");
		return;
	}
	//유효한 index이지만 첫번째 노드가 아닌 경우
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

//index를 인자로 받아 해당 노드 삭제
void deleteNode(listNode* list, int index) {
	listNode* curr = list->start;
	listNode* prev = NULL;

	//유효하지 않은 index인 경우
	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->link;
		if (curr == NULL) {
			printf("잘못된 인덱스입니다.\n");
			return;
		}
	}
	// 삭제할 노드가 첫 번째 노드인 경우
	if (prev == NULL) {
		list->start = curr->link;
	}
	//중간, 마지막 노드인 경우
	else {
		prev->link = curr->link;
	}
	free(curr);
	list->cnt--;
}

//head에 접근하는 함수
void accessHead(listNode* list) {
	if (ListisEmpty(list)) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	listNode* first = list->start;
	printf("Head element of the list : %d\n", first->data);
}

//list를 출력하는 함수
void printNode(listNode* list) {
	if (ListisEmpty(list)) {
		printf("list가 비어있습니다.\n");
		return;
	}
	listNode* curr = list-> start;
	for (curr = list->start; curr != NULL; curr = curr->link) {
		printf("%d ", curr->data);
	}
	printf("\n");
}

//list free
void freeLinkedList(listNode* list) {
	listNode* curr = list->start;
	while (curr != NULL) {
		listNode* temp = curr;
		curr = curr->link;
		free(temp);
	}
}
