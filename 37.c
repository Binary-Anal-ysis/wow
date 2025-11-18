#include <stdio.h>
#include <stdlib.h>

// -----------------------------------
// Binary Tree Node
// -----------------------------------
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// -----------------------------------
// Create Binary Tree Recursively
// -----------------------------------
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

// -----------------------------------
// Stack implementation (array-based)
// -----------------------------------
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

// -----------------------------------
// NON-RECURSIVE INORDER TRAVERSAL
// -----------------------------------
void inorderNonRecursive(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL || !isEmpty()) {

        // Move to leftmost node
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        // Visit node
        curr = pop();
        printf("%d ", curr->data);

        // Explore right subtree
        curr = curr->right;
    }
}

// -----------------------------------
int main() {
    struct Node* root = NULL;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nNon-Recursive Inorder Traversal:\n");
    inorderNonRecursive(root);

    printf("\n");
    return 0;
}
