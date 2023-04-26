#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char num[100];
long long rtoi(char* s,long long len,long long r)
{
	long long ret=s[0];
	for(int i=1;i<len;i++)
	{
		ret=ret*r+s[i];
	}
	return ret;
}
int main()
{
	for(int i=0;i<=9;i++)
	{
		num[i]='-';
	}
	for(int i='a';i<='z';i++)
	{
		num[i]='-';
	}
	for(int i='A';i<='Z';i++)
	{
		num[i]='-';
	}
	
	long long t;
	scanf("%lld",&t);
	for(long long m=0;m<t;m++)
	{
		char ans[60];scanf("%s",ans);
		int index=0,minnum=0;
		long long ret,len=strlen(ans);
		printf("%s\n",ans);
		while(ans[index]!=0)
		{
			int al=ans[index];
			if(index==0)
			{
				num[al]=1;
				ans[index]=num[al];
			}
			if(num[al]!='-')
			{
				ans[index]=num[al];
			}
			if(num[al]=='-')
			{
				if(minnum==1)minnum++;
				ans[index]=minnum;
				num[al]=minnum;minnum++;
			}
			index++;
		}
		if(minnum==0)ret=rtoi(ans,len,2);
		else ret=rtoi(ans,len,minnum);
		printf("case #%d:\n%lld\n\n",m,ret);
		
	}
	return 0;
}