#include <stdio.h>
#include <string.h> 
long long N2T(long long a)
{
	return (a<9)?a:N2T(a/10)*9+a%10;
}

long long int f(long long int a)
{
	long long d0=a%10;
	long long x;
	for(x=a-d0;x<=a;x++)
	{
		char str[100]={0};
		sprintf(str,"%lld",x);
		if(x%9==0||strchr(str,'9')!=0) d0--;
	}
	return d0+8*N2T(a-a%10)/9;
}

int main()
{
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",f(b)-f(a)+1);
	return 0;
}