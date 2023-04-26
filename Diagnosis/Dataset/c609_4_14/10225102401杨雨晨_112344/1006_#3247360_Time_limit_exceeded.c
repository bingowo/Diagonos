#include<stdio.h>
int change(char *s)
{	
	int i; 
	int a[128];for (i=0;i<128;i++)a[i]=-1;
	int digit=0,N=1;char *p=s;
	a[*p]=1;
	while (*p)
	if (a[*p]==-1)
	{a[*p]=digit;
	digit=digit?digit+1:2;
	N++;*p++;}
	if (N<2){N=2;}
	long long ans=0;
	p=s;while(*p)ans=ans*N+a[*p++];
	printf("%lld\n",ans);
}
int main()
{	int t,i;
	char a[100];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%s",&a);
	
		printf("case #%d:\n",i);
		change(a);
	}
}