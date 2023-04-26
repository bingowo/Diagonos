#include <iostream>
#include <vector>

using namespace std;

void getTwoComplement(vector<int> &bi, int n) {
    do {

        int mi,res;
        int re = n % (-2); // 假的余数
        mi = n / (-2);//假的商
        n=mi+ ((re < 0) ? 1 : 0); // 商
        res = ((re == -1) ? 1 : re );//真的余数

        bi.push_back(res);   // 将余数压入二进制列表
    } while (n != 0);
}

int main() {
    int n;
    cin >> n;          // 输入一个十进制数
    vector<int> binary;
    getTwoComplement(binary, n);
    // 输出
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
    return 0;
}
