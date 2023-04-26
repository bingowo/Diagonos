#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
	char s[N + 1];
	fgets(s, N + 1, stdin);
	if (s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = 0;
	char S[2 * N + 1];
	int j = 0;
	if (strlen(s) == 1) printf("%s", s);
	else
	{
		int i;
		for (i = 0; i < strlen(s)-1;)
		{
			if (s[i] < s[i + 1])
			{
				S[j] = s[i];
				j++;
				S[j] = s[i];
				j++;
				i++;
			}
			else if (s[i]>s[i + 1])
			{
				S[j] = s[i];
				j++;
				i++;
			}
			else if (s[i] == s[i + 1])
			{
				int index = i;
				for (; index < strlen(s) - 1; index++)
				{
					if (s[index] != s[index + 1])
						break;
				}
				if (index == strlen(s) - 1)
				{
					S[j] = s[i];
					j++;
					i++;
				}
				else
				{
					int length = index-i + 1;
					char c = s[i];
					int k = 0;
					for (k = 1; k <=length;k++)
					{
						if (s[i + k] != c)
							break;
					}
					if (s[i + k] > c)
					{
						for (int n = 1; n <= k; n++)
						{
							S[j] = s[i];
							j++;
							S[j] = s[i];
							j++;
							i++;
						}
					}
					else
					{
						for (int n = 1; n <= k-1; n ++ )
						{
							S[j] = s[i];
							j++;
							i++;
						}
					}
				}
			}
		}
		S[j] = s[i];
		j++;
		S[j] = 0;
		printf("%s", S);
	}
	return 0;
}