#include <stdio.h>
#include <time.h>

int n, capacity;
int weight[20], value[20], dp[20][20];

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knap() {
    int i, j;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
              
            else if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
              
            else
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
        }
    }

    printf("\nThe DP Table is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[n][capacity];
}

int main() {
    int i, result;
    clock_t start, end;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 1; i <= n; i++) 
        scanf("%d", &weight[i]);

    printf("Enter values of items:\n");
    for (i = 1; i <= n; i++) 
        scanf("%d", &value[i]);

    printf("Enter capacity of basket: ");
    scanf("%d", &capacity);

    start = clock();
    result = knap();
    end = clock();

    printf("\nOptimal solution is %d\n", result);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}