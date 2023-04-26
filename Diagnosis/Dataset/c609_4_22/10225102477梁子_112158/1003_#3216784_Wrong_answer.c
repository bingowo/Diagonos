#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(){
	int i=0;
	long long n;
	long long s[100];
	scanf("%lld",&n);
	while(n){
		s[i++]=n%2333;
		n=n/2333;
	} 
	int j;
	for(j=i-1;j>=0;j--){
		printf("%lld ",s[j]);
		
	}
     printf("%\n");
}

int main()
{
	int t;
	int i;
	scanf("%d\n",&t);
	for(;t>0;t--){
		solve();
	}
	return 0;
}
	