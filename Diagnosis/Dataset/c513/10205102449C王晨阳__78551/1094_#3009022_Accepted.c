#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int flag;
    char s[125];
    int len;
} big;

//increasing
int cmp(const void *a, const void *b) {
    big *a1 = (big *) a, *b1 = (big *) b;
    if (a1->flag == b1->flag) {
        if (a1->flag == 1) {
            if (a1->len == b1->len)
                return strcmp(a1->s, b1->s);
            else
                return a1->len - b1->len;
        } else {
            if (a1->len == b1->len)
                return strcmp(b1->s, a1->s);
            else
                return b1->len - a1->len;
        }
    } else {
        return a1->flag - b1->flag;
    }
}

int main() {
    big ll[50];
    int n;
    char s[125];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if (s[0] == '-') {
            ll[i].flag = -1;
            strcpy(ll[i].s, s + 1);
            ll[i].len = strlen(s) - 1;
        } else {
            ll[i].flag = 1;
            strcpy(ll[i].s, s);
            ll[i].len = strlen(s);
        }
    }
    qsort(ll, n, sizeof(big), cmp);
    int res[125];
    int co = 0;
    if (ll[0].flag == ll[n - 1].flag) {
        if (ll[0].flag == 1) {
            for (int i = ll[n - 1].len - 1; i >= ll[n - 1].len - ll[0].len; i--) {
                if (ll[n - 1].s[i] - ll[0].s[i - ll[n - 1].len + ll[0].len] < 0) {
                    res[co++] = ll[n - 1].s[i] - ll[0].s[i - ll[n - 1].len + ll[0].len] + 10;
                    ll[n - 1].s[i - 1]--;
                } else {
                    res[co++] = ll[n - 1].s[i] - ll[0].s[i - ll[n - 1].len + ll[0].len];
                }
            }
            for (int i = ll[n - 1].len - ll[0].len - 1; i >= 0; i--) {
                if (ll[n - 1].s[i] < '0') {
                    res[co++] = ll[n - 1].s[i] - '0' + 10;
                    ll[n - 1].s[i - 1]--;
                } else {
                    res[co++] = ll[n - 1].s[i] - '0';
                }
            }
        } else {
            for (int i = ll[0].len - 1; i >= ll[0].len - ll[n - 1].len; i--) {
                if (ll[0].s[i] - ll[n - 1].s[i + ll[n - 1].len - ll[0].len] < 0) {
                    res[co++] = ll[0].s[i] - ll[n - 1].s[i + ll[n - 1].len - ll[0].len] + 10;
                    ll[0].s[i - 1]--;
                } else {
                    res[co++] = ll[0].s[i] - ll[0].s[i + ll[n - 1].len - ll[0].len];
                }
            }
            for (int i = ll[0].len - ll[n - 1].len - 1; i >= 0; i--) {
                if (ll[0].s[i] < '0') {
                    res[co++] = ll[0].s[i] - '0' + 10;
                    ll[0].s[i - 1]--;
                } else {
                    res[co++] = ll[0].s[i] - '0';
                }
            }
        }
    } else {
        if (ll[n - 1].len >= ll[0].len) {
            int jin = 0;
            for (int i = ll[n - 1].len - 1; i >= ll[n - 1].len - ll[0].len; i--) {
                int tmp = ll[n - 1].s[i] - '0' + ll[0].s[i - ll[n - 1].len + ll[0].len] - '0' + jin;
                res[co++] = tmp % 10;
                jin = tmp / 10;
            }
            for (int i = ll[n - 1].len - ll[0].len - 1; i >= 0; i--) {
                int tmp = ll[n - 1].s[i] - '0' + jin;
                res[co++] = tmp % 10;
                jin = tmp / 10;
            }
            res[co++] = jin;
        } else {
            int jin = 0;
            for (int i = ll[0].len - 1; i >= ll[0].len - ll[n - 1].len; i--) {
                int tmp = ll[0].s[i] - '0' + ll[n-1].s[i + ll[n - 1].len - ll[0].len] - '0' + jin;
                res[co++] = tmp % 10;
                jin = tmp / 10;
            }
            for (int i = ll[0].len - ll[n - 1].len - 1; i >= 0; i--) {
                int tmp = ll[0].s[i] - '0' + jin;
                res[co++] = tmp % 10;
                jin = tmp / 10;
            }
            res[co++] = jin;
        }
    }
    co--;
    while (res[co]==0)
        co--;
    for(;co>=0;co--)
        printf("%d",res[co]);
    printf("\n");
    return 0;
}
