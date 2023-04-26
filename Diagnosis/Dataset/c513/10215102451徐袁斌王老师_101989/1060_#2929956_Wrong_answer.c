#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h>
int main()
{
	int sum=0,i=0,ans=0;
	char a[100];
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if(a[i]>='1'&&a[i]<='9')
		{
			sum++;i++;
		}
		else
		{
			if(sum>ans)
			{
				ans=sum;
			}
			i++;sum=0;
		}
	}
	if(sum>ans) ans=sum;
	printf("%d",ans);
	
	
	
	
	return 0;
	
	
 } 