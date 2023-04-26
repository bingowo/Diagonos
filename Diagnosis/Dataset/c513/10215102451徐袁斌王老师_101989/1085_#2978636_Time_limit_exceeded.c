#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int a[501],b[501],m=-1,n=-1,ans[502],z=0,fuhao;
	char x[501],y[501];
	while(1)
	{
	m=-1,n=-1,fuhao=0; 
	for(int i=0;i<502;i++) ans[i]=-1;
	scanf("%s",x);
	scanf("%s",y);
	int n1=0,n2=0;
	while(x[n1]!='\0') n1++;
	while(y[n2]!='\0') n2++;
	if(n1!=n2)
	{
		if(n1<n2) fuhao=1;
		else fuhao=0;
	}
	else
	{
		int i=0;
		while(x[i]!='\0')
		{
			if(x[i]!=y[i])
			{
				if(x[i]>y[i]) {fuhao=0;break;}
				else {fuhao=1;break;}
			}
			else {i++;}
		}
	}
	for(int i=0;x[i]!='\0';i++)
	{
		if(fuhao==0)
		{
			a[i]=x[i]-48;m++;
		}
		else
		{
			b[i]=x[i]-48;n++;
		}
	}
	for(int i=0;y[i]!='\0';i++)
	{
		if(fuhao==0)
		{
			b[i]=y[i]-48;n++;
		}
		else
		{
			a[i]=y[i]-48;m++;
		}
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
	if(ans[i]==-1) printf("0");
	if(fuhao==1) printf("-");
	for(;ans[i]!=-1;i++) printf("%d",ans[i]);
	printf("\n");
	}
}