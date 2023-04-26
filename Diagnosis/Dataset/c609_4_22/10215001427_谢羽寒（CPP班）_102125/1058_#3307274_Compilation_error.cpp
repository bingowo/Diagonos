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

    bool operator<(const BigInteger &rhs) const {
        if (digits.size() != rhs.digits.size()) {
            return digits.size() < rhs.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != rhs.digits[i]) {
                return digits[i] < rhs.digits[i];
            }
        }
        return false;
    }

    BigInteger operator-(const BigInteger &rhs) const {
        BigInteger res = *this;
        for (int i = 0, borrow = 0; i < (int)max(digits.size(), rhs.digits.size()) || borrow; i++) {
            if (i < (int)rhs.digits.size()) {
                borrow += rhs.digits[i];
            }
            if ((long long)res.digits[i] - borrow < 0) {
                res.digits[i] = res.digits[i] - borrow + 10;
                borrow = 1;
            } else {
                res.digits[i] = res.digits[i] - borrow;
                borrow = 0;
            }
        }
        res.normalize();
        return res;
    }

    pair<BigInteger, BigInteger> divmod(const BigInteger &rhs) const {
        BigInteger quotient, remainder;
        remainder = 0;
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + digits[i];
            int q = 0;
            if (remainder >= rhs) {
                BigInteger d = rhs;
                int m = 1;
                while ((d * 10) <= remainder) {
                    d = d * 10;
                    m = m * 10;
                }
                while (d <= remainder) {
                    remainder = remainder - d;
                    q += m;
                }
            }
            quotient = q + quotient * 10;
        }
        quotient.normalize();
        remainder.normalize();
        return make_pair(quotient, remainder);
    }

    BigInteger operator/(const BigInteger &rhs) const {
        return divmod(rhs).first;
    }

    BigInteger operator%(const BigInteger &rhs) const {
        return divmod(rhs).second;
    }
};

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
