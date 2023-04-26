#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
 

int main()
{
    int n,dp[21];
    dp[1]=2;
    dp[2]=4;
    dp[3]=7;
    dp[4]=7;
    for(int i=5;i<21;i++)
    {
        dp[i]=dp[i-1]*2-dp[i-2]+dp[i-3];
    }
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%d\n",dp[n]);
    }
    return 0;
}