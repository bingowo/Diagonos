#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[260];
long long rtoi(char* s,long long len,long long r)
{
	long long ret=table[s[0]];
	for(long long i=1;i<len;i++)
	{
		ret=ret*r+table[s[i]];
	}
	return ret;
}
int main()
{
	table['-']=-1;
	table['0']=0;
	table['1']=1;
	long long t;
	scanf("%lld",&t);
	for(long long m=0;m<t;m++)
	{
		int ans=0;char s[50];scanf("%s",s);
		ans=rtoi(s,strlen(s),3);
		printf("case #%d:\n%d\n",m,ans);
	}
	return 0;
}
