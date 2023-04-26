#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007
int T,n,m;
int hav[1005];
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		for(int i=0;i<m;i++) hav[i]=0;
		scanf("%d%d",&n,&m);
		printf("case #%d\n",c);
		printf("%d",n/m);
		n%=m;
		if(n==0) continue;
		putchar('.');
		int pos=0;
		while(n){
			if(hav[n]!=0){
				printf("\n%d-%d",hav[n],pos);
				break;
			}
			hav[n]=++pos;
			n*=10;
			printf("%d",n/m);
			n%=m;
		}
		puts("");
	}
	return 0;
}