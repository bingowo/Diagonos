#include<stdio.h>
int a[1010];
int main(){
	int t, n, i;
	scanf("%d", &t);
	a[0] = 0;
	for(i = 1; i <= 1000; ++i){
		a[i] = a[i-1];
		if(i % 5 == 0){
			int x = i;
			while(x % 5 == 0){
				a[i] += 1;
				x /= 5;
			}
		}
	}
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		printf("case #%d:\n%d\n", i, a[n]);
	}
	return 0;
}