#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level order
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n && !isEmpty()) {
        struct Node* curr = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;

    int leftToRight = 1;

    while (f < r) {
        int size = r - f;
        int temp[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];
            temp[i] = node->data;

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}