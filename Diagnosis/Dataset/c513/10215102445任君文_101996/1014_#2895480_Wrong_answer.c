#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i = 0, small, j, zong, jin = 0, ns = 0;
    long k, temp, N, A, B, C, t[M] = { 0 }, n[M] = { 0 };
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
    N = N + 1;
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
            n[temp] = t[i - 1];
            i--;
            temp++;
        }
    }
    if (B == 0)
    {
        zong = N ;
    }
    else
    {
        zong = small + ns - 1;
    }
    jin = 0;
    for (i = zong-1 ; i >= 0; i--)
    {
        n[i] = n[i] + 1+jin;
        jin = 0;
        if (n[i] >= 3)
        {
            n[i] = n[i]-3;
            jin = 1;
        }
    }
    for (i = 0; i < zong; i++)
    {
        n[i] = n[i] - 1;
        if (n[i] == -1)
        {
           n[i] = 2;
        }
    }
    for (i = 0; i < small; i++)
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