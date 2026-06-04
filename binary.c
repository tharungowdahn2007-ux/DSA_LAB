#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n, a[1000], key;
    int bottom, top, mid;
    int j, temp;

    double clk;
    clock_t starttime, endtime;

    srand(time(NULL));

    printf("Enter the number of Products:\n");
    scanf("%d", &n);

    /* Generate Random Product IDs */
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("The Product ID is: %d\n", a[i]);
    }

    /* Bubble Sort */
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Product ID List:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    printf("\nEnter the Product ID to be searched:\n");
    scanf("%d", &key);

    starttime = clock();

    /* Binary Search */
    bottom = 0;
    top = n - 1;

    do
    {
        mid = (bottom + top) / 2;

        if(key < a[mid])
        {
            top = mid - 1;
        }
        else if(key > a[mid])
        {
            bottom = mid + 1;
        }

    } while(key != a[mid] && bottom <= top);

    if(key == a[mid])
    {
        printf("\nProduct Found !!\n");
        printf("Product %d found at position %d\n", key, mid + 1);
    }
    else
    {
        printf("\nSearch Failed\n");
        printf("Product %d not found\n", key);
    }

    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nRun Time = %f seconds\n", clk);

    return 0;
}