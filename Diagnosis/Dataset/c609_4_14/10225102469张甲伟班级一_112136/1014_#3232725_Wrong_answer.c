#include<stdio.h>
#include<stdlib.h>
char s[100],zheng[100],xiao[100];
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cnt1,cnt2,tap1,tap2,signal,z[100],x[100],cntt;
int A,B,C;
int main()
{
	scanf("%d%d",&A,&B);
	int a,b;
	a=A/B;
	b=A-a*B;
	int temp=B;
	if(B!=1)
	{
		while(temp)
		{
			temp/=3;
			cnt2++;
		}
//		printf("%d\n",cnt2);
		for(int i=1;i<=cnt2;i++)
		{
			int t=b%3;
			x[i]=t;
			b/=3;
		}
	}
	temp=a;
	int i=1;
	while(temp)
	{
		temp/=3;
		cnt1++;
	}
	temp=a;
	while(temp)
	{
		int t=temp%3;
		z[i++]=t;
		temp/=3;
	}
//	printf("%d\n",cnt1);
	int jinwei=0;
	if(B!=1)
	{
		for(i=cnt2;i>=1;i--)
		{
			x[i]+=jinwei;
			x[i]+=1;
			jinwei=0;
			if(x[i]>=3)
			{
				jinwei=x[i]-2;
				x[i]=x[i]-3;
			}
		}
	}
	for(i=1;i<=cnt1;i++)
	{
		z[i]+=jinwei;
		z[i]+=1;
		jinwei=0;
		if(z[i]>=3)
		{
			jinwei=z[i]-2;
			z[i]=z[i]-3;
		}
	}
	while(jinwei>0)
	{
		z[i]=jinwei;
		jinwei-=3;
		cnt1++;
	}
	if(B!=1)
	{
		for(i=cnt2;i>=1;i--)
		{
			x[i]-=1;
			if(x[i]<0)
				x[i]=2;
		}
	}
	for(i=1;i<=cnt1;i++)
	{
		z[i]-=1;
		if(z[i]<0)
			z[i]=2;
	}
	/*for(i=cnt1;x[i]==0;i--);
		cnt1=i;*/
	for(i=cnt1;i>=1;i--)
		printf("%d",z[i]);
	if(B!=1)
	{
		printf(".");
		for(i=cnt2;x[i]==0;i--);
		cnt2=i;
		for(i=1;i<=cnt2;i++)
			printf("%d",x[i]);
	}
	return 0;
 } 