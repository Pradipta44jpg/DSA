#include <stdio.h>
#include <limits.h>

#define V 4

int min_distance(int dist[], int visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int u = 0; u < V; u++) {
        if (!visited[u] && dist[u] <= min) {
            min = dist[u];
            min_index = u;
        }
    }
    return min_index;
}

void short_distance(int adj[V][V], int start) {
    int dist[V], visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int adj[V][V] = {
        {0, 4, 1, 0},
        {4, 0, 2, 5},
        {1, 2, 0, 3},
        {0, 5, 3, 0}
    };

    short_distance(adj, 0);
    return 0;
}
