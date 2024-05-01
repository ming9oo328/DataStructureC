#ifndef _SPACECOMPLEXITY_H_
#define _SPACECOMPLEXITY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���� �迭�� ���� ���⵵�� ����ϴ� �Լ�
// �߰� ��Ÿ�����͸� ����Ͽ� �迭�� ũ��� ����� ������ ����մϴ�.
int calculateDynamicArraySpaceComplexity(int size, int num_elements);

// ���� ����Ʈ�� ���� ���⵵�� ����ϴ� �Լ�
// ���� ����Ʈ�� ��� �� ��帶�� �����Ϳ� ���� ��带 ����Ű�� �����͸� �����ؾ� �մϴ�.
int calculateLinkedListSpaceComplexity(int num_elements);

// ���� �迭�� �����Ͱ� ����� ������ �޸𸮸� ����ϴ� �Լ�
int calculateDynamicArrayDataSpace(int num_elements);

// ���� ����Ʈ�� �����Ͱ� ����� ������ �޸𸮸� ����ϴ� �Լ�
int calculateLinkedListDataSpace(int num_elements);


#endif