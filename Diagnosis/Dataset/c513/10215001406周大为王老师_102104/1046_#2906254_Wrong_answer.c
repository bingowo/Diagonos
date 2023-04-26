#include<stdio.h>//for //
#include<string.h>
int main()
{
	int t = 0;
	scanf("%d", &t);
	int k = 0;
	for (;t>0;t--)
	{
		int record;
		char ch[1000] = { 0 };
		gets(ch);
		for (int j = 0; j < strlen(ch);j++)
		{
			int count = 1;
			if (ch[j] == ' ')
			{
				count++;
				continue;
			}
			else if (ch[j] == 'a' || ch[j] == 'A')
			{
				if (ch[j + 1] == ' ')
				{
					j += 1;
					continue;
				}
				else if (ch[j + 1] == 'n'|| ch[j + 1] == 'N')
				{
					if (ch[j + 2] == ' ')
					{
						j += 2;
						continue;
					}
					else if (ch[j + 2] == 'd'|| ch[j + 2] == 'D')
					{
						j += 3;
						continue;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}//a, an , and
			else if (ch[j] == 'T' || ch[j] == 't')
			{
				if (ch[j + 1] == 'h' && ch[j + 2] == 'e')
				{
					j = j + 3;
					continue;
				}
				else
				{
					continue;
				}
			}
			else if (ch[j] == 'O' || ch[j] == 'o')
			{
				if (ch[j + 1] == 'f'|| ch[j + 1] == 'F')
				{
					j = j + 2;
					continue;
				}
				else
				{
					continue;
				}
			}
			else if (ch[j] == 'F' || ch[j] == 'f')
			{
				if (ch[j + 1] == 'o' && ch[j + 2] == 'r')
				{
					j = j + 3;
					continue;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
			record = count;
		}
		if (record != 0)
		{
			printf("case #%d:\n", k);
			printf("%d\n", record);
			k++;
		}
	}
	return 0;
}