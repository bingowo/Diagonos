#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans[110];
int main(){
	int t, i, j, k, len = 0, temp = 0, a, n;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d%d", &a, &n);
		memset(ans, 0, sizeof(ans));
		temp = 0;
		ans[0] = 1;
		len = 1;
		for(j = 0; j < n; ++j){
			for(k = 0; k < len; ++k){
				int now = (ans[k] * a + temp) % 10;
				temp = (ans[k] * a + temp) / 10;
				ans[k] = now;
			}
			if(temp != 0){
				ans[len] = temp;
				len += 1;
			}
			temp = 0;
		}
		for(j = len - 1; j >= 0; --j){
			printf("%d", ans[j]);
		}
		printf("\n");
	}
	return 0;
}