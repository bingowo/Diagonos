#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int f[22];
	int g[22];
	f[0] = 0; f[1] = 1;
	g[0] = 0; g[1] = 1;
	for (int i = 2; i < 21; i++)
	{
		f[i] = f[i - 1] + g[i - 1];
		g[i] = f[i] - g[i - 2];
	}
	while(n!=-1)
	{
		printf("%d\n", f[n]+g[n]);
		scanf("%d",n);
	}
	return 0;
}