#include<stdio.h>
#include<string.h>
#define N 104

long long solve(char* word) {
	int len = strlen(word);
	//确定每个字母代表的数字
	int a[128], cnt[128], j = 0;
	for (int i = 0; i < 128; ++i) {
		a[i] = -1; cnt[i] = i;
	}
	cnt[0] = 1; cnt[1] = 0;
	for (int i = 0; i < len; ++i) {
		if (a[word[i]] == -1) {
			a[word[i]] = cnt[j++];
		}// j 为进制数
	}
	//求出进制转换结果
	long long ret = 0;
	for (int i = 0; i < len; ++i) {
		ret = ret * j + a[word[i]];
	}
	return ret;
}

int main() {
	int T, x = 0;
	scanf("%d", &T);
	while (x < T) {
		char s[N] = { 0 };
		scanf("%s", s);
		printf("case #%d:\n%lld\n", x++, solve(s));
	}
	return 0;
}