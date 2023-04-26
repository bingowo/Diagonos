#include <stdio.h>
int main()
{
    int M,N,i,j,k;
    scanf("%d %d",&M,&N);
    int a[200][200],dp[200][200] = {0};
    char s[401];
    for(i = 0;i<M;i++)
        {for(j = 0;j<N;j++)
        scanf("%d",&a[i][j]);}
   dp[0][0] = a[0][0];
   for(i = 1;i<N;i++)
   {
       dp[0][i] = a[0][i]+dp[0][i-1];
    }
   for(j = 1;j<M;j++)
   {
       dp[j][0] = a[j][0] +dp[j-1][0];
   }
   for(i = 1;i<M;i++)
   {
       for(j = 1;j<N;j++)
       {
       dp[i][j] = a[i][j] + (dp[i-1][j]<dp[i][j-1]?dp[i-1][j]:dp[i][j-1]);}
   }printf("%d\n",dp[M-1][N-1]);
   k = M+N-3;
   for(i = M-1,j = N-1;k>=0;)
   {if(i==0) {s[k--] = 'R';j--;}
   else if(j==0) {s[k--] = 'D';i--;}
   else
   {if(dp[i-1][j]>dp[i][j-1]) {s[k--] = 'R';j--;}
   else {s[k--] = 'D';i--;}}
   }
   s[M+N-2] = '\0';
   printf("%s",s);
    return 0;
}
