#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A, B, x, i, j, len, endlen;
    int p[100], * c;
    c = p;
    memset(p, 0, sizeof(p));
    scanf("%d %d", &A, &B);
    x = 0;
    while (B != 1)
    {
        x++;
        B /= 3;
    }
    len = 0;
    while (A >= 3)
    {
        c[len++] = A % 3;
        A = A / 3;
    }
    c[len++] = A;

    for (i = 0;i < len;i++)
    {
        c[i] += 1;
        if (c[i] >= 3)
        {
            c[i] -= 3;
            c[i + 1] += 1;                      //原本这里是什么是不确定的，需要先置0
        }
    }

    for (i = 0;i < len;i++)                     //按位减的时候，进位不需要减
    {
        c[i] -= 1;
        if (c[i] == -1)
            c[i] = 2;
    }

    for (len++;c[len] == 0;len--);               //清除转置前的后置零，即转置后的前导0
    len++;

    for (i = 0, j = len - 1;i < j;i++, j--)
    {
        int temp = c[i];
        c[i] = c[j];
        c[j] = temp;
    }

    for (endlen = len;c[endlen] == 0;endlen--);
    endlen++;


    if (x >= len)
    {
        printf("0.");
        for (i = 0;i < x - len;i++)
            printf("0");
        for (i = 0;i < endlen;i++)
        {
            printf("%d", c[i]);
        }
    }
    else
    {
        for (i = 0;i < endlen;i++)
        {
            printf("%d", c[i]);
            if (x != 0 && i == len - x - 1)
                printf(".");
        }
    }

    return 0;
}
