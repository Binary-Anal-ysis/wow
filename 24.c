#include <stdio.h>

#define MAX 100

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ==========================
//  Max-Heapify Procedure
// ==========================
void heapify(int arr[], int n, int i) {
    int largest = i;          // Assume current node is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child exists and is greater than current largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root node, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// ==========================
// Extract Maximum Element
// ==========================
int extractMax(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = arr[0];  // The maximum element (root of max heap)
    arr[0] = arr[*n - 1];  // Move last element to root
    (*n)--;

    heapify(arr, *n, 0);  // Restore heap property

    return max;
}

// ==========================
// Build Max Heap
// ==========================
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify downward
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// ==========================
// Heap Sort
// ==========================
void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // Move current max to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// ==========================
// Utility: Print array
// ==========================
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ==========================
// Main Function
// ==========================
int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Build max heap
    buildMaxHeap(arr, n);
    printf("\nMax Heap: ");
    printArray(arr, n);

    // Extract max element
    int max = extractMax(arr, &n);
    printf("Extracted Max: %d\n", max);

    printf("Heap after extractMax: ");
    printArray(arr, n);

    // Heap sort
    printf("\nPerforming Heap Sort...\n");
    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
