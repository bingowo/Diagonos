#include<stdio.h>
#include<string.h>

int main()
{
	int n,len,a,sum;
	char string[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		sum=0;
		scanf("%s",string);
		len=strlen(string);
		for(int j=0;j<len;j++)
		{
			if(string[j]=='-')
				a=-1;
			else if(string[j]=='0')
				a=0;
			else if(string[j]=='1')
				a=1;			 
			sum=sum*3+a;
		}
		printf("case #%d:\n%d\n",i,sum);
	}
}