#include <iostream>
#include <string>

using namespace std;

void dfs(string &str) {
    int len = str.size();
    string str2(str);//用来保存原字符窜

    // 如果当前字符串长度已经等于1，则无法再进行变换，直接返回
    if (len == 1) { return; }

    // 枚举每个字符，将其变换后放回原字符串中
    for (int i = 0; i < len - 1;) {
        // 如果当前字符比后一个字符大，则不进行变换
        if (str2[i] >= str2[i + 1]) { i++; continue; }

        int j = i + 1;
        char mn = str2[i];

        // 找到待插入字符的位置
        while (j < len && str2[j] >= mn) {
            if (str2[j] > mn) mn = str2[j];
            j++;
        }

        // 插入字符并更新指针位置
        str.insert(i, 1, mn);
        str.erase(j, 1);

        if (i > 0) { i--; } // 如果当前字符是第一个，则不变换
    }

    return;
}

int main() {
    string s;
    cin >> s;
    getchar();

    dfs(s);

    cout << s << endl;

    return 0;
}
