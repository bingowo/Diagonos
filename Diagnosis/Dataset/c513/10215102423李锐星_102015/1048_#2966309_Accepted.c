#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

void readpoly(char *s, int* poly)
{
    while (*s){
        int sign = 1, a = 0, i = 0;
        if (*s == '+' ) ++s;
        else if (*s == '-') sign = -1, ++s;

        while (isdigit(*s)){
            a = a * 10 + *s -'0';
            ++s;
        }
        if (a == 0) a = 1;
        if (*s != 'x') {poly[0] = a * sign; return;}
        else ++s;

        if (*s == '^') ++s;
        while (isdigit(*s)) {
            i = i * 10 + *s - '0';
            ++s;
        }
        if (i == 0) i = 1;

        poly[i] = a * sign;
    }
}

void multiply(char *s1,char *s2, int* poly)
{
    int poly1[N] = {0}, poly2[N] = {0}, i, j;
    readpoly(s1, poly1);
    readpoly(s2, poly2);
    for (i = 0; i < N / 2; ++i)
        for (j = 0; j < N / 2; ++j)
            poly[i + j] += poly1[i] * poly2[j];
}

int main()
{
    char s1[N+1], s2[N+1];

    while(scanf("%s%s", s1, s2) != EOF){
        int poly[N] = {0}, out[N], n = 0, i;
        multiply(s1, s2, poly);
        for (i = 0; i < N; ++i)
            if (poly[i]) out[n++] = poly[i];
        for (i = n - 1; i >= 0; --i){
            printf("%d", out[i]);
            i ? printf(" ") : printf("\n");
        }
    }
    return 0;
}
