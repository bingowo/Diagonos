#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char chr[55];
long long num[256];
int main()
{
	long long ans=0,x=1,last=0;
	num['I']=1;num['V']=5;num['X']=10;num['L']=50;num['C']=100;num['D']=500;num['M']=1000;
	scanf("%s",chr);
	int L=strlen(chr);
	chr[L]=0;
	long long curr=0;
	for(int i=L-1;i>=0;i--)
	{
		if(chr[i]==')')
		{
			x*=1000;
		}
		else if(chr[i]=='('&&chr[i+1]!='(')
		{
			if(curr*x<last){ans-=curr*x;last=-1;}
			else{last=curr*x;ans+=last;}
			x=1;curr=0;
		}
		else
		{
			if(x!=1)
			{
				if(num[chr[i]]<last&&chr[i+1]!=')')curr-=num[chr[i]];
				else curr+=num[chr[i]];
				last=num[chr[i]];
				continue;
			}
			if(num[chr[i]]<last)ans-=num[chr[i]];
			else ans+=num[chr[i]];
			last=num[chr[i]];
		}
	}
	printf("%lld",ans);
	return 0;
}