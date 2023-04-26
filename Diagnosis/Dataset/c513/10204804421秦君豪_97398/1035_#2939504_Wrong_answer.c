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
    qsort(a,n,sizeof(circular),cmp);
    S=(a[0].r)*(a[0].r)+2*(a[0].r)*(a[0].h);
    qsort(a+1,n-1,sizeof(circular),cmp1);
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
