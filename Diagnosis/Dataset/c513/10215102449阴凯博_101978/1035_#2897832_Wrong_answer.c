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
    int i,j; long long RR=0 ,S1,result=0;
    PILLAR* arr=(PILLAR*)malloc(n*sizeof(PILLAR));
    for (i=0;i<n;i++)
    {
        scanf("%lld %lld",&arr[i].R,&arr[i].H);
        arr[i].SS=2*arr[i].H*arr[i].R;
    }
    qsort(arr,n,sizeof(PILLAR),cmp1);
    RR=arr[0].R;
    S1=arr[0].SS;
    qsort(arr,n,sizeof(PILLAR),cmp2);
    PILLAR* arr2=(PILLAR*)malloc(m*sizeof(PILLAR));
    for (i=0;i<m;i++)
    {
        arr2[i].R=arr[i].R;
        arr2[i].SS=arr[i].SS;
    }
    qsort(arr2,m,sizeof(PILLAR),cmp1);
    if  ((arr2[0].R+arr2[0].SS) > RR+S1)
        RR=arr2[0].R;
    for (i=0;i<m;i++)
        result+=arr[i].SS;
    result+=RR*RR;
    printf("%lld\n",result);
    free(arr);
    free(arr2);
    return 0;
}
