#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long a;
}shu;
shu p[1100000];
typedef struct
{
    long long h;
}result;
int cmp(const void*a,const void*b)
{
    shu *s1,*s2;
    s1=(shu*)a;
    s2=(shu*)b;
    if(s1->a>s2->a) return 1;
    else return -1;
}
long long xh(long long  m,long long i)
{
    long long k=0;
    long long l=0;
    for(k=0;k<m-1;k++)
        l=l+p[i+k].a;
        return l;
}
int main()
{
    long long m=0,n=0,i=0,k=0;
    scanf("%lld %lld",&n,&m);

    result sum[1100000];
    long long l=0;
    for(i=0;i<n;i++)scanf("%lld",&p[i].a);
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n-m+1;i++)
    {
        sum[i].h=0;
        l=0;
        sum[i].h=(m-1)*p[i+m-1].a;
       l=xh(m,i);
        sum[i].h=sum[i].h-l;
    }
    qsort(sum,n-m+1,sizeof(sum[0]),cmp);
    printf("%lld",sum[0].h);
    return 0;
}
