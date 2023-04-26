#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void*p1,const void *p2)
{
    long long p_1 = *(long long*)p1;
    long long p_2 = *(long long*)p2;
    return (p_1>p_2)?1:-1;
}
int main()
{
    int t =0;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
    long long *p = (long long *)malloc(sizeof(long long)*1e8);
    memset(p,0,sizeof(long long)*1e8);
    long long a[1001];
    memset(a,0,sizeof(a));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int q = 0;q<n;q++)
    {
        scanf("%lld",&a[q+1]);
        a[q+1] = a[q+1] +a[q];
    }
    int point =0;
    for(int length = 1;length<=n;length++)
    {
        for(int sta = 0;sta<n-length+1;sta++)
        {
            p[point] = a[sta+length] - a[sta];
            point++;
        }
    }
    qsort(p,point,sizeof(long long),cmp);
    printf("case #%d:\n",i);
    for(int z =0;z<m;z++)
    {
        int l,u;
        scanf("%d%d",&u,&l);
        long long g = 0;
        for(int q =u-1;q<l;q++)
        {
            g+=p[q];
        }
        printf("%lld\n",g);
    }

    free(p);
    }

    return 0;
}
