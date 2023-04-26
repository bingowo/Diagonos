#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h>
int main()
{
	int sum=0,i=0,ans=0,b=0;
	char a[101];
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if(a[i]=='0'&&b!=0)
		{
			sum++;i++;
		}
		else if(a[i]>='1'&&a[i]<='9')
		{
			sum++;b++;i++;
		}
		else if(a[i]<'0'||a[i]>'9')
		{
			if(sum>ans)
			{
				ans=sum;
			}
			i++;sum=0;b=0;
		}
		else i++;
	}
	if(sum>ans) ans=sum;
	printf("%d",ans);
	
	
	
	
	return 0;
	
	
 } 