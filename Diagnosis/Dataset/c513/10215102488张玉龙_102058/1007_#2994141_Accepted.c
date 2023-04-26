#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,b,temp,max,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		char string[50]={"\0"};
		k=0;
		while(b>0)
		{
			string[k]=b%2;
			b/=2;
			k++;
		}
		temp=1;
		max=1;
		for(int j=k-1;j>0;j--)
		{
			if(string[j]!=string[j-1])
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