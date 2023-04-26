#include<stdio.h>
#include<string.h>
char s[100];
int used[300];
int num[300];
void sov()
{
	scanf("%s", s + 1);
	memset(used, 0, sizeof(0));
	int a = 0;
	int len = strlen(s + 1);
	for(int i = 1; i <= len; ++i)
	{
		if(used[s[i]])
			continue;
		++a;
		used[s[i]] = 1;
		if(a == 1)
			num[s[i]] = 1;
		else if(a == 2)
			num[s[i]] = 0;
		else
			num[s[i]] = a - 1; 
	}
	long long ans = 0;
	if(a == 1)
		a = 2;
	for(int i = 1; i <= len; ++i)
		ans = ans * a + num[s[i]];
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