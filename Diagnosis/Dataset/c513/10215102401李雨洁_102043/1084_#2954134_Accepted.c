#include <stdio.h>

long long f(int n,int m)
{
    if (m == 0) return 1;
    else if (m == 1) return n;
    else if (!(m%2)) return f(n*n, m/2);
    return f(n*n, m/2)*n;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        long long end = f(2,n);
        printf("%lld\n",end);
    }
    return 0;
}
