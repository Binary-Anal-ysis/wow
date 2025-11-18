#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------------------------
// Adjacency List Node
// ---------------------------
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Array of adjacency lists
Node* adj[MAX];

// Visited array
int visited[MAX];
int V;

// ---------------------------
// Create new node
// ---------------------------
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// ---------------------------
// Add edge (undirected graph)
// ---------------------------
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

// ---------------------------
// DFS Traversal
// ---------------------------
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

// ---------------------------
// Display adjacency list
// ---------------------------
void displayGraph() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ---------------------------
// Main
// ---------------------------
int main() {
    int E, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize adjacency lists & visited
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    displayGraph();

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
