#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertexNum; // ���� ����
    int** arr; // ������ �迭�� �ּ� ����
} graph;

void graphInit(graph* G, int cnt);
void graphEdge(graph* G, int src, int dst, int weight);
void graphShow(graph* G);
void graphFree(graph* G);

int main() {
    // �׷��� �ʱ�ȭ
    graph G;
    graphInit(&G, 16);

    // ���� ���� ����
    graphEdge(&G, 1, 2, 3); graphEdge(&G, 2, 3, 1);
    graphEdge(&G, 3, 4, 4); graphEdge(&G, 5, 6, 1);
    graphEdge(&G, 6, 7, 5); graphEdge(&G, 7, 8, 8);
    graphEdge(&G, 9, 10, 2); graphEdge(&G, 10, 11, 4);
    graphEdge(&G, 11, 12, 6); graphEdge(&G, 13, 14, 3);
    graphEdge(&G, 14, 15, 5); graphEdge(&G, 15, 16, 7);

    // ���� ���� ����
    graphEdge(&G, 1, 5, 2); graphEdge(&G, 2, 6, 5);
    graphEdge(&G, 3, 7, 1); graphEdge(&G, 4, 8, 6);
    graphEdge(&G, 5, 9, 3); graphEdge(&G, 6, 10, 4);
    graphEdge(&G, 7, 11, 2); graphEdge(&G, 8, 12, 6);
    graphEdge(&G, 9, 13, 2); graphEdge(&G, 10, 14, 6);
    graphEdge(&G, 11, 15, 4); graphEdge(&G, 12, 16, 4);

    graphShow(&G);
    graphFree(&G);
    return 0;
}

// �׷��� �ʱ�ȭ
void graphInit(graph* G, int cnt) {
    int i;
    G->vertexNum = cnt;
    G->arr = (int**)malloc(sizeof(int*) * (cnt + 1)); // ������ �κ�

    for (i = 1; i <= cnt; i++) {
        G->arr[i] = (int*)calloc(cnt + 1, sizeof(int));
    }
}

// ����ġ�� �ִ� ������ ���� ����
void graphEdge(graph* G, int src, int dst, int weight) {
    G->arr[src][dst] = weight;
    G->arr[dst][src] = weight;
}

// �׷��� ���
void graphShow(graph* G) {
    int i, j;
    int rows = G->vertexNum / 4 * 4 + 1;
    int cols = 45; // �ִ� �� ũ�� ���� (���� ����)

    // ���� �޸� �Ҵ� �� �ʱ�ȭ
    char** grid = (char**)malloc(rows * sizeof(char*));
    for (i = 0; i < rows; i++) {
        grid[i] = (char*)malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
        grid[i][cols - 1] = '\0'; // ���ڿ� �� ǥ��
    }

    // ���� ��� �迭 �ʱ�ȭ
    for (i = 1; i <= G->vertexNum; i++) {
        int row = (i - 1) / 4 * 4;
        int col = ((i - 1) % 4) * 10;
        sprintf(&grid[row][col], "[%2d]", i);
    }

    // ���� ��� (����ġ ����)
    for (i = 1; i <= G->vertexNum; i++) {
        for (j = i + 1; j <= G->vertexNum; j++) { // �ߺ� ��� ����
            if (G->arr[i][j] != 0) {
                int srcRow = (i - 1) / 4 * 4;
                int srcCol = ((i - 1) % 4) * 10;
                int dstRow = (j - 1) / 4 * 4;
                int dstCol = ((j - 1) % 4) * 10;

                if (srcRow == dstRow) {
                    // ���� ����
                    for (int k = srcCol + 4; k < dstCol - 1; k++) {
                        grid[srcRow][k] = '-';
                    }
                    grid[srcRow][(srcCol + dstCol) / 2] = '-';
                    grid[srcRow][(srcCol + dstCol) / 2 + 1] = G->arr[i][j] + '0';
                }
                else if (srcCol == dstCol) {
                    // ���� ����
                    for (int k = srcRow + 1; k < dstRow; k++) {
                        grid[k][srcCol + 2] = '|';
                    }
                    grid[(srcRow + dstRow) / 2][srcCol + 2] = G->arr[i][j] + '0';
                }
            }
        }
    }

    // ���
    for (i = 0; i < rows; i++) {
        printf("%s\n", grid[i]);
        free(grid[i]); // �޸� ����
    }
    free(grid); // �޸� ����
}

// �޸� ���� �Լ� 
void graphFree(graph* G) {
    for (int i = 1; i <= G->vertexNum; i++) {
        free(G->arr[i]);
    }
    free(G->arr);
}
