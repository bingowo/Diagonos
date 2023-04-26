#include <stdio.h>

int reverse(int n)
{
	int ret = 0;
	while(n > 0){
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main(void)
{
	int n, m, int;
	int cnt = 0;
	scanf("%d", &n);
	while(reverse(n)) != n){
	    m=reverse(n);
		n = m + n;
		cnt ++;
	}
	printf("%d %d", cnt, n);
	
	return 0;
}
