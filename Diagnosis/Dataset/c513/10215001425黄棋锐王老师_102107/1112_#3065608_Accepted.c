#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 200


int main() 
{ 	int T;
	scanf("%d\n",&T);
	int dp[5][1002]={0};
	int type[4]={4,3,2,1};
	int i=0,j=0,k=0,sum=0;
	for(i=0;i<=4;i++) dp[i][0]=1;
	for(i=1;i<=4;i++)//用到的钱币种数,1-4;2-4、3; 3-4、3、2; 4-4、3、2、1 
		for(sum=1;sum<=1000;sum++)// 目标的钱币总量 
			for(j=0;j<=sum/type[i-1];j++)//系数循环
				dp[i][sum]+=dp[i-1][sum-j*type[i-1]]; 
	while(T--)
{	
	int n;
	scanf("%d",&n);
	printf("%d\n",dp[4][n]);
	
}


    return 0;
}
