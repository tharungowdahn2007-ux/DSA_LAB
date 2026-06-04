#include <stdio.h>
#include <time.h>
#define MAX 20
int parent[MAX];
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}
void uni(int i, int j) {
    parent[j] = i;
}
int main() {
    int n, i, j, a, b, u, v;
    int min, mincost = 0;
    int cost[MAX][MAX];
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(i==j)
            cost[i][j]=999;
            
        }
    }
    for (i = 0; i < n; i++)
        parent[i] = 0;
    start = clock();
    printf("\nEdges in MST:\n");
    int edges = 0;
    while (edges < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (u != v) {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            uni(u, v);
            edges++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMinimum Cost = %d\n", mincost);
    printf("Execution Time: %f seconds\n", time_taken);
    return 0;
}