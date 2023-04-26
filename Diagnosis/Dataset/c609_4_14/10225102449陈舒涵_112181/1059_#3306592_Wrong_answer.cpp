#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct NUMBER{
    string s;
    string z;
    string f;
    int sign;
};

bool cmp (const NUMBER a, const NUMBER b){
    int k = 1;
    if (a.sign < 0 && b.sign < 0) k = -1;
    if (a.sign != b.sign){
        return a.sign < b.sign;
    }
    else if (a.z.length() != b.z.length()){
        return k * a.z.length() < k * b.z.length();
    }
    else{
        int i = 0;
        while (i < a.z.length()){
            if (a.z[i] != b.z[i]) return k * a.z[i] < k * b.z[i];
            i ++;
        }
        int j = 0;
        while (j < a.f.length() && j < b.f.length()){
            if (a.f[j] != b.f[j]) return k * a.f[j] < k * b.f[j];
            j ++;
        }
        if (j == a.f.length()){  //b的小数位数比a多
            return -k;
        }
        else{  //a的小数位数比b多
            return k;
        }
    }
}

int main()
{
    int n, j, p, q;
    cin >> n;
    NUMBER *a = new NUMBER[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i].s;
        a[i].sign = 1;
        int j = 0;
        if (a[i].s[0] == '-'){
            a[i].sign = -1;
            j ++;
        }
        else if (a[i].s[0] == '+'){
            j ++;
        }
        int p;
        if ((p = a[i].s.find('.')) != string::npos){
            a[i].z = a[i].s.substr(j, p);
            a[i].f = a[i].s.substr(p + 1);
        }
        else{
            a[i].z = a[i].s;
        }
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i ++){
        cout << a[i].s << endl;
    }
    delete []a;
    return 0;
}