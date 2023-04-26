# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
	int num;
	char str[20];
}STR;

int cmp(const void* a, const void* b)
{
	STR A = *(STR*)a, B = *(STR*)b;
	if (A.num == B.num)  return strcmp(A.str, B.str);
	return B.num - A.num;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 0; cas < t; ++cas)
	{
		int account;
		scanf("%d", &account);
		STR* SS = (STR*)malloc(account * sizeof(STR));
		for (int i = 0; i < account; ++i)
		{
			scanf("%s", SS[i].str);
			int L[128] = {0};
			for (int e = 0; e < strlen(SS[i].str); ++e) L[SS[i].str[e]]++;
			int count = 0;
			for (int e = 60; e < 128; ++e)  if (L[e] > 0) count++;
			SS[i].num = count;
		}
		qsort(SS, account, sizeof(SS[0]), cmp);
		printf("case #%d:\n",cas);
		for (int i = 0; i < account; ++i)   printf("%s\n", SS[i].str);
	}
	return 0;
}