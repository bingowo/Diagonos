#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
long long k[25][2];
long long pow(int x){
	long long a=1;
	for(int i=0;i<x;i++)a*=2;
	return a;
}
int main()
{	
	k[1][0]=0,k[1][1]=0;
	k[2][0]=0,k[2][1]=0;
	k[3][0]=1,k[3][1]=1;
	for(int i=4;i<=20;i++){
		k[i][0]=2*k[i-1][0]+pow(i-3)-k[i-2][1];
		k[i][1]=k[i-1][0]+pow(i-3)-k[i-2][1];
	}
	int x;scanf("%d",&x);
	while(x!=-1){
		printf("%lld\n",pow(x)-k[x][0]);
		scanf("%lld",&x);
	}
	return 0;
}