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
		}
		else if(i==d-1)
		{
			if(w[i]!=w[i-1]) time(a,2);
		}
		else
		{
			if(w[i]!=w[i+1]&&w[i]!=w[i-1]) time(a,3);
			else if(w[i]!=w[i+1]) time(a,2);
			else if(w[i]!=w[i-1]) time(a,2);
		}
	}
	int j=0;
	while(a[j]==0) j++;
	for(;j<1001;j++) printf("%d",a[j]);
	
}