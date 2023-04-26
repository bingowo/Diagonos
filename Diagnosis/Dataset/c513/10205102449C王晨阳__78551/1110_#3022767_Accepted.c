#include <stdio.h>
#include <ctype.h>

#define MAXL 100

char pattern[MAXL];

int main() {
    scanf("%s", pattern);
    int xs = 0;
    int con = 0;
    char *a;
    a = pattern;
    char qw;
    qw = -1;
    char cs;
    while (*a != '=') {
        int shu = 0;
        if (isalpha(*a)) {
            cs = *a;
            if (a - pattern) {
                if (qw == '-')
                    xs--;
                else if (qw == '+')
                    xs++;
            } else
                xs++;
        }
        if (isdigit(*a)) {
            while (isdigit(*a)) {
                shu = shu * 10 + *a - '0';
                a++;
            }
            if (isalpha(*a)) {
                cs = *a;
                if (qw == -1)
                    xs += shu;
                else {
                    if (qw == '-')
                        xs -= shu;
                    else if (qw == '+')
                        xs += shu;
                }
                a++;
                continue;
            }
            if (a - pattern) {
                if (qw == '-')
                    con += shu;
                else if (qw == '+' || qw == -1)
                    con -= shu;
            } else
                con -= shu;
            continue;
        }
        qw = *a;
        a++;
    }
    a++;
    char *a1;
    a1 = a;
    qw = -1;
    while (*a != '\0') {
        int shu = 0;
        if (isalpha(*a)) {
            cs = *a;
            if (a - a1) {
                if (qw == '-')
                    xs++;
                else if (qw == '+')
                    xs--;
            } else
                xs--;
        }
        if (isdigit(*a)) {
            while (isdigit(*a)) {
                shu = shu * 10 + *a - '0';
                a++;
            }
            if (isalpha(*a)) {
                cs = *a;
                if (qw == -1)
                    xs -= shu;
                else {
                    if (qw == '-')
                        xs += shu;
                    else if (qw == '+')
                        xs -= shu;
                }
                a++;
                continue;
            }
            if (a - a1) {
                if (qw == '-')
                    con -= shu;
                else if (qw == '+' || qw == -1)
                    con += shu;
            } else
                con += shu;
            continue;
        }
        qw = *a;
        a++;
    }
    printf("%c=%.3f\n", cs, 1.0 * con / xs);
    return 0;
}