#include <stdio.h>
#include <time.h>
#define MAX 20
int set[MAX], subset[MAX];
int n, K, found = 0;
void subsetSum(int i, int sum, int size) {
    if (sum == K) {
        found = 1;
        printf("Subset: ");
        for (int j = 0; j < size; j++)
            printf("%d ", subset[j]);
        printf("\n");
        return;
    }
    if (i == n || sum > K)
        return;
    subset[size] = set[i];
    subsetSum(i + 1, sum + set[i], size + 1);
    subsetSum(i + 1, sum, size);
}
int main() {
    clock_t start, end;
    double time_taken;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    printf("Enter target sum (K): ");
    scanf("%d", &K);
    start = clock();
    subsetSum(0, 0, 0);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    if (!found)
        printf("No subset found\n");
    printf("\nExecution Time: %f seconds\n", time_taken);
    return 0;
}