#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long int work(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(n==4) return 8;
	else return work(n-1)+work(n-2)+work(n-3)+work(n-4);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int step;
		scanf("%d",&step);
		printf("case #%d:\n",v);
		long long a=work(step) ;
		printf("%lld\n",a);
	}
	return 0;
}