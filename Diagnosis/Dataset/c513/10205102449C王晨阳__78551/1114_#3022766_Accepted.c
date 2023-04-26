#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 100

void ru(char *, int *);

int fen(int, int *);

char fx[MAXN];
char na[] = "No Answer!";
int xi[3];
int yz1[MAXN];
int yz2[MAXN];

int main() {
    scanf("%s\n", fx);
    ru(fx, xi);
    int l1 = fen(xi[2], yz1);
    int l2 = fen(xi[0], yz2);
    int xi1[2][2];
    int state = 0;
    if (l2 == 0) {
        if (xi[2] == 1) {
            xi1[0][1] = xi1[1][1] = 1;
            if (xi[1] <= 0) {
                xi1[0][0] = xi[1];
                xi1[1][0] = 0;
            } else {
                xi1[1][0] = xi[1];
                xi1[0][0] = 0;
            }
        } else {
            xi1[0][1] = 1;
            xi1[0][0] = 0;
            xi1[1][1] = xi[2];
            xi1[1][0] = xi[1];
        }
        state = 1;
    } else {
        int a1, c1, a2, c2;
        for (int i = 0; i < l1; i++) {
            a1 = yz1[i];
            a2 = xi[2] / yz1[i];
            for (int j = 0; j < l2; j++) {
                c1 = yz2[j];
                c2 = xi[0] / yz2[j];
                if (a1 * c2 + a2 * c1 == xi[1]) {
                    state = 1;
                    xi1[0][1] = a1;
                    xi1[0][0] = c1;
                    xi1[1][1] = a2;
                    xi1[1][0] = c2;
                    if (a1 == a2 && c1 > c2) {
                        xi1[1][0] = c1;
                        xi1[0][0] = c2;
                    }
                    break;
                }
            }
            if (state)
                break;
        }
    }
    if (state == 0)
        printf("%s\n", na);
    else {
        for (int i = 0; i < 2; i++)
            for (int j = 1; j >= 0; j--)
                printf("%d ", xi1[i][j]);
        printf("\n");
    }
    return 0;
}

int fen(int x, int *yz) {
    //printf("%d\n", x);
    if (x < 0)
        x *= -1;
    if (x == 0)
        return 0;
    else if (x == 1) {
        yz[0] = 1;
        yz[1] = -1;
        return 2;
    }
    int l = 0;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0)
            yz[l++] = i;
    }
    for (int i = l; i < 2 * l; i++) {
        yz[i] = -1 * yz[i - l];
    }
    return 2 * l;
}

void ru(char *s, int *d) {
    int len = strlen(s);
    int i = 0;
    while (i < len) {
        if (s[i] == 'x') {
            int c = 1;
            if (i < len - 1 && s[i + 1] == '^')
                c = s[i + 2] - '0';
            int i1 = i - 1;
            if (i == 0)
                d[c] = 1;
            else if (s[i - 1] == '-')
                d[c] = -1;
            else {
                while (i1 >= 0 && isdigit(s[i1]))
                    i1--;
                if (i1 >= 1 && s[i1 - 1] == '-')
                    i1--;
                s[i] = '\0';
                d[c] = atoi(i1 == -1 ? s + i1 + 1 : s + i1);
                s[i] = 'x';
            }
        }
        i++;
    }
    int i1 = len - 1;
    while (i1 >= 0 && isdigit(s[i1]))
        i1--;
    if (i1 == -1 || s[i1] == '+' || s[i1] == '-') {
        d[0] = atoi(i1 == -1 ? s + i1 + 1 : s + i1);
    }
}