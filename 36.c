#include <stdio.h>
#include <stdlib.h>

// -----------------------------
// Binary Tree Node
// -----------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// -----------------------------
// Create Binary Tree Recursively
// -----------------------------
struct Node* createTree() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* root = createNode(x);
    printf("Enter LEFT child of %d\n", x);
    root->left = createTree();

    printf("Enter RIGHT child of %d\n", x);
    root->right = createTree();

    return root;
}

// -----------------------------
// Count total nodes
// -----------------------------
int countTotal(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

// -----------------------------
// Count leaf nodes (terminal)
// -----------------------------
int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// -----------------------------
// Count non-terminal nodes
// -----------------------------
int countNonLeaf(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;   // leaf node

    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

// -----------------------------
int main() {
    struct Node* root = NULL;

    printf("Create the binary tree:\n");
    root = createTree();

    int total = countTotal(root);
    int leaf = countLeaf(root);
    int nonLeaf = countNonLeaf(root);

    printf("\nTotal Nodes: %d\n", total);
    printf("Terminal (Leaf) Nodes: %d\n", leaf);
    printf("Non-Terminal Nodes: %d\n", nonLeaf);

    return 0;
}
