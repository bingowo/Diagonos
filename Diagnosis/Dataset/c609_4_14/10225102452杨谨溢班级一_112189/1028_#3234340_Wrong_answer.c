# include <stdio.h>
# include <stdlib.h>

int cmp(const void* a, const void* b)
{
	int* A = *(int(*)[25])a, * B = *(int(*)[25])b; 
	int i = 0;
	while (A[i] == B[i])
	{
		if (A[i] == -1 || B[i] == -1)  break;
		++i;
	}
	if (A[i] != -1 && B[i] != -1)return  B[i] - A[i];
	else if (A[i] == -1)  return 1;
	else return -1;

}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int** L = (int**)malloc(n * sizeof(int(*)[25]));
		for (int i = 0; i < n; ++i)
		{
			L[i] = (int*)malloc(25 * sizeof(int));
			int e = 0;
			int a = 1;
			do
			{
				scanf("%d", &a);
				L[i][e++] = a;//-1也在数组里
			} while (a>0);
		}
		qsort(L, n, sizeof(L[0]), cmp);
		for (int i = 0; i < n; ++i)
		{
			int e = 0;
			int a = L[i][e++];
			while (a>0)
			{
				printf("%d ", a);
				a = L[i][e++];
			}
			printf("\n");
			free(L[i]);
		}
		free(L);
	}
}