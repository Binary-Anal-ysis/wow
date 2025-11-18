#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create node
Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->prev = n->next = NULL;
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
    newNode->prev = temp;
}

// Insert AFTER a given position (1-based indexing)
void insertAfterPos(Node** head, int pos, int x) {
    if (*head == NULL) {
        printf("List empty.\n");
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    Node* newNode = createNode(x);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Sort using simple bubble sort (swapping data only)
void sortList(Node** head) {
    if (*head == NULL) return;

    int swapped;
    Node* ptr;
    Node* last = NULL;

    do {
        swapped = 0;
        ptr = *head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

// Display list
void display(Node* head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, x, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert after position\n");
        printf("3. Sort list\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(&head, x);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &x);
                insertAfterPos(&head, pos, x);
                break;

            case 3:
                sortList(&head);
                printf("List sorted.\n");
                break;

            case 4:
                display(head);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
