#include <stdio.h>

int fib(int m)
{
	if (m==1||m==2)
	return 1;
	int a=1,b=1,aw=0;
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
        int n;
        scanf("%d", &n);
        printf("%d\n", fib(n));
    }
    return 0;
}
