#include<stdio.h>
#include<string.h>


void solve(int n,int m)
{
	if(n == 0)
		return;
	int r = n % m;
	if(r < 0)
	{
		r = r - m;
		solve(n/m+1,m);
	}
	else
	{
		solve(n/m,m);
	}
	if(r >= 10)
		r='A' + r - 10;
	else
		r = r + '0';
	printf("%c",r);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	solve(n,m);
}

