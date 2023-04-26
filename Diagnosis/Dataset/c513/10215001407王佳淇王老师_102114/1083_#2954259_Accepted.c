#include<stdio.h>
int work(int n)
{
	if(n<5) return 0;
	else
	{
		n/=5;
		return n+work(n);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		printf("case #%d:\n",v);
		int n;
		scanf("%d",&n);
		printf("%d\n",work(n));
		
	}
	return 0;
}