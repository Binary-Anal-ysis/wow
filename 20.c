#include <stdio.h>

#define SIZE 20      // hash table size
#define EMPTY -1     // empty slot indicator

int hashTable[SIZE];

// ---------------------------
// Hash function
// ---------------------------
int hash(int key) {
    return key % SIZE;
}

// ---------------------------
// Insert using linear probing
// ---------------------------
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int try = (index + i) % SIZE;

        if (hashTable[try] == EMPTY) {
            hashTable[try] = key;
            printf("Inserted %d at index %d\n", key, try);
            return;
        }
    }

    printf("Hash Table is full. Cannot insert %d\n", key);
}

// ---------------------------
// Search using linear probing
// ---------------------------
int search(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int try = (index + i) % SIZE;

        if (hashTable[try] == key)
            return try;

        if (hashTable[try] == EMPTY)
            return -1; // key not found
    }
    return -1;
}

// ---------------------------
// Display function
// ---------------------------
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("%d : -\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

// ---------------------------
// Main
// ---------------------------
int main() {
    int choice, key;

    // initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
        }
        else if (choice == 2) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            int pos = search(key);
            if (pos != -1)
                printf("Key %d found at index %d\n", key, pos);
            else
                printf("Key %d NOT found\n", key);
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
