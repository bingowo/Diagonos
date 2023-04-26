#include <stdio.h>
#include <string.h>

typedef long long ll;

char str[65];
int val[128]; // 用于存储字符所代表的数字，128个ASCII字符足够了

ll solve(char *s, int len, int base) {
    if (len == 1) return val[*s];
    ll ans = 0, p = 1;
    for (int i = len - 1; i >= 0; i--) {
        ans += p * val[s[i]];
        p *= base;
    }
    if (val[*s] == 0) return solve(s + 1, len - 1, base);
    ll tmp = solve(s + 1, len - 1, base);
    if (tmp == 0) return ans;
    if (ans <= tmp) return ans + tmp * base;
    return ans + tmp;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 0; cas < t; cas++) {
        scanf("%s", str);
        int len = strlen(str);
        memset(val, -1, sizeof(val)); // 初始化为-1
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (val[str[i]] == -1) {
                val[str[i]] = cnt++;
                if (cnt == 1) cnt++; // 0不能作为首位
            }
        }
        printf("case #%d: %lld\n", cas, solve(str, len, cnt));
    }
    return 0;
}
