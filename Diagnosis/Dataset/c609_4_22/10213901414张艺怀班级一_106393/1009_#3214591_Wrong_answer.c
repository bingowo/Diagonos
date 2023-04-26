#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	if (a % b) return gcd(b, a % b);
	else return b;
}

int cnt_digit(char c)
{
	unsigned c_i = (unsigned)c;
	int cnt = 0;
	while (c_i) {
		cnt += c_i & 1;
		c_i >>= 1;
	}
	return cnt;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	getchar();
	char s[300] = {0};
	for (int i = 0; i < n; i++) {
		gets(s);
		int sum = 0;
		for (int i = 0; i < strlen(s); i++) {
			sum += cnt_digit(s[i]);
		}
		int m = gcd(sum, strlen(s) * 8);
		printf("%d/%d\n", sum / m, strlen(s) * 8 / m);
	}

	return 0;
}