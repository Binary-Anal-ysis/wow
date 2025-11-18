#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Push element (insert at head)
void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

// Pop element (remove head)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Peek top element
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, x;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &x);
            push(&top, x);
        }
        else if (choice == 2) {
            int popped = pop(&top);
            if (popped != -1)
                printf("Popped: %d\n", popped);
        }
        else if (choice == 3) {
            int t = peek(top);
            if (t != -1)
                printf("Top element: %d\n", t);
        }
        else if (choice == 4) {
            display(top);
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
