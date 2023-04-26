#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    int *map = (int *)malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++)
    {
        int temp;
        scanf("%d", &temp);
        map[i] = cnt(temp);
        printf("case #%d\n", i);
        printf("%d\n", map[i]);
    }
    return 0;
}

int cnt(int p)
{
    int t[32];
    int m = 0;
    while (p != 0)
    {
        t[m] = p % 2;
        p /= 2;
        ++m;
    }
    int pre = 1;
    int cnt = 0;
    for (int i = m - 1; i > 0; i--)
    {
        if (pre != t[i - 1])
        {
            ++cnt;
        }
        else
        {
            break;
        }
    }
    return cnt;
}