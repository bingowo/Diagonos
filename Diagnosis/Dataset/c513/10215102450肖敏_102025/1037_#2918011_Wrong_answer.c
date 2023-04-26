#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a,const void * b)
{
    long long *a1 = (long long *)a,*b1 = (long long *)b;
    if( *a1 > *b1)
        return 1;
    return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long * p = (long long *) malloc(n*sizeof (long long ));
    for(int i = 0;i <n;i++)
    {
        scanf("%lld",&p[i]);
    }
    qsort(p,n,sizeof (long long),cmp);
    long long sum =0;
    for(int i =0;i < m -1;i ++)
    {
        sum += p[m -1]-p[i];
    }
    long long res = sum;
    for(int i =0;i < n - m;i++)
    {
        res += m* p[i + m] + p[i]-(m +1)*p[i + m-1];
        if(res < sum)
            sum = res;
    }
    printf("%lld\n",sum);
    return 0;
}
