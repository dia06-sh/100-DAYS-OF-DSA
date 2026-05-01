#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX], front = 0, rear = 0;

    // Push all 0 indegree nodes
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX], idx = 0;

    while (front < rear) {
        int node = queue[front++];
        topo[idx++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Output result
    printf("Topological Order: ");
    for (int i = 0; i < idx; i++) {
        printf("%d ", topo[i]);
    }

    return 0;
}