#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int cc(int n,int m)
{
    if(n<m)
        return 0;
    else if(n==m)
        return 1;
    else
        return 2*cc(n-1,m)-cc(n-1-m,m)+pow(2,n-m-1);
}
int main()
{
    int n=1,m=1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==-1)
            break;
        long long int all;
        all=cc(n,m);
        printf("%lld\n",all);
    }
    return 0;
}
