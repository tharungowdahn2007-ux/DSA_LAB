#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[500000], b[500000];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    
    while (i <= mid) b[k++] = a[i++];
    while (j <= high) b[k++] = a[j++];

    for (i = low; i <= high; i++) a[i] = b[i];
}

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records:\n");
    scanf("%d", &n);

    srand(time(NULL));
    printf("The Employee IDs are:\n");
    for (i = 1; i <= n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]); 
    }
    printf("\n");

    starttime = clock();
    merge_sort(1, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nEmployee IDs in sorted order:\n");
    for (i = 1; i <= n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\nThe run time is %f\n", clk);

    return 0;
}