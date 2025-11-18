#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum BFS queue size

// ----------------------------
// Node for adjacency list
// ----------------------------
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// ----------------------------
// Graph structure
// ----------------------------
typedef struct Graph {
    int V;             // Number of vertices
    Node** adjList;    // Array of adjacency lists
} Graph;

// ----------------------------
// Queue for BFS
// ----------------------------
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// ----------------------------
// Queue functions
// ----------------------------
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is Full!\n");
        return;
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset queue after last removal
            q->front = q->rear = -1;
        }
        return item;
    }
}

// ----------------------------
// Create a graph
// ----------------------------
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjList = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// ----------------------------
// Add edge (undirected graph)
// ----------------------------
void addEdge(Graph* graph, int src, int dest) {
    // Add dest → src
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add src → dest
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// ----------------------------
// BFS Traversal
// ----------------------------
void BFS(Graph* graph, int startVertex) {
    int visited[graph->V];

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal starting from %d: ", startVertex);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        Node* temp = graph->adjList[current];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }

            temp = temp->next;
        }
    }
    printf("\n");
}

// ----------------------------
// Display adjacency list
// ----------------------------
void printGraph(Graph* graph) {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        printf("%d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// ----------------------------
// Main function
// ----------------------------
int main() {
    int V, E, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    printf("\nEnter BFS start vertex: ");
    scanf("%d", &start);

    BFS(graph, start);

    return 0;
}
