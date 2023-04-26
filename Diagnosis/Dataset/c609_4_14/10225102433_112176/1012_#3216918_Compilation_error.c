#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char s[50];
}node;

int check(char c)
{
	if((c == '!') || (c == '.') || (c == ',') || (c == '?'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n;scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		printf("case #%d:\n",i);
		node ch[150];
		int cnt = 0;
		char t[50] = {0},c;
		int sig = 1;
		while(sig)
		{
			scanf("%s%c",t,&c);
			unsigned len = strlen(t);
			for(int i = 0;i < len;i++)
			{
				if(check(t[i]))
				{
					for(in)
				}
			}
		}
	}
    return 0;
}