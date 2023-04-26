#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f(int n, int p, int m, int t)
{
	if (m == 0 && t == p)
		return 1;
	else if (m == 0 && t != p)
		return 0;
	else if (t == n)
		return f(n, p, m - 1, t - 1);
	else if (t>1&&t<n)
		return f(n, p, m - 1, t - 1) + f(n, p, m - 1, t + 1);
	else if (t == 1)
		return f(n, p, m - 1, t + 1);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, p, m, t;
		scanf("%d%d%d%d", &n, &p, &m, &t);
		int num = f(n, p, m, t);
		printf("%d\n", num);
	}
	return 0;
}