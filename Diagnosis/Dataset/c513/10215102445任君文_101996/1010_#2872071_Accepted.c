#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 300


int main()

{
    int num = 0, num2 = 0, temp = 0, i = 0, j = 9, t = 1,f,a, s[N] = { 0 }, m[10] = { 0 };
    char c;
    while ((c=getchar()) != '\n')
    {
        if (t < 4)
        {
            temp = temp * 10 + (c - '0');
            t++;
        }
        else
        {
            s[i] = temp;
            i++;
            temp = 0;
            t = 2;
            temp = temp * 10 + (c - '0');
        }
        num++;           
    }
    s[i] = temp;
    num2 = i;
    f = num % 3;
    printf("0001");
    while (num != 0)
    {
        m[j] = num &1;
        num = num >>1;
        j--;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d", m[i]);
        m[i] = 0;
    }

    for (i = 0; i < num2; i++)
    {
        j = 9;
        while (s[i] != 0)
        {
            m[j] = s[i] & 1;
            s[i] = s[i] >> 1;
            j--;
        }
        for (a = 0; a < 10; a++)
        {
            printf("%d", m[a]);
            m[a] = 0;
        }
    }
    j = 9;
    while (s[num2] != 0)
    {
        m[j] = s[num2] % 2;
        s[num2] = s[num2] >> 1;
        j--;
    }
    if (f == 0)
    {
        for (i = 0; i < 10; i++)
        {
            printf("%d", m[i]);
        }
    }
    else if (f == 1)
    {
        for (i =6 ; i < 10; i++)
        {
            printf("%d", m[i]);
        }
    }
    else if(f == 2)
    {
        for (i = 3; i < 10; i++)
        {
            printf("%d", m[i]);
        }
    }

    return(0);
}