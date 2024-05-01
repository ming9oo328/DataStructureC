#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "SpaceComplexity.h"

int main() {
    int sizes[] = { 5000, 15000, 25000, 35000 };
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int num_elements = size; // �� ����� ���� ����� ������ �ش� ������� ���ٰ� ����

        // ���� �迭�� ���� ���⵵ ��� �� ���
        int dynamic_array_data_space = calculateDynamicArrayDataSpace(num_elements);
        printf("Dynamic Array Data Space (size %d, elements %d): %d bytes\n", size, num_elements, dynamic_array_data_space);
        int dynamic_array_space_complexity = calculateDynamicArraySpaceComplexity(size, num_elements);
        printf("Dynamic Array Space Complexity (size %d, elements %d): %d bytes\n", size, num_elements, dynamic_array_space_complexity);

        // ���� ����Ʈ�� ���� ���⵵ ��� �� ���
        int linked_list_data_space = calculateLinkedListDataSpace(num_elements);
        printf("Linked List Data Space (size %d, elements %d): %d bytes\n", size, num_elements, linked_list_data_space);
        int linked_list_space_complexity = calculateLinkedListSpaceComplexity(num_elements);
        printf("Linked List Space Complexity (size %d, elements %d): %d bytes\n\n", size, num_elements, linked_list_space_complexity);
    }

    return 0;
}