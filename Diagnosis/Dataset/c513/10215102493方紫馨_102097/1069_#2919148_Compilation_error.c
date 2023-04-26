#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int reserve(int n){
	char a[15],t;
	itoa(n,a,10);
	for(int i=0,j=strlen(a)-1;i<j;i++,j--){
		t=a[i],a[i]=a[j],a[j]=t;
	}
	return atoi(a);
}
int main()
{
	int n,rn,cnt=0;
	scanf("%d",&n);
	rn = reserve(n);
	while(rn!=n){
		cnt++;
		n=rn+n;
		rn=reserve(n);
	}
	printf("%d %d",cnt,n);
	return 0;
}