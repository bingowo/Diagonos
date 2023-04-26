#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
unsigned long long fb[25]={0,1,1};
typedef struct{
	unsigned long long a,b;
}pair;


int main()
{	
	int a,n,m,x;scanf("%d%d%d%d",&a,&n,&m,&x);
	for(int i=3;i<=n;i++){
		fb[i]=fb[i-1]+fb[i-2];
	}
	pair dp[23]={{0,0},{1,0},{1,0},{2,0},{2,1},{3,2}};
	for(int i=6;i<=n;i++){
		dp[i].a=dp[i-1].a+fb[i-4];
		dp[i].b=dp[i-1].b+fb[i-3];
	}
	
	long long b=(m-dp[n-1].a*a)/dp[n-1].b;
	printf("%llu",dp[x].a*a+dp[x].b*b);
	return 0;
}