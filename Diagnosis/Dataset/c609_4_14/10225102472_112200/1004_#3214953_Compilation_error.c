#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char answer[33] = "\0";

int AtoTen (int A, char n[]);

char * TentoB (int B, int temp);

int main()
{
	int A, B, temp;
	char * answer1;
	char n[33] = "\0";
	
	scanf("%d%s%d", &A, n, &B);
	
	if (n = 0)
	{
		printf("0");
		return 0;
	}
	temp = AtoTen (A, n);
	answer1 = TentoB (B, temp);
	
	printf ("%s", answer1);
	
	return 0;
}

int AtoTen (int A, char n[33])
{
	int x = 0;
	
	for (int i = 0; n[i] != '\0'; i++)
	{
		if (n[i] >= 'a' && n[i] <= 'f')
			x = x * A + (n[i] - 'a' + 10);
		else if (n[i] >= 'A' && n[i] <= 'F')
			x = x * A + (n[i] - 'A' + 10);
		else
			x = x * A + (n[i] - '0');
	}
	
	return x;
}

char * TentoB (int B, int temp)
{
	char temp_answer[33] = "\0";
	int i = 0;
	int j = 0;
	
	if (B <= 10)
	{
		int temp_temp = 0;
		
		for (i = 0; temp > 0; i++)
		{
			temp_temp = temp % B;
			temp_answer[i] = temp_temp + '0';
			temp /= B;
		}
	
		i--;
	
		for (j = 0; i >= 0; i--, j++)
		{
			answer[j] = temp_answer[i];
			answer[j + 1] = '\0';
		}
		
		return answer;
	}
	
	if (B>10)
	{
		int temp_temp = 0;
		
		for (i = 0; temp != 0; i++)
		{
			temp_temp = temp % B;
			if (temp_temp >= 10)
			{
				temp_answer[i] = temp_temp + 'A' - 10;
				temp /= B;
			}
			
			else
			{
				temp_answer[i] = temp_temp + '0';
				temp /= B;
			}
		}
	
		i--;
	
		for (; i >= 0; i--, j++)
		{
			answer[j] = temp_answer[i];
			answer[j + 1] = '\0';
		}
		
		return answer;
	}
}