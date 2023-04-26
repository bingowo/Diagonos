#include <stdio.h>
#include <math.h>

int nonrev(int num)
{
    int remainder, i = 0, cnt = 1, res = 1, temp = 0;
    int len = (int)log2(num) + 1;
    char s[len];
    while (len - i)
    {
        remainder = num % 2;
        s[i++] = remainder;
        num /= 2;
    }
    for (int j = len - 1; j > 0; --j)
    {
        if (s[j] != s[j - 1])
        {
            ++cnt;
            res = cnt;
        }
        else
        {
            temp = res;
            cnt = 1;
        }
        if (temp > res)
            res = temp;
    }
    return res;
}

int main()
{
    int n, dec;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &dec);
        int res = nonrev(dec);
        printf("case #%d:\n%d\n", i, res);
    }
    return 0;
}