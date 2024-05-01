#include "DynamicArray.h"
#include "LinkedList.h"


int main() {

	dArray arr;
	initArray(&arr, 5); // �ʱ� �뷮�� 5�� ���� �迭 ����

	// ��� �߰�
	addIndex(&arr, 0, 10);  // �迭�� �ε��� 0�� ��� �߰�
	addIndex(&arr, 1, 20);  // �迭�� �ε��� 1�� ��� �߰�
	addIndex(&arr, 2, 30);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 3, 40);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 4, 50);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 5, 60);  // �迭�� �ε��� 2�� ��� �߰�


	// �迭 ���
	printarr(&arr); // >> 10 20 30 40 50 60

	// ��� ����
	deleteIndex(&arr, 6); // �迭�� �ε��� 1���� ��� ����
	deleteIndex(&arr, 5); // �迭�� �ε��� 1���� ��� ����
	addIndex(&arr, 3, 40);  // �迭�� �ε��� 2�� ��� �߰�

	// ���� �� �迭 ���
	printarr(&arr); // >> 10 20 30 50 60

	// �迭���� Ư�� �ε����� ��� ���
	accessIndex(&arr, 1); // Element in index 1 : 20

	// �迭�� �޸� ����
	freeDynamicArray(&arr);

	listNode l;
	initList(&l);

	printNode(&l);
	addNode(&l, 0, 1);
	addNode(&l, 2, 2);
	addNode(&l, 1, 2);
	addNode(&l, 2, 3);
	printNode(&l);
	addNode(&l, 2, 4);
	printNode(&l);
	deleteNode(&l, 4);
	deleteNode(&l, 3);
	printNode(&l);
	deleteNode(&l, 0);
	printNode(&l);
	accessHead(&l);

	freeLinkedList(&l);

	return 0;
}