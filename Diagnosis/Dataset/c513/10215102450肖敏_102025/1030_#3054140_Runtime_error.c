#include <stdio.h>
#include <stdlib.h>

struct data {
    char s[20];
    long long num;
    int bit;
};

int cmp(const void *a, const void *b) {
    struct data *a1 = (struct data *) a, *b1 = (struct data *) b;
    if (a1->bit != b1->bit)
        return b1->bit - a1->bit;
    else if (a1->num > b1->num)
        return 1;
    return -1;
}

void high(struct data *b) {
    if (b->s[0] == '-')
        b->bit = b->s[1] - '0';
    else
        b->bit = b->s[0] - '0';
}

int main() {
    struct data list[10001];
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &list[j].num);
            sprintf(list[j].s, list[j].num);
            high(&list[j]);
        }
        qsort(list, n, sizeof(list[0]), cmp);
        printf("case #%d:\n", i);
        for (int k = 0; k < n; k++)
            printf("%lld ", list[k].num);
        printf("\n");
    }
}