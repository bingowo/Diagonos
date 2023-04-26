#include <stdio.h>
#include <math.h>

void dto2333(long long num)
{
    int remainder, i = 0;
    int s[(int)(1.0e18 / 2333)];
    do
    {
        remainder = num % 2333;
        s[i++] = remainder;
    } while (num /= 2333);
    for (int j = i - 1; j > 0; --j)
    {
        printf("%d ", s[j]);
    }
    printf("%d\n", s[0]);
}

int main()
{
    int n;
    long long dec;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &dec);
        dto2333(dec);
    }
    return 0;
}
