#include <stdio.h>
#include <string.h>

#define MAXN 110

int huai(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        if (s[i] == '!')
            return 1;
    return 0;
}

int xiu(char *s) {
    int len = strlen(s);
    int cs[4];
    memset(cs, 0, sizeof(cs));
    for (int i = 0; i < len - 3; i++) {
        int z1 = 0;
        int mh = 0;
        for (int z = 0; z < 4; z++) {
            if (s[i + z] != '!')
                mh++;
            else
                z1 = i + z;
        }
        if (mh == 3) {
            for (int k = 0; k < 4; k++)
                if (s[i + k] == 'R')
                    cs[0]++;
                else if (s[i + k] == 'B')
                    cs[1]++;
                else if (s[i + k] == 'Y')
                    cs[2]++;
                else if (s[i + k] == 'G')
                    cs[3]++;
            for (int k = 0; k < 4; k++)
                if (cs[k] == 0) {
                    if (k == 0)
                        s[z1] = 'R';
                    else if (k == 1)
                        s[z1] = 'B';
                    else if (k == 2)
                        s[z1] = 'Y';
                    else if (k == 3)
                        s[z1] = 'G';
                    return k + 1;
                }
        }
    }
}

char s[MAXN];

int main() {
    int n;
    int c[5];
    int state;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        memset(c, 0, sizeof(c));
        state = 0;
        while (huai(s)) {
            state = xiu(s);
            c[state]++;
        }
        printf("case #%d:\n", i);
        for (int i = 1; i < 5; i++)
            printf("%d ", c[i]);
        printf("\n");
    }
    return 0;
}