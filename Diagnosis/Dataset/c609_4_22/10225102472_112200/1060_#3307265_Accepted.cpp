#include<bits/stdc++.h>
using namespace std;

int main() {
    string in, out; 
    cin >> in; 
    int i = 0;
    for (; i < in.length() - 1; i++) {
        int next = i;
        // 查找连续相同字符的结束位置，记为 next
        while (in[next] == in[next + 1]) next++;
        // 当前字符的最后位置为 next
        if (in[i] < in[next + 1]) {
            // 当前字符的 ASCII 码小于下一个字符的 ASCII 码，需要进行 RLE 编码
            for (int v = 0; v <= next - i; v++) {
                // 复制字符并追加到输出字符串中
                out.insert(out.end(), in[i]);
                out.insert(out.end(), in[i]);
            }
        } else {
            // 当前字符的 ASCII 码大于等于下一个字符的 ASCII 码，直接复制到输出字符串中
            for (int v = 0; v <= next - i; v++) {
                out.insert(out.end(), in[i]);
            }
        }
        i = next; // 由于 next 指向下一个字符，更新 i 的位置
    }
    // 处理输入字符串的最后一个字符
    out.insert(out.end(), in[i]);
    // 输出 RLE 编码后的字符串
    cout << out << endl;
    return 0;
}
