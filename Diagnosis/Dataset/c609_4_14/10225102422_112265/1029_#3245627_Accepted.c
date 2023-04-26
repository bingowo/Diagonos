
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 500
struct p
{
	int num;
	int sion;
};
int sion(int num, int A[N],int m)
{
	int i = 0;
	for (i = 0; i < m; i++)
	{
		if (num == A[i])
			return i;
	}
	return m;
}
int cmp(const void* e1, const void*e2)
{
	struct p p1 = *(struct p*)e1;
	struct p p2 = *(struct p*)e2;
	if (p1.sion != p2.sion)
		return p1.sion - p2.sion;
	else
		return p1.num - p2.num;
}
int main()
{
	int m;
	scanf("%d", &m);
	int A[N];
	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		A[i] = num;
	}
	int n; struct p B[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		B[i].num= num;
		B[i].sion = sion(num, A,m);
	}
	qsort(B, n, sizeof(B[0]), cmp);
	for (int i = 0; i < n ; i++)
		printf("%d ", B[i].num);
	return 0;
}