#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int dp[2001]={0};
    int total[11]={0},id,j,n,a[11]={0},ans[1001]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        total[i]=total[i-1]+a[i];
    }
    dp[1000]++;dp[1000+a[1]]++;dp[1000-a[1]]++;
    for(int i=2;i<=n;i++)
    {
        for(int q=-total[i-1];q<=total[i-1];q++)
        {
            if(dp[1000-q])
            {
                dp[1000-q+a[i]]++;
                dp[1000-q-a[i]]++;
            }
        }
    }
    for(int i=1000-total[n];i<1000;i++)
    {
        if(dp[i])
        {
            ans[1000-i]=1;
        }
    }
    for(int i=1001;i<=1000+total[n];i++)
    {
        if(dp[i])
        {
            ans[i-1000]=1;
        }
    }
    for(int i=1;i<=total[n];i++)
    {
        if(ans[i])
            printf("1");
        else
            printf("0");
    }
    return 0;
}

