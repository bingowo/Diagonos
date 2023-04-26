#include<stdio.h>
int main()
{
	int i=0,T;
	scanf("%d\n",&T);
	for(i;i<T;i++)
	{
		char s[50];
		
		scanf("%s",&s);
	
		
		int j=0;
		int ans=0;
		while(s[j]) 
		{
			if(s[j]=='-')
			{
				ans=ans*3-1;
			}
			else
			{
				ans=ans*3+s[j]-'0';
			}
			j++;
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}	
}