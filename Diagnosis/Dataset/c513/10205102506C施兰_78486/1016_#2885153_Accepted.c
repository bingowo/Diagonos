#include <string.h>
#include <stdio.h>
#include <math.h>
char a[100], b;
char convert(int m)
{
    return m < 10 ? '0' + m : 'A' + m - 10;
}
int main()
{
    int n, r;
    while (~scanf("%d%d", &n, &r))
    {
        b = 0;
        while (n)
        {
            int m = (n % r + abs(r)) % abs(r);
            a[b++] = convert(m);
            n -= m;
            n /= r;
        }
        if (b==0)
            printf("0");
        else
            for (int i =b-1; i >= 0; i--)
                printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}