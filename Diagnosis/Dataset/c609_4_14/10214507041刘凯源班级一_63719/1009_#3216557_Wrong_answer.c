#include<stdio.h>
#include<string.h>
int gcd(int a, int b)
{
	if(a == 0 || b == 0)
		return 1;
	while(b ^= a ^= b ^= a %= b);
	return a;
}
char s[1000];
int count(int x)
{
	int res = 0;
	for(; x; x -= (x & -x))
		++res;
	return res;
}
int sov()
{
	gets(s + 1);
//	puts(s + 1);
	int len = strlen(s + 1);
	int a = 0, b = 0;
	for(int i = 1; i <= len; ++i)
	{
		a += count(s[i]);
		b += sizeof(s[i]);
	}
	int g = gcd(a, b);
	printf("%d/%d\n", a/g, b/g);
}
int main()
{
//	printf("%d %d", gcd(1, 2), gcd(2, 8));
	int n;
	scanf("%d", &n);
	char c = getchar();
	for(int i = 1; i <= n; ++i)
		sov();
}