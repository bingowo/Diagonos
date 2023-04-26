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
    PILLAR* pa=(PILLAR*)a; PILLAR* pb=(PILLAR*)b;
    return (pa->R>pb->R)?1:-1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j; long long L=0 ,result=0;
    PILLAR* arr=(PILLAR*)malloc(n*sizeof(PILLAR));
    for (i=0;i<n;i++)
    {
        scanf("%lld %lld",&arr[i].R,&arr[i].H);
        arr[i].SS=2*arr[i].H*arr[i].R;
    }
    qsort(arr,n,sizeof(PILLAR),cmp);
    i=0;
    while (i<n-m)
    {
        if ((arr[i+m].R*arr[i+m].R+arr[i+m].SS)>(arr[i].R*arr[i].R+arr[i].SS))
            i++;
    }
    for (j=i;j<i+m;j++)
        result+=arr[j].SS;
    result+=arr[i+m-1].R*arr[i+m-1].R;

    printf("%lld\n",result);

    return 0;
}
