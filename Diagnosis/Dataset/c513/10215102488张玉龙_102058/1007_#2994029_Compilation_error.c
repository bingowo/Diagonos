#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,b,temp,max;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		char string[50]={"\0"};
		itoa(b,string,2);
		temp=1;
		max=1; 
		for(int j=0;j<strlen(string)-1;j++)
		{
			if(string[j+1]!=string[j])
			{
				temp++;
			}
			else
				temp=1;
			if(temp>max)
			{
				max=temp;
			}
		}
		printf("case #%d:\n%d\n",i,max);
	}
}