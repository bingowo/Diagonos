#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int m;
int dp[32]={0};
int count(int n);
int main()
{
   int n;
   do
   {
       scanf("%d %d",&n,&m);
       if(m!=-1&&n!=-1)
       {
        int i=0;
        for(;i<32;i++){dp[i]=-1;}
        int res=(int)pow(2.0,n*1.0)-count(n);
        printf("%d\n",res,count(n));
       }
   }while(m!=-1&&n!=-1);
    return 0;
}
int count(int k)
{
    int j=0;
    if(dp[k]!=-1){return dp[k];}
    else
    {
         if(k<m){dp[k]=(int)pow(2.0,k*1.0);return dp[k];}
         else if(k==m){dp[k]=(int)pow(2.0,k*1.0)-1;return dp[k];}
         else
         {
             dp[k]=0;
             for(j=0;j<m;j++){dp[k]=dp[k]+count(k-j-1);}
         }
         return dp[k];
    }
}
