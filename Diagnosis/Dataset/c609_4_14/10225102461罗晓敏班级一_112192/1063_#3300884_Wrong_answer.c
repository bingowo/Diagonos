#include<stdio.h>
long long int num[50];
int main(){
	int t,i;scanf("%d",&t);
	num[0]=1;num[1]=2;num[2]=4;num[3]=8;
	for(i=4;i<50;i++){
	    num[i]=num[i-4]+num[i-3]+num[i-2]+num[i-1];
	}
	for(i=0;i<t;i++){
		int n;scanf("%d",&n);
		printf("%lld",num[n-1]);
	}
}