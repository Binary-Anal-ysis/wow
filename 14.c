#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

// Insert at end
void insertEnd(Node** head, int x) {
    Node* newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Partition list around value x
Node* partition(Node* head, int x) {
    Node *lessHead = NULL, *lessTail = NULL;
    Node *greaterHead = NULL, *greaterTail = NULL;

    Node* curr = head;

    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (curr->data < x) {
            if (lessHead == NULL) {
                lessHead = lessTail = curr;
            } else {
                lessTail->next = curr;
                lessTail = curr;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = greaterTail = curr;
            } else {
                greaterTail->next = curr;
                greaterTail = curr;
            }
        }

        curr = nextNode;
    }

    // If no nodes < x, return greater part
    if (lessHead == NULL) return greaterHead;

    // Attach greater list at end of less list
    lessTail->next = greaterHead;

    return lessHead;
}

// Display list
void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, x, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter list elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Original list: ");
    display(head);

    head = partition(head, x);

    printf("Partitioned list: ");
    display(head);

    return 0;
}

