#include <stdio.h>

#define MAX 100

int inorder[MAX], postorder[MAX];
int postIndex;

struct Node {
    int data;
    struct Node *left, *right;
};

// Simple tree creation using static memory (for simplicity in exams)
struct Node nodes[MAX];
int nodeCount = 0;

struct Node* newNode(int val) {
    struct Node* node = &nodes[nodeCount++];
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// find index in inorder
int search(int val, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inStart, int inEnd) {
    if(inStart > inEnd) return NULL;

    int rootVal = postorder[postIndex--];
    struct Node* root = newNode(rootVal);

    if(inStart == inEnd) return root;

    int inIndex = search(rootVal, inStart, inEnd);

    // IMPORTANT: right first
    root->right = buildTree(inIndex + 1, inEnd);
    root->left  = buildTree(inStart, inIndex - 1);

    return root;
}

// preorder print
void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(0, n - 1);

    preorder(root);

    return 0;
}