#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	int n,a,b;//
	long long up=0,down=1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d/%d",&a,&b);
		up=up*b+a*down;
		down*=b;
		long long GCD=gcd(up,down);
		up/=GCD;down/=GCD;
	}
	printf("%lld/%lld",up,down);
	return 0;
} 