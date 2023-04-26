#include <stdio.h>
#include <string.h>
int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		char s[5][5];
		memset(s,'1',sizeof(s));
		int a,i;
		int pu[5][5];
		for(i=1;i<4;i++)
			for(a=1;a<4;a++)
			{
				scanf("%d",&pu[i][a]);
			}
	
		for(i=1;i<4;i++)
		{
			for(a=1;a<4;a++)
			{
				if(pu[i][a]%2==0) continue;
				else
				{
					s[i][a]=!(s[i][a]-'0')+'0';
					s[i-1][a]=!(s[i-1][a]-'0')+'0';
					s[i][a-1]=!(s[i][a-1]-'0')+'0';
					s[i+1][a]=!(s[i+1][a]-'0')+'0';
					s[i][a+1]=!(s[i][a+1]-'0')+'0';
					
				}
			}
		}
		
		printf("case #%d:\n",e);
		for(i=1;i<4;i++)
		{
			for(a=1;a<4;a++)
			{
				printf("%c ",s[i][a]);
			}
			printf("\n");
		}
		
	}
	return 0;
}