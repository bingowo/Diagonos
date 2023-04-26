#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void func(int n, int r)
{
    char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    char s[16];
    do
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
    } while (n);
    s[i] = '\0';
    for (int j = i - 1; j >= 0; --j)
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