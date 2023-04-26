#include<bits/stdc++.h>
using namespace std;

const int N(102);
const int R(-2);

struct T
{
    int sign, d[N], i1, i2;
};

bool isZero(T n)
{
    return n.i1 == n.i2 && n.d[n.i1] == 0;
}
T Dec(T n, int b)
{
    if(b)
    {
        if(!n.sign)
        {
            n.d[n.i2]--;
        }

        else
        {
            int i;
            n.d[i=n.i2]++;
            while(n.d[i]>9)
            {
                n.d[i]=0;
                n.d[--i]++;
            }

            if(i<n.i1)
            {
                n.i1--;
            }
        }
    }

    return n;
}

T DivR(T n)
{
    int i, t, carry=0;
    n.sign = !n.sign;
    for(i=n.i1; i<=n.i2; i++)
    {
        t = n.d[i]&1;
        n.d[i] = (carry*10 + n.d[i])/-R;
        carry = t;
    }
    if(!isZero(n) && !n.d[n.i1])  n.i1++;
    return n;
}

void dec2R(T n)
{
    int b;
    if(!isZero(n)) dec2R(DivR(Dec(n, b=n.d[n.i2]&1))), cout << b;
}

int main()
{
    T n = {0};
    string s; // 使用string代替char*
    ios_base::sync_with_stdio(false); // 关闭cin和cout与stdio的同步
    cin >> s; // 使用cin代替scanf
    for(int i = 0; i < s.size(); i++) // 遍历string中的每个字符
    {
        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i] == '-')  n.sign = 1;
        }
        else
        {
            n.d[n.i2++] = s[i] - '0';
        }
    }
    n.i2--;
    if(isZero(n)) cout << "0";
    else dec2R(n);
    cout << "\n";
    return 0;
}