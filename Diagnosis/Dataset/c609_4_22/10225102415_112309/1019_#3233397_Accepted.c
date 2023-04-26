#include <stdio.h>

int cntdigit(int n) {
	if (n < 0) n = -n;
	int ret = 0;
	while (n) {
		n /= 10;
		ret++;
	}
	return ret;
}

int cmp(void *a, void *b) {
	int n1 = *(int*)a, n2 = *(int*)b;
	int cntn1, cntn2;
	cntn1 = cntdigit(n1);
	cntn2 = cntdigit(n2);
	//printf("cntn1:%d cntn2:%d\n", cntn1, cntn2);
	if (cntn1 != cntn2){
		return cntn2 - cntn1;
	}
	return n1 - n2;
}

int main() {
	int data[1000000] = {0}; //store the numbers inputted in
	int cnt = 1;
	//printf("test\n");
	scanf("%d", &data[0]);
	while((scanf("%d", &data[cnt++])) != EOF);
	cnt--;
	qsort(data, cnt, sizeof(int), cmp);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}