#include <stdio.h>
#include <stdlib.h>

char * TenToMoreThanTen(int N, int R);

int TenToLessThanTen(int N, int R);

char array[100] = "\0";


int main()
{
	int T, N, R;
	int answer;
	char *answer2;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &N, &R);
		
		if (R <= 9)
		{
			if(N < 0)
			{
				answer = TenToLessThanTen(-N, R);
				printf("-");
				printf ("%d\n", answer);
				continue;
			}
			
			if(N >= 0)
			{
				answer = TenToLessThanTen(N, R);
				printf ("%d\n", answer);
				continue;
			}
		}
		
		else
		{
			if (N < 0)
			{
				answer2 = TenToMoreThanTen(-N, R);
				printf ("-");
				printf ("%s\n", answer2);
				continue;
			}
			
			if (N >= 0)
			{
				answer2 = TenToMoreThanTen(N, R);
				printf ("%s\n", answer2);
				continue;
			}
		}
	}
	
	return 0;
}


char * TenToMoreThanTen(int N, int R)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	char tmp_array[100] = "\0";
	
	for (;N > 0; i++)
	{
		tmp = N % R;
		
		if (tmp <= 9)
			tmp_array[i] = tmp + '0';
		else
			tmp_array[i] = tmp - 10 + 'A';
		
		N = N / R;
	}
	
	for (; i > 0; i--, j++)
	{
		array[j] = tmp_array[i - 1];
		array[j + 1] = '\0';
	}
	
	return array;
}

int TenToLessThanTen(int N, int R)
{
		int answer = 0;
		
		for (; N > 0;)
		{
			answer = answer * 10 + N % R;
			N = N / R;
		}
		
		return answer;
}