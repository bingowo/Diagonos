#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		char s[61];
		scanf("%s",s);
		int a[128];
		for(j=0;j<128;j++){
			a[j]=-1;
		}
		int digit=0,N=1,k;
		char *p=s;
		a[*p]=1;
		while(*++p){
			if(a[*p]==-1){
				a[*p]=digit;
				digit=digit?digit+1:2;
				N++;
			}
		}
		if(N<2)
			N=2;
		long long ret=0;
		p=s;
		while(*p){
			ret = ret*N+a[*p++];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ret);
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
	}
	return 0;
}