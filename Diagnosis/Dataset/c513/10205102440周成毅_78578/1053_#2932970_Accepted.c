#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char s[MAXN];
char time1[12];
char time2[12];

void chuli(char *s) {
    int len = strlen(s);
    int zd = 0;
    unsigned c = 0;
    int i1 = 0;
    for (int i = 1; i < len - 3; i++) {
        c ^= s[i];
        if (s[i] == ',') {
            zd++;
            if (zd == 1)
                i1 = i + 1;
        }
        if (zd == 2 && s[i + 1] == 'A') {
            s[i] = '\0';
            strcpy(time1, s + i1);
        }
    }
    s[6] = '\0';
    if (strcmp(s, "$GPRMC") != 0)
        return;
    unsigned jj = 0;
    sscanf(s + len - 2, "%x", &jj);
    if (jj == c)
        if (strlen(time1) >= 6)
            strcpy(time2, time1);
}

int main() {
    scanf("%s\n", s);
    while (strcmp(s, "END") != 0) {
        chuli(s);
        scanf("%s\n", s);
    }
    int h = 0;
    /*printf("%s\n", time2);*/
    for (int i = 0; i < 2; i++)
        h = h * 10 + time2[i] - '0';
    h += 8;
    if (h >= 24)
        h -= 24;
    time2[6] = '\0';
    printf("%02d:%c%c:%s\n", h, time2[2], time2[3], time2 + 4);
    return 0;
}