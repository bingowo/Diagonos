#include<stdio.h>
#include<string.h>
int main()
{
	int total;
	scanf("%d",&total);
	for(int cnt=0;cnt<total;cnt++)
	{
		char s[61];
		int a[128];
		scanf("%s",s);
		for(int i=0;i<128;i++)a[i]=-1;
		int digit=0,N=1;char *p=s;
		a[*p]=1;
		while(*++p)
		{
			if(a[*p]==-1)
			{
				a[*p]=digit;
				digit=digit?digit+1:2;
				N++;
			}
		}
		if(N<2)N=2;
		long long ans=0;
		p=s;while(*p)ans=ans*N+a[*p++];
		printf("%lld\n",ans);
	}
	return 0;
}