#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long n;
int solve(long long x){
	double fra,res,ans;
	fra=modf(log10(x)*x,&ans);
	res=pow(10,fra);
	modf(res,&ans);
	return (int)ans;
}
int main(){
	while(~scanf("%lld",&n)){
		if(n==0) break;
		printf("%d\n",solve(n));
	}
	return 0;
}