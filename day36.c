#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *q = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int count = n;

    // dequeue m times
    for (int i = 0; i < m; i++) {
        if (count > 0) {
            front = (front + 1) % n;
            count--;
        }
    }

    // print remaining circular queue
    for (int i = 0; i < count; i++) {
        printf("%d ", q[(front + i) % n]);
    }

    free(q);
    return 0;
}