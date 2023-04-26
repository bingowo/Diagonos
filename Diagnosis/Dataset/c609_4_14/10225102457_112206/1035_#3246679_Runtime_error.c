#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int eliminate(char *s) {
    int len = strlen(s);
    char t[len * 2 + 1];
    int ans = 0;
    for (int i = 0; i < len; ) {
        int j = i;
        while (j < len && s[j] == s[i]) {
            j++;
        }
        if (j - i > 1) {
            ans += j - i;
        } else {
            t[strlen(t)] = s[i];
        }
        i = j;
    }
    int new_len = strlen(t);
    while (1) {
        int flag = 0;
        for (int i = 0; i < new_len; ) {
            int j = i;
            while (j < new_len && t[j] == t[i]) {
                j++;
            }
            if (j - i > 1) {
                flag = 1;
                i = j;
            } else {
                i++;
            }
        }
        if (flag) {
            char new_t[new_len * 2 + 1];
            int k = 0;
            for (int i = 0; i < new_len; ) {
                int j = i;
                while (j < new_len && t[j] == t[i]) {
                    j++;
                }
                if (j - i > 1) {
                    ans += j - i;
                } else {
                    new_t[k++] = t[i];
                }
                i = j;
            }
            new_len = k;
            memcpy(t, new_t, new_len);
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char s[201];
        scanf("%s", s);
        int ans = 0;
        for (int j = 0; j <= strlen(s); j++) {
            char t[strlen(s) + 2];
            int k = 0;
            for (int l = 0; l < j; l++) {
                t[k++] = s[l];
            }
            t[k++] = 'A';
            for (int l = j; l < strlen(s); l++) {
                t[k++] = s[l];
            }
            t[k] = '\0';
            ans = max(ans, eliminate(t));
            t[k - 1] = 'B';
            ans = max(ans, eliminate(t));
            t[k - 1] = 'C';
            ans = max(ans, eliminate(t));
        }
        printf("case #%d:\n%d\n", i, ans);
    }
    return 0;
}