#include <string.h>
#include <stdio.h>
#include <math.h>


typedef struct Email {
	char *user;
	char *domain;
} E;

void myPrint(E e) {
	printf("%p@%p\n", e.user, e.domain);
}

int cmp(E a, E b) {
	int flag1 = strcmp(a.domain, b.domain);
	if (!flag1) {
		int flag2 = strcmp(a.user, b.user);
		if (flag2 <= 0)
			return 0;
		else
			return 1;
	}
	if (flag1 > 0)
		return 0;
	else
		return 1;
}

int main() {
	int cnt = 0;
	int n;
	scanf("%d", &n);
	getchar();
	char tmp[1] = {'\0'};
	E *es = (E *)malloc(sizeof(E) * (n + 1));
	char *str = (char *)malloc(sizeof(char) * 2000001);
	for (int i = 0; i < n; i++) {
		es[i + 1].user = tmp;
		es[i + 1].domain = tmp;
		char ch;
		es[i].user = str + cnt;
		while ((ch = getchar()) != '@')
			str[cnt++] = ch;
		str[cnt++] = '\0';
		es[i].domain = str + cnt;
		while ((ch = getchar()) != '\n')
			str[cnt++] = ch;
		str[cnt++] = '\0';
	}
	sort(es, es + n, cmp);
	for (int i = 0; i < n; i++)
		myPrint(es[i]);
	free(es);
	free(str);
	return 0;
}