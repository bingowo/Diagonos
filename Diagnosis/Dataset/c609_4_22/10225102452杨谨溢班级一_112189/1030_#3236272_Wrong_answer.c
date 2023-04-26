# include <stdio.h>
# include <stdlib.h>
# include <string.h>
double alphabet[26] = { 0.0 };
char str[105];
int cmp(const void* a, const void* b)
{
	char ca = *(char*)a, cb = *(char*)b;
	char cca = ca - 'a' >= 0 ? ca - 'a' : ca - 'A';
	char ccb = cb - 'a' >= 0 ? cb - 'a' : cb - 'A';
	// printf(" **** %s \n", str);
	if (alphabet[cca] != alphabet[ccb])  return alphabet[ccb] * 10e20 > alphabet[cca] * 10e20 ? 1 : -1;
	return cb - ca;
}

int main()
{
	int cases = 0;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		for (int i = 0; i < 26; ++i)  scanf("%lf", &alphabet[i]);
		scanf("%s", str);
		//int n = strlen(str);
		//str[strlen(str)] = 0;
		qsort(str,strlen(str), sizeof(char), cmp);
		printf("case #%d:\n", cas);
		printf("%s\n", str);
	}
	return 0;
}