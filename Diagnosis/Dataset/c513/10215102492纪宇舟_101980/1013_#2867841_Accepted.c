#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char chr[35];
long long GCD(long long a,long long b)
{
	if(b==0)return a;
	return GCD(b,a%b);
}
int main()
{
	scanf("%s",chr);
	long long itg=0,up=0,down=1,tri;
	int flag=0,n=strlen(chr);
	for(int i=0;i<n;i++)
	{
		if(chr[i]=='.'){flag=1;continue;}
		if(chr[i]=='2')tri=-1;
		else tri=chr[i]-'0';
		if(flag)
		{
			up=up*3+tri;
			down*=3;
			continue;
		}
		itg=itg*3+tri;
	}
	if(!flag)printf("%lld",itg);
	else
	{
		int sig=0;
		if(up<0){up=-up;++sig;}
		if(down<0){down=-down;++sig;}
		long long gcd=GCD(up,down);
		up/=gcd;down/=gcd;
		if(sig==1)up=-up;
		up+=itg*down;
		if(up<0)
		{up=-up;printf("-");}
		gcd=GCD(up,down);
		up/=gcd;down/=gcd;
		if(up/down>0)printf("%lld ",up/down);
		printf("%lld %lld",up%down,down);
	}
	return 0;
}