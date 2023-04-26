#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A, B, i, j, x, len;
    char res[100];
    scanf("%d %d", &A, &B);

    for (x = 0;B != 1;B /= 3,x++);

    len = 0;
    //memset(res, 0, sizeof(res));
    for (i = 0;i < 100;i++)
        res[i] = '0';
    while (A >= 3)
    {
        if (len == x&&x!=0)
        {
            res[len] = '.';
            len++;
            //res[len++] = '0';
        }
        res[len++] = A % 3+'0';
        A /= 3;
    }
    res[len++] = A+'0';
    if (len <=x)
    {
        for (i = len;i < x;i++)
        {
            res[i] = '0';
        }
        res[x] = '.';
        res[x + 1] = '0';
        len = x + 2;
    }



    for (i = 0;i < len;i++)
    {
        if (res[i] != '.')
        {
            res[i] += 1;
            if (res[i] >= 3+'0')
            {
                res[i] -= 3;
                if (res[i + 1] != '.')
                    res[i + 1] += 1;
                else
                    res[i + 2] += 1;
            }
        }
    }
    
    for (i = 0;i < len;i++)
    {
        if (res[i] != '.')
        {
            res[i] -= 1;
            if (res[i] == -1+'0')
                res[i] = 2+'0';
        }
    }

    if (res[len] != 0)
        len++;

    for (i = 0, j = len - 1;i < j;i++, j--)
    {
        char temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }

    res[len] = 0;
    puts(res);

    return 0;
}