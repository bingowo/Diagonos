#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
long long c,d;
void cal(long long a,long long b,long long r)
{
	c = (-1)*(a+b)+r;
	d = a-b;
}
int main(void)
{
	char num[100];
	scanf("%s",num);
	long long a = 0,b = 0;
	int len = strlen(num);
	for(int i=2;i<len;i++)
	{
		int mask = 8;
		int val;
		if(isdigit(num[i])) val = num[i]-'0';
		else val = num[i]-'A'+10;
		while(mask)
		{
			if(mask & val)
			{
				c = 0,d = 0;
				cal(a,b,1LL);
				a = c,b = d;
			}
			else
			{
				c = 0,d = 0;
				cal(a,b,0LL);
				a = c,b = d;
			}
			mask >>= 1;
		}
	}
	if(a==0)
	{
		if(b==0) printf("0");
		else if(b==-1) printf("-i");
		else if(b==1) printf("i");
		else if(b>0) printf("%lldi",b);
		else if(b<0) printf("%lldi",b);
	}
	else 
	{
		printf("%lld",a);
		if(b==0) ;
		else if(b==-1) printf("-i");
		else if(b==1) printf("+i");
		else if(b>0) printf("%+lldi",b);
		else if(b<0) printf("%lldi",b);
	}
	return 0;
}