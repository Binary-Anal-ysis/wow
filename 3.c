#include <stdio.h>

#define MAX 100   // total array size
#define K 3       // number of stacks

int arr[MAX];
int top[K];
int size;         // size of each stack section

// Initialize all stacks
void initStacks() {
    size = MAX / K;
    for (int i = 0; i < K; i++)
        top[i] = (i * size) - 1;
}

// Push element x into stack number sn
void push(int sn, int x) {
    int end = (sn + 1) * size - 1;

    if (top[sn] == end) {
        printf("Stack %d Overflow\n", sn);
        return;
    }

    top[sn]++;
    arr[top[sn]] = x;
    printf("Pushed %d to stack %d\n", x, sn);
}

// Pop element from stack number sn
int pop(int sn) {
    int start = sn * size;

    if (top[sn] < start) {
        printf("Stack %d Underflow\n", sn);
        return -1;
    }

    return arr[top[sn]--];
}

int main() {
    initStacks();

    // Example usage:
    push(0, 10);
    push(0, 20);
    push(1, 30);
    push(2, 50);

    printf("Pop from stack 0: %d\n", pop(0));
    printf("Pop from stack 1: %d\n", pop(1));
    printf("Pop from stack 2: %d\n", pop(2));

    return 0;
}
