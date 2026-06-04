#include <stdio.h>
#include <time.h>

int n, a[50][50], reach[50];

void dfs(int v) {
    int i;
    reach[v] = 1; 
    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && !reach[i]) {
            printf("Edge: (%d,%d)\n", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, v, count = 0;
    clock_t start, end;

    printf("\t\tDEPTH FIRST SEARCH\n");
    printf("Enter number of Lands to be surveyed: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0/1):\n");
    for (i = 1; i <= n; i++) {
        reach[i] = 0; 
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting Land number: ");
    scanf("%d", &v);

    start = clock();
    dfs(v);
    end = clock();

    for (i = 1; i <= n; i++) if (reach[i]) count++;

    if (count == n) printf("\nGraph is connected\n");
    else printf("\nGraph is not connected\n");

    printf("Run time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}