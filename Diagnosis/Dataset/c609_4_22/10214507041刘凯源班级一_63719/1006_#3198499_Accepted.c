#include<stdio.h>
#include<string.h>
char s[100];
int used[300];
void sov()
{
	scanf("%s", s + 1);
	memset(used, -1, sizeof(used));
	int a = 0;
	int len = strlen(s + 1);
	used[s[1]] = 1;
	for(int i = 1; i <= len; ++i)
	{
		if(used[s[i]] != -1)
			continue;
		used[s[i]] = a;
		a = a ? a + 1 : 2;
	}
	long long ans = 0;
//	printf("%d %d", used['a'], used['b']);
 	if(a < 2)
		a = 2;
//	for(int i = 1; i <= len; ++i)
//		putchar(s[i]);
//	putchar('\n');
	for(int i = 1; i <= len; ++i)
	{
//		printf("%d", used[s[i]]);
		ans = ans * a + used[s[i]];
	}
//	putchar('\n');
	printf("%lld\n", ans);
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