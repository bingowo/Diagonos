#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 101;

struct BigInt
{
    int cnt;
    vector<int> v;

    BigInt() : cnt(0), v(N, 0) {}

    void DIV2()
    {
        int carry = 0;
        if (v[cnt - 1] < 2) cnt--, carry = 1;
        for (int i = cnt - 1; i >= 0; i--)
        {
            int t = 10 * carry + v[i];
            v[i] = t / 2;
            carry = t % 2;
        }
    }

    void ADD1()
    {
        int carry = 0, i = 1;
        v[0] = v[0] + 1;
        carry = v[0] / 10;
        v[0] = v[0] % 10;
        while (carry != 0 && i < cnt)
        {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] = v[i] % 10;
            i++;
        }
        if (carry != 0)
        {
            v[i] = carry;
            cnt++;
        }
    }
};

int main()
{
    // 数据输入
    char s[110];
    scanf("%s", s);
    int sign = 1, len = strlen(s);
    BigInt n;
    for (int i = len - 1; i >= 1; i--)
        n.v[n.cnt++] = s[i] - '0';
    if (s[0] == '-') sign = -1;
    else n.v[n.cnt++] = s[0] - '0';

    vector<int> bin(400, 0);
    int cnt = 0; // bin restore result,cnt restore len

    while (n.cnt > 0)
    {
        int temp = n.v[0] % 2;
        bin[cnt++] = temp;
        n.DIV2();
        if (sign == -1 && temp)
        {
            if (n.cnt == 0)
            {
                n.cnt++;
                n.v[0] = 1;
            }
            else n.ADD1();
        }
        sign = -sign;
    }

    for (int i = cnt - 1; i >= 0; i--)
        cout << bin[i];
    cout << endl;

    return 0;
}
