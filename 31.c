#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Enqueue (insert at rear)
void enqueue(struct Node** front, struct Node** rear, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*rear == NULL) {  // empty queue
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

// Dequeue (remove from front)
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {  // empty
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = *front;
    int val = temp->data;

    *front = (*front)->next;

    if (*front == NULL)  // queue becomes empty
        *rear = NULL;

    free(temp);
    return val;
}

// Display full queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Front element
int frontElement(struct Node* front) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    return front->data;
}

// Rear element
int rearElement(struct Node* rear) {
    if (rear == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    return rear->data;
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int choice, x;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Front\n5. Rear\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &x);
            enqueue(&front, &rear, x);
        }
        else if (choice == 2) {
            int val = dequeue(&front, &rear);
            if (val != -1)
                printf("Dequeued: %d\n", val);
        }
        else if (choice == 3) {
            display(front);
        }
        else if (choice == 4) {
            int f = frontElement(front);
            if (f != -1)
                printf("Front: %d\n", f);
        }
        else if (choice == 5) {
            int r = rearElement(rear);
            if (r != -1)
                printf("Rear: %d\n", r);
        }
        else if (choice == 6) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
