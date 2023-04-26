#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int r;
    int h;
}circular;

int cmp(const void* a,const void *b)
{
    circular* a1=(circular*)a;
    circular* b1=(circular*)b;
    if((a1->r)!=(b1->r))return (a1->r)>(b1->r)?-1:1;
    else return (a1->h)>(b1->h)?-1:1;
}

int cmp1(const void* a,const void*b)
{
    long long int A,B;
    circular* a1=(circular*)a;
    circular* b1=(circular*)b;
    A=(a1->h)*(a1->r);
    B=(b1->h)*(b1->r);
    return A>B?-1:1;
}
long long Max(long long a,long long b)
{
    return a>b?a:b;
}

int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    circular a[n];

    long long int S=0;
    long long int temp;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].r,&a[i].h);
    }

    for( int i=-0;i<n;i++)
    {
        int k=0;
        circular ax[n];
        for (int j=0;j<n;j++)
        {
            if(j!=i&&a[j].r<=a[i].r) ax[k++]=a[j];
        }
        qsort (ax,k,sizeof(circular),cmp1);
        long long area=0;
        if(k!=0&&k>=m-1)
        {
            for (int cnt = 0;cnt<m-1;cnt++) area +=(ax[cnt].h*ax[cnt].r);
        }
        S=Max(S,2*area+a[i].r*a[i].r+2*a[i].r*a[i].h);
    }
    printf("%lld",S);
    system("pause");
    return 0;
}
