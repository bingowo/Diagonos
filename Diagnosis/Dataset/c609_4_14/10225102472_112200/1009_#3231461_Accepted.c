#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int m, int n) //求最小公约数
{
    for (int i = m; i > 0; i--)
    {
        if ((m % i == 0) && (n % i ==0))
            return i;
    }
}

int one_number(char c) //统计1的个数
{
    int number = 0;
    int d = 1;

    for (int i = 0; i < 8; i++)
    {
        if ((c & d)) number++;
        d <<= 1;
    }

    return number;
}

int main()
{
    int n;

    scanf("%d", &n);

    getchar();
    for (int i = 0; i < n; i++)
    {
        char str[120] = "\0";
        char ch;
        int index = 0;

        while ((ch = getchar()) != '\n')
        {
            str[index++] = ch;
        }

        int len = strlen(str);
        int one = 0;
        for (int j = 0; j < len; j++)
        {
            one += one_number(str[j]);
        }

        int all = len * 8;

        int commonfactor = gcd(one, all);

        one /= commonfactor;
        all /= commonfactor;
        printf ("%d/%d\n", one, all);
    }

    return 0;
}
