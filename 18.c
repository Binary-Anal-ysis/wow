#include <stdio.h>

#define MAX 50

int graph[MAX][MAX];   // Adjacency matrix
int visited[MAX];      // Visited array
int V;                 // Number of vertices

// ----------------------------
// DFS using recursion
// ----------------------------
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// ----------------------------
// Display adjacency matrix
// ----------------------------
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// ----------------------------
// Main function
// ----------------------------
int main() {
    int E, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize matrix and visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;   // Edge from src to dest
        graph[dest][src] = 1;   // For undirected graph
    }

    displayMatrix();

    printf("\nEnter DFS starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
