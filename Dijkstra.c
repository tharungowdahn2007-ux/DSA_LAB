#include <stdio.h>
#include <time.h>
#define MAX 20
#define INF 999
int main() {
    int n, i, j, u, v;
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (999 for infinity):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    int source;
    printf("Enter source vertex (0 to %d): ", n-1);
    scanf("%d", &source);
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }
    dist[source] = 0;
    visited[source] = 1;
    start = clock();
    for (i = 1; i < n; i++) {
        int min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nShortest distances from source %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
    printf("\nExecution Time: %f seconds\n", time_taken);
    return 0;
}