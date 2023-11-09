#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure for BFS traversal
struct Queue {
    int arr[MAX_VERTICES];
    int front, rear;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjList;
    bool* visited;
};

// Function prototypes
struct Node* createNode(int data);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void BFS(struct Graph* graph, int startVertex);
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
bool isEmpty(struct Queue* queue);

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;

    // Allocate memory for adjacency list and visited array
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));
    if (graph->adjList == NULL || graph->visited == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize adjacency list and visited array
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isEmpty(&queue)) {
        // Dequeue a vertex and print it
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        // Traverse adjacent vertices
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!graph->visited[adjacentVertex]) {
                // Mark the adjacent vertex as visited and enqueue it
                graph->visited[adjacentVertex] = true;
                enqueue(&queue, adjacentVertex);
            }
            temp = temp->next;
        }
    }
}

// Function to enqueue a value into the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue overflow. Cannot enqueue into a full queue.\n");
        exit(EXIT_FAILURE);
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
}

// Function to dequeue a value from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }
    int dequeuedValue = queue->arr[queue->front++];
    if (queue->front > queue->rear) {
        // Reset front and rear if the queue becomes empty
        queue->front = -1;
        queue->rear = -1;
    }
    return dequeuedValue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Main function to demonstrate BFS traversal
int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (format: src dest):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal starting from vertex %d: ", startVertex);
    BFS(graph, startVertex);
    printf("\n");

    return 0;
}
