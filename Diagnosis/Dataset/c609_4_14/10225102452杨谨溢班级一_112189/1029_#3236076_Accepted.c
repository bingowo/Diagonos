# include <stdio.h>
# include <stdlib.h>

int A[1005] = {0};
int cmp(const void* a, const void* b)
{
	int a1 = *(int*)a, b1 = *(int*)b;
	if (A[a1] != 0 && A[b1] != 0 && A[a1] != A[b1])
		return A[a1] - A[b1];
	if (A[a1] == 0 && A[b1] != 0)  return 1;
	if (A[b1] == 0 && A[a1] != 0)  return -1;
	return a1 - b1;
}

int main()
{
	int na;
	scanf("%d", &na);
	for (int i = 0; i < na; ++i)
	{
		int m = 0;
		scanf("%d",&m);
		A[m] = i + 1;
	}
	int nb;
	scanf("%d", &nb);
	int* B = (int*)malloc(nb * sizeof(int));
	for (int i = 0; i < nb; ++i)  scanf("%d", &B[i]);
	qsort(B, nb, sizeof(int), cmp);
	for (int i = 0; i < nb; ++i)  printf("%d ", B[i]);
	return 0;
}