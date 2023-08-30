#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskal(struct Edge edges[], int V, int E) {
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge));

    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compare);

    int i = 0, j = 0;
    while (j < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[j++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < j; i++) {
        printf("%d -- %d Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
    free(result);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    printf("Enter the source, destination, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);

    free(edges);
    return 0;
}
