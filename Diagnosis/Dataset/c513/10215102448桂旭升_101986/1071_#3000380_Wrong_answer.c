#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 10007;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 10007;
    }
    return result;
}
long long C(long long a, long long b, long long p)  // 通过定义求组合数C(a, b)，乘法逆元
{
    if (a < b) return 0;

    long long x = 1, y = 1;  // x是分子，y是分母
    for (long long i = a, j = 1; j <= b; i --, j ++ )
    {
        x = x * i % p;
        y = y * j % p;
    }

    return x * fastPower(y, p - 2) % p;
}

long long lucas(long long a, long long b, long long p)
{
    if (a < p && b < p) return C(a, b, p);
    return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main(){
	int i, j,d, flag, t;
    long long a, b, k, m, n;
    char c;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        printf("case #%d:\n", i);
        scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
        //printf("%d %d %d\n", n, m, d);
        if(a != 0 && b != 0)printf("%lld\n", lucas(k, n, 10007)*fastPower(a, n)*fastPower(b, m)%10007);
        else if(a == 0 && b != 0)printf("%lld\n", fastPower(a, n));
        else if(a != 0 && b == 0)printf("%lld\n", fastPower(b, m));
        
    }
    system("pause");
	return 0;
}