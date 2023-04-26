#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#define M 100
int main()
{
    int T;
    int temp = 0;
    int i, j, k;
    int L, n;
    int f = 0, a = 0, g = 0;
    char c;
    int s1[M] = { 0 };
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        j = 0;
        k = 0;
        L = 0;
        a = 0;
        g = 0;
        f = 0;
        while ((c = getchar()) != '\n')
        {
            temp = c - 'A' + 1;
            s1[j] = temp;
            j++;
        }
        s1[j] = 0;
        L = j;
        printf("case #%d:\n", i);
        n = L;
        while (a == 0)
        {
            a = 1;
            for (j = 0; j < n; j++)
            {
                k = j + 1;
                f = 0;
                while ((s1[j] == s1[k]) && (k < n))
                {
                    s1[k] = 0;
                    k++;
                    f = 1;
                }
                if (f == 1)
                {
                    s1[j] = 0;
                    j = k-1;
                }
            }
            j = 0;
            while (j < n)
            {
                if (s1[j] == 0)
                {
                    for (k = j; k < n - 1; k++)
                    {
                        s1[k] = s1[k + 1];
                    }
                    n--;
                }
                else
                {
                    j++;
                }
            }
            for (j = 0; j < n - 1; j++)
            {
                if (s1[j] == s1[j + 1])
                {
                    a = 0;
                    break;
                }
            }
        }
        if (n == 0)
        {
            printf("%d\n", L + 1);
        }
        else if (n == 1)
        {
            printf("%d\n", L + 1);
        }
        else
        {
            for (j = 1; j < n - 1; j++)
            {
                if (s1[j - 1] == s1[j + 1])
                {
                    g = 1;
                }
            }
            if (g == 1)
            {
                n = n - 3;
                printf("%d\n", L + 1 - n);
            }
            else if (g == 0)
            {
                n--;
                printf("%d\n", L - n + 1);
            }
        }
    }
    return 0;
}