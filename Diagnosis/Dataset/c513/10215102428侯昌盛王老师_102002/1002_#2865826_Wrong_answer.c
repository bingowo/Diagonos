#include <stdio.h>
void h(char *s,int j)
{
	int a[128],i;
	for(i=0;i<128;i++) a[i]=-1;
	int digit=0,N=1;
	char *p=s;
	a[*p]=1;
	while(*++p) if(a[*p]==-1){a[*p]=digit;digit=digit?digit+1:2;N++;
	}
	if(N<2) N=2;
	long long int ans=0;
	p=s;
	while(*p) ans=ans*N+a[*p++];
	printf("case #%d\n",j);
	printf("%lld\n",ans);
}
int main()
{
	int t,i=0,j=0;

	scanf("%d",&t);
	for(i;i<t;i++)
	{
		char s[61];
		scanf("%s",s);
		h(s,j);
		j++;
	}
	return 0;
	
}