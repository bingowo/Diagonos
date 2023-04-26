#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    long long R;
    long long H;
    long long SS;
} PILLAR;

int cmp1(const void* a,const void *b)
{
    PILLAR* pa=(PILLAR*)a; PILLAR* pb=(PILLAR*)b;
    return (pa->R>pb->R)?-1:1;
}

int cmp2(const void* a,const void *b)
{
    PILLAR* pa=(PILLAR*)a; PILLAR* pb=(PILLAR*)b;
    return (pa->SS>pb->SS)?-1:1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j; long long RR=0 ,result=0;
    PILLAR* arr=(PILLAR*)malloc(n*sizeof(PILLAR));
    for (i=0;i<n;i++)
    {
        scanf("%lld %lld",&arr[i].R,&arr[i].H);
        arr[i].SS=2*arr[i].H*arr[i].R;
    }
    qsort(arr,n,sizeof(PILLAR),cmp1);
    RR=arr[0].R;
    qsort(arr,n,sizeof(PILLAR),cmp2);
    for (i=0;i<m;i++)
        result+=arr[i].SS;
    result+=RR*RR;
    printf("%lld\n",result);
    free(arr);
    return 0;
}
