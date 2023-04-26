# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
typedef struct {
	char str[35];
	int num;
}STR;
int strnumcmp(const void* a, const void* b)
{
	STR A = *(STR*)a, B = *(STR*)b;
	if (A.num == B.num)  return strcmp(A.str, B.str);
	else return A.num - B.num;
}
int main()
{
	STR* L = (STR*)malloc(105*sizeof(STR));
	int i = 0;
	while (scanf("%s", L[i].str) > 0)
	{
		int f = 1;
		for (int j = 0; j < strlen(L[i].str); ++j)
		{
			if (isdigit(L[i].str[j]))
			{
				int q = L[i].str[j] - '0';
				while (isdigit(L[i].str[++j]))
				{
					int p = L[i].str[j] - '0';
					q = q * 10 + p;
				}
				L[i].num = q;
				f = 0;
			}
		}
		++i;
		if (f)  L[i].num = -1;
	}
	qsort(L, i, sizeof(L[0]), strnumcmp);
	for (int e = 0; e < i; ++e)
	{
		printf("%s ", L[e].str);
	}
	return 0;
}
