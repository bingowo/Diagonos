#include <stdio.h>
#define LEN 550

void stod(char s[], int i[])
{
	char *p = NULL;
	int idx = LEN - 1;
	for(p = s; *p; p ++);
	while(1){
		p --;
		i[idx --] = *p - '0';
		if(p == s){
			break;
		}
	}
}

void sub(int a[], int b[])
{
	for(int idx = LEN - 1; idx; idx --){
		a[idx] -= b[idx];
		for(int k = idx; a[k] < 0; k --){
			a[k] += 10;
			a[k - 1] -= 1;
		}
	}
}

int main(void)
{
	char a[LEN], b[LEN];
	while(scanf("%s %s", a, b) != EOF){
		int ia[LEN] = {0}, ib[LEN] = {0};
		int idx;
		stod(a, ia), stod(b, ib);
		sub(ia, ib);
		for(idx = 0 ; ia[idx] == 0; idx ++);
		for(; idx < LEN; idx ++){
			printf("%d", ia[idx]);
		}
		printf("\n");
	}
	
	return 0;
}