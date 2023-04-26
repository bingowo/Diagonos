#include<stdio.h>
#include<stdlib.h>
int main(){
	unsigned long long int a[200]={0};
	int k,n;
	scanf("%d %d",&k,&n);
	a[9]=1;
	for(unsigned long long int l=10;l<n+8;l++)
	for(unsigned long long int j=1;j<=k;j++)
	a[l]+=a[l-j];
	printf("%llu",a[n+7]);
	return 0;
	
	
}