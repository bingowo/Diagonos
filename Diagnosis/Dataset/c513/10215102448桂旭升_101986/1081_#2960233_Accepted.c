#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int a[N] = {0};
int main(){ 
	int i = 0, n, m, len = 1, t, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &n, &m);
		printf("case #%d:\n", i);
		if(m == 0)printf("1");
		else if(m == 1)printf("%d", n);
		else {
			a[N-1] = n;
			for(j = 1; j < m; j++){
				for(k = len - 1; k >= 0; k--){//printf("%d\n", k);
					a[k + N - len] *= n;
				}
				for(k = len - 1; k >= 0; k--){
					if(a[k + N - len] > 9){
						a[k + N - len - 1] += a[k + N - len] / 10;
						a[k + N - len] = a[k + N - len] % 10;
						if(k == 0)len++;
					}
				}
			}
			for(j = N - len; j < N; j++){
				printf("%d", a[j]);
			}
		}
		if(i != t - 1)printf("\n");
		for(j = 0; j < N; j++){
			a[j] = 0;
		}
		len = 1;
	}
		
	return 0;
}