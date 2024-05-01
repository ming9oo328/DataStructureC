#include "DynamicArray.h"
#include "LinkedList.h"


int main() {

	dArray arr;
	initArray(&arr, 5); // 초기 용량이 5인 동적 배열 생성

	// 요소 추가
	addIndex(&arr, 0, 10);  // 배열의 인덱스 0에 요소 추가
	addIndex(&arr, 1, 20);  // 배열의 인덱스 1에 요소 추가
	addIndex(&arr, 2, 30);  // 배열의 인덱스 2에 요소 추가
	addIndex(&arr, 3, 40);  // 배열의 인덱스 2에 요소 추가
	addIndex(&arr, 4, 50);  // 배열의 인덱스 2에 요소 추가
	addIndex(&arr, 5, 60);  // 배열의 인덱스 2에 요소 추가


	// 배열 출력
	printarr(&arr); // >> 10 20 30 40 50 60

	// 요소 삭제
	deleteIndex(&arr, 6); // 배열의 인덱스 1에서 요소 삭제
	deleteIndex(&arr, 5); // 배열의 인덱스 1에서 요소 삭제
	addIndex(&arr, 3, 40);  // 배열의 인덱스 2에 요소 추가

	// 삭제 후 배열 출력
	printarr(&arr); // >> 10 20 30 50 60

	// 배열에서 특정 인덱스의 요소 출력
	accessIndex(&arr, 1); // Element in index 1 : 20

	// 배열의 메모리 해제
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