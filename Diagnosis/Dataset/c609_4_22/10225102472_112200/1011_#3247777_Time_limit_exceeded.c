#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long gcd (long long a, long long b)
{

    while (b != 0)
    {

        a = a % b;

        b = b ^ a;

        a = a ^ b;

        b = b ^ a;

    }

    return a;

}

typedef struct
{

    long long integer;

    long long decimal;

} Number;

int main()
{

    Number num;

    int integer[35];

    int decimal[35];

    int top1 = 0;

    int top2 = 0;

    long long answer1 = 0, answer2 = 0;

    char ch;

    scanf("%lld", &num.integer);

    if (ch = getchar() == '.')  scanf("%lld", &num.decimal);

    for (int temp = num.integer; temp != 0; top1++)
    {

        integer[top1] = temp % 10;

        temp /= 10;

    }

    for (int temp = num.decimal; temp != 0; top2++)
    {

        decimal[top2] = temp % 10;

        temp /= 10;

    }

    for (int temp = integer[top1]; top1 >= 0; temp = integer[top1])
    {

        if (temp == 2)  temp = -1;

        if (temp == 0)  temp = 0;

        if (temp == 1)  temp = 1;

        answer1 = answer1 * 3 + temp;

    }

    int len = sizeof(num.decimal) / sizeof(long long);

    for (int temp = num.decimal % 10; num.decimal != 0; temp = num.decimal % 10)
    {

        if (temp == 2)  temp = -1;

        if (temp == 0)  temp = 0;

        if (temp == 1)  temp = 1;

        answer2 = answer2 * 3 + temp;

        num.decimal /= 10;

    }

    printf ("%lld", answer1);

    return 0;

}