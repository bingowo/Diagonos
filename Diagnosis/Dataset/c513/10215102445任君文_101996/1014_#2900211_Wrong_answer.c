#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i = 0,  j, sum, jin = 0, ns = 0,flag=0,small=0;
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
        N=1;
        n[1]=0;
    }
    else
    {
        temp=A;
        while (temp > 0)
        {
            flag=1;
            t[i] = temp % 3;
            temp = temp / 3;
            i++;
        }
        N=i;//整数个数;
        for (j = 1; j < N+1; j++)
        {
            n[j] = t[i];
            t[i] = 0;
            i--;
        }
    }
    //整数部分；
    ns = N+1;
    if (B!=0)
    {
        while ((B % 3 == 0)&&(C % 3 == 0))
        {
            B = B / 3;
            C = C / 3;
        }
        temp = C;
        while (temp != 0)
        {
            temp = temp / 3;
            small++;
        }
        temp = B * C;
        i = 0;
        while (temp != 0)
        {
            t[i] = temp % 3;
            temp = temp / 3;
            i++;
        }
        temp = ns;
        for (j = 0; j < small; j++)
        {
            n[temp] = t[i - 1];
            i--;
            temp++;
        }
        ns=small;//小数个数；
        
        
    }
    if (B == 0)
    {
        sum = N+1 ;
        ns=0;
    }
    else
    {
        sum = N + ns+1;
    }
    jin = 0;
    for (i = sum ; i >= 1; i--)
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
    for (i = 1; i < sum; i++)
    {
        n[i] = n[i] - 1;
        if (n[i] == -1)
        {
           n[i] = 2;
        }
    }
    if (n[0] == 1)
    {
        for (i = 0; i < N+1; i++)
        {
            printf("%d", n[i]);
        }
    }
    else if(n[0]==0)
    {
        for (i = 1; i < N+1; i++)
        {
            printf("%d", n[i]);
        }
    }
    if (B != 0)
    {
        printf(".");
        for (i = N+1; i < sum; i++)
        {
            printf("%d", n[i]);
        }
    }
    printf("\n");  
    return 0;
}
