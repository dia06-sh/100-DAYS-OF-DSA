#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int preorder[MAX], inorder[MAX];
int preIndex = 0;

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder array
int search(int val, int inStart, int inEnd) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    // Pick root from preorder
    int rootVal = preorder[preIndex++];
    struct Node* root = newNode(rootVal);

    // If no children
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = search(rootVal, inStart, inEnd);

    // Build left and right subtrees
    root->left = buildTree(inStart, inIndex - 1);
    root->right = buildTree(inIndex + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(0, n - 1);

    postorder(root);

    return 0;
}