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

int cmp(int a[], int b[])
{	
	int ret = 0;
	for(int i = 0 ; i < LEN ; i ++){
		if(a[i] > b[i]){
			ret = 1;
			break;
		}else if(a[i] < b[i]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}

int main(void)
{
	char a[LEN], b[LEN];
	while(scanf("%s %s", a, b) != EOF){
		int ia[LEN] = {0}, ib[LEN] = {0};
		int idx, sgn;
		stod(a, ia), stod(b, ib);
		sgn = cmp(ia, ib);
		if(sgn == 1){
			sub(ia, ib);
			for(idx = 0 ; ia[idx] == 0; idx ++);
			for(; idx < LEN; idx ++){
				printf("%d", ia[idx]);
			}	
		}else if(sgn == -1){
			sub(ib, ia);
			for(idx = 0 ; ib[idx] == 0; idx ++);
			printf("-");
			for(; idx < LEN; idx ++){
				printf("%d", ib[idx]);
			}			
		}else{
			printf("0");
		}
		printf("\n");
	}
	
	return 0;
}
