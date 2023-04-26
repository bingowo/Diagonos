#include <stdio.h>

int cmp(void *a, void *b) {
	int n1 = *(int*)a, n2 = *(int*)b;
	return n1 - n2;
}

//int cntdigit()



int main() {
	int data[100000] = {0}; //store the numbers inputted in
	int T;
	scanf("%d", &T);
	int cnt = 0; 
	for(int i = 0; i < T; i++) {
		scanf("%d", &data[cnt++]);
	}
	cnt--;
	qsort(data, cnt, sizeof(int), cmp);
	int sum = 0;
	for(int j = 0; j < T; j++) {
		sum += data[j+1] - data[j];
		j++;
	}
	printf("%d", sum);
}