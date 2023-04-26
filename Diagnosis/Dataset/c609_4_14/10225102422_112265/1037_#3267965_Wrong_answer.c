#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10e6
struct dex
{
	int index;
	int len;
};
int cmp(const void* e1, const void* e2)
{
	struct dex p1 = *(struct dex*)e1;
	struct dex p2 = *(struct dex*)e2;
	if (p1.len != p2.len)
		return p2.len - p1.len;
	else
		return p1.index - p2.index;
}
int main()
{
	char* s = (char*)malloc(sizeof(char)*(N+1));
	scanf("%s\n", s);
	int l = strlen(s);
	if (l == 1) printf("%c", s[0]);
	struct dex* m = (struct dex*)malloc(sizeof(struct dex)*l);
	int i; int j; int flag = 1;
	for (i = 0, j = 0; i < strlen(s) - 1;)
	{
		int count = 1;
		m[j].index = i;
		if (s[i] != s[i + 1])
		{
		    m[j].index=i;
			for (; (s[i] != s[i + 1]) && (i < strlen(s) ); i++)
			{
				if (i>0)
				{
					for (int k = 0; k < i; k++)
					{
						if (s[i] == s[k])
						{
							flag = 0;
							break;
						}
					}
					if (flag == 1)
					{
						count++;
					}
				}
			}
			
	
		}

		else
		{
			i++;
		}
		m[j].len = count;
		if (count > 1)
			j++;
			
	}
	qsort(m, j, sizeof(m[0]), cmp);
	int index = m[0].index;
	int length = m[0].len;
	free(m);
	for (i = index; i < index + length; i++)
		printf("%c", s[i]);
	free(s);
	return 0;
}