#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long a;
}shu;
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
int main()
{
    int m,n,i,k;
    scanf("%d %d",&n,&m);
    shu p[110000];
    result sum[110000];
    for(i=0;i<n;i++)scanf("%lld",&p[i].a);
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n-m+1;i++)
    {
       sum[i].h=0;
       for(k=0;k<m-1;k++)
        sum[i].h=sum[i].h+p[i+m-1].a-p[i+k].a;
    }
    qsort(sum,n-m+1,sizeof(sum[0]),cmp);
    printf("%lld",sum[0].h);
    return 0;
}
