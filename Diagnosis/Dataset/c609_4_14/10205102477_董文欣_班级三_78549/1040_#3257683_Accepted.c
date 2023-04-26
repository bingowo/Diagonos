#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read(char *s, int *index) {
    while (*s) {
        int sign = 1;
        if (*s == '-') {sign = -1; s++;}
        if (*s == '+') s++;
        int down = 0, up = 0;
        while (isdigit(*s)) {
            down = down * 10 + *s - '0';
            s++;
        }
        if (down == 0) down = 1;

        if (*s != 'x') {index[0] = down * sign; return;}
        else s++;

        if (*s == '^') s++;

        while (isdigit(*s)) {
            up = up * 10 + *s - '0';
            s++;
        }

        if(up == 0) up = 1;
        index[up] = down * sign;

    }
}

void mul(char *s1, char *s2, int *ans) {
    int index1[50] = {0}, index2[50] = {0};
    read(s1, index1);
    read(s2, index2);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            ans[i+j] += index1[i] * index2[j];
        }
    }

}

int main()
{
    char s1[101], s2[101];
    while (scanf("%s %s",s1, s2) == 2) {
        int ans[101] = {0};
        mul(s1, s2, ans);

        for (int i = 100; i >= 0; i--) {
            if (ans[i]) printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
