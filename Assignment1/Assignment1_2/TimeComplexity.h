#ifndef _TIMECOMPLEXITY_H_
#define _TIMECOMPLEXITY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// 동적 배열에 대한 각 연산의 실행 시간을 측정하는 함수
void measureDynamicArrayTime(dArray* arr, int size);

// 연결 리스트에 대한 각 연산의 실행 시간을 측정하는 함수
void measureLinkedListTime(listNode* list, int size);

#endif