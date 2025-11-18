#include <stdio.h>
#include <stdlib.h>

// ---------------------- Binary Tree Node ----------------------
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// ---------------------- Stack Implementation ----------------------
struct Stack {
    int top;
    int capacity;
    struct Node** arr;
};

// Create stack
struct Stack* createStack(int capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = capacity;
    s->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return s;
}

int isEmpty(struct Stack* s) { return s->top == -1; }

void push(struct Stack* s, struct Node* node) {
    s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    return s->arr[s->top--];
}

// ---------------------- Non-Recursive Postorder ----------------------
void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;

    struct Stack *s1 = createStack(100), *s2 = createStack(100);

    push(s1, root);

    while (!isEmpty(s1)) {
        struct Node* temp = pop(s1);
        push(s2, temp);

        if (temp->left) push(s1, temp->left);
        if (temp->right) push(s1, temp->right);
    }

    printf("\nPostorder Traversal (Non-Recursive): ");
    while (!isEmpty(s2)) {
        printf("%d ", pop(s2)->data);
    }
}

// ---------------------- Main ----------------------
int main() {
    /*
            Constructed Binary Tree
                    1
                   / \
                  2   3
                 / \   \
                4   5   6
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    postorderNonRecursive(root);

    return 0;
}
