#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    if(b > a)
    {
        int temp =a;
        a=b;
        b=temp;
    }
    if (b <= 0)
        return b;
    if (a % b == 0)
        return b;
    else
        gcd(b, a % b);
}

int main()
{
    int T;
    int  n = 0, i, g=0, num = 0;
    unsigned char c;
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        n=0;
        num=0;
        while ((c = getchar()) != '\n')
        {   
            while (c > 0)
            {
                num = num + (c & 1);
                c = c >> 1;
            }
            n++;
        }
        n=n*8;
        g=gcd(num,n);
        num=num/g;
        n=n/g;
        printf("%d/%d\n", num,n);
    }
    return 0;
}