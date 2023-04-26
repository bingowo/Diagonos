#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

typedef struct data
{
    int R;
    int H;
} Data;

int
main()
{
    int n,m;
    long long int x;

    scanf("%d%d",&n,&m);
    Data *pdata = (Data*)malloc(n*sizeof(Data));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&(pdata+i)->R);
        scanf("%d",&((pdata+i)->H));
    }
    qsort(pdata,n,sizeof(Data),cmp);
    for (int i=0;i<m;i++)
    {
        if (i==0) x = ((pdata+i)->R * (pdata+i)->R);
        x += 2 * (pdata+i)->R * (pdata+i)->H;
    }

    printf("%lld",x);
    return 0;
}

int
cmp(const void* a,const void* b)
{
    Data *pa = (Data*)a;
    Data *pb = (Data*)b;

    if(pa->R < pb->R) return 1;
    else if (pa->R == pb->R) if (pa->H < pb->H) return 1;
    return -1;
}
