#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[200000];

int partition(int low, int high) {
    int pivot = a[low], i = low + 1, j = high, temp;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        
        if (i < j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    
    temp = a[low]; a[low] = a[j]; a[j] = temp;
    return j;
}

void quick_sort(int low, int high) {
    if (low < high) {
        int j = partition(low, high);
        quick_sort(low, j - 1);
        quick_sort(j + 1, high);
    }
}

int main() {
    int i, n;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records:\n");
    scanf("%d", &n);

    srand(time(NULL));
    printf("The roll numbers are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    starttime = clock();
    quick_sort(0, n - 1);
    endtime = clock();
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\n\nSorted roll numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    
    printf("\n\nThe run time is %f\n", clk);

    return 0;
}