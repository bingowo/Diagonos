#include<stdio.h>
int main()
{
	char s[10001]={0},t[10001]={0};
	int i=0,l=0;
	scanf("%s",s);
	while(s[i])
	{
		if(s[i]>=48&&s[i]<=57)
		{
			int temp=s[i]-48;
			if(s[i+1]>=48&&s[i+1]<=57)
			{
				temp=temp*10+(s[i+1]-48);
				if(s[i+2]>=48&&s[i+2]<=57)
					temp=temp*10+(s[i+2]-48);				
			}
			for(int j=0;j<temp;j++)
			{
				for(int k=0;k<l;k++)
				{
					printf("%c",t[k]);					
				}
			}
			l=0;
		}
		else
		{
			t[l]=s[i];
			l++;
		}
		i++;
	}
	if(l!=0)
	{
		i=0;
		while(t[i])
		{
			printf("%c",t[i]);
			i++;			
		}
	}
	return 0;
}