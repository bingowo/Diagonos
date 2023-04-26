#include <stdio.h>
#include <string.h>


void trans(char s1[], char s2[], int a[], int b[]) {
	a[0] = strlen(s1);
	b[0] = strlen(s2);
	for (int i = a[0], j = 0; i >= 1; i--, j++)
		a[i] = s1[j] - '0';
	for (int i = b[0], j = 0; i >= 1; i--, j++)
		b[i] = s2[j] - '0';
	return ;
}

void print(int a[]) {
	int len = a[0];
	while (a[len] == 0 && len > 1)
		len--;
	while (len > 0)
		printf("%d", a[len--]);
	printf("\n");
	return ;
}

void sub(int a[], int b[]) {
	int len = a[0];
	int k = 0;
	for (int i = 1; i <= len; i++) {
		if (a[i] + k >= b[i]) {
			a[i] = a[i] + k - b[i];
			k = 0;
		} else {
			a[i] = a[i] + 10 + k - b[i];
			k = -1;
		}
	}
	return ;
}

int main() {
	char s1[1010], s2[1010];
	while (scanf("%s %s", s1, s2) != EOF) {
		int a[1015] = {0}, b[1015] = {0};
		if (strlen(s1) == strlen(s2)) {
			if (strcmp(s1, s2) >= 0)
				trans(s1, s2, a, b);
			else {
				trans(s2, s1, a, b);
				printf("-");
			}
		} else if (strlen(s1) > strlen(s2))
			trans(s1, s2, a, b);
		else {
			trans(s2, s1, a, b);
			printf("-");
		}
		sub(a, b);
		print(a);
	}
	return 0;
}