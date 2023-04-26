#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long max(long long a,long long b){
	if(a>=b) return a;
	else return b;
	
}
long long min(long long a,long long b){
	if(a<=b) return a;
	else return b;
	
}
unsigned long long int work(long long x,long long y){
	long long int L=max(x,y);
	long long int S=min(x,y);
	long long int M=L-S;
	long long int sum=0;
	if(S==1) return 4*L;
	else if(L%S==0) return L/S*4*S;
	while(L!=S){
		sum+=4*min(L,S);
		L=max(M,S);
		S=min(M,S);
		M=L-S;
	}
	sum+=4*L;
	return sum;
}
int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	printf("%llu ",work(x,y));
	return 0;
}