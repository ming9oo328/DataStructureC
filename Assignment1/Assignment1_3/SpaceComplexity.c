#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"
#include "LinkedList.h"

// ���� �迭�� ���� ���⵵�� ����ϴ� �Լ�
// �߰� ��Ÿ�����͸� ����Ͽ� �迭�� ũ��� ����� ������ ����մϴ�.
int calculateDynamicArraySpaceComplexity(int size, int num_elements) {
    // �迭�� ũ�� = ����� ���� * sizeof(int) (int ������ �����͸� �����ϱ� ����)
    // �߰������� �迭�� ��Ÿ�����͸� �����ϱ� ���� sizeof(dArray)�� ���մϴ�.
    int array_size = num_elements * sizeof(int) + sizeof(dArray);
    return array_size;
}

// ���� ����Ʈ�� ���� ���⵵�� ����ϴ� �Լ�
// ���� ����Ʈ�� ��� �� ��帶�� �����Ϳ� ���� ��带 ����Ű�� �����͸� �����ؾ� �մϴ�.
int calculateLinkedListSpaceComplexity(int num_elements) {
    // �� ����� ũ�� = �������� ũ�� (int ������ �����͸� �����ϱ� ����)
    // + ���� ��带 ����Ű�� �������� ũ�� (listNode* ������ ����Ű�� ����)
    int node_size = sizeof(int) + sizeof(listNode*);
    // �� ���� ����Ʈ�� ũ�� = �� ����� ũ�� * ����� ����
    int linked_list_size = node_size * num_elements;
    return linked_list_size;
}


// ���� �迭�� �����Ͱ� ����� ������ �޸𸮸� ����ϴ� �Լ�
int calculateDynamicArrayDataSpace(int num_elements) {
    // �����Ͱ� ����� ���� = ����� ���� * ������ ������ ũ��(int)
    int data_space = num_elements * sizeof(int);
    return data_space;
}

// ���� ����Ʈ�� �����Ͱ� ����� ������ �޸𸮸� ����ϴ� �Լ�
int calculateLinkedListDataSpace(int num_elements) {
    // �� ����� ������ ������ int �̹Ƿ�, �����Ͱ� ����� ���� = ����� ���� * ������ ������ ũ��(int)
    int data_space = num_elements * sizeof(int);
    return data_space;
}
