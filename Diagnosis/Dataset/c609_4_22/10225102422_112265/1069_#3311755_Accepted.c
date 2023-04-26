#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 32
//方法一，正向求解
int arr[N + 1];
int f(int n, int m)
{
	arr[m] = 1;
	for (int i = 0; i < m; i++)
		arr[i] = 0;
	for (int i = m+1; i <= n; i++)
	{
		arr[i] = 2 * arr[i - 1] - arr[i - 1 - m] + pow(2, i - 1 - m);
	}
	return arr[n];
		
	
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (n != -1 && m != -1)
	{
		int num = f(n, m);
		printf("%d\n",num);
		scanf("%d%d", &n, &m);
	}
	return 0;
}