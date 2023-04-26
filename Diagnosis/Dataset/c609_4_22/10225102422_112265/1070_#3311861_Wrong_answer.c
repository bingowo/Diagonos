#include<stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	int f[22];
	int g[22];
	f[0] = 0; f[1] = 1;
	g[0] = 1; g[1] = 1;
	for (int i = 2; i < 21; i++)
	{
		f[i] = f[i - 1] + g[i - 1];
		g[i] = f[i] - g[i - 2];
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%d", f[n]+g[n]);
	}
	return 0;
}