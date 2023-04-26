#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    unsigned int x, y;
    unsigned int z, num;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%u %u", &x, &y);
        num=0;
        z = x ^ y;
        while (z > 0)
        {
            num = num + (z & 1);
            z=z >> 1;
        }
        printf("%d\n",num);
    }
    return 0;
}