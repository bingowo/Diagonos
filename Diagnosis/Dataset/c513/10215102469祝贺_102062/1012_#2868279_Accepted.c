#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100],ans[300]={0};int sp,p=0;
long long num()
{
	long long t=1,ans=0,sign=1;
	while(sp>=0 && s[sp]!='+' && s[sp]!='-')
	{
		ans+=(s[sp--]-'0')*t;
		t*=10;
	}
	if(sp>=0 && (s[sp]=='+' || s[sp]=='-'))
	{
		ans*=s[sp]=='-'?-1:1;
		sp--;
	}
	return ans;
}
int main()
{
	scanf("%s",s);
	sp=strlen(s)-1;
	long long r=0,v=0;
	if(s[sp]=='0' && sp==0)
		r=v=0;
	else if(s[sp]!='i')
		r=num();
	else
	{
		sp--;
		if(sp<0)
		{
			r=0;v=1;
		}
		else if(s[sp]=='+')
		{
			v=1;
			sp--;
			r=num();
		}
		else if(s[sp]=='-')
		{
			v=-1;
			sp--;
			r=num();
		}
		else
		{
			v=num();
			r=num();
		}
	}
	do
	{
		if(!(v%2)&&(r%2) || (v%2)&&!(r%2))//不同 
		{
			ans[p++]=1;
			r--;
		}
		else ans[p++]=0;
		long long t1=r,t2=v;
		r=(t2-t1)/2;v=(-t2-t1)/2;
	}while(r!=0 || v!=0);
	for(int i=p-1;i>=0;i--)
	{
		printf("%d",ans[i]); 
	}
	return 0;
}