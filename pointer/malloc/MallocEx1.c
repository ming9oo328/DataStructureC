#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_1[5];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언
	int i;

	for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	return 0;
}