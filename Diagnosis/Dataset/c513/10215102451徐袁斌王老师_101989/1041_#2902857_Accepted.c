#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[50],c;
	scanf("%s",a);
	int b=0,i=0,d=1;
	c=a[0];
	while(a[i]!='\0')
	{
		if(a[i]=='|')
		{
			if(a[i+1]=='-'){i++;d++;}
			else 
			{
				if(d>b) {b=d;d=1;i++;}
				else {d=1;i++;}
			}
		}
		if(a[i]=='-')
		{
			if(a[i+1]=='|'){i++;d++;}
			else 
			{
				if(d>b) {b=d;d=1;i++;}
				else {d=1;i++;}
			}
		}
	}
	printf("%d",b);
	
	
	
	
 } 