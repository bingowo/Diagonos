#include <stdlib.h>
#include <stdio.h>

typedef long long int LLD;

LLD f(int n,int p,int m,int t)
{
    if(m == 0 && t == p)
        return 1;
    else if(m == 0 && t != p)
        return 0;
    else if(m != 0 && t == 1)
        return f(n,p,m - 1,t + 1);
    else if( m != 0 && t == n)
        return f(n,p,m - 1,t - 1);
    else
        return f(n,p,m - 1,t + 1) + f(n,p,m - 1,t - 1);
}

int main()
{
    int cas,i;
    scanf("%d",&cas);
    for(i = 0;i < cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        if(t > n)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",f(n,p,m,t));
    }
    return 0;
}