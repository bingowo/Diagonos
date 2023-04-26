#include <stdio.h>

int main()
{
    int T, cnt = 0;
    scanf("%d", &T);
    unsigned long long chart[74] = {0, 1, 1};
    for (int i = 3; i < 75; i++)
    {
        chart[i] = chart[i - 1] + chart[i - 2] + chart[i - 3];
    }
    while (T)
    {
        printf("case #%d:\n", cnt++);
        int n;
        scanf("%d", &n);
        unsigned long long res = chart[n];
        printf("%lld\n", res);
        T--;
    }
    return 0;
}