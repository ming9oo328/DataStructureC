#ifndef _LINKEDLIST_H_
#define __LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// ���� �迭�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureDynamicArrayTime(dArray* arr, int size);

// ���� ����Ʈ�� ���� �� ������ ���� �ð��� �����ϴ� �Լ�
void measureLinkedListTime(listNode* list, int size);

#endif