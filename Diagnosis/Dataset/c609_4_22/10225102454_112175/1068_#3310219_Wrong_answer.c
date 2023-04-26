// #include<bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define pb push_back
// #define eb emplace_back
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define SZ(x) ((int)(x).size())
// #define Bit(x) (1 << (x))
// using VI = vector <int>;
// using PII = pair <int, int>;
// using ll = long long;
// using db = double;
// using u64 = unsigned long long;
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// // head

// // ll f[30][106];
#include <stdio.h>

int f(int n,int p,int m,int t) {
    if (m==0&&p==t) return 1;
    if (m==0&&p!=t) return 0;
    if (m>0&&p==1) return f(n,p + 1,m-1,t);
    if (m>0&&p==n) return f(n,p - 1,m-1,t);
    else return f(n,p + 1,m-1,t)+f(n,p + 1,m-1,t);
}

int main () {
    int cas,i;
    int n,p,m,t;
    scanf ("%d", &cas);
    for (i=0;i<cas;i++) {
        scanf ("%d%d%d%d", &n,&p,&m,&t);
        // memset(f, -1, sizeof(f));
        if (t>n) printf("%d\n", 0);
        else printf("%d\n", f(n,p,m,t));
    }
    return 0;
}

// inline void solve(void)
// {
//     int n;
//     cin >> n;
//     f[1] = 1, f[2] = 2, f[3] = 4, f[4] = 8;
//     for (int i = 5; i <= n; i++)
//         f[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4];
//     cout << f[n] << endl;
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc = 1;
//     // cin >> tc;
//     for (int i = 0; i < tc; i++)
//         solve();
    
//     return 0;
// }