#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i = 0, ps, j=0, jin = 0, ns = 0, L;
    long long temp, A = 0, B, C, t[M] = { 0 }, n[M] = { 0 };
    scanf("%lld %lld", &B, &C);
    temp = B*C;
    while (temp != 0)
    {
        t[j]=t[j] + temp % 3;
        temp = temp / 3;
        j++;
    }
    for (i = 1; i < j+1; i++)
    {
        n[i] = t[j-i];
        t[j-i] = 0;
    }
    L = i;
    while (n[L-1] == 0)
    {
        L--;
    }
    temp = C;
    while (temp != 0)
    {
        ns++;
        temp = temp / 3;
    }
    ns--;
    ps = L - ns;
    n[0] = 0;
    jin = 0;
    for (i = L-1; i >= 1; i--)
    {
        n[i] = n[i] + 1 + jin;
        jin = 0;
        if (n[i] >= 3)
        {
            n[i] = n[i] - 3;
            jin = 1;
        }
    }
    if (jin == 1)
    {
        n[0] = 1;
    }
    for (i = 1; i < L; i++)
    {
        n[i] = n[i] - 1;
        if (n[i] == -1)
        {
            n[i] = 2;
        }
    }
    if (n[0] == 1)
    {
        if (ps == 0)
        {
            printf("0");
        }
        else
        {
            for (i = 0; i < ps; i++)
            {
                printf("%lld", n[i]);
            }
        }

    }
    else if (n[0] == 0)
    {
        if (ps == 1)
        {
            printf("0");
        }
        else
        {
            for (i = 1; i < ps; i++)
            {
                printf("%lld", n[i]);
            }
        }

    }
    if (ns != 0)
    {
        printf(".");
        for (i = ps; i < L; i++)
        {
            printf("%lld", n[i]);
        }
    }
    printf("\n");
    return 0;
}