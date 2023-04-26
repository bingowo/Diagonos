#include<stdio.h>
#include<string.h>
#include<math.h>
//方法一，正向求解
int f(int n, int m)
{
	if (n == m)
		return 1;
	else if (n < m)
		return 0;
	else if (n>m)
		return  2 * f(n - 1, m) - f(n - 1 - m, m) + pow(2,n-1-m);
	
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