#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1;
int n;

// Enqueue operation
void enqueue(int value) {
    if (rear == n - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    scanf("%d", &n);

    // dynamic memory allocation
    queue = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    free(queue);
    return 0;
}