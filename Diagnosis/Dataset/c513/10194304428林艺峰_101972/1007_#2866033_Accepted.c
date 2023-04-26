#include <stdio.h>
#include <stdlib.h>
int num[32];
int main(){
	int t, i, j, k, n, m = 0, l = 0, maxn = 0;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		m = 0;
		while(n){
			num[m++] = n % 2;
			n = n / 2;
		}
		maxn = 0;
		for(j = 0; j < m; ++j){
			l = 1;
			for(k = j + 1; k < m; ++k){
				if(num[k] != num[k-1])	l += 1;
				else	break;
			}
			if(l > maxn)	maxn = l;
		}
		printf("case #%d:\n%d\n", i, maxn);
	}
	return 0;
}