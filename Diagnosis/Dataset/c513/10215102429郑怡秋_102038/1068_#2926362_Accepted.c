#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
unsigned long long f(int n,int m)
{
	if(m>n) return 0;
	if(m==n) return 1;
	else if(m==1) return (1<<n)-1;
	return f(n-1,m)*2+(1<<(n-m-1))-f(n-m-1,m);
}
int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1)
	{
		unsigned long long ans=f(n,m);
		printf("%llu\n",ans);
	}
	return 0;
}