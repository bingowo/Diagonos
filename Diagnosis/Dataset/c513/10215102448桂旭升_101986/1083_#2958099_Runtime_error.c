#include <stdio.h>
#include<string.h>
#include<math.h>
#define N 100
int a[N] = {0};
int power(int a, int b){
	int ans = 1;
	if(b == 0)return 1;
	for(int i = 0; i < b; i++){
		ans *= a;
	}
	return ans;
}
int wei(long long a){
	int wei = 0;
	if(a == 0)wei++;
	while(a>0){
		wei++; a /= 10;
	}
	return wei;
}
int main(){ 
	int temp, i, j, t, b, n; long long a, tempa;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d%d", &a, &b, &n);
		temp = power(10, n);
		a = a % temp; tempa = a;
		for(j = 1; j < b; j++){
			a = a*tempa;
			a = a % temp;//printf("%d\n", a);
		}
		printf("case #%d:\n", i);
		for(j = wei(a); j < n; j++)printf("0");
		printf("%lld", a);
		if(i != t-1)printf("\n");
	}
	return 0;
}