#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];
int hp_count = 0;   // Horspool comparison counter
int ls_count = 0;   // Linear search comparison counter
void shifttable(char p[])
{
    int i,j,m;
    m = strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]] = m-1-j;
}

/* Horspool Algorithm */
int horspool(char src[], char p[])
{
    int i,k,m,n;
    n = strlen(src);
    m = strlen(p);
    printf("\nLength of text = %d",n);
    printf("\nLength of pattern = %d",m);

    i = m-1;

    while(i < n)
    {
        k = 0;
        while(k < m)
{
    hp_count++;   // count comparison

    if(p[m-1-k] == src[i-k])
        k++;
    else
        break;
}

        if(k == m)
            return(i-m+1);
        else
            i += t[src[i]];
    }
    return -1;
}

/* Linear Search (Brute Force) */
int linearsearch(char src[], char p[])
{
    int i,j,n,m;
    n = strlen(src);
    m = strlen(p);
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            ls_count++;
            if(src[i+j] != p[j])
                break;
        }
        if(j==m)
            return i;
    }
    return -1;
}


void main()
{
    char src[100], p[100];
    int pos_hp, pos_ls;
    printf("Enter the text:\n");
    gets(src);
    printf("Enter the pattern:\n");
    gets(p);

    shifttable(p);
   
   pos_hp = horspool(src,p);
    pos_ls = linearsearch(src,p);
   
 if(pos_hp >= 0)
        printf("\n\nHorspool: Pattern found at position %d", pos_hp+1);
    else
        printf("\nHorspool: Pattern not found");
  
  if(pos_ls >= 0)
        printf("\nLinear Search: Pattern found at position %d", pos_ls+1);
    else
        printf("\nLinear Search: Pattern not found");
   
 printf("\n\nNumber of comparisons in Horspool = %d", hp_count);
    printf("\nNumber of comparisons in Linear Search = %d", ls_count);

   
}
