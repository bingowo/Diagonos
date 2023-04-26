#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    long long number;
    int digit;
} DATA;

int count(long long a)
{
    int cnt=0;
    while (a)
    {
        cnt++;
        a=(a-1)&a;
    }
    return cnt;
}

int cmp(const void* a,const void* b)
{
    DATA* pa=(DATA*)a;
    DATA* pb=(DATA*)b;
    if (pa->digit>pb->digit) return -1;
    else if (pa->digit<pb->digit) return 1;
    else if (pa->digit==pb->digit)
    {
        return (pa->number>pb->number?1:-1);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N,j,k;
        scanf("%d",&N);
        DATA* arr=(DATA*)malloc(N*sizeof(DATA));
        for (j=0;j<N;j++)
        {
            scanf("%lld",&arr[j].number);
        }
        for (k=0;k<j;k++) arr[k].digit=count(arr[k].number);
        qsort(arr,j,sizeof(DATA),cmp);
        for (k=0;k<j;k++)
            printf("%d%c",arr[k].number,k==j-1?'\n':' ');
        free(arr);
    }
    return 0;
}
