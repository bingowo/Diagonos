#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;

int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		printf("case #%d:\n%lld\n",c,1<<n);
	}
	return 0;
}