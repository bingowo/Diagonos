#include <stdio.h>
#include <stdlib.h>

char answer[33];

int AtoTen (int A, char n[]);

char * TentoB (int B, int temp);

int main()
{
	int A, B, temp;
	char * answer;
	char n[33];
	
	scanf("%d%s%d", &A, n, &B);
	temp = AtoTen (A, n);
	answer = TentoB (B, temp);
	
	printf ("%s", answer);
	
	return 0;
}

int AtoTen (int A, char n[33])
{
	int x = 0;
	
	for (int i = 0; n[i] != '\0'; i++)
	{
		if (n[i] >= 'a' && n[i] <= 'f')
			x = x * A + (n[i] - 'a');
		else if (n[i] >= 'A' && n[i] <= 'F')
			x = x * A + (n[i] - 'A');
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
		for (; temp != 0; i++)
		{
			answer[i] = temp % B + '0';
			temp /= B;
		}
	
		i--;
	
		for (; i >= 0; i--, j++)
		{
			answer[j] = temp_answer[i];
			answer[j + 1] = '\0';
		}
		
		return answer;
	}
	
	if (B>10)
	{
		for (; temp != 0; i++)
		{
			if ((temp % B) >= 10)
			{
				answer[i] = temp % B + 'A';
				temp /= B;
			}
			
			else
			{
				answer[i] = temp % B + '0';
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