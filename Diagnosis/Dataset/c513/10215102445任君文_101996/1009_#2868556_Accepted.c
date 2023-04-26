#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    if (b == 0)
        return b;
    else if (a % b == 0)
        return b;
    else
        gcd(b, a % b);
}

int main()
{
    int T;
    int  n1 = 0, n2 = 0, i, g, num = 0, res[10] = { 0 }, s[10] = { 0 };
    unsigned char c;
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        while ((c = getchar()) != EOF)
        {   
            if (c == '\n')
                break;
            else if (c < 128)
            {
                while (c > 0)
                {
                    num = num + (c & 1);
                    c = c >> 1;
                }
                n1++;
 

            }
            else
            {
                while (c > 0)
                {
                    num = num + (c & 1);
                    c = c >> 1;
                }
                n2++;
            }
        }
        res[i] = num;
        s[i] = n1 * 8 + n2 * 8;
        n1 = 0;
        n2 = 0;
        num = 0;
    }
    for (i = 0; i < T; i++)
    {
        g = gcd(s[i], res[i]);
        while (g != 1)
        {
            s[i] = s[i] / g;
            res[i] = res[i] / g;
            g = gcd(s[i], res[i]);
        }
        printf("%d/%d\n", res[i], s[i]);
        
    }
    return 0;
}