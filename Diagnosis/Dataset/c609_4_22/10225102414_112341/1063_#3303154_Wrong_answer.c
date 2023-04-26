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
    int T;
    for (int i = 0;i < T;i++){
        int n;
        scanf("%d", &n);
        printf("case #%d:\n", i);
        printf("%lld\n", cal(n));
    }
    return 0;
}
