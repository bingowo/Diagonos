#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int m=-1,ans[501],z=0,fuhao;
	char x[501],y[501];
	while(scanf("%s",x)!=EOF)
	{
	m=-1,fuhao=0; 
	for(int i=0;i<501;i++) ans[i]=-1;
	scanf("%s",y);
	int n1=0,n2=0;
	while(x[n1]!='\0') n1++;
	while(y[n2]!='\0') n2++;
	n1--;n2--;
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
	while(n1>=0||n2>=0)
	{
		if(n1>=0&&n2>=0)
		{
			if(fuhao==0) {m=n1;ans[n1]=x[n1]-y[n2]-z;}
			else {m=n2;ans[n2]=y[n2]-x[n1]-z;}
			if(ans[m]<0) {ans[m]=ans[m]+10;z=1;}
			else z=0;
			n1--;n2--;
		}
		else
		{
			if(fuhao==0) {m=n1;ans[m]=x[n1]-48-z;}
			else {m=n2;ans[m]=y[n2]-48-z;}
			if(ans[m]<0) {ans[m]+=10;z=1;}
			else z=0;
			n1--;n2--;
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