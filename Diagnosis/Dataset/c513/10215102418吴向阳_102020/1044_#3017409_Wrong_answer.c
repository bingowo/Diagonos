#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char *A = (char *)malloc(100000*sizeof(char));
	scanf("%s",A);
	int len = strlen(A), judge = 0;;
	unsigned long long a;
	for (int i = 0; i < len; i++)
	{
		if(A[i] == '0' && A[i+1]== 'x')
		{
			a = 0;
			i += 2;
			while (A[i] == '0') 
			{
				i++;
			}
			if ((A[i] < 48) || (A[i] > 57 && A[i] <97) || (A[i] > 102) || (i == len - 1 && A[i] == 0))
			{
				printf("%lld ",a);
				continue;
			}
			int k,judge1 = 0;
			for (int j = 0; j < 16 && j < len; j++)
			{
				if (i + j == len - 1 && ((A[i + j] > 47 && A[i + j] < 58) || (A[i + j] > 96 && A[i + j] < 103)))
				{
					k = len;
					judge ++;
					break;
				}
				if (A[i + j] < 48 || (A[i + j] > 57 && A[i + j] <97) || (A[i + j] > 102))
				{
					k = i + j;
					if (j == 0) judge1 ++; 
					else judge++;
					break;
				}
			}
			for (int j = i; j < k; j++) 
			{
				if (A[j] > 96 && A[j] < 103) 
				{
					a = a*16 + (A[j] - 'a' + 10);
				}
				else 
				{
					a = a*16 + (A[j] - '0');
				}
			}
			i = k - 1;
			if (judge1 == 0) printf("%lld ",a);
		}
	}
	if (judge == 0) printf("-1");
	free(A);
	return 0;	
}