#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
	char s[N + 1];
	fgets(s, N + 1,stdin);
	if (s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] == 0;
	char S[3 * N + 2];
	int j = 0;
	if (strlen(s) == 1) printf("%s", s);
	else
	{
		for (int i = 0;i < strlen(s) - 1;)
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
				if (i + 1 < strlen(s) - 1)
				{
					if (s[i + 1] < s[i + 2])
					{
						S[j] = s[i];
						j++;
						S[j] = s[i];
						j++;
						i++;
						S[j] = s[i];
						j++;
						S[j] = s[i];
						j++;i++;
					}
					else
					{
						S[j] = s[i];
						j++;
						i++;
						S[j] = s[i];
						j++;
						i++;
					}
				}
				else
				{
					S[j] = s[i];
					i++;
					j++;
					S[j] = s[i];
					j++;
			        i++;
				}
			}
		}
		for(int i=0;i<j;i++)
		printf("%c\n", S[i]);
	}
	return 0;
}