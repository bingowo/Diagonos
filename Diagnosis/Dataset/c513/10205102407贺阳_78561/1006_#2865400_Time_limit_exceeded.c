#include<stdio.h>
int main()
{
	int i=0,T;
	scanf("%d\n",&T);
	for(i;i<T;i++)
	{
		char s[50];
		int j=0;
		for(j;j<50;j++)
		{
			s[j]=-1;
		}
		j=0;
		for(j;j<50;j++)
		{
			scanf("%c",&s[j]);
			if(s[j]=='\n') break;
		}
		j=0;
		int ans=0;
		while(s[j]+1) 
		{
			if(s[j]=='-')
			{
				ans=ans*3-s[j];
			}
			else
			{
				ans=ans*3+s[j];
			}
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}	
}