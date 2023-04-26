#include <stdio.h>
#include<string.h>
#include<math.h>
long long num = 0;
void con(long long x, long long y){
	if(x % y == 0)num += (x / y) * 4 * y;
	else{
		num += (x/y)*4*y;
		x = x%y;
		con(y, x);
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

		
	