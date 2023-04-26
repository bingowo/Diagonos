#include <stdio.h>
#include<stdlib.h>
#include<string.h>



long long RE(int n, int m)
{
    if(n < m) return 0;
    if(n == m) return 1;

    return 2 * RE(n - 1,m) + pow(2, n-m-1) - RE(n - m - 1,m);
}


int main()
{
    long long  n, m;
    while(scanf("%d %d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;


        printf("%lld",RE(n,m));
    }
}
