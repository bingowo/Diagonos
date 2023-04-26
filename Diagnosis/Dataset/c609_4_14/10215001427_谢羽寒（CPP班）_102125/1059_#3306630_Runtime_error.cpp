#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 比较函数
bool cmp(string a, string b) {

   if (a == "0" && b == "0") {  // 如果 a 和 b 都等于 0，直接返回 true
        return true;
    }
    if (a[0] == '-' && b[0] != '-') {  // 如果 a 是负数，b 不是负数，则 a 更小
        return true;
    }
    if (a[0] != '-' && b[0] == '-') {  // 如果 a 不是负数，b 是负数，则 a 更大
        return false;
    }

    if (a[0] == '-') {  // 如果 a 和 b 都是负数，去掉符号位后比较大小
        a = a.substr(1);
        b = b.substr(1);
        try {
        double da = stod(a), db = stod(b);
        return da > db; }
         // 比较大小,负数取绝对值
        catch (...) {
        cerr << "Error: invalid input '" << a << "' or '" << b << "'" << endl;
        return false;
        }
    }

    if (a[0] == '0' && b[0] != '0') {  // 如果 a 是 0，b 不是 0，则 a 更小
        return true;
    }
    if (a[0] != '0' && b[0] == '0') {  // 如果 a 不是 0，b 是 0，则 a 更大
        return false;
    }
    if (a[0] == '+' ) {  // 如果 a 是正数
         a = a.substr(1);
    }
    if (b[0] == '+' ) {  // 如果 a 是正数
         b = b.substr(1);
    }
    try {
        double da = stod(a), db = stod(b);
        return da < db;  // 比较大小
    } catch (...) {
        cerr << "Error: invalid input '" << a << "' or '" << b << "'" << endl;
        return false;
    }
}

int main() {
    int n;
    cin >> n;   // 读取数字个数

    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];   // 读取每个数字，存储到数组中

        //对输入的数值进行校验，判断它们是否符合题目要求。具体而言，数字的长度不超过 100，且不能以多余的 0 开头。
        if (nums[i].length() > 100 || (nums[i][0] == '0' && nums[i].find_first_not_of(".0123456789") != 1)) {
            cerr << "Error: invalid input '" << nums[i] << "'" << endl;
            return 1;
        }
    }

    // 排序
    sort(nums.begin(), nums.end(), cmp);

    // 输出
    for (string num : nums) {
        cout << num << endl;
    }

    return 0;
}