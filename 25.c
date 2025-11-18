#include <stdio.h>
#include <stdlib.h>

// ============================
// Linked List Node Structure
// ============================
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Insert at end of linked list
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

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ============================
// Rotate Linked List by k
// ============================
struct Node* rotateByK(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length of list
    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Connect last node to head (make circular list temporarily)
    temp->next = head;

    // Normalize k: k > length
    k = k % length;

    // New tail will be (length - k)th node
    int skip = length - k;
    struct Node* newTail = head;

    for (int i = 1; i < skip; i++)
        newTail = newTail->next;

    // New head is next of newTail
    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// ============================
// Main Function
// ============================
int main() {
    struct Node* head = NULL;
    int n, k, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter k (rotation amount): ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    head = rotateByK(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}
