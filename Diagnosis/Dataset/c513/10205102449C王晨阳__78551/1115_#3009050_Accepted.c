#include <stdio.h>
#include <string.h>

#define MAXN 50

char shu[MAXN];
char chu[MAXN];

void f(char *, char *);

int main() {
    int pnum;
    scanf("%d\n", &pnum);
    for (int i = 0; i < pnum; i++) {
        scanf("%s\n", shu);
        memset(chu, 0, sizeof(chu));
        f(chu, shu);
        printf("case #%d:\n%s\n", i, chu);
    }
    return 0;
}

void f(char *d, char *s) {
    strcpy(d, s);
    int len = strlen(s);
    int n[10];
    memset(n, 0, sizeof(n));
    int i = 0;
    for (i = len - 1; i >= 1; i--)
        if (s[i] > s[i - 1])
            break;
    int i1 = i;
    if (i > 0)
        i--;
    for (int j = i; j < len; j++)
        n[s[j] - '0']++;
    if (i == 0) {
        for (int i = 1; i <= 9; i++)
            if (n[i]) {
                d[0] = i + '0';
                n[i]--;
                break;
            }
        d[1] = '0';
        for (int i = 2; i < len + 1; i++)
            for (int j = 0; j <= 9; j++)
                if (n[j]) {
                    d[i] = j + '0';
                    n[j]--;
                    break;
                }
        d[len + 1] = '\0';
        return;
    }
    i1--;
    {
        int c = s[i1] - '0';
        //printf("%d\n", c);
        for (int i = c + 1; i <= 9; i++)
            if (n[i]) {
                d[i1] = i + '0';
                n[i]--;
                break;
            }
        for (int i = i1 + 1; i < len; i++)
            for (int j = 0; j <= 9; j++)
                if (n[j]) {
                    d[i] = j + '0';
                    n[j]--;
                    break;
                }
        d[len] = '\0';
    }
    return;
}