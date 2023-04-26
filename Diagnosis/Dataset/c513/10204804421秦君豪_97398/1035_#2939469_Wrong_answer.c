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
    return (a1->r)>(b1->r)?-1:1;
}

int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    circular a[n];
    long long int S=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].r,&a[i].h);
    }
    qsort(a,n,sizeof(circular),cmp);
    S=(a[0].r)*(a[0].r)+2*(a[0].r)*(a[0].h);
////
//    printf("s=%lld",S);
    for (int i=1;i<m;i++)
    {
        S+=2*(a[i].r)*(a[i].h);
    }
    printf("%lld",S);
    system("pause");
    return 0;
}
