#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ===========================================
// Swap nodes in pairs (1 with 2, 3 with 4...)
// ===========================================
struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* newHead = head->next;  // after swap, 2nd node becomes head

    while (curr != NULL && curr->next != NULL) {
        struct Node* nextPair = curr->next->next;
        struct Node* second = curr->next;

        // Perform swap
        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}

// Main
int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    printf("Original List: ");
    printList(head);

    head = swapPairs(head);

    printf("After Swapping in Pairs: ");
    printList(head);

    return 0;
}
