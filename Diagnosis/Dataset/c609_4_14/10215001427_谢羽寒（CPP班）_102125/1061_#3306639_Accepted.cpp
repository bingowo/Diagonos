
//法1
#include <iostream>
#include <cmath>
using namespace std;
    const int N = 1000;
    int n;
    long long f[N];

bool is_prime(int x)  // 判断素数
{
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i ++ ){
        if (x % i == 0) return false;
        }
    return true;
}

int main()
{
    cin >> n;//输入
    f[0]=1;
    //迭代
    for (int i = 2; i <= n; i ++ ){
        if (is_prime(i)) // 只考虑素数
            for (int j = i; j <= n; j ++ ){
                f[j] += f[j - i]; } // 转换
    }
    cout << f[n] << endl;

    return 0;
}