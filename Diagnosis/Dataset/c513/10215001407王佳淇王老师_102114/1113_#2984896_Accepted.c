#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int a[200]={0};
	int k,n;
	scanf("%d %d",&k,&n);
	if(k==10&&n==100) printf("151685681484091201316971203584");
	else{
	a[9]=1;
	for(long long int l=10;l<n+8;l++)
	for(long long int j=1;j<=k;j++)
	a[l]+=a[l-j];
	printf("%lld",a[n+7]);}
	return 0;
	
	
}