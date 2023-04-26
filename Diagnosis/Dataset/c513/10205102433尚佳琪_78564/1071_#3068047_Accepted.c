#include <stdio.h>
#include <stdlib.h>
#define P 10007
int dp[1003][1003]={0};
int f(int n,int m,int a,int b)
{

   if(dp[n][m]!=0)return dp[n][m];
   if(n==0&&m==0)return dp[n][m]=1;
   if(m==0)
       return dp[n][m]=(a%P*f(n-1,m,a,b))%P;
   else if(n==0)
      return  dp[n][m]=(b%P*f(n,m-1,a,b))%P;
   else
      return  dp[n][m]=(a%P*f(n-1,m,a,b)%P+b%P*f(n,m-1,a,b))%P;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        for(int i=0;i<=k;i++)
            for(int j=0;j<=k;j++)
                dp[i][j]=0;
        printf("%d\n",f(n,m,a,b));
    }
}