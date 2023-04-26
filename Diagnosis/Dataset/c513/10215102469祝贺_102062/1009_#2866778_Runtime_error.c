#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sim(int sum,int i)
{
	do
	{
		if(i<sum)
		{
			int temp=i;i=sum;sum=temp;
		}
		i=i%sum;
	}while(i!=0);
	return sum;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	char c;if((c=getchar())==' '||c=='\n');
	for(long long m=0;m<t;m++)
	{
		
		char s[120];int sum=0;
		fgets(s,120,stdin);
		int i=0;
		for(;s[i]!='\n';i++)
		{
			for(int j=0;j<8;j++)
			{
				if((s[i]>>j)&1)sum++;
			}
		}
		int a=sim(sum,8*i);
		printf("%d/%d\n",sum/a,8*i/a);
	}
	return 0;
}