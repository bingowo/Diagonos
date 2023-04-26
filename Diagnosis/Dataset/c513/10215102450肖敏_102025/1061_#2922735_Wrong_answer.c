#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MIN {
    char si[16];
    long long int x;
};
struct MIN min[10001];

int cmp(const void *a, const void *b) {
    struct MIN *a1 = (struct MIN *) a, *b1 = (struct MIN *) b;
    if (a1->x == b1->x)
        strcmp(a1->si, b1->si);
    else {
        if (a1->x > b1->x)
            return 1;
        return -1;
    }
}

int main() {
    int i, t, j, flag;
    long long int m;
    char s[16];
    char s2[123];

    int N;
    scanf("%d", &N);
    for (int e = 0; e < N; e++) {
        j = 2;
        flag = 1;
        m = 0;
        for (t = 0; t < 123; t++) {
            s2[t] = -1;
        }
        scanf("%s", s);
        for (i = 0; s[i] != '\0'; i++) {
            min[e].si[i] = s[i];
            if (s2[s[i]] == -1) {
                if (i == 0) {
                    s2[s[i]] = 1;
                } else if (flag == 1) {
                    s2[s[i]] = 0;
                    flag = 0;
                } else {
                    s2[s[i]] = j;
                    j++;
                }
            }
        }
        for (int k = 0; k < i; k++) {
            m = m * j + s2[s[k]];
            min[e].x = m;
        }
    }
    qsort(min, N, sizeof(min[0]), cmp);
    for (int y = 0; y < N; y++)
        printf("%s\n", min[y].si);
    return 0;
}
