#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ele {
    char str[1000];
    long long num;
    int has_num;
};

void assign(struct ele *e) {
    int len = strlen(e->str);
    for (int i = 0; i < len; i++) {
        if (e->str[i] >= '0' && e->str[i] <= '9') {
            e->has_num = 1;
            e->num *= 10;
            e->num += e->str[i] - '0';
        }
    }
}

int cmp(const void *q1, const void *q2) {
    struct ele *p1 = (struct ele *) q1;
    struct ele *p2 = (struct ele *) q2;
    if (p1->has_num != p2->has_num) {
        return p1->has_num - p2->has_num;
    } else {
        if (p1->num != p2->num) {
            return p1->num - p2->num;
        } else {
            return strcmp(p1->str, p2->str);
        }
    }
}

int main() {
    struct ele a[1000];
    int n = 0;
    char c = getchar();
    int len = 0;
    while (c != '\n') {
        a[n].str[len++] = c;
        c = getchar();
        if (c == ' ') {
            c = getchar();
            len = 0;
            assign(&a[n++]);
        }
    }

    assign(&a[n++]);

    qsort(a, n, sizeof(struct ele), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s ", a[i].str);
    }

    return 0;
}
