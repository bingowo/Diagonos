#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mian()
{
	char s[1000][1000]={0};
	int t1=0,t2=0;
	char temp[1000];
	char c;
	int k=0;
    t1=3;
	scanf("%s",temp);
	for(int i=0;i<t1;i++)
	{
		int flg=0;
		while(s[i][t2])
		{
			if(s[i][t2]=='"')
			{
				flg++;
				t2++;
			}
			if(s[i][t2]=='/'&&s[i][t2+1]=='/'&&(flg%2)==0)//说明//没在""内 
			{
				i++;
				printf("\n");
				t2=0;
			}
			
			if(s[i][t2]=='/'&&s[i][t2+1]=='*')
			{
				t2+=2;
				while(s[i][t2]!='*')
				{
					if(s[i][t2])//到下一行 
					{
						i++;
						printf("\n");
						t2=0;
						continue;
					}
					printf("%c",s[i][t2]);
					t2++;
				}
				if(s[i][t2]=='*'&&s[i][t2+1]=='/')
				{
					t2+=2;
				}
				
			}
			printf("%c",s[i][t2]);
			t2++;
		}
	}
}