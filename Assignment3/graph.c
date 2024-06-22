#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertexNum; // 정점 개수
    int** arr; // 포인터 배열의 주소 저장
} graph;

void graphInit(graph* G, int cnt);
void graphEdge(graph* G, int src, int dst, int weight);
void graphShow(graph* G);
void graphFree(graph* G);

int main() {
    // 그래프 초기화
    graph G;
    graphInit(&G, 16);

    // 가로 엣지 연결
    graphEdge(&G, 1, 2, 3); graphEdge(&G, 2, 3, 1);
    graphEdge(&G, 3, 4, 4); graphEdge(&G, 5, 6, 1);
    graphEdge(&G, 6, 7, 5); graphEdge(&G, 7, 8, 8);
    graphEdge(&G, 9, 10, 2); graphEdge(&G, 10, 11, 4);
    graphEdge(&G, 11, 12, 6); graphEdge(&G, 13, 14, 3);
    graphEdge(&G, 14, 15, 5); graphEdge(&G, 15, 16, 7);

    // 세로 엣지 연결
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

// 그래프 초기화
void graphInit(graph* G, int cnt) {
    int i;
    G->vertexNum = cnt;
    G->arr = (int**)malloc(sizeof(int*) * (cnt + 1)); // 수정된 부분

    for (i = 1; i <= cnt; i++) {
        G->arr[i] = (int*)calloc(cnt + 1, sizeof(int));
    }
}

// 가중치가 있는 무방향 엣지 선언
void graphEdge(graph* G, int src, int dst, int weight) {
    G->arr[src][dst] = weight;
    G->arr[dst][src] = weight;
}

// 그래프 출력
void graphShow(graph* G) {
    int i, j;
    int rows = G->vertexNum / 4 * 4 + 1;
    int cols = 45; // 최대 열 크기 설정 (조정 가능)

    // 동적 메모리 할당 및 초기화
    char** grid = (char**)malloc(rows * sizeof(char*));
    for (i = 0; i < rows; i++) {
        grid[i] = (char*)malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
        grid[i][cols - 1] = '\0'; // 문자열 끝 표시
    }

    // 정점 출력 배열 초기화
    for (i = 1; i <= G->vertexNum; i++) {
        int row = (i - 1) / 4 * 4;
        int col = ((i - 1) % 4) * 10;
        sprintf(&grid[row][col], "[%2d]", i);
    }

    // 간선 출력 (가중치 포함)
    for (i = 1; i <= G->vertexNum; i++) {
        for (j = i + 1; j <= G->vertexNum; j++) { // 중복 출력 방지
            if (G->arr[i][j] != 0) {
                int srcRow = (i - 1) / 4 * 4;
                int srcCol = ((i - 1) % 4) * 10;
                int dstRow = (j - 1) / 4 * 4;
                int dstCol = ((j - 1) % 4) * 10;

                if (srcRow == dstRow) {
                    // 가로 엣지
                    for (int k = srcCol + 4; k < dstCol - 1; k++) {
                        grid[srcRow][k] = '-';
                    }
                    grid[srcRow][(srcCol + dstCol) / 2] = '-';
                    grid[srcRow][(srcCol + dstCol) / 2 + 1] = G->arr[i][j] + '0';
                }
                else if (srcCol == dstCol) {
                    // 세로 엣지
                    for (int k = srcRow + 1; k < dstRow; k++) {
                        grid[k][srcCol + 2] = '|';
                    }
                    grid[(srcRow + dstRow) / 2][srcCol + 2] = G->arr[i][j] + '0';
                }
            }
        }
    }

    // 출력
    for (i = 0; i < rows; i++) {
        printf("%s\n", grid[i]);
        free(grid[i]); // 메모리 해제
    }
    free(grid); // 메모리 해제
}

// 메모리 해제 함수 
void graphFree(graph* G) {
    for (int i = 1; i <= G->vertexNum; i++) {
        free(G->arr[i]);
    }
    free(G->arr);
}
