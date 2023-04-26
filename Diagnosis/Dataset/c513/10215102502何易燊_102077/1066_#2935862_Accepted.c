#include <stdio.h>

int t,n,cnt;

void method(int now,int step)
{
    if (step==0)
    {
        if (now==t) cnt++;
        return ;
    }
    if (now==1) method(2,step-1);
    else if (now==n) method(n-1,step-1);
    else {method(now+1,step-1); method(now-1,step-1);}
}

int main()
{
    int cas,p,m;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        cnt = 0;
        method(p,m);
        printf("%d\n",cnt);
    }
    return 0;
}