#include<stdio.h>

unsigned long long int dp[75]={0};
unsigned long long int tri(int n)
{
    unsigned long long int ans;
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        unsigned long long int a,b,c;
        if(dp[n-1]!=0)
        {
            a = dp[n-1];
        }
        else{a = tri(n-1);}
        if(dp[n-2]!=0)
        {
            b = dp[n-2];
        }
        else{b = tri(n-2);}
        if(dp[n-3]!=0)
        {
            c = dp[n-3];
        }
        else{c = tri(n-3);}
        ans = a+b+c;
        dp[n] = ans;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        unsigned long long int ans;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        ans = tri(n);
        printf("%llu\n",ans);
    }
    return 0;
}
