#include <stdio.h>
#include <stdlib.h>

// --------------------------------------------
// Binary Tree Node
// --------------------------------------------
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

// --------------------------------------------
// Search index of value in inorder[]
// --------------------------------------------
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// --------------------------------------------
// Build tree from preorder + inorder
// --------------------------------------------
// preorder[] gives root first → use static index
// Build left subtree → build right subtree
// --------------------------------------------
struct Node* buildTree(int inorder[], int preorder[],
                       int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// --------------------------------------------
// Postorder Traversal (Recursive)
// --------------------------------------------
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// --------------------------------------------
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    printf("\n");
    return 0;
}

