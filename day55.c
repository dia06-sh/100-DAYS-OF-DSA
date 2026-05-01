#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct Node* queue[1000];
int front = 0, rear = 0;

void push(struct Node* node) {
    queue[rear++] = node;
}

struct Node* pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Right view function
void rightView(struct Node* root) {
    if (!root) return;

    push(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = pop();

            // last node of level → right view
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) push(curr->left);
            if (curr->right) push(curr->right);
        }
    }
}