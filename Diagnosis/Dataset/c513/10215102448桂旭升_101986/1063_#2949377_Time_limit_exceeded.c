#include <stdio.h>
#include<string.h>
#include<math.h>
long long num = 0;
void con(long long x, long long y){
	long long min, max;
	if(x == y){
		num += 4*x;
	}
	if(x != y){
		if(x > 2*y){
			num += (x/y - 1)*4*y;
			x = x%y+y;
			con(y, x);
		}
		else{
			num += 4*y;
			x = x - y; min = x > y? y:x; max = x > y? x:y;
			con(max, min);
		}
		
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

		
	