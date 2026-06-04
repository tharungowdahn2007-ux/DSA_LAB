#include <stdio.h>
#include <time.h>

void bfs(int a[10][10], int n, int source) {
    int s[10] = {0}, q[10], f = 0, r = -1; 
    int t, v;

    q[++r] = source;
    s[source] = 1;

    printf("The BFS traversal is:\n");
    while (f <= r) {
        t = q[f++];
        for (v = 0; v < n; v++) {
            if (a[t][v] == 1 && s[v] == 0) {
                printf("%d %d\n", t, v);
                q[++r] = v;
                s[v] = 1;
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j, s;
    clock_t starttime, endtime;
    double clk;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the matrix representation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source city: ");
    scanf("%d", &s);

    starttime = clock();
    bfs(a, n, s);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f\n", clk);

    return 0;
}