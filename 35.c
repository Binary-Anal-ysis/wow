#include <stdio.h>
#include <stdlib.h>

// -------------------------------
// Binary Tree Structure
// -------------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// -------------------------------
// Check if two trees are identical
// -------------------------------
int isEqual(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    
    return (a->data == b->data) &&
           isEqual(a->left, b->left) &&
           isEqual(a->right, b->right);
}

// -------------------------------
// Mirror a tree (swap left & right recursively)
// -------------------------------
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// -------------------------------
// Inorder Display (to verify mirror)
// -------------------------------
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// -------------------------------
int main() {

    // ------------------------------------
    // Hard-coded Tree 1
    //        1
    //      /   \
    //     2     3
    // ------------------------------------
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    // ------------------------------------
    // Hard-coded Tree 2
    //        1
    //      /   \
    //     2     3
    // ------------------------------------
    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    // 1. Check equality
    if (isEqual(root1, root2))
        printf("Trees are EQUAL.\n");
    else
        printf("Trees are NOT equal.\n");

    // 2. Mirror image of Tree 1
    printf("\nInorder of Tree 1 before mirroring: ");
    inorder(root1);

    mirror(root1);

    printf("\nInorder of Tree 1 after mirroring:  ");
    inorder(root1);

    printf("\n");

    return 0;
}
