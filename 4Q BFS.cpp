#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}
int dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return value;
}
bool isEmpty() {
    return front == -1;
}
int graph[MAX_SIZE][MAX_SIZE];
int vertices, edges;
void bfs(int start) {
    bool visited[MAX_SIZE] = {false};
    printf("Breadth First Search starting from node %d:\n", start);
    enqueue(start);
    visited[start] = true;
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 1; i <= vertices; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}
int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);
    printf("Enter edge connections (vertex1 vertex2):\n");
    for (int i = 0; i < edges; ++i) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;
    }
    int startVertex;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    bfs(startVertex);
    return 0;
}
