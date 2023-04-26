#include <stdio.h>

int main()
{
    int T, n;
    long long a[51] = {0, 1, 1, 1, 1};
    int i = 4;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d", &n);
        for (int j = i + 1; j <= n; j ++){
            a[j] = a[j - 4] + a[j - 3] + a[j - 2] + a[j - 1];
        }
        if (n > i) i = n;
        printf("case #%d:\n%lld\n", t, a[n]);
    }
    return 0;
}