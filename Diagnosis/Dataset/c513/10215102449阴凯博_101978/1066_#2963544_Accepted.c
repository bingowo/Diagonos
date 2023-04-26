#include <stdio.h>
#include <stdlib.h>

int sum=0;
int n,p,m,t;

void dfs(int a,int cnt)
{
    if (a==t && cnt==m)
    {
        sum++;
        return;
    }
    if (cnt>m) return ;
    if (a==1)
    {
        dfs(a+1,cnt+1);
    }
    else if (a==n)
    {
        dfs(a-1,cnt+1);
    }
    else
    {
        dfs(a+1,cnt+1);
        dfs(a-1,cnt+1);
    }
}

int main()
{
    int cas;
    scanf("%d",&cas);
    for (int i=0;i<cas;i++)
    {
        sum=0;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        dfs(p,0);
        printf("%d\n",sum);
    }
    return 0;
}
