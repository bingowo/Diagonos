#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int dp[1005]={0};
    int a[4]={1,2,3,4};
    dp[0]=1;
    for(int i=0;i<4;i++)
    {
        for(int j=a[i];j<=1000;j++)
            dp[j]+=dp[j-a[i]];
    }
     int n;
     scanf("%d",&n);
     while(n--)
     {
         int t;
         scanf("%d",&t);
         printf("%d\n",dp[t]);
     }
}
