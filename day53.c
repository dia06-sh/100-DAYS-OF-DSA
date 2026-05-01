#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Simple queue
struct QNode queue[MAX];
int front = 0, rear = 0;

void push(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[MAX][MAX] = {0};
    int size[MAX] = {0};
    int minHD = MAX, maxHD = MAX;

    push(root, MAX);

    while (!isEmpty()) {
        struct QNode temp = pop();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd][size[hd]++] = curr->data;

        if (curr->left) push(curr->left, hd - 1);
        if (curr->right) push(curr->right, hd + 1);

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
    }

    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}