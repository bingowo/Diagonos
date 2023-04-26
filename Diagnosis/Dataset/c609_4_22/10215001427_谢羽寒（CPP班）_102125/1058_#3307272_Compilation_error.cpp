#include <iostream>
#include <vector>

using namespace std;

struct BigInteger {
    vector<int> digits;

    BigInteger() {}

    BigInteger(long long n) {
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    BigInteger operator-() const {
        BigInteger res = *this;
        for (int i = 0; i < res.digits.size(); i++) {
            res.digits[i] = -res.digits[i];
        }
        return res;
    }

    bool isPositive() const {
        return digits.empty() || digits.back() >= 0;
    }

    void normalize() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
        for (int i = 0; i < digits.size() - 1; i++) {
            if (digits[i] < 0) {
                digits[i] += 10;
                digits[i + 1]--;
            }
            if (digits[i] >= 10) {
                digits[i] -= 10;
                digits[i + 1]++;
            }
        }
        if (digits.back() < 0) {
            digits.back() *= -1;
            digits.push_back(-1);
        }
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
    }
};

const int base = 10;

BigInteger operator+(const BigInteger &a, const BigInteger &b) {
    BigInteger res;
    int carry = 0;
    for (int i = 0; i < (int)max(a.digits.size(), b.digits.size()) || carry; i++) {
        if (i < (int)a.digits.size()) {
            carry += a.digits[i];
        }
        if (i < (int)b.digits.size()) {
            carry += b.digits[i];
        }
        res.digits.push_back(carry % base);
        carry /= base;
    }
    res.normalize();
    return res;
}

BigInteger operator-(const BigInteger &a, const BigInteger &b) {
    BigInteger res;
    int carry = 0;
    for (int i = 0; i < (int)a.digits.size(); i++) {
        carry += a.digits[i];
        if (i < (int)b.digits.size()) {
            carry -= b.digits[i];
        }
        res.digits.push_back((carry + base) % base);
        if (carry < 0) {
            carry = -1;
        } else {
            carry = 0;
        }
    }
    res.normalize();
    return res;
}

bool operator<(const BigInteger &a, const BigInteger &b) {
    if (a.digits.size() != b.digits.size()) {
        return a.digits.size() < b.digits.size();
    }
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        if (a.digits[i] != b.digits[i]) {
            return a.digits[i] < b.digits[i];
        }
    }
    return false;
}

void getTwoComplement(vector<int> &bi, BigInteger n) {
    do {
        int mi,res;
        BigInteger re = n % BigInteger(-2); // 假的余数
        mi = n / BigInteger(-2);//假的商
        n=mi+(re < 0 ? BigInteger(1) : BigInteger(0)); // 商
        res = (re == BigInteger(-1) ? 1 : re.digits[0]); // 真的余数
        bi.push_back(res);   // 将余数压入二进制列表
    } while (n != BigInteger(0));
}

int main() {
    BigInteger n;
    string s;
    cin >> s;          // 输入一个十进制数
    n=0;
    for(int i=0;i<s.size();i++){
        n=n*BigInteger(10)+(s[i]-'0');
    }
    vector<int> binary;
    getTwoComplement(binary, n);
    // 输出
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
    return 0;
}
