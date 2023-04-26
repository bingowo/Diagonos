#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int
main()
{
    int questions;
    int N;

    scanf("%d",&questions);

    for (int i=0;i<questions;i++)
    {
        scanf("%d",&N);
        long long int *pnum = (long long int*)malloc(N*sizeof(long long int));
        for (int j=0;j<N;j++)
        {
            scanf("%lld",(pnum+j));
        }
        qsort(pnum,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<N;j++)
        {
            printf("%lld ",*(pnum+j));
        }
        printf("\n");
    }

    return 0;
}

int
cmp(const void* a,const void* b)
{
    long long int num1 = *(long long int*)a;
    long long int num2 = *(long long int*)b;
    long long int n1 = num1,n2 = num2;

    while (n1/10 != 0)
    {
        n1 /= 10;
    }
    while (n2/10 != 0)
    {
        n2 /= 10;
    }
    n1 = n1>0?n1:(-1)*n1;
    n2 = n2>0?n2:(-1)*n2;
    if (n1<n2) return 1;
    else if (n1 == n2) if (num1>num2) return 1;
    return -1;
}