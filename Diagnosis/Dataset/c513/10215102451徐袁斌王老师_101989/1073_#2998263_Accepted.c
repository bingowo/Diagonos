#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int f(long long int a)
{
	return (a<9)?a:f(a/10)*9+a%10;
}
long long int g(long long int a)
{
	int b=a%10;
	for(long long int i=a-b;i<=a;i++)
	{
        char str[100] = {0};
        sprintf(str,"%lld",i);
        if(i%9==0||strchr(str,'9')!=0) b--;
	}
	return b+8*f(a-a%10)/9;
}
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",g(b)-g(a)+1);
	return 0;
}