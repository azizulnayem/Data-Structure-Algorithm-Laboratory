#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000
#define MAX_NODES 100

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
void floyd_warshall(int dist[MAX_NODES][MAX_NODES], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int P, Q;
    int coordinates[MAX_NODES][2];
    int dist[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes and bridges: ");
    scanf("%d %d", &P, &Q);

    printf("Enter the coordinates of the nodes (x y):\n");
    for (int i = 0; i < P; i++) {
        scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    printf("Enter the existing bridges (node1 node2):\n");
    for (int i = 0; i < Q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        dist[u][v] = dist[v][u] = manhattan_distance(coordinates[u][0], coordinates[u][1], coordinates[v][0], coordinates[v][1]);
    }
    floyd_warshall(dist, P);
    int best_u = -1, best_v = -1;
    int max_reduction = 0;
    int min_distance = INF;

    for (int u = 0; u < P; u++) {
        for (int v = u + 1; v < P; v++) {
            if (dist[u][v] != INF) continue;
            int current_cost = 0;
            for (int i = 0; i < P; i++) {
                for (int j = i + 1; j < P; j++) {
                    current_cost += dist[i][j];
                }
            }
            int new_dist = manhattan_distance(coordinates[u][0], coordinates[u][1], coordinates[v][0], coordinates[v][1]);
            int new_dist_matrix[MAX_NODES][MAX_NODES];
            for (int i = 0; i < P; i++) {
                for (int j = 0; j < P; j++) {
                    new_dist_matrix[i][j] = dist[i][j];
                }
            }
            new_dist_matrix[u][v] = new_dist_matrix[v][u] = new_dist;
            floyd_warshall(new_dist_matrix, P);
            int new_cost = 0;
            for (int i = 0; i < P; i++) {
                for (int j = i + 1; j < P; j++) {
                    new_cost += new_dist_matrix[i][j];
                }
            }
            int reduction = current_cost - new_cost;
            if (reduction > max_reduction) {
                max_reduction = reduction;
                best_u = u;
                best_v = v;
                min_distance = new_dist;
            } else if (reduction == max_reduction && new_dist < min_distance) {
                best_u = u;
                best_v = v;
                min_distance = new_dist;
            } else if (reduction == max_reduction && new_dist == min_distance) {
                if (u < best_u || (u == best_u && v < best_v)) {
                    best_u = u;
                    best_v = v;
                }
            }
        }
    }
    if (max_reduction > 1) {
        printf("The best pair of nodes to connect is: %d %d\n", best_u + 1, best_v + 1);
    } else {
        printf("No bridge required\n");
    }

    return 0;
}
