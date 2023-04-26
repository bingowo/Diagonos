#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n; 
LL stk[10005],top,X;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&X);top=0;
		if(X==0) stk[++top]=0;
		while(X) stk[++top]=X%2333,X/=2333;
		while(top) printf("%lld ",stk[top--]);
		puts("");
	}
	return 0;
}