#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	char x[61];
	for (int i=0;i<T;i++){
		scanf("%s",x);
		int a[128],digit=0,N=1;
		char *p=x;
		for (int j=0;j<129;j++) a[j]=-1;
		a[*p]=1;
		while(*++p){
			if (a[*p]==-1){
				a[*p]=digit;
				digit=(digit==0)?2:digit+1;
				N++;
			}
		}	
		if (N<2) N=2;
		long long ans=0;
		p=x;
		while (*p) {
			ans=ans*N+a[*p++];
		}
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
}