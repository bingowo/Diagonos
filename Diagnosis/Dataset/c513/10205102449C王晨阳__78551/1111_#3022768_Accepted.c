#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 110

int f(int x, int *xi) {
    return xi[3] * x * x * x + xi[2] * x * x + xi[1] * x + xi[0];
}

void ru(char *s, int *xi);

void csh(char s[][42]);

char s[MAXN];
char pi[42][42];

int main() {
    int xi[4];
    while (scanf("%s", s) != EOF) {
        memset(xi, 0, sizeof(xi));
        ru(s, xi);
        csh(pi);
        for (int i = 0; i <= 40; i++) {
            int y = f(i - 20, xi);
            if (y >= -20 && y <= 20)
                pi[20 - y][i] = '*';
        }
        for (int i = 0; i <= 40; i++) {
            for (int j = 0; j <= 40; j++)
                printf("%c", pi[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

void csh(char s[][42]) {
    for (int i = 0; i <= 40; i++)
        for (int j = 0; j <= 40; j++)
            s[i][j] = '.';
    for (int i = 0; i <= 40; i++) {
        s[20][i] = '-';
        s[i][20] = '|';
    }
    s[0][20] = '^';
    s[20][40] = '>';
    s[20][20] = '+';
}

void ru(char *s, int *xi) {
    int i = 5;
    while (s[i] != '\0') {
        if (s[i] == 'x') {
            s[i] = '\0';
            int c;
            int a;
            if (s[i + 1] == '^')
                c = s[i + 2] - '0';
            else
                c = 1;
            int i1 = i - 1;
            if (s[i1] == '-')
                a = -1;
            else if (s[i1] == '+' || s[i1] == '=')
                a = 1;
            else {
                while (isdigit(s[i1]))
                    i1--;
                if (s[i1] == '-')
                    i1--;
                a = atoi(s + i1 + 1);
            }
            s[i] = 'x';
            xi[c] = a;
        }
        i++;
    }
    int len = strlen(s);
    if (isdigit(s[len - 1]) && s[len - 2] != '^') {
        int i1 = len - 2;
        while (isdigit(s[i1]))
            i1--;
        if (s[i1] == '-')
            i1--;
        xi[0] = atoi(s + i1 + 1);
    }
}