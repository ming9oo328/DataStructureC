#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_1[10];	// �迭 ����
	int* arr_2;		// ������ ���� ����
	int i;

	for (i = 0; i < 10; i++) {
		arr_1[i] = i + 1;	// �迭�� �� ����
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// �޸� �Ҵ�, �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� 5�� ����

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	printf("\n");

	// sizeof(int) = 4����Ʈ
	realloc(arr_2, sizeof(int) * 10);	// arr_2�� �޸𸮸� 40����Ʈ�� �� �Ҵ�
	// arr_2�� �޸� ũ�� : 20����Ʈ -> 40����Ʈ

	for (i = 0; i < 10; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free�Լ��� �̿��Ͽ� �޸� ����

	return 0;
}