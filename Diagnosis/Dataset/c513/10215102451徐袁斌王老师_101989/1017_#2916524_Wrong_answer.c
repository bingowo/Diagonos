#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char x[50];
	int i=0,ans=0,a[100],b[100],c=1,k=0;
	a['I']=1,a['V']=5,a['X']=10,a['L']=50,a['C']=100,a['D']=500,a['M']=1000;
	scanf("%s",x);
	int j=0;
	while(x[j]!='\0')
	{
		if(x[j]=='(')
		{
			c=c*1000;j++;
		}
		if(x[j]==')')
		{
			c=c/1000;j++;
		}
		else
		{
			b[k]=a[x[j]]*c;j++;k++;
		}
	}
	b[k]='\0';
	while(b[i+1]!='\0')
	{
		if(b[i]<b[i+1])
		{
			ans=ans-b[i];
		}
		if(b[i]>=b[i+1])
		{
			ans=ans+b[i];
		}
		i++;
	}
	ans=ans+b[i];
	printf("%d",ans);
	return 0;
	
	
 } 