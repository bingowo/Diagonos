#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNum(char *s, int n); //获取字符串中数字并返回

int cmp(const void *s1, const void *s2);

int main() {
	char data[100][40];
	int n = 0;
	while (scanf("%s", &data[n++]) != EOF);
//	printf("n:%d\n", n - 1);
	n--;
	char *datap[100];
	for (int i = 0; i < n; i++) {
		datap[i] = data[i];
//		printf("data %d:%s len:%d\n", i, datap[i], strlen(datap[i]));
	}
	qsort(datap, n, sizeof(char **), cmp);
	for (int i = 0; i < n; i++) {
		printf("%s ", datap[i]);
	}
	return 0;
}

int getNum(char *s, int n) {
	int num = 0;
	int mut = 1;
	int flg = -1;
	for (int i = n - 1; i > -1; i--) {
		if (s[i] >= '0' && s[i] <= '9') {
			num += mut * (s[i] - '0');
			mut *= 10;
			flg = 1;
		}
	}
//	printf("num:%d\n", num);
	return flg == -1 ? -1 : num;
}

int cmp(const void *s1, const void *s2) {
	char *n1 = *(char **)s1;
	int len1 = strlen(n1);
//	printf("n1:%s len1:%d\n", n1, len1);
	char *n2 = *(char **)s2;
	int len2 = strlen(n2);
//	printf("n2:%s len2:%d\n", n2, len2);
//	return getNum(n1, len1) - getNum(n2, len2);
	if (getNum(n1, len1) != getNum(n2, len2))
		return getNum(n1, len1) - getNum(n2, len2);
	else
		return strcmp(n1, n2);
}
