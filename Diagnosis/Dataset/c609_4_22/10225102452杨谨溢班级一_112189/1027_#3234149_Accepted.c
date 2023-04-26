#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char num[13];
	int score;
}STU;

int cmp(const void* a, const void* b)
{
	STU A = *(STU*)a, B = *(STU*)b;
	if (A.score != B.score)  return B.score - A.score;
	return strcmp(A.num, B.num);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 0; cas < T; ++cas)
	{
		int N, M, G;
		scanf("%d %d %d", &N, &M, &G);
		int* MM = (int*)malloc((M+1) * sizeof(int));
		for (int i = 1; i < M+1; ++i) scanf("%d", &MM[i]);
		STU* STDS = (STU*)malloc(N * sizeof(STU));
		int count = 0;
		int* L = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", STDS[i].num);
			int S;
			scanf("%d", &S);
			int sum = 0;
			for (int e = 0; e < S; ++e)
			{
				int a;
				scanf("%d", &a);
				sum += MM[a];
			}
			if (sum >= G) count++;
			STDS[i].score = sum;
		}
		qsort(STDS, N, sizeof(STU), cmp);
		printf("case #%d:\n", cas);
		printf("%d\n", count);
		for (int i = 0; i < count; ++i)  printf("%s %d\n", STDS[i].num, STDS[i].score);
	}
	return 0;
}