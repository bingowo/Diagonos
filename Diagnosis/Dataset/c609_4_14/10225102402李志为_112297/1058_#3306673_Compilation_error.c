#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct N {
    vector<int> v;
    int cnt;
};

void Div(N& a) {  // 除以2
    int carry = 0;
    if (a.v[a.cnt - 1] < 2) {
        a.v[a.cnt - 1] = 0;
        a.cnt--;
        carry = 1;
    }
    for (int i = a.cnt - 1; i >= 0; i--) {
        int t = carry * 10 + a.v[i];
        a.v[i] = t / 2;
        carry = t % 2;
    }
}

void Add(N& a) {  // 加1
    int carry = 0, i = 1;
    if (a.v[0] == 9) {
        a.v[0] = 0;
        carry = 1;
        if (a.cnt == 1)
            a.cnt++;
    }
    else
        a.v[0]++;
    while (carry != 0) {
        int t = carry + a.v[i];
        if (t == 10) {
            carry = 1;
            a.v[i++] = 0;
        }
        else {
            a.v[i] = t;
            break;
        }
    }
}

int main() {
    string s;
    cin >> s;
    int l = s.size();
    bool sign = true;//true是正，false是负
    N n = { vector<int>(l), 0 };
    for (int i = l - 1; i >= 1; i--) {//倒着存储数据，v的每一个元素都只是一位数
        n.v[n.cnt++] = s[i] - '0';//cnt来表示位数
    }
    if (s[0] == '-')
        sign = false;
    else
        n.v[n.cnt++] = s[0] - '0';
    vector<int> ans;//分析一下我们要做的工作 1.将数存下来，做除法 2.在做除法的同时要将答案存下来
    while (n.cnt > 0) {
        int t = n.v[0] % 2;
        ans.insert(ans.begin(), t);//因为倒置，所以对第一位取余
        Div(n);//除法操作
        if (!sign && t) {
            Add(n);
            sign = true;
            if (n.cnt == 0) {//因为除法操作里有对位数减1的操作，而如果处在这种情况下，不应该结束
                n.cnt++;
                n.v[0] = 1;
            }
        }
        else
            sign = !sign;
    }
    for (auto e : ans) cout << e;

    return 0;
}