#include <stdio.h>
#include <stdlib.h>
int a[110];
char key[40];
int main(){
	int t, r, i, j, k, flag = 0;
	long long n;
	for(i = 0; i < 36; ++i){
		if(i < 10)	key[i] = i + '0';
		else	key[i] = i - 10 + 'A';
	}
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%lld%d", &n, &r);
		k = 0;
		if(n < 0){
			flag = 1;
			n = -n;
		}
		while(n){
			a[k++] = n % r;
			n /= r;
		}
		if(flag)	printf("-");
		for(j = k - 1; j >= 0; --j)	printf("%c",key[a[j]]);
		printf("\n");
	}
	return 0;
}