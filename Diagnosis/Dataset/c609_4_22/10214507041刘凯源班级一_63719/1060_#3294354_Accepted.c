#include<stdio.h>
#include<string.h>
char s[105];
char sta[205];
int tot;
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len; ++i)
	{
		int has = 0;
		for(int j = i + 1; j < len; ++j)
		{
			if(s[j] != s[i])
			{
				if(s[j] > s[i])
					has = 1;
				break;
			}
		}
		if(has)
		{
			sta[++tot] = s[i];
			sta[++tot] = s[i];
		}
		else
		{
			sta[++tot] = s[i];
		}
	}
	puts(sta + 1);
}