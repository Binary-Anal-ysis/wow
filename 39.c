#include <stdio.h>
#include <stdlib.h>

// -------------------------------------
// Binary Tree Node
// -------------------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// -------------------------------------
// Recursive creation of binary tree
// -------------------------------------
struct Node* createTree() {
    int x;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* root = createNode(x);

    printf("Enter LEFT child of %d:\n", x);
    root->left = createTree();

    printf("Enter RIGHT child of %d:\n", x);
    root->right = createTree();

    return root;
}

// -------------------------------------
// Stack implementation
// -------------------------------------
struct Node* stack[100];
int top = -1;

void push(struct Node* n) {
    stack[++top] = n;
}

struct Node* pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// -------------------------------------
// NON-RECURSIVE PREORDER TRAVERSAL
// -------------------------------------
void preorderNonRecursive(struct Node* root) {
    if (root == NULL)
        return;

    push(root);

    while (!isEmpty()) {
        struct Node* curr = pop();
        printf("%d ", curr->data);

        // Push right first so left is processed first
        if (curr->right != NULL)
            push(curr->right);

        if (curr->left != NULL)
            push(curr->left);
    }
}

// -------------------------------------
int main() {
    struct Node* root = NULL;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nNon-Recursive Preorder Traversal:\n");
    preorderNonRecursive(root);

    printf("\n");
    return 0;
}
