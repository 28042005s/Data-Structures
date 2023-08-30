#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;
typedef struct {
    int vertices;
    int** adjacencyList;
} Graph;
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}
int dequeue(Queue* queue) {
    int item;
    if (queue->front == -1) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = V;
    
    graph->adjacencyList = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        graph->adjacencyList[i] = NULL;
    }
    
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->vertices || dest >= graph->vertices) {
        printf("Invalid vertex\n");
        return;
    }
        if (graph->adjacencyList[src] == NULL) {
        graph->adjacencyList[src] = (int*)malloc(sizeof(int));
        graph->adjacencyList[src][0] = dest;
    } else {
        int i;
        for (i = 0; graph->adjacencyList[src][i] != -1; i++);
        graph->adjacencyList[src] = (int*)realloc(graph->adjacencyList[src], (i + 2) * sizeof(int));
        graph->adjacencyList[src][i] = dest;
        graph->adjacencyList[src][i + 1] = -1;
    }
}
void bfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue* queue = createQueue();

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != -1) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; graph->adjacencyList[currentVertex][i] != -1; i++) {
            int adjacentVertex = graph->adjacencyList[currentVertex][i];
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
        }
    }

    free(queue);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Graph* graph = createGraph(V);

    printf("Enter edges:\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth First Traversal (starting from vertex %d): ", startVertex);
    bfs(graph, startVertex);

    return 0;
}
