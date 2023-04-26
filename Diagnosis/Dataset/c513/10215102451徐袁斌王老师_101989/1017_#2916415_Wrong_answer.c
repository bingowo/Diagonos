#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char x[50];
	int i=0,ans=0,a[100];
	a['I']=1,a['V']=5,a['X']=10,a['L']=50,a['C']=100,a['D']=500,a['M']=1000;
	scanf("%s",x);
	while(x[i+1]!='\0')
	{
		if(a[x[i]]<a[x[i+1]])
		{
			ans=ans-a[x[i]];
		}
		if(a[x[i]]>=a[x[i+1]])
		{
			ans=ans+a[x[i]];
		}
		i++;
	}
	ans=ans+a[x[i]];
	printf("%d",ans);
	return 0;
	
	
 } 