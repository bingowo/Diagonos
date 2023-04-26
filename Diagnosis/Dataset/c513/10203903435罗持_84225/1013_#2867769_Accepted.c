#include <stdio.h>
#include <string.h>
char s[50] = {0};
int main(void)
{
	scanf("%s",s);
	int len = strlen(s);
	int idx = 0;
	long long a = 0;
	while(idx<len)
	{
		if(s[idx]=='.') break;
		long long add;
		if(s[idx]=='1') add = 1;
		else if(s[idx]=='0') add = 0;
		else if(s[idx]=='2') add = -1;
		a = a*3+add;
		idx++;
	}
	if(idx==len)
	{
		printf("%lld\n",a);
	}
	else
	{
		idx++;
		long long b = 0,c = 1;
		while(idx<len)
		{
			c *= 3;
			long long add;
			if(s[idx]=='1') add = 1;
			else if(s[idx]=='0') add = 0;
			else if(s[idx]=='2') add = -1;
			b = b*3+add;
			idx++;
		}
		if(a>0)
		{
			if(b>0)
			{
				printf("%lld %lld %lld\n",a,b,c);
			}
			else if(b==0) printf("%lld\n",a);
			else if(b<0)
			{
				b += c;
				a--;
				printf("%lld %lld %lld\n",a,b,c);
			}
		}
		else if(a==0)
		{
			printf("%lld %lld\n",b,c);
		}
		else if(a<0)
		{
			if(b>0)
			{
				b = c-b;
				a++;
				printf("%lld %lld %lld\n",a,b,c);
			} 
			else if(b==0) printf("%lld\n",a);
			else if(b<0)
			{
				b *= -1;
				printf("%lld %lld %lld\n",a,b,c);
			}
		}
	}
	return 0;
}