#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_num[110]; 
int main(){
	int i;
	long long mult = 1, a = 0, b = 0, r = 0, num = 0;
	scanf("%lld", &a);
	while(a != 0 || b != 0){
		if((a % 2 + b % 2) == 1)	r = 1;
		else	r = 0;
		str_num[num++] = r;
		long long a1 = (r - a + b) / 2, b1 = (r - a - b) / 2;
		a = a1;
		b = b1;
//		printf("%lld %lld\n",a,b);
	}
	for(i = num - 1; i >= 0; --i)	printf("%d", str_num[i]);
	return 0;
}