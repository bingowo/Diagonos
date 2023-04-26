#include<stdio.h>
#include<stdlib.h>
long long num[110];
int main(){
	int k, n, i, j;
	scanf("%d%d", &k, &n);
	num[1] = 0;
	num[2] = 1;
	for(i = 3; i <= n; ++i){
		long long sum = 0;
		if(i > k){
			for(j = 1; j <= k; ++j){
				sum += num[i-j];
			}
		}
		else if(i <= k){
			for(j = i - 1; j > 0; --j){
				sum += num[j];
			}
		}
		num[i] = sum;
	}
	printf("%lld", num[n]);
	return 0;
}