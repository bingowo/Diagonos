#include <stdio.h>
#include<string.h>
#include<ctype.h>
long long num = 0;
void con(int x, int y){
	int min, max;
	if(x == y){
		num += 4*x;return;
	}
	if(x != y){
		num += 4*y;
		x = x - y; min = x > y? y:x; max = x > y? x:y;
		con(max, min);
	}
}
int main(){
	long long n, m, min, max;
	scanf("%lld%lld", &n, &m);
	min = n > m? m:n; max = n > m? n:m;
	con(max, min);
	printf("%lld\n", num);
	return 0;
}

		
	