#include "DynamicArray.h"
#include "LinkedList.h"


int main() {
	//DynamicArray와 LinkedList를 테스트

	printf("<DynamicArray Test>\n");

	dArray arr;
	initArray(&arr, 5); // 초기 용량이 5인 동적 배열 생성

	// 요소 추가
	addIndex(&arr, 0, 10);  // 배열의 인덱스 0에 요소 추가
	addIndex(&arr, 1, 20);  // 배열의 인덱스 1에 요소 추가
	addIndex(&arr, 2, 30);  // 배열의 인덱스 2에 요소 추가
	addIndex(&arr, 3, 40);  // 배열의 인덱스 3에 요소 추가
	addIndex(&arr, 4, 50);  // 배열의 인덱스 4에 요소 추가
	addIndex(&arr, 5, 60);  // 배열의 인덱스 5에 요소 추가 --> size 조정[10]


	// 배열 출력
	printarr(&arr); // >> 10 20 30 40 50 60

	// 요소 삭제, 추가
	deleteIndex(&arr, 6); // 배열의 인덱스 6에서 요소 삭제 --> 유효하지 않은 index
	deleteIndex(&arr, 5); // 배열의 인덱스 5에서 요소 삭제 --> 10 20 30 40 50 (size 절반으로 재조정[5])
	addIndex(&arr, 3, 35);  // 배열의 인덱스 2에 요소 추가 --> size 조정[10]

	// 배열 출력
	printarr(&arr); // >> 10 20 30 35 40 50

	// 배열에서 특정 인덱스의 요소 출력
	accessIndex(&arr, 1); // Element in index 1 : 20

	// 배열의 메모리 해제
	freeDynamicArray(&arr);

	printf("\n");

	printf("<LinkedList Test>\n");

	listNode l;
	initList(&l); //list 생성

	//빈 list 출력
	printNode(&l);

	//node 추가
	addNode(&l, 0, 1); //리스트의 인덱스 0에 요소 추가
	addNode(&l, 2, 2); //유효하지 않은 인덱스
	addNode(&l, 1, 2); //리스트의 인덱스 1에 요소 추가
	addNode(&l, 2, 3); //리스트의 인덱스 2에 요소 추가
	addNode(&l, 2, 4); //리스트의 인덱스 2에 요소 추가
	printNode(&l); //1 2 4 3
	
	//node 삭제
	deleteNode(&l, 4); //유효하지 않은 인덱스
	deleteNode(&l, 3); //3 삭제
	printNode(&l); //1 2 4
	deleteNode(&l, 0); //1 삭제
	printNode(&l); //2 4

	//head 접근
	accessHead(&l); //2 출력

	//리스트의 메모리 해제
	freeLinkedList(&l);

	return 0;
}