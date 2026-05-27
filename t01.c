
#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX], count = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }

    while(front <= rear) {
        int v = queue[front++];
        topo[count++] = v;

        for(i = 0; i < n; i++) {
            if(adj[v][i] == 1) {
                indegree[i]--;

                if(indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if(count != n) {
        printf("Topological ordering is not possible (Graph contains a cycle).\n");
    } else {
        printf("Topological Order: ");
        for(i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}
