#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

bool dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true;  // cycle detected
            }
        }
    }
    return false;
}

bool isCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    if (isCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}