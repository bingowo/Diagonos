#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
long long gcd(long long x,long long y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
int main()
{
	char s[20];
	int T,ct=0;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		long long pre=0,pretimes=0,tol=0,toltimes=0;
		int point=0,flag=0,len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]==']')break;
			if(s[i]=='.'){point=1;continue;}
			if(s[i]=='['){flag=1;pre=tol;pretimes=toltimes;continue;}
			tol=tol*10+s[i]-'0';
			if(point)toltimes++;
		}
		long long x=tol-pre,t1=1,t2=1,y;
		for(int i=1;i<=pretimes;i++)t1*=10;
		for(int i=1;i<=toltimes;i++)t2*=10;
		if(flag==0)t1=0;
		y=t2-t1;
		//printf("fuck %lld %lld\n",x,y);
		long long GCD=gcd(x,y);
		x/=GCD;y/=GCD;
		printf("case #%d:\n%lld/%lld",ct++,x,y);
		if(T)printf("\n");
	}
	return 0;
}