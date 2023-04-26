#include <stdio.h>
typedef long long int lli;

int main()
{
    int T, cnt = 0;
    lli res[51] = {0, 1, 2, 4, 8};
    for (int i = 5; i < 51; i++)
    {
        res[i] = res[i - 1] + res[i - 2] + res[i - 3] + res[i - 4];
    }
    scanf("%d", &T);
    while (T--)
    {
        printf("case #%d:\n", cnt);
        int n;
        scanf("%d", &n);
        printf("%lld\n", res[n]);
    }
    return 0;
}