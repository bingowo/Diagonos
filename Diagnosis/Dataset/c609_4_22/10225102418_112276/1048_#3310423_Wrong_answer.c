#include <stdio.h>

long long fib(long long m)
{
	if (m==1||m==2)
	return 1;
	long long a=1,b=1,aw=0;
	while(m>=2)
	{
		aw=aw+a;
		a=b;
		b=aw;
		m=m-1;
	}
	return aw;
 } 


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        printf("case #%d:\n",T-1);
        printf("%lld\n", fib(n));
    }
    return 0;
}
