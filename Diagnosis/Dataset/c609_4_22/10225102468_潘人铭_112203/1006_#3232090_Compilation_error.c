#include <iostream>
#include <cstdio>
using namespace std;

void solve()
{
    char s[61]; cin >> s;
    int num[128];
    for (int i = 0; i < 128; i++) num[i] = -1;
    int cnt = 0;
    char* p = s;
    num[*p] = 1;
    while (*++p)
    {
        if (num[*p] == -1)
        {
            num[*p] = cnt;
            cnt = cnt ? cnt + 1 : 2;
        }
    }
    if (cnt < 2) cnt = 2;
    long long ans = 0;
    p = s;
    while (*p) ans = ans * cnt + num[*p++];
    printf("%lld\n", ans);
}

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "case #" << i << ":" << endl;
        solve();
    }
}