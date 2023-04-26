#include <stdio.h>

int times,t,n;

void solve(int p,int m)
{
    if(m==0)
    {
        if(p==t)
            times++;
        return;
    }
    if(p==1) solve(2,m-1);
    else if(p==n) solve(n-1,m-1);
    else
    {
        solve(p+1,m-1);
        solve(p-1,m-1);
    }
}

int main()
{
    int cas,p,m;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        times=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        solve(p,m);
        printf("%d\n",times);
    }
    return 0;
}
