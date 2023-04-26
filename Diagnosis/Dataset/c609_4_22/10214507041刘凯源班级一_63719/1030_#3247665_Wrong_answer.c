#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double cnt[300];
char s[105];
int cmp(const void *p1, const void *p2)
{
	char a, b;
	a = *(char *)p1;
	b = *(char *)p2;
//	printf("%c %f %c %f\n", a, cnt[a], b, cnt[b]);
	if(cnt[a] == cnt[b])
		return b - a;
	return cnt[b] - cnt[a];
}
void sov()
{
	for(int i = 'a'; i <= 'z'; ++i)
	{
		scanf("%lf", &cnt[i]);
		cnt[i] *= 100;
	}
	for(int i = 'A'; i <= 'Z'; ++i)
		cnt[i] = cnt[i + 32];
	scanf("%s", s);
	qsort(s, strlen(s), sizeof(s[0]), cmp);
	puts(s);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
}