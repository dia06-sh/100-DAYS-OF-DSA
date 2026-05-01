#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
int dequeue() {
    if (front == NULL) {
        return -1; // Queue empty
    }

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return val;
}

// Main
int main() {
    int n, x;
    char op;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &op);

        if (op == 'E') {
            scanf("%d", &x);
            enqueue(x);
        } else if (op == 'D') {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}