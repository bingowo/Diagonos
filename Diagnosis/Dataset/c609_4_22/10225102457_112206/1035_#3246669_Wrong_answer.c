#include <stdio.h>
#include <string.h>

#define MAXN 105

char s[MAXN];
int len, ans;

int find(char c, int l, int r) {//find the nearest diff
    for (int i = l; i <= r; i++) {
        if (s[i] == c) return i;
    }
    return -1;
}

int solve(char c, int l, int r) {//calculate diff
    int cnt = 0;
    while (1) {
        int pos1 = find(c, l, r);
        if (pos1 == -1) break;
        int pos2 = pos1 + 1;
        while (pos2 <= r && s[pos2] == s[pos1]) pos2++;
        if (pos2 - pos1 > 1) {
            cnt += pos2 - pos1;
            l = pos2;
        } else {
            l = pos1 + 1;
        }
    }
    return cnt;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%s", s);
        len = strlen(s);
        ans = 0;
        for (int i = 0; i <= len; i++) {
            for (char c = 'A'; c <= 'C'; c++) {
                int cnt = solve(c, 0, i - 1) + solve(c, i, len - 1);//find
                if (cnt > ans) ans = cnt;//plus
            }
        }
        printf("case #%d:\n%d\n", t, ans);
    }
    return 0;
}