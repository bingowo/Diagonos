#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int gcd(int a, int b)
{
    if (b == 0)
        return 1;
    else if (a % b == 0)
        return b;
    else
        gcd(b, a % b);
}
//int MAX(int x, int y)
//{
//  return (x > y ? x : y);
//
//}

int main()
{
    int i=0, small, j,zong,jin=0;
    long k, temp, N, A, B, C, ns=0, t[M] = { 0 }, n[M] = { 0 };
    scanf("%ld %ld", &B, &C);
    A = 0;
    while (B >= C)
    {
        B = B - C;
        A++;
    }
    while (A > 0)
    {
        t[i] = A % 3;
        A = A / 3;
        i++;
    }
    i--;
    N = i;
    for (j = 0; j < N+1; j++)
    {
        n[j] = t[i];
        t[i] = 0;
        i--;
    }
    small = j;
    if (B!=0)
    {
        while (B % 3 == 0)
        {
            B = B / 3;
            C = C / 3;
        }
        temp = C;
        while (temp != 0)
        {
            temp = temp / 3;
            ns++;
        }
        temp = B * C;
        i = 0;
        while (temp != 0)
        {
            t[i] = temp % 3;
            temp = temp / 3;
            i++;
        }
        temp = small;
        for (j = 0; j < ns; j++)
        {
            n[temp] = t[i - ns];
            i++;
            temp++;
        }
    }
    zong = small + ns-1;
    for (i = zong-1; i >= 0; i--)
    {
        n[i + 1] = n[i];
    }
    n[0] = 0;
    for (i = zong - 1; i >= 1; i--)
    {
        n[i] = n[i] + 1+jin;
        jin = 0;
        if (n[i] >= 3)
        {
            n[i] = n[i]-3;
            jin = 1;
        }
    }
    if (jin == 1)
    {
        n[0] = 1;
    }
    if (n[0] == 1)
    {
        for (i = 0; i < zong; i++)
        {
            n[i] = n[i] - 1;
            if (n[i] == -1)
            {
                n[i] = 2;
            }
        }
    }
    else if (n[0] == 0)
    {
        for (i = 1; i < zong; i++)
        {
            n[i] = n[i] - 1;
            if (n[i] == -1)
            {
                n[i] = 2;
            }
        }
    }
    for (i = 1; i < small; i++)
    {
        printf("%d", n[i]);
    }
    printf(".");
    for (i = small; i < zong; i++)
    {
        printf("%d", n[i]);
    }
    printf("\n");  
    return 0;
}