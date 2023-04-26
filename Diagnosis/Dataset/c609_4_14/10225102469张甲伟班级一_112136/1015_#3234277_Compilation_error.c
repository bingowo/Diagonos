#include<stdio.h>
#include<stdlib.h>
int cnt1=1,cnt2,tap1,tap2,signal,z[100],x[100],cntt;
int A,B,C;
int main()
{
	scanf("%d%d",&A,&B);
	int a,b;
	a=(abs)A/B;
	b=abs(A)-a*B;
	int i=1;
	int temp=B;
	if(B!=1&&A%B!=0)
	{
		while(temp)
		{
			temp/=3;
			cnt2++;
		}
		temp=b;
		cnt2--;
		i=cnt2;
		while(b)
		{
			int t=b%3;
			x[i--]=t;
			b/=3;
		}
	}
	temp=a;
	i=1;
	while(temp)
	{
		temp/=3;
		cnt1++;
	}
	cnt1--;
	temp=a;
	while(temp)
	{
		int t=temp%3;
		z[i++]=t;
		temp/=3;
	}
	int jinwei=0;
	if(B!=1&&A%B!=0)
	{
		for(i=cnt2;i>=1;i--)
		{
			x[i]+=jinwei;
			x[i]+=1;
			jinwei=0;
			if(x[i]>=3)
			{
				jinwei=1;
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
			jinwei=1;
			z[i]=z[i]-3;
		}
	}
	while(jinwei>0)
	{
		z[i]=jinwei;
		jinwei-=3;
		cnt1++;
	} 
	if(B!=1&&A%B!=0)
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
	if(cnt1<1)
		cnt1++;
	else if(z[cnt1]==0)
		z[cnt1]++;
	if(A>=0)
	{
		for(i=cnt1;i>=1;i--)
		printf("%d",z[i]);
		if(B!=1&&A%B!=0)
		{
			printf(".");
			for(i=cnt2;x[i]==0;i--);
			cnt2=i;
			for(i=1;i<=cnt2;i++)
				printf("%d",x[i]);
		}
	}
	else
	{
		for(i=cnt1;i>=1;i--)
		{
			if(z[i]==1)
				z[i]=2;
			else if(z[i]==2)
				z[i]=1;
			printf("%d",z[i]);
		}
		if(B!=1&&A%B!=0)
		{
			printf(".");
			for(i=cnt2;x[i]==0;i--);
			cnt2=i;
			for(i=1;i<=cnt2;i++)
			{
				if(x[i]==1)
					x[i]=2;
				else if(x[i]==2)
					x[i]=1;
				printf("%d",x[i]);
		}
		}
	}
	return 0;
 } 