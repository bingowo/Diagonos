#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int level,i,len,score;
	char c[100];
	scanf("%s", c);
	len = strlen(c);
	level = 0;
	score = 0;
	for (i = 0;i < len;i++)
	{
		if (c[i] == '(')
		{
			level++;
		}
		else if (c[i] == ')')
		{
			level--;
			if (i > 0 && c[i - 1] == '(')
			{
				score += pow(2, level);
			}
		}
	}
	printf("%d", score);
}