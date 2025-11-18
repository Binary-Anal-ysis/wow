#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// --------------------------------------------------------
// Create a new node
// --------------------------------------------------------
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --------------------------------------------------------
// Recursive creation of Binary Tree
// User enters -1 when a node does not exist
// --------------------------------------------------------
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

// --------------------------------------------------------
// Inorder Traversal (Left, Root, Right)
// --------------------------------------------------------
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// --------------------------------------------------------
// Height of a Binary Tree
// Height = 1 + max(height(left), height(right))
// --------------------------------------------------------
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

// --------------------------------------------------------
int main() {
    struct Node* root = NULL;

    printf("\n--- Create Binary Tree ---\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\n\nHeight of the Tree = %d\n", height(root));

    return 0;
}
