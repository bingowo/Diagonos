#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long sim(long long s,long long i)
{
	long long c;
	if(s<i)
	{
		c=s;s=i;i=c;
	}
	while((c=s%i)!=0)
	{
		s=i;i=c;
	}
	return i;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	char c;if((c=getchar())==' '||c=='\n');
	for(long long m=0;m<t;m++)
	{
		
		char s[250];int sum=0;
		fgets(s,250,stdin);
		int i=0;
		for(;s[i]!='\n';i++)
		{
			for(int j=0;j<8;j++)
			{
				if(((s[i]>>j)&1)==1)sum++;
			}
		}
		int a=sim(sum,8*i);
		printf("%d/%d\n",sum/a,8*i/a);
	}
	return 0;
}