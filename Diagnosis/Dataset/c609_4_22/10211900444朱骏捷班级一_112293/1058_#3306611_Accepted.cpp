#include <iostream>
#include <string>
using namespace std;

const int N = 110;

struct BIGINT
{
    int cnt, digit_val[N];
    BIGINT()
    {
        cnt = 0;
        *digit_val = 0;
    }
};

void DIV2(BIGINT *num)
{
    int carry = 0;
    if (num->digit_val[num->cnt - 1] < 2)
        num->cnt--, carry = 1;
    for (int i = num->cnt - 1; i >= 0; i--)
    {
        int t = 10 * carry + num->digit_val[i];
        num->digit_val[i] = t / 2;
        carry = t % 2;
    }
}

void ADD1(BIGINT *num)
{
    int carry = 0, i = 1;
    num->digit_val[0] = num->digit_val[0] + 1;
    carry = num->digit_val[0] / 10;
    num->digit_val[0] = num->digit_val[0] % 10;
    while (carry && i < num->cnt)
    {
        num->digit_val[i] += carry;
        carry = num->digit_val[i] / 10;
        num->digit_val[i] = num->digit_val[i] % 10;
        i++;
    }
    if (carry)
        num->digit_val[i] = carry, num->cnt++;
}

int main()
{
    string s;
    cin >> s;
    int sign = 1;
    BIGINT number;
    for (int i = s.length() - 1; i > 0; i--)
        number.digit_val[number.cnt++] = s[i] - '0';
    if (s[0] == '-')
        sign = -1;
    else
        number.digit_val[number.cnt++] = s[0] - '0';
    int bin[N * 10] = {0}, count = 0;
    while (number.cnt > 0)
    {
        int temp = number.digit_val[0] % 2;
        bin[count++] = temp;
        DIV2(&number);
        if (sign == -1 && temp)
        {
            if (!number.cnt)
                number.cnt++, number.digit_val[0] = 1;
            else
                ADD1(&number);
        }
        sign = -sign;
    }
    for (int i = count - 1; i >= 0; i--)
        cout << bin[i];
    cout << endl;
    return 0;
}
