# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char CC[128] = {0};
int cmp(const void* a, const void* b)
{
	char* A;
	A = *((char**)a);
	char* B;
	B = *((char**)b);
	int i = 0;
	int n1 = strlen(A);
	int n2 = strlen(B);
	int n = n1 < n2 ? n1 : n2;
	while (A[i] == B[i] && i < n) ++i;
	if (i == n && A[i - 1] == B[i - 1])  return n1 - n2;
	else return CC[A[i]] - CC[B[i]];
}

int main()
{
	char c;
	while (c = getchar() != EOF)
	{
		CC[c] = 1;
		CC[c + 32] = 1;
		for (int i = 2; i <= 26; ++i)
		{
			c = getchar();
			CC[c] = i;
			CC[c + 32] = ++i;
		}
		getchar();

		char *p,**STR;
		STR = (char**)malloc(105 * sizeof(char*));
		int n = 0;
		char str[25];
		do
		{
			 scanf("%s", str);
			 p = (char*)malloc((strlen(str) + 1) * sizeof(char));
			 strcpy(p, str);
			 *(STR + n) = p;
			 n++;
		} while (getchar() != '\n');  

		qsort(STR, n, sizeof(char*), cmp);
		for (int i = 0; i < n; ++i)
		{
			if (i == n - 1)  printf("%s\n", STR[i]);
			else printf("%s ", STR[i]);
		}
	}
	return 0;
}