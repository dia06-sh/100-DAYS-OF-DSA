#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

void BFS(int n, int adj[MAX][MAX], int start) {
    int queue[MAX], front = 0, rear = 0;

    // initialize visited
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    // start BFS
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}