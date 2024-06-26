#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_1[10];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언
	int i;

	for (i = 0; i < 10; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	printf("\n");

	// sizeof(int) = 4바이트
	realloc(arr_2, sizeof(int) * 10);	// arr_2의 메모리를 40바이트로 재 할당
	// arr_2의 메모리 크기 : 20바이트 -> 40바이트

	for (i = 0; i < 10; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free함수를 이용하여 메모리 해제

	return 0;
}