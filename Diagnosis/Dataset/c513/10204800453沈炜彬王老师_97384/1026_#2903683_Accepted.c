#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int
main()
{
    int n;
    int temp;
    long long int sum=0;

    scanf("%d",&n);
    int *pnum = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d",pnum+i);
    }
    qsort(pnum,n,sizeof(int),cmp);
    for (int i=0;i<n;i+=2)
    {
        temp = (*(pnum+i) - *(pnum+i+1));
        sum += temp>0?temp:temp*(-1);
    }
    printf("%lld",sum);

    return 0;
}

int
cmp(const void* a,const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1>num2) return 1;
    else    return -1;
}
