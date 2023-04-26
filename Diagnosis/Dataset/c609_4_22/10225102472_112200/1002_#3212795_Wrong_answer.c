#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Number(int N);
int main()
{
	int T, n, answer;
	
	scanf ("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		answer = Number(n);
		printf("case #");
		printf("%d", i);
		printf(":\n");
		printf("%d\n", answer);
	}
	
	return 0;
}	

int Number(int N)
{
	int count = 1, temp_count = 1;
	int N1 = N%2, N2;
	
	while (N)
	{
		N = N >> 1;
		N2 = N % 2;
		if (N1 != N2) 
			temp_count++;
		else 
		{
			if (temp_count > count)
				count = temp_count;
			temp_count = 1;
		}
		N1 = N2;
	}
	
	return count;
}