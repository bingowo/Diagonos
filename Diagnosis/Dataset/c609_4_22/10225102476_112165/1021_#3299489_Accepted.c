#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include<ctype.h>  

int weigh[128] = { 0 };

int cmp(const void* a, const void* b)
{
	char* m = (char*)a;
	char* n = (char*)b;
	while (*m && *n)
	{
		if (weigh[*m] > weigh[*n])
		{
			return 1;
		}
		else if (weigh[*m] < weigh[*n])
		{
			return -1;
		}
		else {
			m++;
			n++;
		}
	}
	if (!*m && *n)  
	{
		return -1;
	}
	else if (!*n && *m)      
	{
		return 1;
	}
}

int main()
{
	char s[27];
	while (scanf("%s", s) != EOF)
	{
		for (int i = 0;i < 26;i++)
		{
			weigh[s[i]] = i + 1;
			if (s[i] >= 'a' && s[i] <= 'z')  
			{
				weigh[s[i] - 32] = i + 1;
			}
			if (s[i] >= 'A' && s[i] <= 'Z')  
			{
				weigh[s[i] + 32] = i + 1;
			}
		}
		getchar();  
		char s1[3000];
		char s2[100][21];  

		gets(s1);
		int j = 0, count = 0;

		while (j < strlen(s1))
		{
			int k = 0;
			while (isspace(s1[j]) && j < strlen(s1)) 
			{
				j++;
			}
			while (!isspace(s1[j]) && j < strlen(s1))
			{
				s2[count][k++] = s1[j];
				j++;
			}
			s2[count++][k] = '\0';
		}
		qsort(s2, count, 21, cmp);

		for (int i = 0;i < count;i++)
		{
			printf("%s ", s2[i]);
		}
		printf("\n");
	}
	return 0;
}
