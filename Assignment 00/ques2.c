#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
} Edge;

int find(int u, int *parent) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u], parent);
}

void union_sets(int u, int v, int *parent, int *rank) {
    u = find(u, parent);
    v = find(v, parent);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    Edge *edges = malloc(b * sizeof(Edge));
    int *parent = malloc((a + 1) * sizeof(int));
    int *rank = malloc((a + 1) * sizeof(int));

    for (int i = 1; i <= a; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < b; ++i) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    int drivers_needed = 0;
    for (int i = 0; i < b; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u, parent) != find(v, parent)) {
            union_sets(u, v, parent, rank);
            drivers_needed++;
        }
    }
    printf("%d\n", drivers_needed);
    free(edges);
    free(parent);
    free(rank);

    return 0;
}

