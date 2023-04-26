#include<stdio.h>
#define abs(x) (x >= 0 ? x : -x)
int n, k;
int ans[100], tot;
char s[] = "0123456789ABCDEFGHIJKLMN";
int main()
{
	scanf("%d %d", &n, &k);
	if(n == 0)
		puts("0");
	while(n)
	{
		ans[++tot] = n % k;
		int tmp = n / k;
		if(ans[tot] < 0)
		{
			ans[tot] -= k;
			++tmp;
		}
		n = tmp;
	}
	for(int i = tot; i >= 1; --i)
		printf("%c", s[ans[i]]);
}