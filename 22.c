#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;

// -------------------------
// Swap
// -------------------------
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// -------------------------
// Heapify (min-heap) — O(log n)
// Fixes heap property at index i
// -------------------------
void heapify(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// -------------------------
// Build Min Heap from array
// -------------------------
void buildMinHeap() {
    for (int i = heapSize/2 - 1; i >= 0; i--)
        heapify(i);
}

// -------------------------
// Insert element in heap
// -------------------------
void insert(int val) {
    int i = heapSize;
    heap[i] = val;
    heapSize++;

    // Fix upward
    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// -------------------------
// Extract minimum element
// -------------------------
int extractMin() {
    if (heapSize <= 0)
        return -1;

    int root = heap[0];
    heap[0] = heap[heapSize-1];
    heapSize--;

    heapify(0);
    return root;
}

// -------------------------
// Heap Sort (Ascending)
// -------------------------
void heapSort(int sorted[]) {
    int originalSize = heapSize;

    for (int i = 0; i < originalSize; i++) {
        sorted[i] = extractMin(); // smallest pulled out each time
    }

    heapSize = originalSize;  // restore if needed (not required here)
}

// -------------------------
// Display heap array
// -------------------------
void displayHeap() {
    printf("Heap: ");
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// -------------------------
// Main
// -------------------------
int main() {
    int n, val, sorted[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }

    printf("\nMin Heap created:\n");
    displayHeap();

    printf("\nExtracting Min: %d\n", extractMin());
    displayHeap();

    heapSort(sorted);

    printf("\nHeap Sort (Ascending): ");
    for (int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    return 0;
}
