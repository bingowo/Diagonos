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

    BigInteger operator*(const BigInteger &rhs) const {
        BigInteger res;
        res.digits.resize(digits.size() + rhs.digits.size());
        fill(res.digits.begin(), res.digits.end(), 0);
        for (int i = 0; i < (int)digits.size(); i++) {
            long long carry = 0;
            for (int j = 0; j < (int)rhs.digits.size() || carry; j++) {
                long long n = res.digits[i + j] + carry + (long long)digits[i] * (j < (int)rhs.digits.size() ? (long long)rhs.digits[j] : 0);
                carry = n / 10;
                res.digits[i + j] = n % 10;
            }
        }
        res.normalize();
        return res;
    }

    BigInteger operator+(const BigInteger &rhs) const {
        BigInteger res = *this;
        res.digits.resize(max(digits.size(), rhs.digits.size()));
        for (int i = 0, carry = 0; i < (int)res.digits.size() || carry; i++) {
            if (i == (int)res.digits.size()) res.digits.push_back(0);
            res.digits[i] += carry + (i < (int)rhs.digits.size() ? rhs.digits[i] : 0);
            carry = res.digits[i] >= 10;
            if (carry) res.digits[i] -= 10;
        }
        res.normalize();
        return res;
    }

    BigInteger operator-(const int &rhs) const {
        BigInteger temp = rhs;
        return *this - temp;
    }

    bool operator==(const BigInteger &rhs) const {
        return digits == rhs.digits;
    }

    bool operator!=(const BigInteger &rhs) const {
        return !(*this == rhs);
    }

    bool operator<=(const BigInteger &rhs) const {
        return (*this < rhs) || (*this == rhs);
    }

    friend ostream& operator<<(ostream &out, const BigInteger &num) {
        if (num.digits.empty()) {
            out << "0";
        } else {
            for (int i = num.digits.size() - 1; i >= 0; i--) {
                out << num.digits[i];
            }
        }
        return out;
    }

    friend istream& operator>>(istream &in, BigInteger &num) {
        string s;
        in >> s;
        num = 0;
        for (int i = 0; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
        }
        return in;
    }
};

void getTwoComplement(vector<BigInteger> &bi, BigInteger n) {
    do {
        BigInteger res;
        int mi, rem;
        BigInteger re = n % BigInteger(-2); // 假的余数
        mi = n / BigInteger(-2);//假的商
        n = mi + ((re < 0) ? BigInteger(1) : BigInteger(0)); // 商
        rem = (re == BigInteger(-1) ? 1 : re.digits[0]); // 真的余数
        res = rem;
        bi.push_back(res);   // 将余数压入二进制列表
    } while (n != BigInteger(0));
}

int main() {
    BigInteger n;
    cin >> n;          // 输入一个十进制数
    vector<BigInteger> binary;
    getTwoComplement(binary, n);
    // 输出
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
    return 0;
}

