#include<stdio.h>

int a[1100],b[1100],c[1100],book[1100];
int n=0;
long long ans=1000000,t=0;

void dfs(int step)
{
    int i;
    if (step == n + 1)
    {
        for (i = 1; i <= n; i++)
        {
            t+=a[i-1]*b[c[i]-1];
        }
        ans=ans<t?ans:t;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {
            c[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        dfs(1);
        printf("case #%d:\n",t);
        printf("%lld",ans);
    }
    return 0;
}
