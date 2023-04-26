#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void func(int n, int r)
{
    int len = n ? (int)(log(abs(n)) / log(abs(r) + 1e-8)) + 1 : 0;
    char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    char s[len];
    while (n)
    {
        if (n % r < 0)
        {
            s[i++] = xdigits[-r + n % r];
            n = 1 + n / r;
        }
        else
        {
            s[i++] = xdigits[n % r];
            n /= r;
        }
    }
    for (int j = len - 1; j >= 0; --j)
        printf("%c", s[j]);
    printf("\n");
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    func(n, r);
    return 0;
}