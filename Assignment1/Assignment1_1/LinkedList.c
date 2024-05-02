#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ListNode ����ü ����
typedef struct listNode* listPointer;  // ���� ���� �ȵ� �ڷ����� ���� ������ ������ ����
typedef struct {
	int data;
	int cnt;
	listPointer start;
	listPointer link;
}listNode; // self referential structure

//�ʱ�ȭ
void initList(listNode* list) {
	list->start = (listNode*)malloc(sizeof(listNode*));
	list->cnt = 0;
}

//list�� ����ִ� ���
bool ListisEmpty(listNode* list) {
	if (list->cnt<=0) return true;
	else return false;
}

//index�� data�� ���ڷ� �޾ƿ� list�� �߰�
void addNode(listNode* list, int index, int data) {
	//list�� ����ִ� ��� ���ο� ��� ����
	if (ListisEmpty(list)){
		listNode* newNode = (listNode*)malloc(sizeof(listNode*));
		list->start = newNode;
		newNode->data = data;
		newNode->link = NULL;
		list->cnt++;
	}
	//��������� ������ ��ȿ���� ���� index�� ���
	else if (list->cnt + 1 <= index) {
		printf("�߸��� ��ġ�Դϴ�.\n");
		return;
	}
	//��ȿ�� index������ ù��° ��尡 �ƴ� ���
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

//index�� ���ڷ� �޾� �ش� ��� ����
void deleteNode(listNode* list, int index) {
	listNode* curr = list->start;
	listNode* prev = NULL;

	//��ȿ���� ���� index�� ���
	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->link;
		if (curr == NULL) {
			printf("�߸��� �ε����Դϴ�.\n");
			return;
		}
	}
	// ������ ��尡 ù ��° ����� ���
	if (prev == NULL) {
		list->start = curr->link;
	}
	//�߰�, ������ ����� ���
	else {
		prev->link = curr->link;
	}
	free(curr);
	list->cnt--;
}

//head�� �����ϴ� �Լ�
void accessHead(listNode* list) {
	if (ListisEmpty(list)) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	listNode* first = list->start;
	printf("Head element of the list : %d\n", first->data);
}

//list�� ����ϴ� �Լ�
void printNode(listNode* list) {
	if (ListisEmpty(list)) {
		printf("list�� ����ֽ��ϴ�.\n");
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
