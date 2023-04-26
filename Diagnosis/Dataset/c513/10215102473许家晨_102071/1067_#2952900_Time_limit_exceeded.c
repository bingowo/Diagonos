#include <stdio.h>
long long tribonacci(long long n)
{
    switch (n)
    {
    case (0):
        return 0;
        break;
    case (1):
        return 1;
        break;
    case (2):
        return 1;
        break;
    default:
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
}
int main()
{
    int T, cnt = 0;
    scanf("%d", &T);

    while (T--)
    {
        printf("case #%d:\n", cnt++);
        long long n;
        scanf("%lld", &n);
        long long res = tribonacci(n);
        printf("%lld\n", res);
    }
    return 0;
}