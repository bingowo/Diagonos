# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
double alphabet[26] = { 0.0 };
char str[105];
int cmp(const void* a, const void* b)
{
	char ca = *(char*)a, cb = *(char*)b;
	char cca = ca - 'a' >= 0 ? ca - 'a' : ca - 'A';
	char ccb = cb - 'a' >= 0 ? cb - 'a' : cb - 'A';
	if ((alphabet[cca] > alphabet[ccb])||(alphabet[cca] < alphabet[ccb]))  return alphabet[ccb] > alphabet[cca] ? 1 : -1;
	return cb > ca;
}

int main()
{
	int cases = 0;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		for (int i = 0; i < 26; ++i) {
			alphabet[i] = 0.0;
			scanf("%lf", &alphabet[i]);
		}
		scanf("%s", str);
		qsort(str, strlen(str), sizeof(char), cmp);
		printf("case #%d:\n", cas);
		printf("%s\n", str);
	}
	return 0;
}