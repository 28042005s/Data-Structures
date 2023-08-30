#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 10

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    int distance[MAX_NODES];
    bool visited[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[startNode] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int minDistance = INT_MAX, u;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Node   Distance from Source\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(graph, numNodes, startNode);

    return 0;
}
