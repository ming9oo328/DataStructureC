#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// �׷��� ����ü ����
typedef struct graph {
    int vertexNum;
    int** arr;
} graph;

// ���� ����ü ����
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

    // ���� ����
    graphEdge(&G, 1, 2, 3); graphEdge(&G, 2, 3, 1);
    graphEdge(&G, 3, 4, 4); graphEdge(&G, 5, 6, 1);
    graphEdge(&G, 6, 7, 5); graphEdge(&G, 7, 8, 8);
    graphEdge(&G, 9, 10, 2); graphEdge(&G, 10, 11, 4);
    graphEdge(&G, 11, 12, 6); graphEdge(&G, 13, 14, 3);
    graphEdge(&G, 14, 15, 5); graphEdge(&G, 15, 16, 7);

    // ���� ����
    graphEdge(&G, 1, 5, 2); graphEdge(&G, 2, 6, 5);
    graphEdge(&G, 3, 7, 1); graphEdge(&G, 4, 8, 6);
    graphEdge(&G, 5, 9, 3); graphEdge(&G, 6, 10, 4);
    graphEdge(&G, 7, 11, 2); graphEdge(&G, 8, 12, 6);
    graphEdge(&G, 9, 13, 2); graphEdge(&G, 10, 14, 6);
    graphEdge(&G, 11, 15, 4); graphEdge(&G, 12, 16, 4);

    printf("�⺻ �׷���:\n\n");
    graphShow(&G);

    printf("\n\n\nMST:\n\n");
    MST = KruskalMST(&G);
    graphShow(&MST);

    printf("\n\n\n��� 1�κ��� ��� �������� �ִ� ���:\n\n");
    dijkstra(&G, 1);

    graphFree(&G);
    return 0;
}

// �׷��� �ʱ�ȭ
void graphInit(graph* G, int cnt) {
    int i;
    G->vertexNum = cnt;
    G->arr = (int**)malloc(sizeof(int*) * (cnt + 1));

    for (i = 1; i <= cnt; i++) {
        G->arr[i] = (int*)calloc(cnt + 1, sizeof(int));
    }
}

// ����ġ�� �ִ� ������ �׷��� ���� �߰�
void graphEdge(graph* G, int src, int dst, int weight) {
    G->arr[src][dst] = weight;
    G->arr[dst][src] = weight;
}

// �׷��� ���
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

// �޸� ���� �Լ�
void graphFree(graph* G) {
    for (int i = 1; i <= G->vertexNum; i++) {
        free(G->arr[i]);
    }
    free(G->arr);
}

// �θ� ã�� �Լ�
int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// ������ �Լ�
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

// ���� �� �Լ�
int compareEdges(const void* a, const void* b) {
    edge* e1 = (edge*)a;
    edge* e2 = (edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal �˰���
graph KruskalMST(graph* G) {
    int V = G->vertexNum;
    edge* edges = (edge*)malloc(V * V * sizeof(edge));
    int edgeCount = 0;

    // �׷����� ��� ������ �迭�� ����
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

    // ������ ����ġ �������� ����
    qsort(edges, edgeCount, sizeof(edge), compareEdges);

    // ���ο� �׷��� �ʱ�ȭ
    graph MST;
    graphInit(&MST, V);

    int* parent = (int*)malloc((V + 1) * sizeof(int));
    int* rank = (int*)calloc((V + 1), sizeof(int));

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int e = 0;  // ������� ���õ� ���� ��
    int i = 0;  // ���ĵ� ���� �迭�� �ε���

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

// ���ͽ�Ʈ�� �˰���
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

// ��� ��� �Լ�
void printPath(int* parent, int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("-%d", j);
}
