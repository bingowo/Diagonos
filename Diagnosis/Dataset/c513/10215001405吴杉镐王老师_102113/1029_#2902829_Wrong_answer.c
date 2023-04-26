#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		int ans[26]={0};
		char res[201]={'\0'};
		gets(res);
		int len=strlen(res);
		int j;
		for(j=0;j<len;j++)
		{
			if(isalpha(res[j]))
			{
				ans['A'-res[j]]++;
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
	}
	return 0;
}

