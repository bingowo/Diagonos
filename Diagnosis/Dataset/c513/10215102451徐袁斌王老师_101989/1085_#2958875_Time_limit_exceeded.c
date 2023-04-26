#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int a[500],b[500],m=-1,n=-1,ans[500],z=0;
	char x[500],y[500];
	while(1)
	{
	for(int i=0;i<500;i++) ans[i]=-1;
	scanf("%s",x);
	scanf("%s",y);
	for(int i=0;x[i]!='\0';i++)
	{
		a[i]=x[i]-48;m++;
	}
	for(int i=0;y[i]!='\0';i++)
	{
		b[i]=y[i]-48;n++;
	}
	while(m>=0||n>=0)
	{
		if(n>=0)
		{
			ans[m]=a[m]-b[n]-z;
			if(ans[m]<0) {ans[m]=ans[m]+10;z=1;}
			else z=0;
			m--;n--;
		}
		else
		{
			ans[m]=a[m]-z;
			if(ans[m]<0) {ans[m]+=10;z=1;}
			else z=0;
			m--;n--;
		}
	}
	int i=0;
	while(ans[i]==0) i++;
	for(;ans[i]!=-1;i++) printf("%d",ans[i]);
	printf("\n");
	}
}