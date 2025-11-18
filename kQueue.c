#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Global variables for the kQueues structure
int *arr;    // Array to store actual content of the queues
int *front;  // Array to store front indexes of each queue
int *rear;   // Array to store rear indexes of each queue
int *next;   // Array to store next free index for each position

int n, k;    // Number of queues and size of the array
int freeIndex;    // To store the beginning index of the free list

// Function to create k queues in a single array of size n
void createQueues(int k1, int n1) {
    int i;
    k = k1;
    n = n1;

    // Dynamically allocate memory for arrays
    arr = (int*)malloc(n * sizeof(int));
    front = (int*)malloc(k * sizeof(int));
    rear = (int*)malloc(k * sizeof(int));
    next = (int*)malloc(n * sizeof(int));

    // Initialize all queues as empty
    for (i = 0; i < k; i++) {
        front[i] = -1;
    }

    // Initialize all spaces as free
    freeIndex = 0;
    for (i = 0; i < n - 1; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = -1; // -1 indicates the end of free list
}

// Utility function to check if the queues are full
bool isFull() {
    return (freeIndex == -1);
}

// Function to enqueue an item in the specified queue number (qn)
void enqueue(int item, int qn) {
    if (isFull()) {
        printf("\nQueue Overflow\n");
        return;
    }

    // Get the index of the first free slot
    int i = freeIndex;
    freeIndex = next[i]; // Update the free list

    if (front[qn] == -1) {
        front[qn] = i; // If the queue is empty, set the front
    } else {
        next[rear[qn]] = i; // Otherwise, link the previous rear to the new index
    }

    next[i] = -1; // This index will be the new rear, so next should be -1
    rear[qn] = i; // Update the rear of the queue

    arr[i] = item; // Store the item in the array
}

// Function to dequeue an item from the specified queue number (qn)
int dequeue(int qn) {
    if (front[qn] == -1) {
        printf("\nQueue Underflow\n");
        return INT_MAX;
    }

    // Get the index of the front item of the queue
    int i = front[qn];

    // Move the front to the next item in the queue
    front[qn] = next[i];

    // Link the dequeued index back to the free list
    next[i] = freeIndex;
    freeIndex = i;

    return arr[i]; // Return the dequeued item
}

// Driver program to test the kQueues functionality
int main() {
    int k = 3, n = 10;

    // Create the kQueues structure
    createQueues(k, n);

    // Enqueue items into different queues
    enqueue(15, 2);
    enqueue(45, 2);

    enqueue(17, 1);
    enqueue(49, 1);
    enqueue(39, 1);

    enqueue(11, 0);
    enqueue(9, 0);
    enqueue(7, 0);

    // Dequeue and print items from the queues
    printf("Dequeued element from queue 2 is %d\n", dequeue(2));
    printf("Dequeued element from queue 1 is %d\n", dequeue(1));
    printf("Dequeued element from queue 0 is %d\n", dequeue(0));

    // Free dynamically allocated memory
    free(arr);
    free(front);
    free(rear);
    free(next);

    return 0;
}
