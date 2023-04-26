#include<stdio.h>
#include<stdlib.h>
int p[26];
int cmp(const void* a, const void* b)
{
	char* s1, * s2; char ch1, ch2;
	s1 = (char*)a; s2 = (char*)b;
	while (*s1 && *s2)
	{
		ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1; //转换为大写字母
		ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2; //转换为大写字母
		if (p[ch1 - 'A'] != p[ch2 - 'A']) //按字母顺序表比较字母
			return p[ch1 - 'A'] - p[ch2 - 'A'];
		else { s1++; s2++; }
	}
	if (*s1 == 0) return -1;
	else return 1;
}

int main()
{
	char s[26];
	while ((scanf("%s", s)) != EOF)
	{
		for(int i = 0; i < 26; i++)
		{
			p[s[i] - 'A'] = i;
		}
	}
	char str[2100];
	char a[100][50];
	gets(str);
	int count = 0,i = 0;
	while (1)
	{
		int j = 0;
		while (str[i] != ' ' && str[i]) 
			a[count][j++] = str[i++];
		a[count][j] = '\0';
		count++;
		if (!str[i])
			break; 
		else i++;
	}
	qsort(a, count, sizeof(a[0]), cmp);
	for (i = 0; i < count - 1; i++)
		printf("%s ", a[i]);
	printf("%s\n", a[i]);
	return 0;
}