#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
long long c,d;
void cal(long long a,long long b,long long r)
{
	c = (r-a+b)/2;
	d = (r-a-b)/2;
}
int main(void)
{
	char s[100];
	scanf("%s",s);
	long long a = 0,b = 0;
	int len = strlen(s);
	if(s[len-1]!='i')
	{
		a = atoll(s);
		b = 0;
	}
	else
	{
		int a1=0,a2=0,b1=0,b2=0;
		b2 = len-1;
		b1 = b2-1;
		while(b1>=0)
		{
			if(!isdigit(s[b1])) break;
			b1--;
		}
		char sb[40];
		strncpy(sb,s+b1,b2-b1);
		b = atoll(sb);
		if(b==0) b=1;
		if(b1==0) a=0;
		else
		{
			a2 = b1-1;
			char sa[40];
			strncpy(sa,s,a2+1);
			a = atoll(sa);
		}
	}
	//scanf("%lld %lld",&a,&b);
	//printf("%lld %lld\n",a,b);
	int res[100];
	int length = 0;
	while(!(a==0 && b==0))
	{
		if((a&1)!=(b&1))
		{
			res[length] = 1;
			c = 0,d = 0;
			cal(a,b,1);
			a = c,b = d;
		}
		else 
		{
			res[length] = 0;
			c = 0,d = 0;
			cal(a,b,0);
			a = c,b = d;
		}
		length++;
	}
	for(int i=length-1;i>=0;i--) printf("%d",res[i]);
	return 0;
}