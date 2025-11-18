#include <stdio.h>

#define MAX 5   // size of circular queue

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)      // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("Enqueued %d\n", x);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return value;
}

int getFront() {
    if (isEmpty()) return -1;
    return queue[front];
}

int getRear() {
    if (isEmpty()) return -1;
    return queue[rear];
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // queue full

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    enqueue(60);
    enqueue(70);

    printf("Front element: %d\n", getFront());
    printf("Rear element : %d\n", getRear());

    return 0;
}
