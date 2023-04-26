#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int j=0;j<T;j++)
	{
		char s[61]; 
		scanf("%s",s);
		int a[128];
		int digit=0,N=1,i; 
		for (i=0;i<128;i++) a[i]=-1;
		
		char *p=s; 
		a[*p]=1;
		while (*++p)
			if (a[*p]==-1)   
			{ a[*p]=digit; digit=digit?digit+1:2; N++;}
		if (N<2) N=2;
		long long ans=0;
		p=s; 
		printf("case #%d:\n",j);
		while (*p) ans=ans*N+a[*p++];
		printf("%lld\n",ans); 
	}
} 