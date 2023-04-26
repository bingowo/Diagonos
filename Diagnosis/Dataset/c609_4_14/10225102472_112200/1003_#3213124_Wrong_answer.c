#include <stdio.h>

int main()
{
	int T;
	long long n;
	int answer[100] = {0} ;
	int temp[100] = {0};
	int count = 0;
	
	scanf ("%d", &T);
	for (int i = 0; i < T; i++)
	{
		count = 0;
		
		scanf("%lld", &n);
		
		for (; n; count++)
		{
			temp[count] = n % 2333;
			n /= 2333;
		}
		
		for (count--; count>=0; count--)
		{
			printf("%d", temp[count]);
			if (count != 0) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}