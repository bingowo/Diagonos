#include <stdio.h>
#include <math.h>

void d2x(int dec, int R)
{
    int n = dec;
    int len = (int)(log(abs(n)) / log(R)) + 1;
    char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0, k = 0;
    char s[len];
    if (n < 0)
    {
        n = -n;
        i = 1;
        printf("-");
        k = 1;
    }
    do
    {
        s[i++] = xdigits[n % R];
    } while (n /= R);

    for (int j = len - 1; j >= k; --j)
        printf("%c", s[j]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int dec, R;
        scanf("%d %d", &dec, &R);
        d2x(dec, R);
    }
    return 0;
}