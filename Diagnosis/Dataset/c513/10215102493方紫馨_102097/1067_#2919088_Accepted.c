#include<stdio.h>
int main()
{
	int N,n;
	scanf("%d",&N);
	long long int T[75];
	T[0]=0,T[1]=1,T[2]=1;
	for(int i=3;i<=74;i++){
		T[i]=T[i-1]+T[i-2]+T[i-3];
	}
	for(int i=0;i<N;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",T[n]);
	}
	return 0;	
}