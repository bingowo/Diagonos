#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A, B, x, mer, i, j, len;
    int p[100],*c;
    c = p;
    memset(c, 0, sizeof(p));
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

    for (i = 0;i < len;i++)
    {
        c[i] -= 1;
        if (c[i] == -1)
            c[i] = 2;
    }

    if (c[len] != 0)                       //长度可能+1
        len++;

    for (i = 0, j = len - 1;i < j;i++, j--)
    {
        int temp = c[i];
        c[i] = c[j];
        c[j] = temp;
    }

    for (;c[len] == 0;len--,x--);               //删除后置0，同时减小小数的位数
    len++;
    x++;

    for (i = 0;i < len;i++)                 //删除前置0
    {
        if (c[i] == 0)
        {
            c++;
            len--;
        }
        else if (c[i] != 0)
            break;
    }


    for (i=0;i < len;i++)
    {
        
        printf("%d", c[i]);
        if (x != 0 && i == len - x - 1)
            printf(".");
        
    }

    return 0;
}
