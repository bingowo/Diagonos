#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T,n,m;
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		int cnt=0;
		scanf("%d%d",&n,&m);
		n^=m;
		while(n) cnt+=n%2,n/=2;
		printf("%d\n",cnt);
	}
	return 0; 
} 