#include<stdio.h>
#include<string.h>

int main()
{
	int x,y,n,k1,k2,sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		char string1[50]={"\0"};
		k1=0;
		while(x>0)
		{
			string1[k1]=x%2+48;
			x/=2;
			k1++;
		}
		char string2[50]={"\0"};
		k2=0;
		while(y>0)
		{
			string2[k2]=y%2+48;
			y/=2;
			k2++;
		}
		sum=0;
		for(int j=0;j<strlen(string1)&&j<strlen(string2);j++)
		{
			if(string1[j]!=string2[j])
				sum++;
		}
		if(strlen(string1)>strlen(string2))
			sum+=strlen(string1)-strlen(string2);
		else
			sum+=strlen(string2)-strlen(string1);
		printf("%d\n",sum);
		}
}