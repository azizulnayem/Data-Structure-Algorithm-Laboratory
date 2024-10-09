#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_NODES 100
#define INF DBL_MAX

typedef struct {
    double x, y;
} Point;

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
void floydWarshall(double graph[MAX_NODES][MAX_NODES], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
double totalTravelCost(double graph[MAX_NODES][MAX_NODES], int n) {
    double totalCost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            totalCost += graph[i][j];
        }
    }
    return totalCost;
}

int main() {
    int n, m;
    Point nodes[MAX_NODES];
    double graph[MAX_NODES][MAX_NODES];
    double originalGraph[MAX_NODES][MAX_NODES];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &nodes[i].x, &nodes[i].y);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        double distance = dist(nodes[u], nodes[v]);
        graph[u][v] = graph[v][u] = distance;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            originalGraph[i][j] = graph[i][j];
        }
    }
    floydWarshall(graph, n);
    double originalCost = totalTravelCost(graph, n);
    int bestU = -1, bestV = -1;
    double bestCost = originalCost;
    double bestDistance = INF;

    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            if (originalGraph[u][v] == INF) {
                double newDistance = dist(nodes[u], nodes[v]);
                graph[u][v] = graph[v][u] = newDistance;
                floydWarshall(graph, n);
                double newCost = totalTravelCost(graph, n);
                if (newCost < bestCost || (newCost == bestCost && newDistance < bestDistance)) {
                    bestCost = newCost;
                    bestU = u;
                    bestV = v;
                    bestDistance = newDistance;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        graph[i][j] = originalGraph[i][j];
                    }
                }
            }
        }
    }
    if (bestU != -1 && bestV != -1 && (originalCost - bestCost > 1.0)) {
        printf("%d %d\n", bestU + 1, bestV + 1);
    } else {
        printf("No road required\n");
    }

    return 0;
}
