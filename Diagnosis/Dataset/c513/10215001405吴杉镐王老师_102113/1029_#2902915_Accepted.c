#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char res[201]={'\0'};

int main()
{
	int T;
	scanf("%d",&T);
	char c;
	gets(res);
	int i;
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		int ans[26]={0};
		//gets(res);
		gets(res);
		int len=strlen(res);
		int j;
		for(j=0;j<len;j++)
		{
			if(isalpha(res[j]))
			{
				ans[res[j]-'A']++;
			}
		}
		for(int j=0;j<len;j++)
		{
			if(isalpha(res[j]))
			{
				for(int k=0;k<26;k++)
				{
					if(ans[k])
					{
						printf("%c",k+'A');
						ans[k]--;
						break;
					}
				}
			}
			else
			{
				printf("%c",res[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

