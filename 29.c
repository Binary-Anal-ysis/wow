#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// ====================================
// 1. CREATE (insert at end)
// ====================================
void create(struct Node** head, int x) {
    struct Node* newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// ====================================
// 2. DISPLAY
// ====================================
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ====================================
// 3. INSERT (insert at end)
// ====================================
void insertEnd(struct Node** head, int x) {
    create(head, x);  // same operation
}

// ====================================
// 4. DELETE by value
// ====================================
void deleteValue(struct Node** head, int x) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;

    // If head needs to be deleted
    if (temp->data == x) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL)
        return; // not found

    // Adjust pointers
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// ====================================
// MAIN
// ====================================
int main() {
    struct Node* head = NULL;
    int n, x, choice;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        create(&head, x);
    }

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display\n2. Insert (end)\n3. Delete (value)\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            display(head);
        }
        else if (choice == 2) {
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insertEnd(&head, x);
        }
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            deleteValue(&head, x);
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
