#include <stdio.h>
#include <math.h>
long long int func(int n, int m)
{
    if(n < m) return 0;
    if(n == m) return 1;
    return 2*func(n-1,m)+pow(2, n-m-1)-func(n-m-1,m);
}
int main()
{
    while(1)
    {
        long long int count=0;
        int m=0,n=0;
        scanf("%d %d",&n,&m);
        if(m==-1 && n==-1) break;
        count = func(n,m);
        printf("%lld\n",count);
    }
    return 0;
}