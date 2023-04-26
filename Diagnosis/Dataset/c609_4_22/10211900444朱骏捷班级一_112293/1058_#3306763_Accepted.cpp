#include <iostream>
#include <string>
#include <vector>

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

void DIV2(BIGINT &num)
{
    int carry = 0;
    if (num.digit_val[num.cnt - 1] < 2)
        num.cnt--, carry = 1;
    for (int i = num.cnt - 1; i >= 0; i--)
    {
        int t = 10 * carry + num.digit_val[i];
        num.digit_val[i] = t / 2;
        carry = t % 2;
    }
}

void ADD1(BIGINT &num)
{
    int carry = 0, i = 1;
    num.digit_val[0] = num.digit_val[0] + 1;
    carry = num.digit_val[0] / 10;
    num.digit_val[0] = num.digit_val[0] % 10;
    while (carry && i < num.cnt)
    {
        num.digit_val[i] += carry;
        carry = num.digit_val[i] / 10;
        num.digit_val[i] = num.digit_val[i] % 10;
        i++;
    }
    if (carry)
        num.digit_val[i] = carry, num.cnt++;
}

int main()
{
    string s;
    cin >> s;
    int sign = 1;
    BIGINT number;
    for (auto it = s.rbegin(); it != s.rend() - 1; it++)
        number.digit_val[number.cnt++] = *it - '0';
    if (s[0] == '-')
        sign = -1;
    else
        number.digit_val[number.cnt++] = s[0] - '0';
    vector<int> bin{0};
    while (number.cnt > 0)
    {
        int temp = number.digit_val[0] % 2;
        bin.push_back(temp);
        DIV2(number);
        if (sign == -1 && temp)
        {
            if (!number.cnt)
                number.cnt++, number.digit_val[0] = 1;
            else
                ADD1(number);
        }
        sign = -sign;
    }
    for (auto i = bin.rbegin(); i != bin.rend() - 1; i++)
        cout << *i;
    cout << endl;
    return 0;
}