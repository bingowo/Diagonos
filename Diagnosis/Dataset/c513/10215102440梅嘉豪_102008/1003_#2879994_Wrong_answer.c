#include <stdio.h>
#include <stdlib.h>
struct data
{
    long long a;
    int num;
}p[10000];
int cmp(const void *a,const void *b);
int main()
{
    
    
    int T,n,d;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)    
        {
            scanf("%lld",&p[j].a);
            p[j].num=0;
            d=1;
            for(int k=0;k<64;k++)
            {
                if(d&p[j].a)    p[j].num++;
                d=d<<1;
            }
            
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)    printf("%lld%c",p[j].a,j==n-1?'\n':' ');
    }
}
int cmp(const void *a,const void *b)
{
    struct data p1,p2;
    p1=*((struct data *)a);
    p2=*((struct data *)b);
    if(p1.num==p2.num)  return p1.a<p2.a?-1:1;
    else return p1.num>p2.num?-1:1;
}

