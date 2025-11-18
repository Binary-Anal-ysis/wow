#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// ===============================
// Recursive Create
// ===============================
struct Node* createList(int n) {
    if (n == 0)
        return NULL;

    int x;
    scanf("%d", &x);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = createList(n - 1);   // recursive call for next node

    return temp;
}

// ===============================
// Recursive Display
// ===============================
void display(struct Node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    display(head->next);
}

// ===============================
// Recursive Length
// ===============================
int length(struct Node* head) {
    if (head == NULL)
        return 0;
    return 1 + length(head->next);
}

// ===============================
// Recursive Reverse
// ===============================
struct Node* reverse(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    head = createList(n);

    printf("List: ");
    display(head);

    printf("Length: %d\n", length(head));

    head = reverse(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}
