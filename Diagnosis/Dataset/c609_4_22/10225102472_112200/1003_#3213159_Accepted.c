#include <stdio.h>

int main()
{
	int T;
	long long n;
	
	scanf ("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int temp[10000] = {0};
		int count = 0;
		
		scanf("%lld", &n);
		
		for (; n; count++)
		{
			temp[count] = n % 2333;
			n /= 2333;
		}
		
		for (count != 0 ? count-- : 1; count>=0; count--)
		{
			printf("%d", temp[count]);
			if (count != 0) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}