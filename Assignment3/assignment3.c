#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 그래프 구조체 정의
typedef struct graph {
    int vertexNum;
    int** arr;
} graph;

// 간선 구조체 정의
typedef struct edge {
    int src;
    int dst;
    int weight;
} edge;

void graphInit(graph* G, int cnt);
void graphEdge(graph* G, int src, int dst, int weight);
void graphShow(graph* G);
void graphFree(graph* G);
int find(int* parent, int i);
void unionSet(int* parent, int* rank, int x, int y);
graph KruskalMST(graph* G);
int compareEdges(const void* a, const void* b);
void dijkstra(graph* G, int start);
void printPath(int* parent, int j);


int main() {
    graph G;
    graph MST;
    graphInit(&G, 16);

    // 가로 연결
    graphEdge(&G, 1, 2, 3); graphEdge(&G, 2, 3, 1);
    graphEdge(&G, 3, 4, 4); graphEdge(&G, 5, 6, 1);
    graphEdge(&G, 6, 7, 5); graphEdge(&G, 7, 8, 8);
    graphEdge(&G, 9, 10, 2); graphEdge(&G, 10, 11, 4);
    graphEdge(&G, 11, 12, 6); graphEdge(&G, 13, 14, 3);
    graphEdge(&G, 14, 15, 5); graphEdge(&G, 15, 16, 7);

    // 세로 연결
    graphEdge(&G, 1, 5, 2); graphEdge(&G, 2, 6, 5);
    graphEdge(&G, 3, 7, 1); graphEdge(&G, 4, 8, 6);
    graphEdge(&G, 5, 9, 3); graphEdge(&G, 6, 10, 4);
    graphEdge(&G, 7, 11, 2); graphEdge(&G, 8, 12, 6);
    graphEdge(&G, 9, 13, 2); graphEdge(&G, 10, 14, 6);
    graphEdge(&G, 11, 15, 4); graphEdge(&G, 12, 16, 4);

    printf("기본 그래프:\n\n");
    graphShow(&G);

    printf("\n\n\nMST:\n\n");
    MST = KruskalMST(&G);
    graphShow(&MST);

    printf("\n\n\n노드 1로부터 모든 노드까지의 최단 경로:\n\n");
    dijkstra(&G, 1);

    graphFree(&G);
    return 0;
}

// 그래프 초기화
void graphInit(graph* G, int cnt) {
    int i;
    G->vertexNum = cnt;
    G->arr = (int**)malloc(sizeof(int*) * (cnt + 1));

    for (i = 1; i <= cnt; i++) {
        G->arr[i] = (int*)calloc(cnt + 1, sizeof(int));
    }
}

// 가중치가 있는 무방향 그래프 간선 추가
void graphEdge(graph* G, int src, int dst, int weight) {
    G->arr[src][dst] = weight;
    G->arr[dst][src] = weight;
}

// 그래프 출력
void graphShow(graph* G) {
    int rows = 4; // Assume a 4x4 grid
    int cols = 4;
    for (int i = 0; i < rows; ++i) {
        // Print horizontal edges
        for (int j = 1; j <= cols; ++j) {
            int node = i * cols + j;
            if (node <= G->vertexNum) {
                printf("[%2d]", node);
                if (j < cols) {
                    if (G->arr[node][node + 1] != 0) {
                        int nextNode = node + 1;
                        printf("--%d--", G->arr[node][nextNode]);
                    }
                    else {
                        int nextNode = node + 1;
                        printf("     ");
                    }
                }
            }
        }
        printf("\n");
        if (i < rows - 1) {
            // Print vertical edges
            for (int j = 1; j <= cols; ++j) {
                int node = i * cols + j;
                if (node <= G->vertexNum && node + cols <= G->vertexNum) {
                    if (G->arr[node][node + cols] != 0) {
                        printf("   |    ");
                    }
                    else {
                        printf("        ");
                    }
                }
            }
            printf("\n");
            for (int j = 1; j <= cols; ++j) {
                int node = i * cols + j;
                if (node <= G->vertexNum && node + cols <= G->vertexNum) {
                    if (G->arr[node][node + cols] != 0) {
                        printf("   %d    ", G->arr[node][node + cols]);
                    }
                    else {
                        printf("        ");
                    }
                }
            }
            printf("\n");
            for (int j = 1; j <= cols; ++j) {
                int node = i * cols + j;
                if (node <= G->vertexNum && node + cols <= G->vertexNum) {
                    if (G->arr[node][node + cols] != 0) {
                        printf("   |    ");
                    }
                    else {
                        printf("        ");
                    }
                }
            }
            printf("\n");
        }
    }
}

// 메모리 해제 함수
void graphFree(graph* G) {
    for (int i = 1; i <= G->vertexNum; i++) {
        free(G->arr[i]);
    }
    free(G->arr);
}

// 부모 찾기 함수
int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// 합집합 함수
void unionSet(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// 간선 비교 함수
int compareEdges(const void* a, const void* b) {
    edge* e1 = (edge*)a;
    edge* e2 = (edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal 알고리즘
graph KruskalMST(graph* G) {
    int V = G->vertexNum;
    edge* edges = (edge*)malloc(V * V * sizeof(edge));
    int edgeCount = 0;

    // 그래프의 모든 간선을 배열에 저장
    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (G->arr[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dst = j;
                edges[edgeCount].weight = G->arr[i][j];
                edgeCount++;
            }
        }
    }

    // 간선을 가중치 기준으로 정렬
    qsort(edges, edgeCount, sizeof(edge), compareEdges);

    // 새로운 그래프 초기화
    graph MST;
    graphInit(&MST, V);

    int* parent = (int*)malloc((V + 1) * sizeof(int));
    int* rank = (int*)calloc((V + 1), sizeof(int));

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int e = 0;  // 현재까지 선택된 간선 수
    int i = 0;  // 정렬된 간선 배열의 인덱스

    while (e < V - 1 && i < edgeCount) {
        edge nextEdge = edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dst);

        if (x != y) {
            graphEdge(&MST, nextEdge.src, nextEdge.dst, nextEdge.weight);
            unionSet(parent, rank, x, y);
            e++;
        }
    }

    free(edges);
    free(parent);
    free(rank);

    return MST;
}

// 다익스트라 알고리즘
void dijkstra(graph* G, int start) {
    int V = G->vertexNum;
    int* dist = (int*)malloc((V + 1) * sizeof(int));
    int* parent = (int*)malloc((V + 1) * sizeof(int));
    int* visited = (int*)calloc(V + 1, sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int i = 1; i <= V; i++) {
        int minDist = INT_MAX;
        int u = -1;

        for (int j = 1; j <= V; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= V; v++) {
            if (G->arr[u][v] && !visited[v] && dist[u] + G->arr[u][v] < dist[v]) {
                dist[v] = dist[u] + G->arr[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (i != start) {
            printf("Node %d, Min Distance = %d, Path = ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }

    free(dist);
    free(parent);
    free(visited);
}

// 경로 출력 함수
void printPath(int* parent, int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("-%d", j);
}
