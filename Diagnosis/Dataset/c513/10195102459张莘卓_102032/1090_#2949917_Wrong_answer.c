#include <stdio.h>

int multiply(int a, int b) {
    long long ans = (long long)a * (long long)b;
    while(ans >= 1000000000) ans /= 10;
    return (int)ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)) {
        if(n == 0) break;
        int ans = 1, mult = n;
        while(n > 0) {
            if(n % 2) ans = multiply(ans, mult);
            mult = multiply(mult, mult);
            n /= 2;
        }
        while(ans >= 10) ans /= 10;
        printf("%d\n",ans);
    }
    return 0;
}
