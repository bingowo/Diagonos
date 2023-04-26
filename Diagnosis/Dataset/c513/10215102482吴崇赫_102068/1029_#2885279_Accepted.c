#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 205

int cmp(const void* a, const void* b) {
	if (*(char*)a != *(char*)b)return *(char*)a > *(char*)b ? 1 : -1;
	return 0;
}

int main() {
    char s[N]={0};

	int T, a = 0;
	scanf("%d\n", &T);
	while (a < T) {
		gets(s);
		char ret[N] = { 0 }, alpha[N] = { 0 }, other[N] = { 0 };
		int j = 0, k = 0;
		int n = strlen(s);
		for (int i = 0;i < n;++i) {
			if (isalpha(s[i]))alpha[j++] = s[i];
			else other[k++] = s[i];
		}
		qsort(alpha, j, sizeof(char), cmp);
		j = k = 0;
		for (int i = 0;i < n;++i) {
			if (isalpha(s[i]))ret[i] = alpha[j++];
			else ret[i] = other[k++];
		}
		printf("case #%d:\n",a);
		printf("%s\n",ret);
		a++;
	}

	return 0;
}
