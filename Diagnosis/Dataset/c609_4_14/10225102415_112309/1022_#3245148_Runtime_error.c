#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define usrsize 10000
#define domsize 10000

typedef struct {
	char usr[usrsize];
	char dom[domsize];
} EMAIL;

EMAIL *Input(int T);

char *GetUsr(char *ads, int len, char *ret);

char *GetDom(char *ads, int len, char *ret);

int cmp(const void *a, const void *b);

int main() {
	EMAIL *data = 0;
	int T;
	scanf("%d", &T);
	data = Input(T);
	qsort(data, T, sizeof(EMAIL), cmp);
	for (int i = 0; i < T; i++) {
		printf("%s@%s\n", data[i].usr, data[i].dom);
	}
	return 0;
}

EMAIL *Input(int T) {
	EMAIL *p = (EMAIL *)malloc(sizeof(EMAIL) * (T + 10));
	for (int i = 0; i < T; i++) {
		char ads[usrsize + domsize] = {0};
		scanf("%s", &ads);
		int len = strlen(ads);
		strcpy((p + i) -> usr, GetUsr(ads, len, (p + i) -> usr));
		strcpy((p + i) -> dom, GetDom(ads, len, (p + i) -> dom));
	}
	return p;
}

char *GetUsr(char *ads, int len, char *ret) {
//	strcpy(ret, "pass");
	char usr[usrsize] = {0};
	int retLen = 0;
	int flg = -1;
	for (int i = len - 1; i > -1; i--) {
		if (ads[i] == '@' && flg != 1) {
			flg = 1;
			i--;
		}
		if (flg == 1) {
			usr[retLen] = ads[i];
			retLen++;
		}
	}
//	printf("usrLen:%d\n", retLen);
	for (int j = retLen - 1; j > -1; j--) {
		ret[j] = usr[retLen - j - 1];
		//printf("ret[%d]:%c\n", j, ret[j]);
	}
	ret[retLen] = '\0';
//	printf("usr:%s\n", ret);
	return ret;
}

char *GetDom(char *ads, int len, char *ret) {
//	strcpy(ret, "pass");
	char dom[domsize] = {0};
	int retLen = 0;
	for (int i = len - 1; i > -1; i--) {
		if (ads[i] == '@')
			break;
		dom[retLen] = ads[i];
		retLen++;
	}
//	printf("domLen:%d\n", retLen);
	for (int j = retLen - 1; j > -1; j--) {
		ret[j] = dom[retLen - j - 1];
		//printf("ret[%d]:%c\n", j, ret[j]);
	}
	ret[retLen] = '\0';
//	printf("dom:%s\n", ret);
	return ret;
}

int cmp(const void *a, const void *b) {
	EMAIL *A = (EMAIL *)a;
	EMAIL *B = (EMAIL *)b;
	if (strcmp(A -> dom, B -> dom) == 0) {
		return strcmp(B -> usr, A -> usr);
	} else {
		return strcmp(A -> dom, B -> dom);
	}
}