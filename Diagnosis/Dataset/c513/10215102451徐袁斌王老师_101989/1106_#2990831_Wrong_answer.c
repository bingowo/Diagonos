#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void time(int a[],int b)
{
	int c=0;
	for(int i=1000;i>=0;i--)
	{
		a[i]=a[i]*b+c;
		if(a[i]>=10) c=a[i]/10;
		else c=0;
		a[i]=a[i]%10;
	}
}
int mod(int a[],int j)
{
	long long int c=0;
	int i=j;
	for(;c<1000000007;i++)
	{
		c=c*10+a[i];
	}
	c=c%1000000007;
	while(i<=1000)
	{
		if(c<1000000007)
		{
			c=c*10+a[i];
		}
		else
		{
			c=c%1000000007;
			c=c*10+a[i];
		}
		i++;
	}
	return c;
}
int main()
{
	int a[1001]={0},d;
	char w[1002];
	scanf("%s",w);
	d=strlen(w);
	a[1000]=1;
	for(int i=0;i<d;i++)
	{
		if(i==0)
		{
			if(i!=d-1&&w[i]!=w[i+1]) time(a,2);
			else continue;
		}
		else if(i==d-1)
		{
			if(w[i]!=w[i-1]) time(a,2);
			else continue;
		}
		else
		{
			if(w[i]!=w[i+1]&&w[i]!=w[i-1]&&w[i-1]!=w[i+1]) time(a,3);
			else if(w[i]!=w[i+1]&&w[i]!=w[i-1]) time(a,2);
			else if(w[i]!=w[i+1]) time(a,2);
			else if(w[i]!=w[i-1]) time(a,2);
			else continue;
		}
	}
	int j=0;
	while(a[j]==0) j++;
	if(j>(1001-10))
	{
		int x=mod(a,j);
		printf("%d",x);
	}
	else {for(;j<1001;j++) printf("%d",a[j]);}
	
}