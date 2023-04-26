#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char s[105][25];
int cmp(const void *p1, const void *p2)
{
//	printf("cmp");
	char *s1, *s2;
	s1 = (char **)p1;
	s2 = (char **)p2;
//	printf("cmp %s %s", s1, s2);
	int used[30];
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int cnt1 = 0, cnt2 = 0;
	memset(used, 0, sizeof(used));
	for(int i = 0; i < len1; ++i)
		used[s1[i] - 'A'] = 1;
	for(int i = 0; i < 26; ++i)
		cnt1 += used[i];
	memset(used, 0, sizeof(used));
	for(int i = 0; i < len2; ++i)
		used[s2[i] - 'A'] = 1;
	for(int i = 0; i < 26; ++i)
		cnt2 += used[i];
	if(cnt1 != cnt2)
		return cnt2 - cnt1;
	return strcmp(s1, s2);
}
void sov()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	qsort(s, n, sizeof(char) * 25, cmp);
	for(int i = 0; i < n; ++i)
		printf("%s\n", s[i]);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
}