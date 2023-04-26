#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    long long R;
    long long H;
    long long SS;
} PILLAR;

int cmp(const void* a,const void *b)
{
    long long* pa=(long long*)a; long long* pb=(long long*)b;
    return (*pa>*pb)?-1:1;
}

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
    long long* arr2=(long long*)malloc(m*sizeof(long long));
    for (i=0;i<m;i++)
    {
        arr2[i]=arr[i].R;
    }
    qsort(arr2,m,sizeof(long long),cmp);
    if (arr2[0]<RR)
        RR=arr2[0];
    for (i=0;i<m;i++)
        result+=arr[i].SS;
    result+=RR*RR;
    printf("%lld\n",result);
    free(arr);
    free(arr2);
    return 0;
}
