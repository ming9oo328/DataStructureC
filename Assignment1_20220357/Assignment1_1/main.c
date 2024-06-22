#include "DynamicArray.h"
#include "LinkedList.h"


int main() {
	//DynamicArray�� LinkedList�� �׽�Ʈ

	printf("<DynamicArray Test>\n");

	dArray arr;
	initArray(&arr, 5); // �ʱ� �뷮�� 5�� ���� �迭 ����

	// ��� �߰�
	addIndex(&arr, 0, 10);  // �迭�� �ε��� 0�� ��� �߰�
	addIndex(&arr, 1, 20);  // �迭�� �ε��� 1�� ��� �߰�
	addIndex(&arr, 2, 30);  // �迭�� �ε��� 2�� ��� �߰�
	addIndex(&arr, 3, 40);  // �迭�� �ε��� 3�� ��� �߰�
	addIndex(&arr, 4, 50);  // �迭�� �ε��� 4�� ��� �߰�
	addIndex(&arr, 5, 60);  // �迭�� �ε��� 5�� ��� �߰� --> size ����[10]


	// �迭 ���
	printarr(&arr); // >> 10 20 30 40 50 60

	// ��� ����, �߰�
	deleteIndex(&arr, 6); // �迭�� �ε��� 6���� ��� ���� --> ��ȿ���� ���� index
	deleteIndex(&arr, 5); // �迭�� �ε��� 5���� ��� ���� --> 10 20 30 40 50 (size �������� ������[5])
	addIndex(&arr, 3, 35);  // �迭�� �ε��� 2�� ��� �߰� --> size ����[10]

	// �迭 ���
	printarr(&arr); // >> 10 20 30 35 40 50

	// �迭���� Ư�� �ε����� ��� ���
	accessIndex(&arr, 1); // Element in index 1 : 20

	// �迭�� �޸� ����
	freeDynamicArray(&arr);

	printf("\n");

	printf("<LinkedList Test>\n");

	listNode l;
	initList(&l); //list ����

	//�� list ���
	printNode(&l);

	//node �߰�
	addNode(&l, 0, 1); //����Ʈ�� �ε��� 0�� ��� �߰�
	addNode(&l, 2, 2); //��ȿ���� ���� �ε���
	addNode(&l, 1, 2); //����Ʈ�� �ε��� 1�� ��� �߰�
	addNode(&l, 2, 3); //����Ʈ�� �ε��� 2�� ��� �߰�
	addNode(&l, 2, 4); //����Ʈ�� �ε��� 2�� ��� �߰�
	printNode(&l); //1 2 4 3
	
	//node ����
	deleteNode(&l, 4); //��ȿ���� ���� �ε���
	deleteNode(&l, 3); //3 ����
	printNode(&l); //1 2 4
	deleteNode(&l, 0); //1 ����
	printNode(&l); //2 4

	//head ����
	accessHead(&l); //2 ���

	//����Ʈ�� �޸� ����
	freeLinkedList(&l);

	return 0;
}