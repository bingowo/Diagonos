#include<stdio.h>
#include<string.h>
typedef long long ll;
ll mypow(int n,int p)
{
	ll sum=1;
	for(int i=0;i<p;i++)sum*=n;
	return sum;
}
ll GCD(ll a,ll b){return a%b?GCD(b,a%b):b;}

int main()
{
	char s[1005];scanf("%s",s);
	if(strchr(s,'.')==0)
	{
		ll sum=0;
		int i=strlen(s)-1;
		int length=strlen(s)-1;
		for(i;i>=0;i--)
		{
			if(s[i]=='2')sum-=mypow(3,length-i);
			else if(s[i]=='1')sum+=mypow(3,length-i);
		}
		printf("%lld",sum);
		return 0;
	}
	else
	{
		int i=0,pos;
		int length=strlen(s);
		for(i;i<length;i++)if(s[i]=='.')break;
		pos=i;
		ll sum;i--;
		for(i;i>=0;i--)
		{
			if(s[i]=='2')sum-=mypow(3,pos-1-i);
			else if(s[i]=='1')sum+=mypow(3,pos-1-i);
		}
		ll mole,deno;
		deno=mypow(3,length-1-pos);
		if(s[length-1]=='2')mole=-1;
		else if(s[length-1]=='1')mole=1;
		else mole=0;
		for(i=pos+1;i<length;i++)
		{
			if(s[i]=='2')mole-=mypow(3,length-1-i);
			else if(s[i]=='1')mole+=mypow(3,length-1-i);
		}
		if(mole==0)
		{
			printf("%lld",sum);
			return 0;
		}
		else if(sum>0&&mole>0)
		{
			ll div=GCD(mole,deno);
			mole/=div;
			deno/=div;
			printf("%lld %lld %lld",sum,mole,deno);
			return 0;			
		}
		else if(sum<0&&mole<0)
		{
			mole*=-1;
			ll div=GCD(mole,deno);
			mole/=div;
			deno/=div;
			printf("%lld %lld %lld",sum,mole,deno);
			return 0;
		}
		else if(sum>0&&mole<0)
		{
			sum-=1;mole=deno+mole;
			ll div=GCD(mole,deno);
			mole/=div;
			deno/=div;
			printf("%lld %lld %lld",sum,mole,deno);
			return 0;		
		}
		else if(sum<0&&mole>0)
		{
			sum+=1;mole=deno-mole;
			ll div=GCD(mole,deno);
			mole/=div;
			deno/=div;
			printf("%lld %lld %lld",sum,mole,deno);
			return 0;		
		}
		
	}
}