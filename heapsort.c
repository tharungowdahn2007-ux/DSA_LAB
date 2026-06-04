#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct candidate {
    char name[20];
    float percentage;
} a[20000];

void heapbottomup(int n) {
    int i, j, k;
    struct candidate v;
    
    for (i = n / 2; i > 0; i--) {
        k = i; 
        v = a[k]; 
        while (2 * k <= n) { 
            j = 2 * k; 
            if (j < n && a[j].percentage < a[j+1].percentage) j++;
            if (v.percentage >= a[j].percentage) break;
            
            a[k] = a[j]; 
            k = j; 
        }
        a[k] = v; 
    }
}

void heapsort(int n) {
    int i;
    struct candidate temp;
    heapbottomup(n); 
    for (i = n; i > 1; i--) {
        temp = a[1]; a[1] = a[i]; a[i] = temp; 
        heapbottomup(i - 1); 
    }
}

int main() {
    int n, i;
    clock_t s, e;

    printf("Enter number of candidates: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (i = 1; i <= n; i++) {
        sprintf(a[i].name, "Cand_%d", i); 
        a[i].percentage = 50 + (rand() % 500) / 10.0; 
    }
    printf("Before Sorting\n");
    for (i = 1; i <= n; i++)
        printf("%s\t%.2f\n", a[i].name, a[i].percentage); 
        
    s = clock(); 
    heapsort(n); 
    e = clock(); 

    printf("\nSorted Candidates:\n");
    for (i = 1; i <= n; i++)
        printf("%s\t%.2f\n", a[i].name, a[i].percentage); 

    printf("\nTime taken: %f\n", (double)(e - s) / CLOCKS_PER_SEC); 
    return 0;
}