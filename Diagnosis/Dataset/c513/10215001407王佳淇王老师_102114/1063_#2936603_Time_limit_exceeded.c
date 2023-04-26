#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
long long int work(long long x,long long y){
	long long int L=fmax(x,y);
	long long int S=fmin(x,y);
	long long int M=L-S;
	long long int sum=0;
	while(L!=S){
		sum+=4*fmin(L,S);
		L=fmax(M,S);
		S=M;
		M=L-S;
	}
	sum+=4*L;
	return sum;
}
int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	printf("%lld ",work(x,y));
	return 0;
}