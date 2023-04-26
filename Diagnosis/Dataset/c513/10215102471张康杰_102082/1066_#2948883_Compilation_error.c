#include <stdio.h>
#include <stdlib.h>

int f(int n,int p,int m,int t,int start)
{
    if(start > m)
        return 0;
    else if(t == n)
        return f(n,p,m,t - 1,start + 1);
    else if(t == 1)
        return f(n,p,m,t + 1,start + 1);
    else if(t == p && start <= m)
        return f(n,p,m,t+1,start + 1) + f(n,p,m,t-1,start + 1,0) + 1;
    else
        return f(n,t + 1,m,t,start + 1) + f(n,t - 1,m - 1,t,start + 1);
}
int main()
{
    int cas,i;
    scanf("%d",&cas);
    for(i = 0;i < cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",f(n,p,m,t,0));
    }
}