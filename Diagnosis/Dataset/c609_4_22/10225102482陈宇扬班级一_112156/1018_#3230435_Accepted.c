#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LL long long int
int cmpA(const void *a, const void *b)
{
    return *(LL *)a - *(LL *)b;
}

int main()
{
    int n;
    LL s[100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &s[i]);
    qsort(s, n, sizeof(s[0]), cmpA);
    LL sum_min = 0;
    for (int j = 0; j < n; j += 2)
    {
        sum_min += (s[j + 1] - s[j]);
    }
    printf("%lld\n", sum_min);
    system("pause");
    return 0;
}
