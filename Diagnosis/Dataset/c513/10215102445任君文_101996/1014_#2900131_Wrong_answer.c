#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i = 0, small, j, zong, jin = 0, ns = 0;
    int temp, N, A, B, C, t[M] = { 0 }, n[M] = { 0 };
    scanf("%d %d", &B, &C);
    A = 0;
    while (B >= C)
    {
        B = B - C;
        A++;
    }
    if(A==0)
    {
        printf("0");
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
        small = N;
    }
    else
    {
        zong = small + ns - 1;
    }
    
    for (i = zong; i >= 1; i--)
    {
        n[i] = n[i - 1];
    }
    n[0] = 0;
    jin = 0;
    for (i = zong ; i >= 1; i--)
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
    for (i = 1; i < zong+1; i++)
    {
        n[i] = n[i] - 1;
        if (n[i] == -1)
        {
           n[i] = 2;
        }
    }
    if (n[0] == 1)
    {
        for (i = 0; i < small+1; i++)
        {
            printf("%d", n[i]);
        }
    }
    else if(n[0]==0)
    {
        for (i = 1; i < small+1; i++)
        {
            printf("%d", n[i]);
        }
    }
    if (B != 0)
    {
        printf(".");
        for (i = small + 1; i < zong + 1; i++)
        {
            printf("%d", n[i]);
        }
    }
    printf("\n");  
    return 0;
}
