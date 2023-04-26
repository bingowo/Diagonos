#include<stdio.h>
#include<string.h>
#define N 20
int main()
{
	int sum[N + 1];
	int up[N + 1];
	int down[N + 1];
	int a, m, n, x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	sum[1] = a;
	up[1] = a;
	down[1] = 0;
	sum[2] = a;
	int left = 0;
	int right = m;
	while (left <= right)
	{
		int t = (left + right) / 2;
		up[2] = t;
		down[2] = t;

		for (int i = 3;i < n;i++)
		{
			up[i] = up[i - 1] + up[i - 2];
			down[i] = up[i - 1];
			sum[i] = up[i] - down[i] + sum[i + 1];

		}
		if (sum[n - 1] == m)
		{
			printf("%d", sum[x]);
			break;
		}
		else if (sum[n - 1] < m)
		{
			left = t;
		}
		else if (sum[n - 1] > m)
		{
			right = t;
		}
	}
	return 0;
}