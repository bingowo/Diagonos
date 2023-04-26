#include <stdio.h>
#include <stdlib.h>
int ones(long long a)
{
    int j = 0,k = 0;
    if(a == 0)
        return 0;
    else
    {
        for(;j < 64;j ++)
        {k += (a & (1 << j)) == 0?0:1;}
        return k;
    }
}
int cmp(const void* a,const void* b)
{
    long long int t;
    long long ia=*(long long *)a,ib = *( long long *)b;
    if(t = ones(ib) - ones(ia)) return t;
    if(ia > ib) return 1;
    if(ia < ib) return -1;
    return 0;
}
void Sort(long long *p, unsigned n)
{
    qsort(p,n,sizeof(p[0]),cmp);
}
void Sort(long long *p, unsigned n);

int main()
{   int T,e;
    scanf("%d",&T);
    for(e = 0;e < T;e++)
    {
        unsigned n,i;
        long long int a[1000];  scanf("%u",&n);
        for (i=0;i<n;i++) scanf("%lld",a+i);   Sort(a,n);
        printf("case #%d:\n",e);
        for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
    }
    return 0;
}
