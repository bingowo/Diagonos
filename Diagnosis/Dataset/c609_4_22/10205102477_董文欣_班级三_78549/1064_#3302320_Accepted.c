#include <stdio.h>
#include <stdlib.h>

long long solve(long long x, long long y) {
    if (x < y) {
        int tmp = y;
        y = x;
        x = tmp;
    }
    if (y == 0) return 0;
    long long ans;
    ans = (x/y*y*4) + solve(y, x%y);
    return ans;

}


int main()
{
    long long x, y;
    scanf("%lld %lld",&x, &y);
    printf("%lld\n", solve(x, y));
    return 0;
}
