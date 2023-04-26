#include <stdio.h>
#include <string.h>

int RemoveStr(char M[])
{
	int len = strlen(M);
	if (len == 0 || len == 1) return 0;
	int x = 0, k = 0;
	char m[110];
	for (int i = 0; i < len; i++)
	{
		while(M[i] == M[i+1] || M[i-1] == M[i])	i++;
		if (M[i] > 64 && M[i] < 91)
		{
			m[k] = M[i];
			k++;
		}
	}
	m[k] = '\0';
	if (strcmp(m,M) == 0) return 0;
	x = strlen(M) - strlen(m) + RemoveStr(m);
	return x;
}

int main()
{
	int T, t;
	scanf ("%d", &T);
	t = T;
	while (T)
	{
		char s[110];
		scanf ("%s",s);
		int count = 0, len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			char t[110];
			char *p = s;
			for(int j = 0; j < len+1; j++)
			{
				if (j == i)
				{
					t[j] = *p;
					t[j+1] = *p;
					j++;
					p++;
				}
				else 
				{
					t[j] = *p;
					p++;
				}
			}
			t[len+1] = '\0';
			count = RemoveStr(t) > count ? RemoveStr(t) : count;
		}
		printf("case #%d:\n%d\n", t-T, count);
		T--;
	}
	return 1;
} 