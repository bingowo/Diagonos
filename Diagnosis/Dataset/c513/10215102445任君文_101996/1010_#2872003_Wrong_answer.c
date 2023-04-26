#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 200


int main()

{
    int num = 0, num2 = 0, temp = 0, i = 0, j = 9, t = 1, s[N] = { 0 }, m1[10] = { 0 };
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

    for (i = 0; i < num2; i++)
    {
        j = 9;
        while (s[i] != 0)
        {
            m1[j] = s[i] % 2;
            s[i] = s[i] >> 1;
            j--;
        }
        for (i = 0; i < 10; i++)
        {
            printf("%d", m1[i]);
            m1[i] = 0;
        }
    }
    j = 9;
    while (s[num2] != 0)
    {
        m1[j] = s[num2] % 2;
        s[num2] = s[num2] >> 1;
        j--;
    }
    if (num % 3 == 0)
    {
        for (i = 0; i < 10; i++)
        {
            printf("%d", m1[i]);
        }
    }
    else if (num % 3 == 1)
    {
        for (i =6 ; i < 10; i++)
        {
            printf("%d", m1[i]);
        }
    }
    else if(num % 3 == 2)
    {
        for (i = 3; i < 10; i++)
        {
            printf("%d", m1[i]);
        }
    }

    return(0);
}