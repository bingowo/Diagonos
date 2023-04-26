#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 50
#define MAXN 28

int x[MAXN];
char com[MAXC];

char di[MAXC];

void chuli(char *, char *);

int main() {
    memset(x, 0, sizeof(x));
    while (scanf("%s", com) != EOF) {
        scanf("%s", di);
        chuli(com, di);
    }
    return 0;
}

void chuli(char *s, char *d) {
    if (strcmp(s, "IN") == 0) {
        x[d[0] - 'A'] = atoi(d + 3);
    } else if (strcmp(s, "MOV") == 0) {
        x[d[0] - 'A'] = x[d[3] - 'A'];
    } else if (strcmp(s, "ADD") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] += x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] + x[d[6] - 'A'];
    } else if (strcmp(s, "SUB") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] -= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] - x[d[6] - 'A'];
    } else if (strcmp(s, "MUL") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] *= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] * x[d[6] - 'A'];
    } else if (strcmp(s, "DIV") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] /= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] / x[d[6] - 'A'];
    }
    else if (strcmp(s, "MOD") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] %= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] % x[d[6] - 'A'];
    } else if (strcmp(s, "AND") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] &= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] & x[d[6] - 'A'];
    } else if (strcmp(s, "OR") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] |= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] | x[d[6] - 'A'];
    } else if (strcmp(s, "XOR") == 0) {
        if (strlen(d) == 5)
            x[d[0] - 'A'] ^= x[d[3] - 'A'];
        else
            x[d[0] - 'A'] = x[d[3] - 'A'] ^ x[d[6] - 'A'];
    }
    else if (strcmp(s, "OUT") == 0) {
        printf("%d\n", x[d[0] - 'A']);
    }
}
