#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------
// Definition of a node in the Binary Tree
// ------------------------------------------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ------------------------------------------------------------
// Create new node
// ------------------------------------------------------------
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// ------------------------------------------------------------
// Recursive Binary Tree Creation
// User enters -1 when a child does not exist.
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// Queue Implementation for Level Order Traversal
// ------------------------------------------------------------
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* x) {
    if (rear == 99) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

// ------------------------------------------------------------
// Level Order Traversal (Breadth-First Search)
// ------------------------------------------------------------
void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Enqueue root
    enqueue(root);

    printf("\nLevel Order Traversal: ");

    while (!isEmpty()) {
        struct Node* cur = dequeue();

        printf("%d ", cur->data);

        if (cur->left)
            enqueue(cur->left);

        if (cur->right)
            enqueue(cur->right);
    }
}

// ------------------------------------------------------------
int main() {
    struct Node* root = NULL;

    printf("\n--- Create Binary Tree ---\n");
    root = createTree();

    printf("\n--- Level by Level Traversal ---\n");
    levelOrder(root);

    printf("\n\n");
    return 0;
}
