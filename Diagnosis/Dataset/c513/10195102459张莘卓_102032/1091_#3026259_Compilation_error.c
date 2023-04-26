#include <iostream>
#include <string>
using namespace std;

class NUM {
private:
    int* a;
    int cnt;
    int flag;
    void zeroCheck();
    
public:
    NUM();
    NUM(const NUM&);
    NUM& operator=(const NUM&);
    NUM& operator=(const string&);
    bool operator>=(const NUM&) const;
    NUM operator+(const NUM&) const;
    NUM operator*(const NUM&) const;
    NUM operator-(const NUM&) const;
    friend void complexPrint(const NUM&, const NUM&);
    ~NUM();
};
void complexPrint(const NUM&, const NUM&);

class complex {
private:
    NUM a; //real
    NUM b; //imaginary
    
public:
    complex();
    complex& operator=(const complex&);
    complex operator+(const complex&) const;
    complex operator*(const complex&) const;
    friend istream& operator>>(istream&, complex&);
    friend ostream& operator<<(ostream&, const complex&);
    ~complex();
};
istream& operator>>(istream&, complex&);
ostream& operator<<(ostream&, const complex&);

int main()
{
    complex c, ans;
    int n;
    cin >> c >> n;
    cin.putback('1');
    cin >> ans;
    while(n) {
        if(n % 2) ans = ans * c;
        n /= 2;
        if(n) c = c * c;
    }
    cout << ans;
    return 0;
}




NUM::NUM():cnt(1), flag(1) {
    a = new int[5000]{0};
}

NUM::NUM(const NUM& p) {
    a = new int[5000]{0};
    cnt = p.cnt;
    flag = p.flag;
    for(int i=0; i<cnt; ++i) a[i] = p.a[i];
}

void NUM::zeroCheck() {
    if(cnt==1 && a[0]==0) flag = 1;
}

NUM& NUM::operator=(const NUM & p) {
    cnt = p.cnt;
    flag = p.flag;
    for(int i=0; i<cnt; ++i) a[i] = p.a[i];
    return *this;
}

NUM& NUM::operator=(const string & s) {
    for(int i=0; i<5000; ++i) a[i] = 0;
    int len = (int) s.length();
    for(int i=0; i<len && isdigit(s[len-1-i]); ++i)
        a[i] = s[len-1-i] - '0';
    flag = s[0]=='-' ? -1 : 1;
    cnt = isdigit(s[0]) ? len : len-1;
    return *this;
}

bool NUM::operator>=(const NUM & p) const {
    if(flag != p.flag)
        return flag==1 ? true : false;
    if(cnt != p.cnt)
        return cnt > p.cnt ? true : false;
    for(int i=cnt-1; i>=0; --i)
        if(a[i] > p.a[i]) return true;
        else if(a[i] < p.a[i]) return false;
    return false;
}

NUM NUM::operator+(const NUM & p) const {
    if(flag != p.flag) {
        if(flag == 1) {
            NUM temp{p};  temp.flag *= -1;
            return *this - temp;
        }else {
            NUM temp{*this}; temp.flag *= -1;
            return p - temp;
        }
    }
    NUM ans = p;
    int carry = 0, len = max(cnt,p.cnt);
    for(int i=0; i<len; ++i) {
        ans.a[i] += a[i] + carry;
        carry = ans.a[i] / 10;
        ans.a[i] %= 10;
    }
    if(carry) ans.a[len++] = carry;
    ans.cnt = len;
    ans.zeroCheck();
    return ans;
}

NUM NUM::operator*(const NUM & p) const {
    NUM ans;
    ans.flag = flag * p.flag;
    for(int i=0; i<cnt; ++i)
        for(int j=0; j<p.cnt; ++j)
            ans.a[i+j] += a[i] * p.a[j];
    int i, carry = 0, len = cnt+p.cnt;
    for(i=0; i<len || carry; ++i) {
        ans.a[i] += carry;
        carry = ans.a[i] / 10;
        ans.a[i] %= 10;
    }
    while(i && ans.a[i-1]==0) --i;
    if(i) ans.cnt = i;
    else ans.cnt = 1;
    ans.zeroCheck();
    return ans;
}

NUM NUM::operator-(const NUM & p) const {
    if(flag != p.flag) {
        NUM temp{p};
        temp.flag *= -1;
        return *this + temp;
    }
    if(p >= *this) {
        NUM temp = p - *this;
        temp.flag *= -1;
        temp.zeroCheck();
        return temp;
    }
    NUM ans = *this;
    for(int i=0; i<p.cnt; ++i) {
        if(ans.a[i] < p.a[i]) {
            ans.a[i] += 10;
            int k = i+1;
            while(ans.a[k]==0) ans.a[k++]=9;
            --ans.a[k];
        }
        ans.a[i] -= p.a[i];
    }
    while(ans.cnt && ans.a[ans.cnt-1]==0) --ans.cnt;
    if(!ans.cnt) ++ans.cnt;
    ans.zeroCheck();
    return ans;
}

void complexPrint(const NUM& a, const NUM& b) {
    if(b.cnt==1 && b.a[0]==0) {
        if(a.flag == -1) cout << "-";
        for(int i=a.cnt-1; i>=0; --i) cout << a.a[i];
        cout << endl;
    }else if(a.cnt==1 && a.a[0]==0) {
        if(b.flag == -1) cout << "-";
        if(b.cnt!=1 || b.a[0]!=1)
            for(int i=b.cnt-1; i>=0; --i) cout << b.a[i];
        cout << "i" << endl;
    }else {
        if(a.flag == -1) cout << "-";
        for(int i=a.cnt-1; i>=0; --i) cout << a.a[i];
        cout << (b.flag==1 ? "+" : "-");
        if(b.cnt!=1 || b.a[0]!=1)
            for(int i=b.cnt-1; i>=0; --i) cout << b.a[i];
        cout << "i" << endl;
    }
}

NUM::~NUM() {
    delete[] a;
}

complex::complex():a(), b() {}

complex& complex::operator=(const complex & z) {
    a = z.a;
    b = z.b;
    return *this;
}

complex complex::operator+(const complex & z) const {
    complex ans;
    ans.a = a + z.a;
    ans.b = b + z.b;
    return ans;
}

complex complex::operator*(const complex & z) const {
    complex ans;
    ans.a = a*z.a - b*z.b;
    ans.b = b*z.a + a*z.b;
    return ans;
}

istream& operator>>(istream& stream, complex& z) {
    string s;
    stream >> s;
    if(s.find('i')==string::npos) z.a = s;
    else {
        int end = s.find('i'), len=0, i;
        for(i=end-1; i>=0 && isdigit(s[i]); --i,++len);
        if(i < 0){
            if(len) z.b = s.substr(0,len);
            else z.b = "1";
        }else {
            if(i) z.a = s.substr(0,i);
            if(len) z.b = s.substr(i,len+1);
            else z.b = s[i]=='+' ? "1" : "-1";
        }
    }
    return stream;
}

ostream& operator<<(ostream& s, const complex& z) {
    complexPrint(z.a, z.b);
    return s;
}

complex::~complex() {}
