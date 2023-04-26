#include <stdio.h>
#include <stdlib.h>
int whet(int a[])
{
	
	int x1=0,x2=100;
	while(a[x1]==-1) x1++;
	while(a[x2]==-1) x2--;
	for(int j=x1;j<x2;j++)
	{
		if(a[j]==a[j+1]) return 1;
	}
	return 0;
}
void add(int a[])
{
	int x1=0,x2=100;
	while(a[x1]==-1) x1++;
	while(a[x2]==-1) x2--;
	int x3;
	for(x3=x2;x3>x1;x3--)
	{
		if(a[x3]==a[x3-1]) break;
	}
	//printf("x3:%d\n",x3);
	int carry=0;//printf("x2:%d:%d\n",x2,a[x2]);
	if(a[x3]>=9)
	while(a[x3]>=9&&x3>=x1+2)
	{
		a[x3]=0;a[x3-1]=1;
		x3-=2;
	 } 
	else if(a[x3]==0)
	{
		int i=0;
		while(a[x3-i]==0) i++;
		if(i%2==0) while(a[x3]==0&&x3>=x1+2) a[x3]=1,a[x3-1]=0,x3-=2;
		else if(i%2==1) while(a[x3]==0&&x3>=x1+2) a[x3]=0,a[x3-1]=1,x3-=2,carry=1;
		if(carry==1) a[x3+1]=1;
	}
	else if(a[x3]<9) a[x3]+=1;
	//if(carry>0) a[x1-1]=carry;
}
void ad(int a[])
{
	int x1=0,x2=100;
	while(a[x1]==-1) x1++;
	while(a[x2]==-1) x2--;
	int b[101];
	for(int j=0;j<101;j++) b[j]=0;
	b[x2]=1;int carry=0;
	for(int j=x2;j>=x1;j--)
	{
		int n=a[j]+b[j]+carry;
		if(n>=10) 
		{
			a[j]=n%10;
			carry=n/10;
		}
		else 
		{
			a[j]=n;
			carry=0;
		}
	}
	if(carry>0) a[x1-1]=carry;
}
int main()
{
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
	{
		printf("case# %d:\n",i);
		int a[101],in=2;
		for(int j=0;j<101;j++) a[j]=-1;;
		char c;
		while((c=getchar())!='\n') a[in++]=c-'0';
		ad(a);//for(int j=1;j<=13;j++) printf("%d ",a[j]);
		while(whet(a)) add(a);
		int x1=0,x2=100;
		while(a[x1]==-1) x1++;
		while(a[x2]==-1) x2--;
		//printf("%d\n",a[x1]);
		//printf("%d %d\n",x1,x2);
		for(int j=x1;j<=x2;j++)
		{
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
}