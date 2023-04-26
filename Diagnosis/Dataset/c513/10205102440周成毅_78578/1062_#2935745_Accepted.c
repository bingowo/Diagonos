#include <stdio.h>
#include <stdlib.h>
#define MAXN 51

unsigned long long f[MAXN];

int main()
{
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4; i < MAXN; i++)
        f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4];
    int pnum;
    scanf("%d\n", &pnum);
    int n;
    for (int i = 0; i < pnum; i++)
    {
        scanf("%d\n", &n);
        printf("case #%d:\n%llu\n", i, f[n]);
    }
    return 0;
}