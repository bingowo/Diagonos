#include <stdio.h>

long long cal(int n)
{
    if (n >= 4) return 8 * cal(n - 4);
    if (n == 3) return 4 * cal(n - 3);
    if (n == 2) return 2 * cal(n - 2);
    return 1;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) printf("%lld\n", cal(n));
    return 0;
}
