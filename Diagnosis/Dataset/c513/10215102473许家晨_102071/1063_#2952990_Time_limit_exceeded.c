#include <stdio.h>
long long oil(long long lenth, long long width)
{
    if (lenth % width == 0)
        return 4 * width * (lenth / width);
    else
        return 4 * width + oil(width, lenth - width);
}
int main()
{
    long long l, w;
    scanf("%lld %lld", &l, &w);
    printf("%lld", oil(l, w));
}