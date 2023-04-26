#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL long long
#define N 100000

typedef struct {
	int len, d[N];
} bigint;

bigint change(char str[]) {
	bigint a;
	a.len  = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bigint add(bigint a, bigint b) {
	bigint c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bigint sub(bigint a, bigint b) {
	bigint c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) {
			a.d[i + 1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

void print(bigint a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}

int compare(bigint a, bigint b) {
	if (a.len > b.len)
		return 1;
	else if (a.len < b.len)
		return -1;
	else {
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.d[i] > b.d[i])
				return 1;
			else if (a.d[i] < b.d[i])
				return -1;
		}
		return 0;
	}
}

int main() {
	char str1[100000], str2[100000];
	scanf("%s%s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (str1[0] != '-' && str2[0] != '-') {
		bigint a = change(str1);
		bigint b = change(str2);
		print(add(a, b));
	} else if (str1[0] == '-' && str2[0] == '-') {
		char str11[100000], str22[100000];
		for (int i = 0; i < len1; i++) {
			str11[i] = str1[i + 1];
		}
		for (int i = 0; i < len2; i++) {
			str22[i] = str2[i + 1];
		}
		bigint a = change(str11);
		bigint b = change(str22);
		printf("-");
		print(add(a, b));

	} else {
		char str11[100000], str22[100000];
		if (str1[0] == '-') {
			//char str11[1000], str22[1000];
			for (int i = 0; i < len1; i++) {
				str11[i] = str1[i + 1];
			}
			for (int i = 0; i < len2; i++) {
				str22[i] = str2[i];
			}
		} else {
			//char str11[1000], str22[1000];
			for (int i = 0; i < len2; i++) {
				str11[i] = str2[i + 1];
			}
			for (int i = 0; i < len1; i++) {
				str22[i] = str1[i];
			}
		}

		bigint a = change(str11);
		bigint b = change(str22);
		//print(a);
		//print(b);
		int flag = compare (a, b);
		//printf("kk=%d", flag);
		if (flag == 1) {

			printf("-");
			print(sub(a, b));
		} else {
			print(sub(b, a));
		}
	}

	return 0;
}
