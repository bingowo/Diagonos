#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char usr[100000];
	char dom[100000];
	char web[100000];
} EMAIL;

EMAIL *Input(int T);

char *GetUsr(char *ads, int len, char *ret);

char *GetDom(char *ads, int len, char *ret);

char *GetWeb(char *ads, int len, char *ret);

int cmp(const void *a, const void *b);

int main() {
	EMAIL *data = 0;
	int T;
	scanf("%d", &T);
	data = Input(T);
	qsort(data, T, sizeof(EMAIL), cmp);
	for (int i = 0; i < T; i++) {
		printf("%s@%s.%s\n", data[i].usr, data[i].dom, data[i].web);
	}
	return 0;
}

EMAIL *Input(int T) {
	EMAIL *p = (EMAIL *)malloc(sizeof(EMAIL) * (T + 10));
	for (int i = 0; i < T; i++) {
		char ads[1000000000] = {0};
		scanf("%s", &ads);
		int len = strlen(ads);
		strcpy((p + i) -> usr, GetUsr(ads, len, (p + i) -> usr));
		strcpy((p + i) -> dom, GetDom(ads, len, (p + i) -> dom));
		strcpy((p + i) -> web, GetWeb(ads, len, (p + i) -> web));
	}
	return p;
}

char *GetUsr(char *ads, int len, char *ret) {
//	strcpy(ret, "pass");
	char usr[100000] = {0};
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
	char dom[100000] = {0};
	int retLen = 0;
	int flg = -1;
	for (int i = len - 1; i > -1; i--) {
		if (ads[i] == '@')
			break;
		if (ads[i] == '.' && flg != 1) {
			flg = 1;
			i--;
		}
		if (flg == 1) {
			dom[retLen] = ads[i];
			retLen++;
		}
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

char *GetWeb(char *ads, int len, char *ret) {
	char web[100000] = {0};
	int retLen;
	for (int i = len - 1; i > -1; i--) { //倒序检索
		if (ads[i] == '.')
			break;
		web[len - i - 1] = ads[i];
		retLen = len - i - 1;
	}

	for (int j = retLen; j > -1; j--) {
		ret[j] = web[retLen - j];
		//printf("ret[%d]:%c\n", j, ret[j]);
	}
	ret[retLen + 1] = '\0';
//	printf("web:%s\n", ret);
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