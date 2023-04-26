#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
int gcd(int a, int b)
{
    if (b == 0)
        return 1;
    else if (a % b == 0)
        return b;
    else
        gcd(b, a % b);
}
int main()
{
    long k, temp,g,A,B,C;
    char c;
    A = 0;
    C = 1;
    B = 0;
    k = 1;
    while ((c = getchar()) != '\n')
    {
        if (c == '.')
        {
            k = -1;
        }
        else
        {
            if (c == '1')
            {
                temp = 1;
            }
            else if (c == '0')
            {
                temp = 0;
            }
            else if (c == '2')
            {
                temp = -1;
            }
            if (k == 1)
            {
                A = A * 3 + temp;
            }
            else if (k == -1)
            {
                B = B * 3 + temp;
                C = C * 3;
            }
            
        }
    }
    if (B == 0)
    {
        printf("%ld\n", A);
    }
    else
    {
        if (B < 0)
        {
            temp = -B;
            k = -1;
        }
        else
        {
            temp = B;
            k = 1;
        }
        while (temp >= C)
        {
            temp = temp - C;
            if (k == 1)
            {
                A++;
            }
            else if (k == -1)
            {
                A--;
            }
            
        }
        if (temp == 0)
        {
            printf("%ld\n", A);
        }
        else
        {
            B = k * temp;
            g = gcd(temp, C);
            if (g != 1)
            {
                B = B / g;
                C = C / g;
            }
            if (A == 0)
            {
                printf("%ld %ld\n", B, C);
            }
            else
            {
                if(B<0)
                {
                    A--;
                    B=B+C;
                }
                printf("%ld %ld %ld\n", A, B, C);
            }
 
        }


    }
    return 0;
}
