#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	long long int number[205][205],sum[205][205];
    long long int n,m,k,result,count=0,i,j,z;
	scanf("%lld%lld%lld",&n,&m,&k);  //记录矩阵
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)scanf("%lld",&number[i][j]);
	}   
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			sum[i][j]=sum[i-1][j]+number[i][j];  //计算每一列的总和 
		}
	}
	count=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			result=number[i][j];
			//向右向下
			for(z=1;i+z<=n && j+z<=m;z++){
				result+=(sum[i+z][j+z]-sum[i-1][j+z]);
				if(result>=k)count++;
			} 
			result=number[i][j];
			//向右向上
			for(z=1;i-z>=1 && j+z<=m;z++){
				result+=(sum[i][j+z]-sum[i-z-1][j+z]);
				if(result>=k)count++;
			}
			result=number[i][j];
			//向左向下
			for(z=1;i+z<=n && j-z>=1;z++){
				result+=(sum[i+z][j-z]-sum[i-1][j-z]);
				if(result>=k)count++;
			} 
			result=number[i][j];
			//向左向上
			for(z=1;i-z>=1 && j-z>=1;z++){
				result+=(sum[i][j-z]-sum[i-z-1][j-z]);
				if(result>=k)count++;
			} 
		}
	}
	printf("%lld\n",count);
	return 0; 
}