#include <stdio.h>
#include <stdlib.h>
#include<math.h>

long long re(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    return 2 * re(n - 1,m) + pow(2, n-m-1) - re(n - m - 1,m);
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==-1&&m==-1)
            break;
    printf("%lld\n",re(n,m));
    }
    return 0;
}
