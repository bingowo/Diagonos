#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int number;
	scanf("%d%c",&number);
	for(int i=0;i<number;i++)
	{
		char s[205];
		gets(s);
		int l=strlen(s);
		for(int j=0;j<l;j++)
		{
			for(int k=j+1;k<l;k++)
			{
				if(s[j]>='A'&&s[j]<='Z'&&s[k]>='A'&&s[k]<='Z')
				{
					if(s[j]>s[k])
					{
						char c=s[j];
						s[j]=s[k];
						s[k]=c;
					}
				}
			}
		}
		printf("case #%d:\n",i);
		for(int j=0;j<l;j++)
		{
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}