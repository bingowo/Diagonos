#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 125
int GCD(int m, int n)
{
	return n % m == 0 ? m : GCD(n % m, m);
}

int countOne(char c) {
	int a = c;int ans = 0;
	while (a) {
		if (a % 2)ans++;
		a >>= 1;
	}
	return ans;
}
void solve(unsigned char* s) {
	int n = strlen(s);
	int sum = 0;
	for (int i = 0;i < n;++i) {
		sum += countOne(s[i]);
	}
	int x = n * 8 / GCD(sum, n * 8);
	int y = sum / GCD(sum, n * 8);
	printf("%d/%d\n", y, x);
}
int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		char s[N];
		gets(s);
		unsigned char* p=(unsigned char*)s;
        solve(p);
	}
	return 0;
}