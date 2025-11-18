#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------
// Definition of BST node
// ------------------------------------------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ------------------------------------------------------------
// Create a new node
// ------------------------------------------------------------
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// ------------------------------------------------------------
// Insert a value in BST
// ------------------------------------------------------------
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// ------------------------------------------------------------
// Reverse Inorder Traversal → Descending Order
// Right → Root → Left
// ------------------------------------------------------------
void printDescending(struct Node* root) {
    if (root == NULL)
        return;

    printDescending(root->right);
    printf("%d ", root->data);
    printDescending(root->left);
}

// ------------------------------------------------------------
int main() {
    struct Node* root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("\nBST in Descending Order:\n");
    printDescending(root);

    printf("\n");
    return 0;
}
