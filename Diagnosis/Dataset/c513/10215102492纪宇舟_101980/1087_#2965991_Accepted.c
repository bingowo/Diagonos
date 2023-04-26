#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,num[105];
int check()
{
	for(int i=1;i<n;i++)
	if(num[i]==num[i+1])return i;
	return 0;
}
int process(int pos)
{
	num[pos]++;
	for(int i=pos;i<=n;i++)
	{
		if(num[i]<10)
		{
			pos=i;break;
		}
		num[i]-=10;num[i+1]++;
		if(i==n)num[++n]=1;
	}
	int sig=0;
	for(int j=pos-1;j>=1;j--)
	{
		num[j]=sig;sig=1-sig;
	}
}
int main()
{
	char s[105];
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		for(int i=n-1;i>=0;i--)num[i+1]=s[n-i-1]-'0';
		num[1]++;
		for(int i=1;i<=n;i++)
		{
			if(num[i]<10)break;
			num[i]-=10;num[i+1]++;
			if(i==n)num[++n]=1;
		}
		int x=check();
		while(x!=0)
		{
			process(x);
			x=check();
		}
		printf("case #%d:\n",ct++);
		for(int i=n;i>=1;i--)printf("%d",num[i]);
		printf("\n");
	}
	return 0;
}