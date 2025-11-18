#include <stdio.h>

#define MAX 100   // total array size
#define K   3     // number of queues

int arr[MAX];      // actual storage
int next[MAX];     // next index links
int front[K];      // front index of each queue
int rear[K];       // rear index of each queue
int freeSpot;      // beginning of free list

// Initialize k queues
void init() {
    for (int i = 0; i < K; i++) {
        front[i] = -1;
        rear[i] = -1;
    }

    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;
    next[MAX - 1] = -1;     // end of free list

    freeSpot = 0;
}

// Enqueue x into queue number qn
void enqueue(int x, int qn) {
    if (freeSpot == -1) {
        printf("Queue Overflow\n");
        return;
    }

    int index = freeSpot;          // take free spot
    freeSpot = next[index];        // update free list

    if (front[qn] == -1)           // first element
        front[qn] = index;
    else
        next[rear[qn]] = index;    // link previous rear → new

    next[index] = -1;
    rear[qn] = index;
    arr[index] = x;

    printf("Enqueued %d to queue %d\n", x, qn);
}

// Dequeue from queue qn
int dequeue(int qn) {
    if (front[qn] == -1) {
        printf("Queue %d Underflow\n", qn);
        return -1;
    }

    int index = front[qn];
    front[qn] = next[index];       // move front pointer

    next[index] = freeSpot;        // add freed index to free list
    freeSpot = index;

    return arr[index];
}

// Display one queue q
void displayq(int q) {
    if (front[q] == -1) {
        printf("Queue %d is empty\n", q);
        return;
    }

    int i = front[q];
    printf("Queue %d: ", q);
    while (i != -1) {
        printf("%d ", arr[i]);
        i = next[i];
    }
    printf("\n");
}

// Display all queues
void displayAll() {
    for (int q = 0; q < K; q++)
        displayq(q);
}

int main() {
    init();

    enqueue(10, 0);
    enqueue(20, 0);
    enqueue(30, 1);
    enqueue(40, 2);
    enqueue(50, 1);

    printf("Dequeued from queue 1: %d\n", dequeue(1));
    printf("Dequeued from queue 0: %d\n", dequeue(0));

    printf("\nDisplaying Queue 0, 1, 2:\n");
    displayAll();

    return 0;
}
