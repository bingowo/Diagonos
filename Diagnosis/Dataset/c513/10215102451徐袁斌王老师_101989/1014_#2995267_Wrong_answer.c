#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void f(int a[])
{
	int c=0;
	for(int i=99;i>=0;i--)
	{
		if(a[i]==-100) {}
		else
		{
			a[i]=a[i]+c+1;
			c=a[i]/3;
			a[i]=a[i]%3;
		}
	}
	for(int i=99;i>=0;i--)
	{
		if(a[i]!=-100) a[i]=a[i]-1;
		if(a[i]==-1) a[i]=2;
	}
}
int main()
{
	int a[100]={0},c=0;
	long long int x,y,z;
	scanf("%lld%lld",&x,&y);
	int i=0,j=1,t;
	while((int)pow(3,i)!=y) i++;
	if(x>y)
	{
		z=x%y;x=x/y;
		while(x>=3)
		{
			a[j]=x%3;
			x=x/3;
			j++;
		}
		a[j]=x;
		for(int k=1;k<=j/2;k++)
		{
			t=a[k];
			a[k]=a[j-k+1];
			a[j-k+1]=t;
		}
		j++;a[j]=-100;j++;
	}
	else
	{
		z=x;
		a[1]=-100;j++;
		c=1;
	}
	while(y>3)
	{
		a[j]=z/3;
		z=z%3;
		j++;
		y=y/3;
	}
	a[j]=z;
	f(a);
	int k=0;

	if(c==0)
	{
		while(a[k]<=0) k++;
		while(a[j]==0) j--;
		for(;k<=j;k++)
		{
			if(a[k]==-100&&k!=j) printf(".");
			else if(a[k]!=-100)printf("%d",a[k]);
		}
	}
	else
	{
		printf("%d.",a[0]);
		k=2;
		while(a[j]==0) j--;
		for(;k<=j;k++)
		{
			printf("%d",a[k]);
		}	
	}
}