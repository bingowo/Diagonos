#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    unsigned int x, y, z, i, num = 0, f[100] = { 0 };
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%u%u", &x, &y);
        z = x ^ y;
        while (z != 0)
        {
            num = num + (z & 1);
            z >> 1;
        }
        f[i] = num;
    }
    for (i = 0; i < T; i++)
    {
        printf("%d\n", f[i]);
    }
    return 0;
}