#include <stdio.h>
#define MAX 20
#define INF 9999

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX], mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nEdges in MST (Prim's):\n");
    int total = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total Cost = %d\n", total);
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);
    return 0;
}

