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
    char c;
    unsigned int temp=0;
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        temp=0;
        n=0;
        num=0;
        while ((c = getchar()) != '\n')
        {   
                temp=(unsigned int)c;
                while (temp != 0)
                {
                    num = num + (temp & 1);
                    temp = temp >> 1;
                }
                n++;
        }
        n=n*8;
        g=gcd(num,n);
        num=num/g;
        n=n/8;
        printf("%d/%d\n", num,n);
    }
    return 0;
}