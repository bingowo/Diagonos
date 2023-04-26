#include<stdio.h>
int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    long long int deep1=((b-b%10)-(a-a%10))/10;
	long long int a1=a,b1=b;
	while(a1%9!=0)
	{
		a1=a1+1;
	}
	while(b1%9!=0)
	{
		b1=b1-1;
	}
	long long int deep2=(b1-a1)/9+1; 
	long long int t=b-a+1-deep1-deep2;
    printf("%lld",t);
    return 0;
}