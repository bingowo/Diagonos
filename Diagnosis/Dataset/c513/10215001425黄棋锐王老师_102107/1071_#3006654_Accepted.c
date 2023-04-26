#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  
int f(int a,int b,int n,int m)
{  int dp[1002][1002]={1},i,j;
   int N=10007;
	for(i=0;i<=n;i++)
	 {for(j=0;j<=m;j++)
	   { 
	   if(i+j)
	     {
	   		 if(i==0) dp[0][j]=b*dp[0][j-1]%N;
	   	   	else if(j==0) dp[i][0]=a*dp[i-1][0]%N;
	  		else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
         }
	   }
	 }
	return dp[n][m];
}
int main()
{    int i,T;
	scanf("%d\n",&T);
	for(i=0;i<T;i++)
	{	int a,b,k,n,m;
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
		a%=10007;b%=10007;
		int ant=f(a,b,n,m);
		printf("case #%d:\n",i);
		printf("%d\n",ant);
	}
}