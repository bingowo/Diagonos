#include <stdio.h>

long long  multiply(long long a, long long b) {
    long long ans = a * b;
    while(ans >= 1000000000) ans /= 10;
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)) {
        if(n == 0) break;
        long long ans = 1, mult = n;
        while(n > 0) {
            if(n % 2) ans = multiply(ans, mult);
            mult = multiply(mult, mult);
            n /= 2;
        }
        while(ans >= 10) ans /= 10;
        printf("%d\n",(int)ans);
    }
    return 0;
}
