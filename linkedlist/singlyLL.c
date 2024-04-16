#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;  // 아직 선언 안된 자료형에 대해 포인터 참조만 가능
typedef struct{
	char data;
	listPointer link;
}listNode; // self referential structure
listPointer ptr = NULL;
int cnt=0;

#define isEmpty(ptr) (!ptr) // list가 비어있는지 확인하는 메크로

void addNode(int num, char d) {
	if (isEmpty(ptr)) {
		listNode* newNode = (listNode*)malloc(sizeof(listNode));
		ptr = newNode;
		newNode->data = d;
		newNode->link = NULL;
		cnt++;
	}
	else if (cnt+1 <= num) {
		printf("잘못된 위치입니다.\n");
		return;
	}
	else {
		listNode* curr = ptr;
		for (int i = 1; i < num; i++) {
			curr = curr->link;
		}
		listNode* addNode = (listNode*)malloc(sizeof(listNode));
		addNode->data = d;
		addNode->link = curr->link;
		curr->link = addNode;
		cnt++;
	}
}

void printNode() {
	if (isEmpty(ptr)) {
		printf("list가 비어있습니다.\n");
		return;
	}
	listNode* curr = ptr;
	for (curr = ptr; curr!= NULL; curr=curr->link) {
		printf("%c ", curr->data);
	}
	printf("\n");
}

int main() {
	printNode();
	addNode(0, 'a');
	addNode(2, 'b');
	addNode(1, 'b');
	addNode(2, 'c');
	printNode();
	addNode(2, 'd');
	printNode();

	return 0;
}