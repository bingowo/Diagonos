#include <stdio.h>
#include<string.h>
#include<math.h>
#define N 100
int a[N] = {0};
int whe(int x){
	int re = 0;
	if(x%10 == 0 && x != 0)return 0;
	while(x > re){
		re = re * 10 + x % 10;
		x /= 10;
	}
	return x == re || x == re / 10;
}
int add(int a){
	int wei = 0, wide = 1;
	while(wide <= a){
		wei = wei * 10 + (a / wide) % 10;//printf("%d\n", wei);
		wide *= 10;
	}
	return a + wei;
}
int main(){ 
	int i = 0, n;
	scanf("%d", &n);
	while(whe(n) == 0){
		i++;
		n = add(n);
	}
	printf("%d %d", i, n);
	return 0;
}