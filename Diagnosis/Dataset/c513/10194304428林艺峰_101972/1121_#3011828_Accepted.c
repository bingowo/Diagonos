#include<stdio.h>
#include<stdlib.h>
#define Maxn 1010
int w[20], flag[Maxn], str[Maxn], sign[20];
void solve(int num, int n){
	int i;
	if(num == n){
		int sum = 0;
		for(i = 0; i < n; ++i){
			sum += sign[i] * w[i];
		}
		if(sum > 0)	flag[sum] = 1;
		return;
	}
	for(i = -1; i <= 1; i++){
		sign[num] = i;
		solve(num + 1, n);
		sign[num] = 0;
	}
	return;
}
int main(int argc, char *argv[]){
	int n, i, j, total = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%d", &w[i]);
		total += w[i];
	}
	solve(0, n);
	for(i = 1; i <= total; ++i){
		printf("%d", flag[i]);
	}
	return 0;
}