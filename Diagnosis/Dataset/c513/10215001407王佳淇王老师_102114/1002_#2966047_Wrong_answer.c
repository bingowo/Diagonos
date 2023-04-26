#include<stdio.h>
int main(){
	long long int T,i,j;
	char*p;
	char s[61];
	long long int a[128];
	for(j=0;j<128;j++) a[j]=-1;
	scanf("%lld",&T);
	for(i=0;i<T;i++){
		scanf("%s",s);
		printf("case #%d:\n",i);
		int digit=0,N=1,k;
		p=s;
		a[*p]=1;
		while(*++p){
			if(a[*p]==-1){
				a[*p]=digit;
				digit=digit?digit+1:2;
				N++;	}
			}
			if(N<2) N=2;
				long long ans=0;
				p=s;
				while(*p) ans=ans*N+a[*p++];
				printf("%lld\n",ans);
			
		} 
	return 0;
} 