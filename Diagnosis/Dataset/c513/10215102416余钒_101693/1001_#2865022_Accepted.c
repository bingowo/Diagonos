#include<stdio.h>
int T;
void out(long long n,long long r){
	if(n<r){
		if(n>9) printf("%c",'A'+n-10);
		else printf("%lld",n);
		return;
	}
	out(n/r,r);
	long long tmp=n%r;
	if(tmp>9) printf("%c",'A'+tmp-10);
	else printf("%lld",tmp);
	return;
}
int main(){
	long long n,r; 
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&r);
		if(n<0) printf("-"),out(-n,r);
		else out(n,r);
		puts("");
	}
	return 0;
} 