#include<stdio.h>
void solve(long long n,long long r)
{
	if(n==0)return;
	else
	{
		solve(n/r,r);
		if(n%r>9)
			printf("%c",n%r+'A'-10);
		else printf("%d",n%r);
	}
}
int main()
{
	long long t,n,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&r);
		if(n<0)
		{
			printf("%c",'-');n=-n;
		}
		if(n==0)printf("%d",0);
		solve(n,r);
		printf("\n");
	}
	return 0;
}