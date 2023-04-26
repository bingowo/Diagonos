#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int T,i,j,n,m,,k,dp[1111],type[4]={4,3,2,1};
dp[0]=1;
for(i=0;i<4;i++)
 { for(j=type[i];j<=1000;j++)
     {                                  
       dp[j]+=dp[j-type[i]];
     }
 }
  scanf("%d",&T);
  for(i=0;i<T;i++)
  { scanf("%d",&n);
     if(n==0) printf("0\n");
     else printf("%d\n",dp[n]);
  }
}