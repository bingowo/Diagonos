#include<stdio.h>
#include<string.h>
int main()
{
	int total,cnt=0;
	scanf("%d",&total);
	char s[61];
	while(cnt<total)
	{
		scanf("%s",s);
		int digit=0,N=1,i;char *p=s;
		int a[128];for(int i=0;i<128;i++)a[i]=-1;
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
		cnt++;
	}
	return 0;
}