#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a node
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

// Concatenate list2 at end of list1
void concatenate(Node** list1, Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    if (list2 == NULL) return;

    Node* temp = *list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    list2->prev = temp;
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
    Node *list1 = NULL, *list2 = NULL;
    int choice, x;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert end (List 1)\n");
        printf("2. Insert end (List 2)\n");
        printf("3. Concatenate List2 → List1\n");
        printf("4. Display List 1\n");
        printf("5. Display List 2\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(&list1, x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(&list2, x);
                break;

            case 3:
                concatenate(&list1, list2);
                list2 = NULL;  // optional, since list2 is merged
                printf("Lists concatenated.\n");
                break;

            case 4:
                printf("List 1: ");
                display(list1);
                break;

            case 5:
                printf("List 2: ");
                display(list2);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
