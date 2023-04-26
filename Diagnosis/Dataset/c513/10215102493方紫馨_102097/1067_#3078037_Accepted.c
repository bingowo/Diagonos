#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	long long T[74];
	T[0]=0;
	T[1]=1;
	T[2]=1;
	for(int i=3;i<74;i++){
		T[i]=T[i-1]+T[i-2]+T[i-3];
	}
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		printf("case #%d:\n",i);
		printf("%lld\n",T[t]);
	}
	return 0;
}