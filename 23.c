#include <stdio.h>
#include <stdlib.h>

// ---------------------------
// Linked list node
// ---------------------------
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Insert at end (simple creation)
Node* insertEnd(Node* head, int data) {
    Node* n = newNode(data);
    if (!head) return n;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

// ---------------------------
// Length of LL
// ---------------------------
int length(Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

// ---------------------------
// Add same-size lists
// Returns carry
// ---------------------------
int addSame(Node* l1, Node* l2, Node** result) {
    if (!l1) return 0;

    int carry = addSame(l1->next, l2->next, result);

    int sum = l1->data + l2->data + carry;

    Node* n = newNode(sum % 10);
    n->next = *result;
    *result = n;

    return sum / 10;
}

// ---------------------------
// Add carry to remaining leading nodes
// ---------------------------
int addCarryToRemaining(Node* head, Node* cur, int carry, Node** result) {
    if (head == cur) return carry;

    carry = addCarryToRemaining(head->next, cur, carry, result);

    int sum = head->data + carry;

    Node* n = newNode(sum % 10);
    n->next = *result;
    *result = n;

    return sum / 10;
}

// ---------------------------
// Add two numbers (MAIN FUNCTION)
// ---------------------------
Node* addLists(Node* l1, Node* l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    // Ensure l1 is longer
    if (len2 > len1) {
        Node* temp = l1;
        l1 = l2;
        l2 = temp;

        int t = len1;
        len1 = len2;
        len2 = t;
    }

    int diff = len1 - len2;

    Node *cur1 = l1;
    Node *cur2 = l2;

    while (diff--) cur1 = cur1->next;

    Node* result = NULL;

    // Add equal-length tail parts
    int carry = addSame(cur1, cur2, &result);

    // Add remaining leading nodes
    carry = addCarryToRemaining(l1, cur1, carry, &result);

    // If carry remains, add new node
    if (carry) {
        Node* n = newNode(carry);
        n->next = result;
        result = n;
    }

    return result;
}

// ---------------------------
// Print linked list
// ---------------------------
void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ---------------------------
// Main
// ---------------------------
int main() {
    Node *l1 = NULL, *l2 = NULL;

    // Example
    // operand_1: 7 → 2 → 3 → 3
    // operand_2: 5 → 7 → 4

    l1 = insertEnd(l1, 7);
    l1 = insertEnd(l1, 2);
    l1 = insertEnd(l1, 3);
    l1 = insertEnd(l1, 3);

    l2 = insertEnd(l2, 5);
    l2 = insertEnd(l2, 7);
    l2 = insertEnd(l2, 4);

    printf("Operand 1: "); printList(l1);
    printf("Operand 2: "); printList(l2);

    Node* result = addLists(l1, l2);

    printf("Result:    "); 
    printList(result);

    return 0;
}
