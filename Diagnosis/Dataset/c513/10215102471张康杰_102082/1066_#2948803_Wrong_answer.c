#include <stdio.h>
#include <stdlib.h>

int f(int n,int p,int m,int t)
{
    if(m < 0)
        return 0;
    else if(t == n)
        return f(n,t - 1,m - 1,t);
    else if(t == 1)
        return f(n,t + 1,m - 1,t);
    else if(t == p && m >= 0)
        return 0;
    else
        return f(n,t + 1,m - 1,t) + f(n,t - 1,m - 1,t);
}
int main()
{
    int cas,i;
    scanf("%d",&cas);
    for(i = 0;i < cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",f(n,p,m,t));
    }
}