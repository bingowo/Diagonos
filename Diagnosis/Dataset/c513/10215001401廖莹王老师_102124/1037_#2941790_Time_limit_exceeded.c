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
    long long sum,g=0;
    long long l=0;
    for(i=0;i<n;i++)scanf("%lld",&p[i].a);
    qsort(p,n,sizeof(p[0]),cmp);
        sum=(m-1)*p[m-1].a-xh(m,0);
    for(i=0;i<n-m+1;i++)
    {   g=0;
        g=(m-1)*p[i+m-1].a-xh(m,i);
        if(sum>=g)sum=g;
    }
    printf("%lld",sum);
    return 0;
}
