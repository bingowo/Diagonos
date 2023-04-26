#include <stdio.h>

int main(void)
{
	int one, zero, total;
	one = zero = total = 0;
	int cnt = 0;
	int n;
	scanf("%d", &n);
	int c[n], r[n];
	int order[n], temp[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%d", &c[i]);
		if(c[i] == 1){
			temp[one] = total;
			one ++;
		}else{
			order[zero] = total;
			zero ++;
			cnt ++;
		}
		total ++;
	}
	
	for(int i = 0 ; i < one; i ++){
		order[zero + i] = temp[i];
	}
	
	for(int i = 0, j = 0; i < total; i ++, j = order[j]){
		r[i] = c[order[j]];
		if(r[i] == 0){
			cnt --;
		}
	}
	if(cnt != 0){
		printf("-1");
	}else{
		for(int i = 0 ; i < n ; i ++){
			printf("%d ", r[i]);
		}
	}
	
	return 0;
}