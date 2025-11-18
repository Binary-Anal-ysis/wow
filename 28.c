#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

// Insert in sorted (ascending) order
void insertSorted(struct Node** head, int x) {
    struct Node* newNode = createNode(x);

    if (*head == NULL || x < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data <= x)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Print list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ===================================
// Merge two sorted lists
// ===================================
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

// ===================================
// Check if two lists are equal
// ===================================
int isEqual(struct Node* a, struct Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }

    return (a == NULL && b == NULL);
}

// ===================================
// Make a deep copy of a list
// ===================================
struct Node* copyList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* newHead = createNode(head->data);
    newHead->next = copyList(head->next);
    return newHead;
}

// ===================================
// Main
// ===================================
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2, x;

    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n1);
    printf("Enter %d numbers (auto-inserted in ascending order):\n", n1);

    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        insertSorted(&list1, x);
    }

    printf("Enter number of nodes for List 2: ");
    scanf("%d", &n2);
    printf("Enter %d numbers (auto-inserted in ascending order):\n", n2);

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        insertSorted(&list2, x);
    }

    printf("\nList 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Merge
    struct Node* merged = merge(list1, list2);
    printf("\nMerged List: ");
    display(merged);

    // Check equality
    if (isEqual(list1, list2))
        printf("\nLists are Equal\n");
    else
        printf("\nLists are NOT Equal\n");

    // Copy list
    struct Node* copied = copyList(list1);
    printf("Copy of List 1: ");
    display(copied);

    return 0;
}
