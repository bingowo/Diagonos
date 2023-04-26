//-std=c99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000001

char s[N];
char res[N];

int main()
{
	int a[128] = {0};
	int cnt = 0;
	char c;
	while(1)
	{
		c = getchar();
		if(c == '\n'){
			break;
		}
		if(a[c] == 0)
		{
			a[c]++;
			res[cnt++] = c;
			continue;
		}
		else
		{
			res[cnt] = '\0';
			if(strlen(res) > strlen(s))
			{
				strcpy(s,res);
			}
			memset(a,0,sizeof(a));
			memset(res,'\0',N);
			res[0] = c;
			cnt = 1;
		}
	}
	if(strlen(res) > strlen(s))
	{
		strcpy(s,res);
	}
	printf("%s",s);
	return 0;
} 