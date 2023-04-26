#include <stdio.h>
#include <math.h>

void d2x(int n, int r)
{
    int len = (int)(log(abs(n)) / log(r)) + 1;
    char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    char s[len];
    if (n < 0)
    {
        n = -n;
        printf("-");
    }
    do
    {
        s[i++] = xdigits[n % r];
    } while (n /= r);
    
    for (int j = len - 1; j >= 0; --j)
        printf("%c", s[j]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int dec, R;
        scanf("%d %d", &dec, &R);
        d2x(dec, R);
    }
    return 0;
}