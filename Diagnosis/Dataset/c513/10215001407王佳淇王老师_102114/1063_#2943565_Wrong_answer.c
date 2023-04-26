#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
unsigned long long int work(long long x,long long y){
	long long int L=fmax(x,y);
	long long int S=fmin(x,y);
	long long int M=L-S;
	long long int sum=0;
	if(S==1) return 4*L;
	else if(L%S==0) return L%S*4*S;
	while(L!=S){
		sum+=4*fmin(L,S);
		L=fmax(M,S);
		S=fmin(M,S);
		M=L-S;
	}
	/*sum+=4*L;*/
	return sum;
}
int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	printf("%llu ",work(x,y));
	return 0;
}