#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int A_Ten(int A, char * n);

char * Ten_B(int B, int x);


int main()
{
	int A, B, x;
	char * n = (char*)malloc(sizeof(char) * 33);
	char * answer = (char*)malloc(sizeof(char) * 33);
	
	scanf("%d", &A);
	scanf("%s", n);
	scanf("%d", &B);
	
	x = A_Ten(A, n);
	answer = Ten_B(B, x);
	
	printf("%s", answer);
	
	return 0;
}


int A_Ten(int A, char * n)
{
	int x = 0;
	int len = strlen (n);
	for(int i = 0; i < len; i++)
	{
		if (A <= 10)
			x = x * A + (n[i] - '0');
		else
		{
			if (n[i] >= 'A' && n[i] >= 'a')
				x = x * A + (n[i] - 'A' + 10);
			else
				x = x * A + (n[i] - 'a' + 10);
		}
	}
	
	return x;
}

char * Ten_B(int B, int x)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	char * temp_result;
	char * result;
	
	for (; x > 0; i++)
	{
		temp = x % B;
		if (temp <= 10)
			temp_result[i] = temp + '0';
		else
			temp_result[i] = temp - 10 + 'A';
		x /= B;
	}
	
	for (j = 0; i > 0; i--, j++)
	{
		result[j] = temp_result[i - 1];
		result[j + 1] = '\0';
	}
	
	return result;
}
