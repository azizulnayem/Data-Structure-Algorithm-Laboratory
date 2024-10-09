#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int dest;
    int stamina;
} Edge;

typedef struct {
    int level;
    int stamina;
    int sleep_time;
} State;

typedef struct {
    int level;
    int stamina;
    int sleep_time;
} PriorityQueueItem;

int** allocate_sleep_record(int levels) {
    int** sleep_record = (int**)malloc((levels + 1) * sizeof(int*));
    for (int i = 0; i <= levels; i++) {
        sleep_record[i] = (int*)malloc(101 * sizeof(int));
        for (int j = 0; j < 101; j++) {
            sleep_record[i][j] = INT_MAX;
        }
    }
    return sleep_record;
}

void free_sleep_record(int** sleep_record, int levels) {
    for (int i = 0; i <= levels; i++) {
        if (sleep_record[i] != NULL) {
            free(sleep_record[i]);
        }
    }
    free(sleep_record);
}

void push(PriorityQueueItem pq[], int* size, PriorityQueueItem item) {
    pq[(*size)++] = item;
    int i = *size - 1;
    while (i > 0 && pq[i].sleep_time < pq[(i - 1) / 2].sleep_time) {
        PriorityQueueItem temp = pq[i];
        pq[i] = pq[(i - 1) / 2];
        pq[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

PriorityQueueItem pop(PriorityQueueItem pq[], int* size) {
    PriorityQueueItem root = pq[0];
    pq[0] = pq[--(*size)];
    int i = 0;
    while (i * 2 + 1 < *size) {
        int smallest = i;
        if (pq[i * 2 + 1].sleep_time < pq[smallest].sleep_time) {
            smallest = i * 2 + 1;
        }
        if (i * 2 + 2 < *size && pq[i * 2 + 2].sleep_time < pq[smallest].sleep_time) {
            smallest = i * 2 + 2;
        }
        if (smallest == i) break;
        PriorityQueueItem temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;
        i = smallest;
    }
    return root;
}

int dijkstra(int levels, int transitions, int start, int end, Edge** graph, int* graph_size, int** sleep_record, int* stamina_fruit, int* sleep_fruit) {
    PriorityQueueItem pq[10000];
    int pq_size = 0;

    push(pq, &pq_size, (PriorityQueueItem){start, 0, 0});
    sleep_record[start][0] = 0;

    while (pq_size > 0) {
        PriorityQueueItem current = pop(pq, &pq_size);

        int level = current.level;
        int stamina = current.stamina;
        int sleep_time = current.sleep_time;

        if (level == end) {
            return sleep_time;
        }
        int new_stamina = stamina_fruit[level];
        int sleep_cost = sleep_fruit[level];
        if (sleep_time + sleep_cost < sleep_record[level][new_stamina]) {
            sleep_record[level][new_stamina] = sleep_time + sleep_cost;
            push(pq, &pq_size, (PriorityQueueItem){level, new_stamina, sleep_time + sleep_cost});
        }
        for (int i = 0; i < graph_size[level]; i++) {
            int next_level = graph[level][i].dest;
            int stamina_cost = graph[level][i].stamina;
            if (stamina >= stamina_cost && sleep_time < sleep_record[next_level][stamina - stamina_cost]) {
                sleep_record[next_level][stamina - stamina_cost] = sleep_time;
                push(pq, &pq_size, (PriorityQueueItem){next_level, stamina - stamina_cost, sleep_time});
            }
        }
    }

    return -1;
}

int main() {
    int levels, transitions, start, end;
    scanf("%d %d %d %d", &levels, &transitions, &start, &end);

    Edge** graph = (Edge**)malloc((levels + 1) * sizeof(Edge*));
    int* graph_size = (int*)calloc((levels + 1), sizeof(int));

    for (int i = 0; i <= levels; i++) {
        graph[i] = (Edge*)malloc(transitions * sizeof(Edge));
    }

    for (int i = 0; i < transitions; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        graph[x][graph_size[x]++] = (Edge){y, z};
        graph[y][graph_size[y]++] = (Edge){x, z};
    }

    int* stamina_fruit = (int*)malloc((levels + 1) * sizeof(int));
    int* sleep_fruit = (int*)malloc((levels + 1) * sizeof(int));
    for (int i = 1; i <= levels; i++) {
        scanf("%d %d", &stamina_fruit[i], &sleep_fruit[i]);
    }

    int** sleep_record = allocate_sleep_record(levels);
    int result = dijkstra(levels, transitions, start, end, graph, graph_size, sleep_record, stamina_fruit, sleep_fruit);
    printf("%d\n", result);

    free_sleep_record(sleep_record, levels);

    for (int i = 0; i <= levels; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graph_size);
    free(stamina_fruit);
    free(sleep_fruit);

    return 0;
}
