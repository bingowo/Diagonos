#include <bits/stdc++.h>
using namespace std;
struct Val{
    int dig; // 数位长度
    int val; // 数字
};
Val a[1000006];
// 获得数位长度
int getDig (int val){
    val = abs(val);
    int ans = 0;
    while (val){
        ans ++;
        val /= 10;
    }
    return ans;
}
int cmp (const Val & a , const Val& b){
    if (a.dig != b.dig)
        return a.dig > b.dig;
    return a.val < b.val;
}
int main() {
    int x , n = 0;
    while (cin >> x) {
        a[++n].val = x;
        a[n].dig = getDig(a[n].val);
    }
    sort(a + 1 , a + n + 1 , cmp);
    for (int i = 1 ; i <= n ; i++){
        cout << a[i].val;
        if (i == n) cout << endl;
        else cout << " ";
    }
    return 0;
}