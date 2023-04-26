#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 500


int main()
{
    int num = 0, temp = 0, i = 0, j = 9, n = 0, s[N] = { 0 }, m1[10] = { 0 }, m2[4] = { 0 }, m3[7] = { 0 };
    char c;
    while ((c=getchar()) != 'EOF')
    {
        s[i] = c - '0';
        i++;
        num++;           
    }
    i = 0;
    temp = num;
    printf("0001");
    while (temp != 0)
    {
        m1[j] = temp % 2;
        temp = temp / 2;
        j--;
    }
    j = 9;
    for (i = 0; i < 10; i++)
    {
        printf("%d", m1[i]);
        m1[i] = 0;
    }
    for (i = 0; i < num; i++)
    {
        if (n < 100)
        {
            n = n * 10 + s[i];
        }
        if (n > 100)
        {
            j = 9;
            while (n != 0)
            {
                m1[j] = n % 2;
                n = n / 2;
                j--;
            }
            for (i = 0; i < 10; i++)
            {
                printf("%d", m1[i]);
                m1[i] = 0;
            }
            continue;
        }
        if (i + 3 > num)
        {
            if (n < 10)
            {
                j = 3;
                while (n != 0)
                {
                    m2[j] = n % 2;
                    n = n / 2;
                    j--;
                }
                for (i = 0; i < 4; i++)
                {
                    printf("%d", m2[i]);
                    m2[i] = 0;
                }
                continue;
            }
            else if (n < 100)
            {
                j = 6;
                while (n != 0)
                {
                    m3[j] = n % 2;
                    n = n / 2;
                    j--;
                }
                for (i = 0; i < 7; i++)
                {
                    printf("%d", m3[i]);
                    m3[i] = 0;
                }
                continue;
            }
        }
   
    }

    return(0);
}