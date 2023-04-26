#include<stdio.h>//for //
#include<string.h>
int main()
{
	int t = 0;
	scanf("%d", &t);
	int k = 0;
	for (;t>=0;t--,k++)
	{
		int count = 0;
		char ch[1000] = { 0 };
		gets(ch);
		for (int j = 0; j < strlen(ch);j++)
		{
			if (ch[j] == ' ')
			{
				continue;
			}
			else if (ch[j] == 'a' || ch[j] == 'A')
			{
				if (ch[j + 1] == ' ')
				{
					continue;
				}
				else if (ch[j + 1] == 'n')
				{
					if (ch[j + 2] == ' ')
					{
						continue;
					}
					else if (ch[j + 2] == 'd')
					{
						continue;
					}
					else
					{
						count++;continue;
					}
				}
				else
				{
					count++;continue;
				}
			}//a, an , and
			else if (ch[j] == 'T' || ch[j] == 't')
			{
				if (ch[j + 1] == 'h' && ch[j + 2] == 'e')
				{
					continue;
				}
				else
				{
					count++;
					continue;
				}
			}
			else if (ch[j] == 'O' || ch[j] == 'o')
			{
				if (ch[j + 1] == 'f')
				{
					continue;
				}
				else
				{
					count++;
					continue;
				}
			}
			else if (ch[j] == 'F' || ch[j] == 'f')
			{
				if (ch[j + 1] == 'o' && ch[j + 2] == 'r')
				{
					continue;
				}
				else
				{
					count++;
					continue;
				}
			}
			else
			{
				count++;
				continue;
			}
		}
		printf("case #%d:\n", k);
		printf("%d\n", count);
	}
	return 0;
}