#include <stdio.h>
#include <stdlib.h>
#define N 10007
#define M 1001

int f(int n,int m,int a, int b)
{ 
   static int dp[M][M]={1},i,j; 
   for (i=0;i<=n;i++) 
    for (j=0;j<=m;j++)
     if (i+j)
       if (i==0) 
           dp[i][j] = b*dp[i][j-1]%N;
       else if (j==0) 
           dp[i][j] = a*dp[i-1][j]%N;
       else 
           dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
    return dp[n][m];
}


int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        int re;
        re=f(n,m,a,b);
        printf("case #%d:\n%d\n",i,re);
    }
    return 0;

}
