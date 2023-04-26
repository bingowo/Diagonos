#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int case_id = 0; case_id < T; case_id++) {
        char s[105];
        scanf("%s", s);
        int n = strlen(s);

        int ans = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                char c = 'A' + j;
                int cnt = 0;
                int k = 0;
                char t[105];
                for (int p = 0; p < i; p++) {
                    t[k++] = s[p];
                }
                t[k++] = c;
                for (int p = i; p < n; p++) {
                    if (s[p] == c) {
                        cnt++;
                    } else {
                        if (cnt % 2 == 1) {
                            t[k++] = c;
                        }
                        cnt = 0;
                        t[k++] = s[p];
                    }
                }
                if (cnt % 2 == 1) {
                    t[k++] = c;
                }
                t[k] = '\0';

                int len = strlen(t);
                int flag = 1;
                while (flag) {
                    flag = 0;
                    cnt = 0;
                    k = 0;
                    for (int p = 0; p < len; p++) {
                        if (p < len - 1 && t[p] == t[p + 1]) {
                            cnt++;
                        } else {
                            if (cnt >= 1) {
                                flag = 1;
                                cnt = 0;
                            } else {
                                t[k++] = t[p];
                            }
                        }
                    }
                    t[k] = '\0';
                    len = strlen(t);
                }

                ans = max(ans, n - len);
            }
        }

        printf("case #%d:\n", case_id);
        printf("%d\n", ans);
    }

    return 0;
}