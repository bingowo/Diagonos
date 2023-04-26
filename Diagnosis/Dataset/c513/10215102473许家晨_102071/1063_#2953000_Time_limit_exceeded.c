#include <stdio.h>
unsigned long long oil(unsigned long long lenth,unsigned long long width)
{
    if (lenth % width == 0)
        return 4 * width * (lenth / width);
    else
        return 4 * width + oil(width, lenth - width);
}
int main()
{
    unsigned long long l, w;
    scanf("%llu %llu", &l, &w);
    printf("%llu", oil(l, w));
}