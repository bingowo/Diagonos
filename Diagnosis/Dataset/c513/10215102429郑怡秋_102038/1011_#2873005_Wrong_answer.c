#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	long long n;
	scanf("%x",&n);
	long long a=0,b=0,aa;
	int i=0,r;
	while((n>>i)) i++;
	i--;
	while(i>=0)
	{
		r=(n>>i)&1;
		aa=a;
		a=r-aa-b;
		b=aa-b;
		i--;
	}
	if(a==0) printf("%lldi",b);
	else if(b==0) printf("%lld",a);
	else if(b==1) printf("%lld+i",a);
	else if(a>0&&b>0 ||(a<0&&b>0)) printf("%lld+%lldi",a,b);
	else if(a<0&&b<0 ||(a>0&&b<0)) printf("%lld%lldi",a,b);
	
	return 0;
}