#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10e5
#define N1 34000
struct hex
{
	int begin;
	unsigned int num;
};
int main()
{
	char *s = (char*)malloc(sizeof(char)*N);
	struct hex* n = (struct hex*)malloc(sizeof(struct hex)*N1);
	scanf("%s", s); int i, j; int len = strlen(s);
	for ( i = 0, j = 0; i<len-2; )
	{
		if (s[i] == '0'&&s[i + 1] == 'x'&&((s[i+2]<='9'&&s[i+2]>='0')||(s[i+2]>='a'&&s[i+2]<='f')))
		{
			n[j].begin = i;
			i = i + 2;
			int num = 0;
			for (; (s[i] <= '9' && s[i] >= '0'&&i < len) || ((s[i] <= 'a' && s[i] >= 'f') && i < len); i++)
			{
				if (s[i] <= '9' && s[i] >= '0')
					num = num * 16 + s[i] - '0';
				else if (s[i] <= 'f' && s[i] >= 'a')
					num = num * 16 + s[i] - 'a' + 10;
			}
			n[j].num = num;
			j++;
			


		}
		else
			i++;
	}
	free(s);
	if (j == 0 && i == len - 2)
		printf("%d\n", -1);
	else
	{
		for (int k = 0; k < j; k++)
			printf("%u ", n[k].num);
	}
	free(n);
	
	return 0;
}