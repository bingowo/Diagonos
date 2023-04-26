#include <stdio.h>

typedef unsigned long long int lli;

lli reverse(lli n)
{
	lli ret = 0;
	while(n > 0){
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main(void)
{
	lli n, m;
	lli sum;
	int cnt = 0;
	scanf("%lld", &n);
	while((m = reverse(n)) != n){
		n = m + n;
		cnt ++;
	}
	printf("%d %lld", cnt, n);
	
	return 0;
}