#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
long long h(int x)
{
	long long ans=1;
	while(x)
	{
		ans*=10;x--;
	}
	return ans;
}
long long g(int x)
{
	char s[15];int i=0;
	while(x)
	{
		s[i++]=x%10+'0';
		x/=10;
	}
	long long ans=0;
	for(int j=0;j<i;j++)
	{
		ans=ans*10+(s[j]-'0');
	}
	return ans;
}
long long f(int x)
{
	char s[15];int i=0;
	while(x)
	{
		s[i++]=x%10+'0';
		x/=10;
	}
	for(int j=0;j<i/2;j++)
	{
		if(s[j]!=s[i-1-j]) return -1;
	}
	return 1;
}
int main()
{
	long long x;
	scanf("%lld",&x);
	int num=0;
	while(f(x)==-1)
	{
		x+=g(x);
		num++;
	}
	printf("%d %lld",num,x);
}