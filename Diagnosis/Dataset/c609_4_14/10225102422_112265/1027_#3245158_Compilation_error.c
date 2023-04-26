#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu
{
	char ID[12];
	int score;
};
int cmp(const void* e1, const void* e2)
{
	struct stu p1 = *(struct stu*)e1;
	struct stu p2 = *(struct stu*)e2;
	if (p1.score != p2.score)
		return p2.score - p1.score;
	else
		return strcmp(p1.ID, p2.ID);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N, M, G;
		scanf("%d%d%d", &N, &M, &G);
		int* value = (int*)malloc(sizeof(int)*M);
		for (int j = 0; j < M; j++)
		{
			int val;
			scanf("%d", &val);
			value[j] = val;
		}
		struct stu* all = (struct stu*)malloc(sizeof(struct stu)*N);
		int s;
		for (int j = 0; i < N; j++)
		{
			scanf("%s%d", all[j].ID, &s);
			int score = 0; int l;
			for (int k = 0; k < s; k++)
			{
				scanf("%d", &l);
				score = score + value[l];
			}
			if (score>G)
			{
				all[j].score = score; j++;
			}
		}
		int people=j;
		free(value);
		qsort(all, people, sizeof(all[0]), cmp);
		printf("case #%d:\n", i);
		printf("%d\n",people);
		for (int j = 0; j < people; j++)
			printf("%s %d\n", all[j].ID, all[j].score);
        free(all);
	}
	return 0;
}