#include <stdio.h>
#include <stdlib.h>
int a[110];
char key[40];
int main(){
	int t, n, r, i, j, k = 0, flag = 0;
	for(i = 0; i < 36; ++i){
		if(i < 10)	key[i] = i + '0';
		else	key[i] = i - 10 + 'A';
	}
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d%d", &n, &r);
		k = 0;
		flag = 0;
		if(n < 0){
			flag = 1;
			n = -n;
		}
		while(n){
			a[k++] = n % r;
			n /= r;
		}
		if(flag)	printf("-");
		if(k != 0){
			for(j = k - 1; j >= 0; --j)
				printf("%c",key[a[j]]);
		}
		else{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}