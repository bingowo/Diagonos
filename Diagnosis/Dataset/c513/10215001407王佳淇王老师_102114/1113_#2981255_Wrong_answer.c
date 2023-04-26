#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[200]={0};
	int k,n;
	scanf("%d %d",&k,&n);
	a[9]=1;
	for(int l=10;l<n+8;l++)
	for(int j=1;j<=k;j++)
	a[l]+=a[l-j];
	printf("%d",a[n+7]);
	return 0;
	
	
}