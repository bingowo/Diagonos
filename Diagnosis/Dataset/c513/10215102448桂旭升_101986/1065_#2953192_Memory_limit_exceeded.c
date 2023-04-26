#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int b[21] = {0};
int a, n, m;
int f(int x){
	if(x == 1){
		b[x] = a; return b[x];
	}
	if(x == 2){
		b[x] = a; return b[x];
	}
	if(x == 3){
		b[x] = 2*a; return b[x];
	}
	if(x == n-1){
		b[x] = m; return b[x];
	}
	if(x > 3){
		if(b[x] == 0){
			b[x] = (f(x-2) + f(x+1)) / 2;return b[x];
		}
		else return b[x];
	}
}
int main(){
	int x;
	scanf("%d%d%d%d", &a, &n, &m, &x);
	printf("%d", f(x));
	return 0;
}