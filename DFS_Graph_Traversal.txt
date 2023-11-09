#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure for DFS traversal
struct Stack {
    int arr[MAX_VERTICES];
    int top;
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
void DFS(struct Graph* graph, int startVertex);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
bool isEmpty(struct Stack* stack);

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

// Function to perform Depth-First Search traversal of the graph
void DFS(struct Graph* graph, int startVertex) {
    struct Stack stack;
    stack.top = -1;

    // Mark the start vertex as visited and push it onto the stack
    graph->visited[startVertex] = true;
    push(&stack, startVertex);

    while (!isEmpty(&stack)) {
        // Pop a vertex from the stack and print it
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        // Traverse adjacent vertices
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!graph->visited[adjacentVertex]) {
                // Mark the adjacent vertex as visited and push it onto the stack
                graph->visited[adjacentVertex] = true;
                push(&stack, adjacentVertex);
            }
            temp = temp->next;
        }
    }
}

// Function to push a value onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_VERTICES - 1) {
        printf("Stack overflow. Cannot push onto a full stack.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop a value from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Main function to demonstrate DFS traversal
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
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex);
    printf("\n");

    return 0;
}
