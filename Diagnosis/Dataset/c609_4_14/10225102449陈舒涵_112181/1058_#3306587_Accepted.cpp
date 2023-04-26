#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BIGINT {
    int cnt;
    vector<int> v;
};

void DIV2(BIGINT &n)
{
    int carry = 0;
    if (n.v[n.cnt - 1] < 2){
        n.cnt --;
        carry = 1;
    }
    for (int i = n.cnt - 1; i >= 0; i --){
        int t = 10 * carry + n.v[i];
        n.v[i] = t / 2;
        carry = t % 2;
    }
}

void ADD1(BIGINT &n){
    int carry = 0, i = 1;
    n.v[0] ++;
    carry = n.v[0] / 10;
    n.v[0] %= 10;
    while (carry != 0 && i < n.cnt){
        n.v[i] += carry;
        carry = n.v[i] / 10;
        n.v[i] = n.v[i] % 10;
        i ++;
    }
    if (carry != 0){
        n.v[i] = carry;
        n.cnt ++;
    }
}

int main(){
    //输入
    string s;
    cin >> s;
    int sign = 1, len = s.length();
    BIGINT n = {0, {}};
    for (int i = len - 1; i >= 1; i --){  //倒序存放除第一位以外的所有数字
        n.v.push_back(s[i] - '0');
        n.cnt ++;
    }
    if (s[0] == '-'){  //若第一位为负号则记录正负，否则存储数字
        sign = -1;
    }
    else{
        n.v.push_back(s[0] - '0');
        n.cnt ++;
    }

    //计算负二进制
    vector<int> bin;
    int cnt = 0;
    while (n.cnt > 0){
        int temp = n.v[0] % 2;

        bin.push_back(temp);
        DIV2(n);

        if (sign == -1 && temp){
            if (n.cnt == 0){
                n.cnt++;
                n.v[0] = 1;
            }
            else{
                ADD1(n);
            }
        }
        sign = -sign;  //除以-2后变号
    }

    //输出
    for (auto it = bin.rbegin(); it != bin.rend(); it ++){
        cout << *it;
    }
    return 0;
}