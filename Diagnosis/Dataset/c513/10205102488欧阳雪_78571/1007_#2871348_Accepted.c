#include <stdio.h>
#include <stdlib.h>
int maxstring(long long int n)
{
	int a=n%2,b;
	int cnt=1;
	int temp=1;
	while(n)
	{
		if(cnt>temp) temp=cnt;
		n/=2;
		b=n%2;
		if(a!=b) 
		{
			cnt++;
		}
		else
		{
			cnt=1;
		}
		a=b;
	}
	return temp;
}
int main()
{
	int T;
	int i;
	long long int n;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%lld",&n);
		printf("case #%d:\n",i);
		printf("%d\n",maxstring(n));
	}
}