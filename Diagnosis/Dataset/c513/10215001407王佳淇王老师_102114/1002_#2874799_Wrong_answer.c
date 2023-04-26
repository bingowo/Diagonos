#include<stdio.h>
#include<math.h>
int main(){
	int T,i,j;
	char*p;
	char s[61];
	int a[128];
	for(j=0;j<128;j++) a[j]=-1;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%s",s);
		printf("case #");
		printf("%d",i);
		printf(":\n");
		int digit=0,N=1,k;
		p=s;
		a[*p]=1;
		while(*++p){
			if(a[*p]==-1){
				a[*p]=digit;
				digit=digit?digit+1:2;
				N++;	}
			}
			long long ans=0;
			if(N==1) ans=pow(2,N-1);
			else {	p=s;
				while(*p) ans=ans*N+a[*p++];}
		    printf("%lld\n",ans);
			
		} 
	return 0;
} 