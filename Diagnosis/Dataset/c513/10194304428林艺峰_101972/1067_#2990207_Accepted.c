#include<stdio.h>
long long T[80];
int main(){
	int i, n, t;
	T[0] = 0;
	T[1] = 1;
	T[2] = 1;
	for(i = 3; i <= 73; ++i){
		T[i] = T[i-1] + T[i-2] + T[i-3];
	}
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		printf("case #%d:\n%lld\n", i, T[n]);
	}
	return 0;
}