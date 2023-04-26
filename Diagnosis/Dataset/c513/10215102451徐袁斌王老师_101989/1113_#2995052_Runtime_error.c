#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void add(int a[],int b[])
{
	int c=0;
	for(int i=99;i>=0;i--)
	{
		a[i]=a[i]+b[i]+c;
		c=a[i]/10;
		a[i]=a[i]%10;
	}
}
void min(int a[],int b[])
{
	int c=0;
	for(int i=99;i>=0;i--)
	{
		a[i]=a[i]-b[i]-c;
		if(a[i]<0){a[i]+=10;c=1;}
		else c=0;
	}
}
int main()
{
	int a[101][100]={0},k,n;
	scanf("%d%d",&k,&n); 
	a[1][99]=1;a[2][99]=1;
	if(k>2)
	{
		for(int i=3;i<=k+1;i++)
		{
			add(a[i],a[i-1]);
			add(a[i],a[i-1]);
		}
	}
	else a[3][99]=2;
	for(int i=k+2;i<=n;i++)
	{
			add(a[i],a[i-1]);
			add(a[i],a[i-1]);
			min(a[i],a[i-k-1]);
	}
	int i=0;
	while(a[n-1][i]==0) i++;
	for(;i<100;i++) printf("%d",a[n-1][i]);
	
}