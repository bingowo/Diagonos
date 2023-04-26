#include <stdio.h>

unsigned long long f(int n)
{
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	if(n==3){
		return 4;
	}
	if(n==4){
		return 8;
	}
	return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,n;
	for (i=0;i<T;i++){
		scanf("%d",&n);
		unsigned long long way=0;
		way=f(n);
		printf("case #%d:\n",i);
		printf("%llu\n",way);
	}
	return 0;
 } 