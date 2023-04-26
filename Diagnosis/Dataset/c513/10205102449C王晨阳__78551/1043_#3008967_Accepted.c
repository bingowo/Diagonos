#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 200

char s[MAXN];

char s1[MAXN];

int chacho(char *s) {
    int l = strlen(s);
    if (l <= 1)
        return 0;
    for (int i = 1; i < l; i++) {
        if (s[i] == s[i - 1])
            return 1;
    }
    return 0;
}

int xiaochu(char *s) {
    int l = strlen(s);
    int xcs = 0;
    for (int i = 0; i < l - 1; i++) {
        if (s[i] == s[i + 1]) {
            s[i] = 0;
            i++;
            while (s[i] == s[i + 1]) {
                s[i] = 0;
                i++;
            }
            s[i] = 0;
        }
    }
    for (int i = 0, k = 0; i < l && k < l; i++, k++) {
        while (!isalpha(s[k]) && k < l) {
            k++;
            xcs++;
        }
        s[i] = s[k];
    }
    s[l - xcs] = '\0';
    return xcs;
}


int main() {
    int pnum;
    scanf("%d\n", &pnum);
    for (int i = 0; i < pnum; i++) {
        scanf("%s", s);
        int x = 0, x1;
        int zx = x;
        int len = strlen(s);
        for (int i = 0; i < 3 * (len - 1); i++) {
            x1 = 0;
            char c;
            if (i % 3 == 0)
                c = 'A';
            else if (i % 3 == 1)
                c = 'B';
            else if (i % 3 == 2)
                c = 'C';
            int w = i / 3;
            for (int j = 0; j <= w; j++) {
                s1[j] = s[j];
                s1[j + 1] = c;
                s1[j + 2] = '\0';
            }
            strcat(s1, s + w + 1);
            /*printf("%s\n", s1);*/
            while (chacho(s1))
                x1 += xiaochu(s1);
            /*printf("%s\n", s1);*/
            if (x1 > zx)
                zx = x1;
        }
        printf("case #%d:\n", i);
        printf("%d\n", zx);
    }
    return 0;
}