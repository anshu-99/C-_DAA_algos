#include<stdio.h>

#define V 4

void print_transitive_closure(int reach[][V]);

void transitive_closure(int graph[][V]) {
    int reach[V][V], i, j, k;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];
    }
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    print_transitive_closure(reach);
}

void print_transitive_closure(int reach[][V]) {
    printf("Transitive closure of the given graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                printf("1 ");
            else
                printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    transitive_closure(graph);
    return 0;
}

