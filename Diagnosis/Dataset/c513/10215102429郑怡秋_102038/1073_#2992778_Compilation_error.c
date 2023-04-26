#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long n2t(long long a)
{
	return (a<9)?a:n2t(a/10)*9+a%10;
}
long long f(long long a)
{
	long long d=a%10;
	for(long long x=a-d;x<=a;x++)
	{
		char s[100]={0};
		sprintf(str,"%lld",x);
		if(x%9==0||strchr(str,'9')!=0) d--;
	}
	return d+8*n2t(a-a%10)/9;
	
}

int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	
	printf("%lld\n",f(a)-f(b)-1);
	return 0;
}