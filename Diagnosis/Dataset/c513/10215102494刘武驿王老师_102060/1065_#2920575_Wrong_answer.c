#include<stdio.h>
struct pos
{
    int k;
    int uk;
};
int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    struct pos dp[30];
    struct pos up[30];
    struct pos down[30];
    dp[1].k=a;
    dp[2].k=a;
    dp[1].uk=0;
    dp[2].uk=0;
    up[1].k=a;
    up[1].uk=0;
    up[2].k=0;
    up[2].uk=1;
    down[1].k=0;
    down[1].uk=0;
    down[2].k=0;
    down[2].uk=1;
    for(int i=3;i<n;i++)
    {
        up[i].k=up[i-1].k+up[i-2].k;
        up[i].uk=up[i-1].uk+up[i-2].uk;
        down[i].k=up[i-1].k;
        down[i].uk=up[i-1].uk;
        dp[i].k=up[i].k-down[i].k;
        dp[i].uk=up[i].uk-down[i].uk;
    }
    int unk=m-dp[n-1].k;
    unk/=dp[n-1].uk;
    printf("%d",dp[x].k+unk*dp[x].uk);
}
